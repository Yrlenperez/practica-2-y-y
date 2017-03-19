#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include "Archivo.h"
#include <stdio.h>
#include <ctype.h>

using namespace std;

int main(int argc, char** argv) {
	string buffer, copia;
	int tam, tama, tama2, band=0, band1=0, cont=1, con =0, div;
	vector< char > almacen;
	Archivo *archi = new Archivo( "html.txt" );
	archi->abrir();
	while( !archi->isFinal() )
		{
			buffer = archi->leerCampo( '\n' );
			tam = strlen( buffer.c_str() );
			band = band1 = 0;
			//cout<<endl<<buffer<<endl;
			for( int i = 0; i < tam; i++ )
			{
				if( buffer[ i ] == '<' && buffer[ i+2 ] == '>' )
				{
					char* h = new char[ buffer.length() +1 ];
					copia=buffer[i+1];
					strcpy(h,copia.c_str());
					if(isupper(h[0]))
					{
						almacen.push_back(h[0]);
					//	cout<<h<<endl;	
					}	
				}
				else if( buffer[ i ] == '<' && buffer[ i+3 ] == '>' )
				{
					char* h = new char[ buffer.length() +1 ];
					copia = buffer[ i+2 ];
					strcpy( h, copia.c_str( ) );
					if( isupper( h[ 0 ] ) && buffer[ i+1 ] == '/' )
					{
						almacen.push_back(h[0]);
					//	cout<<"/"<<h<<endl;	
					}	
				}	
			}
			if( buffer[ tam - 1 ] == '#' )
			{
				tama = almacen.size();
				div=tama/2;
				if(tama % 2 == 0)
				{
					if( almacen[0] == almacen[tama-1] )
					{
						for(int i=tama/2,j=i-1; i>0 && 
						i<tama-1 && j>0 && j<tama-1;i++,j--)
						{
							if( almacen[i]== almacen[j] )
							{
								if(band==0)
								{
									cout<<"Caso #"<<cont
									<<": Codigo valido"<<endl;
									band=1;
								}	
							}		
						}	
					}
					else 
						{
							for(int i=tama/2,j=i-1; i>0 && 
							i<tama-1 && j>0 && j<tama-1;i++,j--)
							{
								if( almacen[i] != almacen[j] )
								{
									if( band1 == 0 )
									{
										cout<<"caso #"<<cont<<": Se esperaba </"<<almacen[j]
										<<"> pero se encontro </"<<almacen[i]<<">"<<endl;
										band1=1;
									}
								}
							}	
						}	
				}
				else if( almacen[0] != almacen[tama-1])
				{ 
				while(con<almacen.size() && con+1<almacen.size()){
					if(almacen[con]==almacen[con+1]){
						almacen.erase(almacen.begin()+con,almacen.begin()+con+2);
						if(con>=div)	{
					cout<<"Caso #"<<cont<<": Se esperaba </"
					<<almacen[0]<<"> pero se encontro #"<<endl;	
					}
					else if(con<=div){
					cout<<"Caso #"<<cont<<": Se esperaba #"
					<<" pero se encontro </"<<almacen[0]<<">"<<endl;		
					}
					}
					con++;
				}
				}
		
				almacen.clear();
			}
			cont++;	
		}
	return 0;
}
