#include "Archivo.h"

using namespace std; 
 
Archivo::Archivo( string n ) : nombre( n ) {}

Archivo::~Archivo()
{
	if( this->flujo.is_open() ) 
		this->flujo.close();   
} 

string Archivo::getNombre() const
{
	return this->nombre;  
} 

bool Archivo::abrir() 
{
	this->flujo.open( this->nombre.c_str(), fstream::in ); 
	return !this->flujo.fail(); 
} 

bool Archivo::crear()
{
	this->flujo.open( this->nombre.c_str(), fstream::out ); 
	return !this->flujo.fail();  
} 

string Archivo::leerLinea()
{
	string* linea = new string();  
	getline( this->flujo, *linea, '\n' );  
	return *linea;  
} 

 string Archivo::leerLinea( const char elim )
 {
	string* linea = new string();   
	string* buffer = new string();  
	
	while( !this->flujo.eof() && !this->isFinLinea( elim ) )  
	{
		getline( this->flujo, *buffer, elim );  
		*linea += *buffer; 
	} 
	if( !this->flujo.eof() )  
	{
		getline( this->flujo, *buffer, '\n' );  
		*linea += *buffer; 
	} 
	delete buffer; 
	return *linea; 
 } 
 
 string Archivo::leerCampo( const char delim )
 {
	string* campo = new string();   
	if( !this->flujo.eof() ) 
		if( this->isFinLinea( delim ) ) 
			getline( this->flujo, *campo, '\n' ); 
		else 
			getline( this->flujo, *campo, delim ); 
	return *campo;  
 } 
 
 string* Archivo::leerCampos( const char delim, const unsigned int num_campos )
 {
	string* campos = new string[num_campos]; 
	for( int campo = 0; campo < num_campos; campo++ )
		getline( this->flujo, campos[campo], 
			( campo == num_campos - 1 ? '\n' : delim ) ); 
	return campos; 
 }
 
bool Archivo::isFinLinea( const char delim )
{
	fstream flujoAux; 
	flujoAux.open( this->nombre.c_str(), fstream::in ); 
	flujoAux.seekg( this->flujo.tellg() );
	string* lectura = new string(); 
	getline( flujoAux, *lectura, delim ); 
	flujoAux.close();
	return ( lectura->find( '\n' ) == string::npos ? false : true );
} 

bool Archivo::isFinal() const
{
	return this->flujo.eof();
} 
