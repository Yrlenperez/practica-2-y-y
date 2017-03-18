#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include "Archivo.h"

using namespace std;

int main(int argc, char** argv) {
	string buffer;
	int tam;
	Archivo *archi = new Archivo( "html.txt" );
	archi->abrir();
	while( !archi->isFinal() )
		{
			buffer = archi->leerCampo( '\n' );
			tam = strlen( buffer.c_str() );
			cout << buffer << endl;
		}
	return 0;
}
