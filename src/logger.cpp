#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>
#include <cstring>

int main(){

	if(mkfifo("LoggerFIFO",0777)!=0){
	perror("ERROR MAKE LOGGER");
	return 1;
	}

	int fdLogger=open("LoggerFIFO",O_RDONLY);
	if(fdLogger==-1){
	perror("ERROR OPEN LOGGER");
	exit(1);
	}

	while(1){
		char cadFIFO[200];
		int n;
		n=read(fdLogger, cadFIFO, sizeof(cadFIFO));
		if(n==0) break;
		printf("%s\n",cadFIFO);	
	}
	
	close(fdLogger);
	unlink("LoggerFIFO");
	return 0;
}
