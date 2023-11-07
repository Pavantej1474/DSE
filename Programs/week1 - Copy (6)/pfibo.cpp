#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int fibnums[100];
void *fibonacci(void *arg)
{
	int n = *((int*)arg);
	int t1,t2;
	t1=0;
	t2=1;
	int count=2;
	fibnums[0]=0;
	fibnums[1]=1;
	
	for(int i=3;i<=n;++i)
	{
		int nextterm=t1+t2;
		fibnums[count++]=nextterm;
		t1=t2;
		t2=nextterm;
		
		
	}
	fibnums[count]=-1;
	
	return NULL;
	
}

int main()
{
	int n;
	printf("Enter the number\n");
	scanf("%d", &n);
	pthread_t thread;
	pthread_create(&thread,NULL,fibonacci,&n);
	pthread_join(thread, NULL);
	
	printf("The fibonacci sequence of %d numbers is : \n", n);
    	for (int i=0; fibnums[i]!=-1; ++i)	
    	{
    		printf("%d  ", fibnums[i]);
		}
	return 0;
    		
    		
  
}

