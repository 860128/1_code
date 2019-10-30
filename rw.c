//
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>
using namespace std;

volatile int ticket = 1000;
pthread_rwlock_t rwlock;

class ThreadAttr
{
	pthread_t tid;
	string id;
};

void* reader(void* arg)
{
	char* id = (char*)arg;
	while (1)
	{
		pthread_rwlock_rdlock(&rwlock);
		if (tiket <= 0)
		{
			pthread_rwlock_unlock(&rwlock);
			break;
		}
		printf("%s:%d\n", id, ticket);
		pthread_rwlock_unlock(&rwlock);
		sleep(1);
	}
	return nullptr;
}




void* writer(void* arg)
{
	char* id = (char*)arg;
	while (1)
	{
		pthread_rwlock_rdlock(&rwlock);
		if (tiket <= 0)
		{
			pthread_rwlock_unlock(&rwlock);
			break;
		}
		printf("%s:%d\n", id, --ticket);
		pthread_rwlock_unlock(&rwlock);
		sleep(1);
	}
	return nullptr;
}

string create_reader_id(std::size_t i)
{
	ostringstream oss("thread reader", ios_base::ate);
	oss << i;
	return oss.str();
}

string create_writer_id(std::size_t i)
{
	ostringstream oss("thread writer", ios_base::ate);
	oss << i;
	return oss.str();
}


void init_readers(vector<ThreadAttr>& vec)
{
	for (size_t i = 0; i < vec.size(); i++)
	{
		vec[i].id = create_read_id();

		pthread_create(&vec[i].tid, nullptr, read, (void*)vec[i].id.c_str());
	}
}

void init_writers(vector<ThreadAttr>& vec)
{
	for (size_t i = 0; i < vec.size(); i++)
	{
		vec[i].id = create_writer_id();

		pthread_create(&vec[i].tid, nullptr, writer, (void*)vec[i].id.c_str());
	}
}

void join_thread(vector<ThreadAttr> const& vec)
{
	for (vector<ThreadAttr>::const_reverse_iterator it = vec.rbegin(); it != vec.rend(); it++)
	{
		pthread const& tid = it->tid;
		pthead_join(tid, nullptr);
	}
}

void init_rwlock()
{
	//写优先
	pthread_rwlockattr_t attr;
	pthread_rwlockattr_init(&attr);
	pthread_rwlockattr_setkind_np(&attr, PTHREAD_RWLOCK_PREFER_WRITER_NP);//写者优先
	pthread_rwlock_init(&rwlock, &attr);
	pthread_rwlockattr_destroy(&attr);
	//读优先 pthread_rwlock_init(&rwlock, nullptr);
}


int main()
{
	const size_t reader_num = 1000;
	const size_t writer_num = 2;
	
	vector<ThreadAttr> reader(reader_num);
	vector<ThreadAttr> writer(writer_num);

	init_rwlock();

	init_readers(reader);
	init_readers(writer);

	join_threads(reader);
	join_threads(writer);

	pthread_rwlock_destroy(&rwlock);
}


