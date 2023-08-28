#include <iostream>
#include <string>

//-----------Componentes----------------
struct Componente{
	
	string nombre_comp;
	int cantidad;
	string unidad_medida;
	
	// -------Constructores-----------
	Componente(){
		nombre_comp = "";
		cantidad = 0;
		unidad_medida = "";

	}
	Componente(string _nombre_comp , int _cantidad, string _unidad){
		nombre_comp = _nombre_comp;
		cantidad = _cantidad;
		unidad_medida = _unidad;
		
	}
};

//-----------Combo----------------
struct Combo{
	
	string nombre_combo;
	int num_porciones;
	Componente componentes[30];
	int sizeCombo;
	
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
	}
};


//-----------Base de datos de combos----------------
struct Combos{
	
	Combo _combos[100];
	
	void imprimirCombos(int combos_size){
		
		for (int i = 0; i < combos_size; i++){
			_combos[i].imprimirCombo();
		}
	}
};

