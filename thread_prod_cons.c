#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
int count=0;
int n=5;
void *producer(void *arg)
{  
	srand(2);
	while(1)
	{   
		
		while(count==n);
		sleep(rand() %3);
		printf("produced item :%d\n",count);
		count++;
	}
}
void *consumer(void *arg)
{   
	srand(1);
	while(1)
	{
		sleep(rand() %5);
     while(count==0);
     printf("consumed item:%d\n",count-1);
     count--;
	}
}
int main()
{
	pthread_t ptid,ctid;
	pthread_create(&ptid,NULL,producer,NULL);
	pthread_create(&ctid,NULL,consumer,NULL);
	pthread_exit(NULL);
	return 0;
}