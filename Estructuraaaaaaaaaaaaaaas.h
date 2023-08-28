#include <iostream>
#include <string>

using namespace std;

// --------Prototipos de función---------------
string enteroStr(int); 
int convertir_Str_Int(string);

struct Combo;



// ----------Estructuras---------------------

//-----------Componentes----------------
struct Componente{
	
	string nombre_comp;
	int cantidad;
	string unidad_medida;
	
	// -------Constructores-----------
	Componente(){
		nombre_comp = "";
		cantidad = 0;

	}
	Componente(string _nombre_comp , int _cantidad){
		nombre_comp = _nombre_comp;
		cantidad = _cantidad;

	}
	
	// ---------------Métodos--------------
	string retornarComponente(){
		string _cantidad_str = enteroStr(cantidad);
	
		return nombre_comp + " " + _cantidad_str;
	}	
};	

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
	
	//-----------Procedimientos------------
	
	void imprimirCombo();
	
	string comboVacio(){
		if(nombre_combo == ""){
			return "";
		}else{
			return nombre_combo;
		}
	}	
};


struct Combos{
	
	Combo _combos[100];
	
	void imprimirCombos(int combos_size){
		
		for (int i = 0; i < combos_size; i++){
			_combos[i].imprimirCombo();
		}
	}
};






// ------------Funciones aux----------------

//---------- INT to STR ------------
//Convierte un entero a string

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

//--------------STR to INT----------------
//Convierte de string a entero

int convertir_Str_Int(string num_str){
	
	int result = 0;
	size_t i = 0;
	
	for (; i < num_str.length(); ++i) {
        if (num_str[i] >= '0' && num_str[i] <= '9'){
        	result = result * 10 + (num_str[i] - '0');
        	
		}            
	}	
	return result;
}
