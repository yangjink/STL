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

	// ���һ�����Ϊ����
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
					// 1.operator new���ռ�
					// 2.���캯��
					// 3.��ֵ

					// 1.operator new���ռ�
					// 2.��ֵ
					// 3.���캯��
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
			// �ر����ݿ�����
		}

		// ������
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

// 1.����ģʽ + lazy load + ��Զ��� ����--���ֳ����¶�����
// 2.����ģʽ + һ��ʼ(main) load  ��� �����Ի��ܵ����� ��̬��

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