#include <queue>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
using namespace std;

int cal(int x, int y, int op);
typedef int (*HandlerTask_t)(int x,int y,int op);//定义一个函数指针

class Task
{
private:
	int _left;
	int _right;
	int _op;
	HandlerTask_t _handler;
public:
	Task(int left = 0, int right = 0, int op = 0) :_left(left), _right(right), _op(op)
	{
	}

	void Register(HandlerTask_t handler)
	{
		_handler = handler;
	}

	void Run()//任务执行
	{
		int ret = _handler(_left, _right, _op);
		const char* str = "+-*/";
		cout << "thread is [" << pthread_self() << _left << str[_op] << _right << "=" << ret << endl;

	}
	~Task()
	{

	}
};
class thread_pool
{
private:
	size_t thread_num;//记录当前有多少进程空闲
	queue<Task> thread_queue;
	pthread_cond_t cond;
	pthread_mutex_t mutex;
public:
	thread_pool(int num = 5): thread_num(num)
	{
		pthread_cond_init(&cond,nullptr);
		pthread_mutex_init(&mutex, nullptr);
	}
	~thread_pool()
	{
		pthread_cond_destroy(&cond);
		pthread_mutex_destroy(&mutex);
	}

	void Init_thread_pool()
	{
		pthread_t id;
		for(int i = 0; i < thread_num; i++)
		{
			pthread_create(&id, nullptr, Run_func, this);//注意把this作为变量传给Run_func，这里只做演示只写了一个运行的函数。
		}
	}

	void lock_queue()
	{
		pthread_mutex_lock(&mutex);
	}

	void unlock_queue()
	{
		pthread_mutex_unlock(&mutex);
	}

	bool Is_empty()
	{
		return thread_queue.size() == 0;
	}

	void thread_Idle()
	{
		thread_num++;
		pthread_cond_wait(&cond, &mutex);
		thread_num--;
	}
	void wake_thread()
	{
		pthread_cond_signal(&cond);
	}

	void pop_task(Task& t)
	{
		t = thread_queue.front();
		thread_queue.pop();
	}
	
	void push_task(const Task& t)
	{
		lock_queue();
		thread_queue.push(t);
		wake_thread();
		unlock_queue();
	}
		static void* Run_func(void* arg)
	{
		pthread_detach(pthread_self());
		thread_pool* pool = (thread_pool*) arg;
		while (1)
		{
			pool->thread_queue;
			while (pool->Is_empty())
			{
				pool->thread_Idle();//idle
			}
			Task it;
			pool->pop_task(it);
			pool->unlock_queue();
			it.Run();
		}


	}

};



int cal(int x, int y, int op)//模拟一个计算器
{
	int ret = -1;
	switch (op)
	{
	case 0:
		ret = x + y;
		break;
	case 1:
		ret = x - y;
		break;
	case 2:
		ret = x * y;
		break;
	case 3:
		ret = x / y;
		break;
	default:
		cout << "cal error!" << endl;
		break;
	}
}

int main()
{
	thread_pool tp;
	tp.Init_thread_pool();
	srand((unsigned long)time(NULL));
	for (;;) {
		int x = rand() % 100 + 1;
		int y = rand() % 100 + 1;
		int op = rand() % 4;
		Task t(x, y, op);
		t.Register(cal);
		tp.push_task(t);
		sleep(1);
	}
	return 0;
}
