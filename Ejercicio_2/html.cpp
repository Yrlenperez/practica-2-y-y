#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include "Archivo.h"
#include <stdio.h>
#include <ctype.h>
using namespace std;

int main(int argc, char** argv) {
	string buffer,copia;
	int tam;
	vector< char > almacen;
	Archivo *archi = new Archivo( "html.txt" );
	archi->abrir();
	while( !archi->isFinal() )
		{
			buffer = archi->leerCampo( '\n' );
			tam = strlen( buffer.c_str() );
			cout<<buffer<<endl;
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
				
		}
	for(int i=0;i<almacen.size();i++)
	cout<<almacen[i]<<" ";
	return 0;
}
