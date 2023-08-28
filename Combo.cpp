#include <iostream>
#include "Estructuras.h"
// Métodos
	void Combo::imprimirCombo(){
		
		if(nombre_combo != ""){
			cout << "NOMBRE: " + nombre_combo << endl;
			cout << "PORCIONES: " + num_porciones << endl;
			cout << "COMPONENTES:" << endl;
		
			for (int i = 0; i < sizeCombo; i++){
				cout << componentes[i].retornarComponente() << endl;	
			}
			cout << "------------------------------------------" << endl;	
		}		
	}
