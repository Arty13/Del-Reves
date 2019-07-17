#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <sysexits.h>
#include "auxiliar.h"
#define MAXTAM 2048

void delreves(int argc, char *argv[]){
	int i,j;
	FILE *fichero;
	char inverso[MAXTAM];
	argv0="delreves";
	if((strcmp(argv[1],"-h") == 0) || (strcmp(argv[1],"--help") == 0)){
		printf("delreves: Uso: delreves [ fichero...]\n");
 		printf("delreves: Invierte el contenido de las lí­neas de los ficheros (o de la entrada) \n");
		exit(EX_OK);
	}
	for(i=1;i<argc;i++){
		fichero=fopen(argv[i],"r");
		if(fichero==NULL){
		Error(EX_NOINPUT,"El fichero \"%s\" no puede ser leido",argv[i]);
		exit(EX_NOINPUT);
		}else{
			while (fgets(inverso,MAXTAM,fichero)!='\0'){
				j=strlen(inverso);
				for(j=j-2; j>-1; j--){
					printf("%c",inverso[j]);
				}printf("\n");
			}
		}
		fclose(fichero);
	}	
}

int main(int argc, char *argv[]){
  	int i;
  	char inverso[MAXTAM];
	
	if (argc==1){
    	while(fgets(inverso,MAXTAM,stdin)!= NULL){
		for(i=strlen(inverso)-2; i>-1;i--){
         	printf("%c",inverso[i]);
       		}
	printf("\n");
    	}
exit(EX_OK);

} else {
	delreves(argc,argv);
	exit(EX_OK);
}

  return 0;
}
