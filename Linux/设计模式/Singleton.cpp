#include <iostream>
#include <mutex>
using namespace std;

#include <windows.h>

namespace LAZY
{

	class Lock
	{
	public:
		// RAII
		Lock(mutex& mtx)
			:_mtx(mtx)
		{
			_mtx.lock();
		}

		~Lock()
		{
			_mtx.unlock();
		}

	protected:
		Lock(const Lock&);
		Lock& operator=(const Lock&);

	private:
		mutex& _mtx;
	};

	// 设计一个类成为单例
	class Singleton
	{
	public:
		static Singleton* GetInstance()
		{
			// t1 t2

			// RAII
			if (_inst == NULL)
			{
				//Lock lock(_mtx);
				lock_guard<mutex> lock(_mtx);
				if (_inst == NULL)
				{
					// 1.operator new开空间
					// 2.构造函数
					// 3.赋值

					// 1.operator new开空间
					// 2.赋值
					// 3.构造函数
					//_inst = new Singleton;
					Singleton* tmp = new Singleton;
					MemoryBarrier();
					_inst = tmp;
				}

			}

			return _inst;
		}

		struct GC
		{
			~GC()
			{
				DelInstance();
			}
		};

		static void DelInstance()
		{
			lock_guard<mutex> lock(_mtx);
			if (_inst)
			{
				cout << "delete" << endl;
				delete _inst;
				_inst = NULL;
			}
		}

		void Print()
		{
			cout << "Singleton:" << _a << endl;
		}

	private:
		Singleton()
			:_a(0)
		{}

		~Singleton()
		{
			// 关闭数据库连接
		}

		// 防拷贝
		Singleton(const Singleton&);
		Singleton& operator=(const Singleton&);

		//threadPool pool;
		//memoryPool pool;
		int _a;


		static Singleton* _inst;
		static mutex _mtx;
	};

	Singleton* Singleton::_inst = NULL;
	mutex Singleton::_mtx;

	void Test()
	{
		Singleton::GetInstance()->Print();
		Singleton::GetInstance()->Print();
		Singleton::GetInstance()->Print();
		Singleton::GetInstance()->Print();
		Singleton::GetInstance()->Print();

		//atexit(Singleton::DelInstance);
	}

	static Singleton::GC gc;
}

// 1.懒汉模式 + lazy load + 相对而言 复杂--各种场景下都适用
// 2.饿汉模式 + 一开始(main) load  简洁 适用性会受到限制 动态库

#include <assert.h>

namespace HUNGRY
{
	//class Singleton
	//{
	//public:
	//	static Singleton& GetInstance()
	//	{
	//		assert(_inst);
	//		return *_inst;
	//	}

	//	void Print()
	//	{
	//		cout << "Singleton:" << _a << endl;
	//	}

	//protected:
	//	Singleton()
	//		:_a(0)
	//	{}
	//	Singleton(const Singleton&);
	//	Singleton& operator=(const Singleton&);

	//	static Singleton* _inst;
	//	int _a;
	//};

	//Singleton* Singleton::_inst = new Singleton;

	class Singleton
	{
	public:
		static Singleton& GetInstance()
		{
			static Singleton inst;
			return inst;
		}

		void Print()
		{
			cout << "Singleton:" << _a << endl;
		}

	protected:
		Singleton()
			:_a(0)
		{}
		Singleton(const Singleton&);
		Singleton& operator=(const Singleton&);

		int _a;
	};

	void Test()
	{
		Singleton::GetInstance().Print();
		Singleton::GetInstance().Print();
		Singleton::GetInstance().Print();
	}
}

int main()
{
	//HUNGRY::Test();
	LAZY::Test();
	getchar();
	//system("pause");

	return 0;
}