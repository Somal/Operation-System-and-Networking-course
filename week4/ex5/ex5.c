#include<stdio.h>
#include<signal.h>

void sig_handler(int signo){
	if (signo==SIGTERM) {
		printf("received SIGTERM\n");
	}
}


int main(void){
	int i=0;
	int pid=fork();
	if (pid==0){//child

		while(1){
			printf("I'm alive\n");
			sleep(0.01);
		}

	} else if (pid>0) {//parent 
		sleep(5);
		kill(pid,SIGTERM);
	}


/*	if (signal(SIGUSR1, sig_handler)==SIG_ERR){
		printf("\ncan't catch SIGUSR1\n");
	}*/

	return 0;
}

