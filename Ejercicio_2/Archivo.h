#ifndef ARCHIVO_H
#define ARCHIVO_H

#include <string>
#include <fstream>
#include <iostream>

class Archivo
{
	private:
		std::string nombre; 
		std::fstream flujo; 
		bool isFinLinea( const char );		
	public:
		explicit Archivo( std::string ); 
		~Archivo(); 
		std::string getNombre() const; 
		bool abrir(); 
		bool crear(); 
		std::string leerLinea(); 
		std::string leerLinea( const char );  
		std::string leerCampo( const char ); 
		std::string* leerCampos( const char, const unsigned int );
		template<class T> bool escribir( T&, bool finLinea = false );  
		bool isFinal() const; 
}; 

template<class T> bool Archivo::escribir( T& datos, bool finLinea )
{
	
	if( this->flujo.is_open() )
	{
		this->flujo << datos; 
		if( finLinea ) 
			this->flujo << std::endl; 
	}
	else 
		return false; 
		
	return true; 
} 
#endif
