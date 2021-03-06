#include<stdio.h>
#include<signal.h>

void sig_handler(int signo){
	if (signo==SIGKILL) {
		printf("received SIGKILL\n");
	}
	
	if (signo==SIGSTOP) {
		printf("received SIGSTOP\n");
	}

	if (signo==SIGUSR1) {
		printf("received SIGUSR1\n");
	}
}


int main(void){
	int i=0;
	/*if (signal(SIGKILL, sig_handler)==SIG_ERR ){
		printf("\ncan't catch SIGKILL\n");
	}

	if ( signal(SIGSTOP, sig_handler)==SIG_ERR){
		printf("\ncan't catch SIGSTOP\n");
	}*/

	if (signal(SIGUSR1, sig_handler)==SIG_ERR){
		printf("\ncan't catch SIGUSR1\n");
	}
	while (i<100){
		sleep(1);
		i=i+1;
	}
	return 0;
}

