#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(){
	int size=10*1024*1024;
	int j;
	for (j=0;j<10;++j){
		void *ptr= malloc(size);
		memset(ptr,0,size);
		sleep(1);
	}

	return 0;
}
