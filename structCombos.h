#include "Declaraciones.h"

struct Combos{
	Combo _combos[100];
	
	void imprimirCombos(int combos_size){
		for (int i = 0; i < combos_size; i++){
			_combos[i].imprimirCombo();
		}
	}
};
