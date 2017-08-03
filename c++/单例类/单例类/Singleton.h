#include <iostream>
#include <mutex>
using namespace std;

namespace LAZY//����ģʽ ��Ҫ��ʱ���ٶ���
{
	//���һ����Ϊ����
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
	};//���RAII��ֹ����
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
		Singleton()//��������������Ϊ˽�У������޷��ٶ������
		{}
		~Singleton()
		{}

		//������
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