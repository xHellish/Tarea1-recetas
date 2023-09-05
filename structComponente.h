#include "Declaraciones.h"

struct Componente{
	
	string nombre_comp;
	int cantidad;
	
	// Constructor
	Componente(string _nombre_comp = "", int _cantidad = 0){
		nombre_comp = _nombre_comp;
		cantidad = _cantidad;	
	}
	
	// -----------------Métodos------------------
	string retornarComponente(){
		string _cantidad_str = enteroStr(cantidad);
		
		if (nombre_comp == ""){
			return "";
		}else{
			string compUnido = "- " + nombre_comp + " " + _cantidad_str + " ";
			return compUnido;	
		}		
	}	
};	
