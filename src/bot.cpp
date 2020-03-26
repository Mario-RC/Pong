#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include "DatosMemCompartida.h"
#include <sys/types.h>
#include <ctype.h>
#include <cstring>

int main(){

	DatosMemCompartida *memcomp;

	int fdBot=open("BotFIFO",O_RDWR);
	if(fdBot==-1){
	perror("ERROR OPEN BOT");
	exit(1);
	}

	memcomp=(DatosMemCompartida*) mmap(NULL, sizeof(DatosMemCompartida), PROT_READ|PROT_WRITE, MAP_SHARED, fdBot, 0);

	while(1)
	{	//Movimiento raqueta 1
		if(memcomp->esfera2.centro.x==0){
			if(memcomp->raqueta1.y1 < memcomp->esfera.centro.y)memcomp->accion=1;
			else if(memcomp->raqueta1.y2 > memcomp->esfera.centro.y)memcomp->accion=-1;
		}
		else if(memcomp->esfera.centro.x < memcomp->esfera2.centro.x){
			if(memcomp->raqueta1.y1 < memcomp->esfera.centro.y)memcomp->accion=1;
			else if(memcomp->raqueta1.y2 > memcomp->esfera.centro.y)memcomp->accion=-1;
		}
		else if(memcomp->esfera.centro.x > memcomp->esfera2.centro.x){
			if(memcomp->raqueta1.y1 < memcomp->esfera2.centro.y)memcomp->accion=1;
			else if(memcomp->raqueta1.y2 > memcomp->esfera2.centro.y)memcomp->accion=-1;
		}

		//Movimiento raqueta 2
		if((memcomp->esfera2.centro.x==0)&&(memcomp->tiempo_bot>=10.0f)){
			if(memcomp->raqueta2.y1 < memcomp->esfera.centro.y)memcomp->accion=2;
			else if(memcomp->raqueta2.y2 > memcomp->esfera.centro.y)memcomp->accion=-2;
		}
		else if((memcomp->esfera.centro.x > memcomp->esfera2.centro.x)&&(memcomp->tiempo_bot>=10.0f)){
			if(memcomp->raqueta2.y1 < memcomp->esfera.centro.y) memcomp->accion=2;
			else if(memcomp->raqueta2.y2 > memcomp->esfera.centro.y) memcomp->accion=-2;
		}
		else if((memcomp->esfera.centro.x < memcomp->esfera2.centro.x)&&(memcomp->tiempo_bot>=10.0f)){
			if(memcomp->raqueta2.y1 < memcomp->esfera2.centro.y) memcomp->accion=2;
			else if(memcomp->raqueta2.y2 > memcomp->esfera2.centro.y) memcomp->accion=-2;
		}

		//Disparo 1
		if(((memcomp->raqueta1.y1 + memcomp->raqueta1.y2)/2) == ((memcomp->raqueta2.y1 + memcomp->raqueta2.y2)/2)&&(memcomp->disparo1.posicion.x > memcomp->raqueta2.x2)) memcomp->accion=3;

		//Disparo 2
		if(((memcomp->raqueta1.y2 + memcomp->raqueta2.y2)/2) == ((memcomp->raqueta1.y1 + memcomp->raqueta1.y2)/2)&&(memcomp->disparo2.posicion.x < memcomp->raqueta1.x1)&&(memcomp->tiempo_bot>=10.0f)) memcomp->accion=-3;

		usleep(25000);

		if(memcomp->fin_bot == 1) break;
	}

	close(fdBot);
	unlink("BotFIFO");
	munmap(memcomp,sizeof(DatosMemCompartida));
	return 0;
}	
