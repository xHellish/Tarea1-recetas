#include <iostream>
#include <string>
#include "Prototipos.c"
using namespace std;

struct Componente{
	
	string nombre_comp;
	int cantidad;
	
	Componente(string _nombre_comp = "", int _cantidad = 0){
		
		nombre_comp = _nombre_comp;
		cantidad = _cantidad;
		
	}	
	
};

struct Combo{
	
	string nombre_combo;
	int num_porciones;
	Componente componentes[30];
	
	Combo(string _nombre_combo, int _num_porciones, Componente _componentes[30]){
		nombre_combo = _nombre_combo;
		num_porciones = _num_porciones;
		
		for (int i = 0; i < 30; i++){
			componentes[i] = _componentes[i];
		}	
	}; 
	
};


