#include <iostream>
#include <mutex>
using namespace std;

namespace LAZY//懒汉模式 需要的时候再定义
{
	//设计一个类为单例
	class Lock
	{
	public:
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
	};//设计RAII防止死锁
	class Singleton
	{
	public:
		static Singleton* GetInstance()
		{
			if (_inst == NULL)
			{
				lock_guard<mutex> lock(_mtx);
				if (_inst == NULL)
				{
					Singleton* tmp = new Singleton;
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

	private:
		Singleton()//构造析构都定义为私有，类外无法再定义对象
		{}
		~Singleton()
		{}

		//防拷贝
		Singleton(const Singleton&);
		Singleton& operator=(const Singleton&);

		static Singleton* _inst;
		static mutex _mtx;
	};

	Singleton* Singleton::_inst = NULL;
	mutex Singleton::_mtx;
}


#include <assert.h>
namespace HUNGRY
{
	class Singleton
	{
	public:
		static Singleton& GetInstance()
		{
			static Singleton inst;
			return inst;
		}
	protected:
		Singleton()
		{}
		Singleton(const Singleton&);
		Singleton& operator=(const Singleton&);
	};
}