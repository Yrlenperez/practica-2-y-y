//autor: yehimer urbina & yrlen perez
//version: 0.4v
//estatus: problema con partidas multiples
//bugs: falla al comprobar multiples partidas simultaneamente
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
int rep=0 ,maria[20] ,juan[20] ,win=0 ,minwin=99,caso=0 ,resul=0;
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
				if(resul %2 != 0){
					win=1;
					cout<<"CASO #"<<caso<<": "<<win<<endl;
				}
				else
					cout<<"CASO #"<<caso<<": "<<win<<endl;
			}
			// de otro modo para multiples jugadas
			else{
				//picando jugadas de maria
				x = strtok(buffer , " ");
				maria[0] = atoi(x);
				//i=1 por que ya se tomo la primera jugada
				for(int i=1 ; i < rep ; i++){
					//comprobante de final de linea
					if(i == rep-1){
						x = strtok(NULL , "\n");
						maria[i] = atoi(x);
					}
					//de otro modo hasta encontrar fin de linea
					else{
						x = strtok(NULL , " ");
						maria[i] = atoi(x);
					}
				}	
					//re-alimentando buffer
					fgets(buffer,100,fl);
					//picando jugadas juan
					x = strtok(buffer , " ");
					juan[0] = atoi(x);
					//i=1 por que ya se tomo la primera jugada
				for(int i=1 ; i < rep ; i++){
					//comprobante de final de linea
					if(i == rep-1){
						x = strtok(NULL , "\n");
						juan[i] = atoi(x);
					}
					//de otro modo hasta encontrar fin de linea
					else{
						x = strtok(NULL , " ");
						juan[i] = atoi(x);
					}	
				}
			// inicio de suma definitiva
			for(int i=0 ; i < rep ; i++){
				
				for(int j=0 ; j < rep ; j++){
					resul = maria[i] + juan[j];
					// si gano maria 
					if(resul %2 !=0 )
						win++;
				}
				//verificasion de menor de veces ganado por maria
				if(minwin > win)
					minwin = win;
					win=0;
			}
			cout<<"CASO #"<<caso<<": "<<minwin<<endl;
			}
		}
	}
}
int main(int argc, char** argv) {
	conteo();
}
