#include <iostream>
#include <string>
#include "Prototipos.c"
using namespace std;

// Funciones aux

string enteroStr(int entero) {
	    if (entero == 0) {
	        return "0";
	    }
	    
	    string cadena;
	    
	    while (entero > 0) {
	        int digito = entero % 10;
	        char caracterDigito = '0' + digito;
	        cadena = caracterDigito + cadena;
	        entero /= 10;
	    }
	    
	    return cadena;
}

// Estructuras

struct Componente{
	
	string nombre_comp;
	int cantidad;
	
	// Constructor
	Componente(string _nombre_comp = "", int _cantidad = 0){
		nombre_comp = _nombre_comp;
		cantidad = _cantidad;	
	}
	
	string retornarComponente(){
		string _cantidad_str = enteroStr(cantidad);
	
		return nombre_comp + " " + _cantidad_str;
	}	
};	

struct Combo{
	
	string nombre_combo;
	int num_porciones;
	Componente componentes[30];
	int sizeCombo = 0;
	
	// Constructor
	Combo(string _nombre_combo, int _num_porciones, Componente _componentes[30], int _sizeCombo){
		nombre_combo = _nombre_combo;
		num_porciones = _num_porciones;
		sizeCombo = _sizeCombo;
		
		for (int i = 0; i < 30; i++){
			componentes[i] = _componentes[i];
		}	
	}; 
	
	// Métodos
	void imprimirCombo(){
		cout << "NOMBRE: " + nombre_combo << endl;
		cout << "PORCIONES: " + num_porciones << endl;
		cout << "COMPONENTES: \n";
		
		for (int i = 0; i < sizeCombo; i++){
			cout << componentes[i].retornarComponente() << endl;	
		}	
	}	
};


