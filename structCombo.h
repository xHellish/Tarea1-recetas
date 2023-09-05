#include "Declaraciones.h"

struct Combo{
	
	string nombre_combo;
	float num_porciones;
	Componente componentes[30];
	int sizeCombo = 0;
	
	// Default
	Combo(string nombre_combo = "", int num_porciones = 0, int sizeCombo = 0){	
	}
	
	// Constructor
	Combo(string _nombre_combo, int _num_porciones, Componente _componentes[30], int _sizeCombo){
		nombre_combo = _nombre_combo;
		num_porciones = _num_porciones;
		sizeCombo = _sizeCombo;
		
		for (int i = 0; i < 30; i++){
			componentes[i] = _componentes[i];
		}	
	}; 
	
	// --------------Métodos-------------
	void imprimirCombo(){
		
		if(nombre_combo != ""){
			cout << "NOMBRE: " + nombre_combo + ", para " + enteroStr(num_porciones) + " porciones." << endl;
			cout << "COMPONENTES: ";
		
			for (int i = 0; i <= sizeCombo; i++){
				cout <<componentes[i].retornarComponente() << endl;	
			}
			cout << "----------------------------------------" << endl;	
		}		
	}
	
	string comboVacio(){
		if(nombre_combo == ""){
			return "";
		}else{
			return nombre_combo;
		}
	}	
};
