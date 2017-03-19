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
	int tam, tama, band=0;
	vector< char > almacen;
	Archivo *archi = new Archivo( "html.txt" );
	archi->abrir();
	while( !archi->isFinal() )
		{
			buffer = archi->leerCampo( '\n' );
			tam = strlen( buffer.c_str() );
			band=0;
			cout<<endl<<buffer<<endl;
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
						cout<<h<<endl;	
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
						cout<<"/"<<h<<endl;	
					}	
				}	
			}
			if( buffer[ tam - 1 ] == '#' )
			{
				//for(int i=0;i<almacen.size();i++)
				//cout<<almacen[i]<<" ";
				tama = almacen.size();
				if(tama % 2 == 0)
				{
					//if( strcmp(&almacen[0], &almacen[tama-1]) )
					if( almacen[0]== almacen[tama-1] )
					{
						for(int i=tama/2,j=i-1; i>0 && i<tama-1 && j>0 && j<tama-1;i++,j--)
						{
							if( almacen[i]== almacen[j] )
							{
								if(band==0)
								{
									cout<<almacen[0]<<" la que inicia es la que cierra "<<almacen[tama-1]<<endl;
									band=1;
								}
								
							}
								
						}
						
					}
				
						
					
				}
				
				almacen.clear();
			}
				
		}
	
	return 0;
}
