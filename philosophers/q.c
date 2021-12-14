#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

void *t_function(void *data)
{
    pid_t pid;            // process id
    pthread_t tid;        // thread id

    pid = getpid();
    tid = pthread_self();

    char* thread_name = (char*)data;
    int i = 0;

    while (i<10)   // 0,1,2 까지만 loop 돌립니다.
    {
        // 넘겨받은 쓰레드 이름과
        // 현재 process id 와 thread id 를 함께 출력
        printf("[%s] pid:%u, tid:%x --- %d\n",
            thread_name, (unsigned int)pid, (unsigned int)tid, i);
        i++;
        sleep(1);  // 1초간 대기
    }
}

int main()
{
	pthread_t p_thread[2];
	int thr_id;
	int status;
	char p1[] = "thread_1";
	char p2[] = "thread_2";
	char pM[] = "thread_m";
	int i = 0;

	sleep(1);

	thr_id = pthread_create(&p_thread[0], NULL, t_function, (void *)p1);

	if (thr_id < 0)
	{
		perror("thread create error : ");
		exit(0);
	}

	// pthread_join(p_thread[0], (void **)&status);
	thr_id = pthread_create(&p_thread[1], NULL, t_function, (void *)p2);

	// pthread_join(p_thread[0], (void **)&status);
	if (thr_id < 0)
	{
		perror("thread create error : ");
		exit(0);
	}

//	pthread_join(p_thread[1], (void **)&status);
	
	pause();
	printf("언제 종료 될까요?\n");
	return (0);
}
