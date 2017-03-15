//autor: yehimer urbina
//version: 0.1v
//estatus: asignacion de conteos sin finalizar
//bugs: sin determinar por el instante
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <cstdlib>
#include <string>
#include <stdio.h>
using namespace std;
//metodo de conteo 
int conteo(){
FILE *fl;
int rep=0 ,maria[rep] ,juan[rep] ,win=0 ,caso=0 ,resul=0;
char *x ,buffer[100];
fl=fopen("pares.txt" , "r+");
if(!fl)
	cout<<"oh no !"<<endl;
else
	while(!feof (fl)){
		if(!feof (fl)){
			//reinicio y alimentacion de variables 
			caso++;
			win=0;
			rep=0;
			//alimentando buffer
			fgets(buffer,100,fl);
			//obtencion de repeticiones
			rep = atoi(buffer);
			//re-alimentacion de buffer
			fgets(buffer,100,fl);
			//para solo tomar una jugada si rep==1
			if(rep == 1){
				//jugada maria
				maria[0] = atoi(buffer);
				//re-alimentando buffer
				fgets(buffer,100,fl);
				//jugada juan
				juan[0] = atoi(buffer);
				//comprobacion 
				resul = maria[0] + juan[0];
				if(resul % 2 != 0){
					win=1;
					cout<<"CASO #"<<caso<<":"<<win<<endl;
				}
				else
					cout<<"CASO #"<<caso<<":"<<win<<endl;
			}
			// de otro modo para multiples jugadas
			else
				//picando jugadas de maria
				x = strtok(buffer , " ");
				maria[0] = atoi(x);
				//i=1 por que ya se tomo la primera jugada
				for(int i=1 ; i <= rep ; i++){
					//comprobante de final de linea
					if(i == rep){
						x = strtok(NULL , "\n");
						maria[i] = atoi(x);
					}
					//de otro modo hasta encontrar fin de linea
					else
						x = strtok(NULL , " ");
						maria[i] = atoi(x);
				}
				
				
		}		
	}
}

int main(int argc, char** argv) {
	conteo();
	getch();
}
