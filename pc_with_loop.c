
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
using namespace std;

#define NUM 8
class RingQueue
{
    private:
		vector<int> q;
        int cap;//容量
		sem_t data_sem;
		sem_t space_sem;
		int consume_step;
		int product_step;

    public:
		RingQueue(int _cap =NUM):cap(_cap)
    {
			sem_init(&data_sem, 0, 0);
			sem_init(&space_sem, 0, cap);
			consume_step = 0;
			product_step = 0;
    }
     ~RingQueue()
     {
		 sem_destroy(&data_sem);
		 sem_destroy(&space_sem);
    }
    
    void PutData(const int& data)
    {
		sem_wait(&space_sem);
		q[consume_step] = data;
		consume_step++;
		consume_step %= cap;
		sem_post(&data_sem);
    }

    void GetData(int & data)
    {
		sem_wait(&data_sem);
		data = q[product_step] ;
		product_step++;
		product_step %= cap;
		sem_post(&space_sem);
    
    }

};


void* producter(void* arg)
{
 int data;
 srand((unsigned long)time(NULL));
 for(;;)
 {  
	 RingQueue *bq = (RingQueue*) arg;
 data = rand()%1024;
     bq->PutData(data);
    cout<<"the data is push done :"<<data<<endl;
    sleep(1);
 }


}

void* consumer(void *arg)
{
	RingQueue *bq = (RingQueue*) arg;
 int data;
 for(;;)
 {  bq->GetData(data);
    cout<<"the data is pop done :"<<data<<endl;
    sleep(1);
 }

}



int main()
{
BlockQueue bd;
pthread_t c,p;
pthread_create(&c,NULL,consumer,(void*)&bd);//线程为可分离的
pthread_create(&p,NULL,producter,(void*)&bd);

pthread_join(c,NULL);
pthread_join(p,NULL);

}

