#pragma once

#include <stdarg.h>//c���Ե�����Ϊ���ú������Խ��ܿɱ����

//////////////////////////////////////////////////////////

//#define __DEBUG__

static string GetFileName(const string& path)
{
	char ch = '/';

#ifdef _WIN32
	ch = '\\' ;
#endif

	size_t pos = path. rfind(ch );
	if (pos == string:: npos)
		return path ;
	else
		return path .substr( pos + 1);
}

// ���ڵ���׷�ݵ�trace log
inline static void __trace_debug (const char* function,
								  const char * filename, int line , char* format , ...)
{
	// ��ȡ�����ļ�
#ifdef __DEBUG__
	// ������ú�������Ϣ
	fprintf(stdout, "�� %s:%d��%s" , GetFileName (filename). c_str(), line , function);

	// ����û����trace��Ϣ
	va_list args ;
	va_start (args , format);
	vfprintf (stdout , format, args);
	va_end (args );
#endif
}

#define __TRACE_DEBUG(...)  \
	__trace_debug(__FUNCTION__ , __FILE__, __LINE__, __VA_ARGS__);


//////////////////////////////////////////////////////////
// һ���ռ�������
typedef void (*HANDLER_FUNC) ();
template <int inst>
class __MallocAllocTemplate
{
private:

static HANDLER_FUNC __malloc_alloc_oom_handler;

public:
	static void* OOM_Malloc(size_t n)
	{
		void* ret = NULL;
		while (1)
		{
			if (__malloc_alloc_oom_handler == 0)
				throw bad_alloc();

			__malloc_alloc_oom_handler();
			ret = malloc(n);
			if(ret)
				break;
		}		
		return ret;
	}

	static void * Allocate(size_t n)
	{
		void *result = malloc(n);
		if (0 == result)
			result = OOM_Malloc(n);

		__TRACE_DEBUG("һ���ռ����������룺0x%p, %d\n",result, n);

		return result;
	}

	static void Deallocate(void *p, size_t n/* n */)
	{
		__TRACE_DEBUG("һ���ռ��������ͷţ�0x%p, %d\n",p, n);

		free(p);
	}

	HANDLER_FUNC SetMallocHandler(HANDLER_FUNC f)
	{
		HANDLER_FUNC old = f;
		__malloc_alloc_oom_handler = f;
		return old;
	}
};

template<int inst>
HANDLER_FUNC __MallocAllocTemplate<inst>::__malloc_alloc_oom_handler = 0;

////////////////////////////////////////////////////////
// �����ռ�������

template <bool threads, int inst>
class __DefaultAllocTemplate
{
	enum {__ALIGN = 8};
	enum {__MAX_BYTES = 128};
	enum {__NFREELISTS = __MAX_BYTES/__ALIGN};

	union Obj
	{
		union Obj* _freeListLink;
		char client_data[1];    /* The client sees this.        */
	};

	static Obj* _freeList[__NFREELISTS];

	// Chunk allocation state.
	static char* _startFree;
	static char* _endFree;
	static size_t _heapSize;

	static  size_t FREELIST_INDEX(size_t bytes)
	{
		// 1 8 -> 0  8  15
		// 9 16 -> 1 16 23
		return (((bytes) + __ALIGN-1)/__ALIGN - 1);		
	}

	static size_t ROUND_UP(size_t n)
	{
		return (n+__ALIGN-1) & (~(__ALIGN-1));
	}

	static char* ChunkAlloc(size_t size, size_t& nobjs)
	{
		__TRACE_DEBUG("��С���ȡ����%d��%d��С�Ķ���\n",nobjs, size);

		size_t totalBytes = size*nobjs;
		size_t bytesLeft = _endFree - _startFree;
		// 1. >20
		// 2. 1-19
		// 3.����
		if (bytesLeft >= totalBytes)
		{
			__TRACE_DEBUG("С�����%d��%d��С�Ķ���\n",nobjs, size);
			char* ret = _startFree;
			_startFree += totalBytes;
			return ret;
		}
		else if (bytesLeft > size)
		{
			nobjs = bytesLeft/size;
			totalBytes = nobjs*size;
			char* ret = _startFree;
			_startFree += totalBytes;
			__TRACE_DEBUG("С���ֻ��%d��%d��С�Ķ���\n",nobjs, size);
			return ret;
		}
		else
		{
			__TRACE_DEBUG("С���һ��%d��С�Ķ���û��\n", size);

			if (bytesLeft > 0)
			{
				size_t index = FREELIST_INDEX(bytesLeft);
				((Obj*)_startFree)->_freeListLink = _freeList[index];
				_freeList[index] = (Obj*)_startFree;
			}

			size_t bytesToGet = totalBytes*2 + ROUND_UP(_heapSize>>4);
			_startFree = (char*)malloc(bytesToGet);
			__TRACE_DEBUG("��ϵͳ����%d�ֽڴ�С�Ĵ���ڴ�\n", bytesToGet);

			if (_startFree == 0)
			{
				// �������������
				for (size_t i = FREELIST_INDEX(size); i < __NFREELISTS; ++i)
				{
					if (_freeList[i])
					{
						Obj* obj = _freeList[i];
						_freeList[i] = obj->_freeListLink;
						_startFree = (char*)obj;
						_endFree = _startFree + (i+1)*__ALIGN;
						return ChunkAlloc(size, nobjs);
					}
				}

				_endFree = 0; // ��ֹ�쳣
				_startFree = (char*)__MallocAllocTemplate<inst>::Allocate(bytesToGet);
			}

			_endFree = _startFree+bytesToGet;
			_heapSize += bytesToGet;
			return ChunkAlloc(size, nobjs);
		}
	}

	static void* Refill(size_t size)
	{
		size_t nobjs = 20;
		char* chunk = ChunkAlloc(size, nobjs);
		if (nobjs == 1)
			return chunk;

		__TRACE_DEBUG("��ʣ���%d������ҵ��������������\n", nobjs-1);
		size_t index = FREELIST_INDEX(size);
		for (size_t i = 1; i < nobjs; ++i)
		{
			Obj* obj = (Obj*)(chunk+i*size);
			obj->_freeListLink = _freeList[index];
			_freeList[index] = obj;
		}

		return chunk;
	}

public:
	static void* Allocate(size_t n)
	{
		if (n > __MAX_BYTES)
		{
			return __MallocAllocTemplate<inst>::Allocate(n);
		}

		size_t index = FREELIST_INDEX(n);
		if (_freeList[index])
		{
			Obj* ret = _freeList[index];
			_freeList[index] = ret->_freeListLink;

			__TRACE_DEBUG("��������ȡ�ڴ����0x%p, %d\n",ret, index);
			return ret;
		}
		else
		{
			return Refill(ROUND_UP(n));
		}
	}

	static void Deallocate(void* ptr, size_t n)
	{
		if (ptr == NULL)
			return;

		__TRACE_DEBUG("�����ռ��������ͷ��ڴ����0x%p, %d\n",ptr, n);

		if (n > __MAX_BYTES)
		{
			__MallocAllocTemplate<inst>::Deallocate(ptr, n);
		}
		else
		{
			size_t index = FREELIST_INDEX(n);
			((Obj*)ptr)->_freeListLink = _freeList[index];
			_freeList[index] = (Obj*)ptr;
		}		
	}
};

template<bool threads, int inst>
typename __DefaultAllocTemplate<threads, inst>::Obj*
__DefaultAllocTemplate<threads, inst>::_freeList[__NFREELISTS] = {0};

// Chunk allocation state.
template<bool threads, int inst>
char* __DefaultAllocTemplate<threads, inst>::_startFree = 0;

template<bool threads, int inst>
char*__DefaultAllocTemplate<threads, inst>:: _endFree = 0;

template<bool threads, int inst>
size_t __DefaultAllocTemplate<threads, inst>::_heapSize = 0;

# ifdef __USE_MALLOC
typedef __MallocAllocTemplate<0> Alloc;
#else
typedef __DefaultAllocTemplate<false, 0> Alloc;
#endif // __USE_MALLOC



template<class T, class Alloc>
class SimpleAlloc
{
public:

	static T* Allocate(size_t n)
	{ 
		return 0 == n? 0 : (T*) Alloc::Allocate(n * sizeof (T));
	}

	static T* Allocate(void)
	{ 
		return (T*) Alloc::Allocate(sizeof (T));
	}

	static void Deallocate(T *p, size_t n)
	{ 
		if (0 != n) Alloc::Deallocate(p, n * sizeof (T));
	}

	static void Deallocate(T *p)
	{ 
		Alloc::Deallocate(p, sizeof (T));
	}
};

void TestAlloc1()
{
	void* p1 = __DefaultAllocTemplate<false, 1>::Allocate(129);
	__DefaultAllocTemplate<false, 1>::Deallocate(p1, 129);

	void* p2 = __DefaultAllocTemplate<false, 1>::Allocate(5);
	__DefaultAllocTemplate<false, 1>::Deallocate(p2, 5);


	void* p3 = __DefaultAllocTemplate<false, 1>::Allocate(5);
	__DefaultAllocTemplate<false, 1>::Deallocate(p3, 5);
}

// ͨ��__TRACE_DEBUG ���׺в���

// �����ڴ�ص�һ������������������
void TestAlloc2 ()
{
	// ���Ե���һ�������������ڴ�
	cout<<" ���Ե���һ�������������ڴ� "<<endl ;
	char*p1 = SimpleAlloc<char, Alloc>::Allocate (129);
	SimpleAlloc<char , Alloc>:: Deallocate(p1 , 129);

	// ���Ե��ö��������������ڴ�
	cout<<" ���Ե��ö��������������ڴ� "<<endl ;
	char*p2 = SimpleAlloc< char, Alloc>::Allocate (128);
	char*p3 = SimpleAlloc< char, Alloc>::Allocate (128);
	char*p4 = SimpleAlloc< char, Alloc>::Allocate (128);
	char*p5 = SimpleAlloc< char, Alloc>::Allocate (128);
	SimpleAlloc<char , Alloc>:: Deallocate(p2 , 128);
	SimpleAlloc<char , Alloc>:: Deallocate(p3 , 128);
	SimpleAlloc<char , Alloc>:: Deallocate(p4 , 128);
	SimpleAlloc<char , Alloc>:: Deallocate(p5 , 128);

	for (int i = 0; i < 21; ++i )
	{
		printf(" ���Ե�%d�η��� \n", i +1);
		char*p = SimpleAlloc< char, Alloc>::Allocate (128);
	}
}

// ����ϵͳ���ڴ�ľ��ĳ���
void TestAlloc3 ()
{
	cout<<" ����ϵͳ���ڴ�ľ� "<<endl ;

	SimpleAlloc<char , Alloc>::Allocate (1024*1024*1024);
	//SimpleAlloc<char, Alloc>::Allocate(1024*1024*1024);
	SimpleAlloc<char , Alloc>::Allocate (1024*1024);

	// ���ò��ԣ�˵��ϵͳ����С���ڴ���������Ǻ�ǿ�ġ�
	for (int i = 0; i < 100000; ++i )
	{
		char*p1 = SimpleAlloc< char, Alloc>::Allocate (128);
	}
}

