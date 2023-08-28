#include "Estructuras.h"

// Funciones aux
Combo array_combos[100];



// Función 1: Crear combo. Pide datos para agregar el combo al array de combos.	

Combo crearCombo(){
	
	string combo_nom = "";
	string porciones_str = "";
	Componente combo_componentes[30];
	int porciones_int = 0;
	
	cout << "Ingrese el nombre del combo: ";
	getline(cin, combo_nom);
	
	cout << "Digite las porciones: ";
	getline(cin, porciones_str);
	
	porciones_int = convertir_Str_Int(porciones_str);
	
	cout << "Seleccione los componentes y su cantidad: " << endl;
	
	int sizeCont = 0;
	
	for (int i = 0; i <= 30; i++){
		
		if(i == 30){
			cout << "No se pueden agregar más componentes. (máx 30) \n" << endl;
			break;
		}
		
		string _componente = "";
		string _cantidad = "0";
		
		cout << "COMPONENTE: ";
		getline(cin, _componente); 
		
		cout << "CANTIDAD: ";
		getline(cin, _cantidad);
		
		string _confirm = "";
		
		cout << "¿Desea agregar otro componente? (y/n) ";
		getline(cin, _confirm);
		
		int cantidad;
		cantidad = convertir_Str_Int(_cantidad);
		
		combo_componentes[i] = Componente(_componente, cantidad);
		
		if (_confirm != "y" and _confirm != "Y"){
			break;
		}
		
		sizeCont += 1;
				
	}
	
	Combo _combo = Combo(combo_nom, porciones_int, combo_componentes, sizeCont);
	
	return _combo;
						
}

void agregarCombo(){
	
	for (int i = 0; i < 100; i++){
		
		if(array_combos[i].comboVacio() == ""){
			Combo combo1 = crearCombo();
			array_combos[i] = combo1;
			break;	
		}else{
			continue;
		}
		
	}
		
}

// Función 4: Imprime todos los combos del array de combos.

void imprimirTodosCombos(Combo array[]){
	
	for (int i = 0; i < 100; i++){
		array[i].imprimirCombo();
	};
	
	cout << endl;
	
}

void Menu(){
	
	while (true){
		cout << "\n * MENU * \n" << endl;
		cout << "1. Agregar combo" << endl;
		cout << "2. Buscar combo" << endl;
		cout << "3. Borrar combo" << endl;
		cout << "4. Imprimir todos los combos" << endl;
		cout << "5. Modificar nombre de un combo" << endl;
		cout << "6. Modificar cantidad de un componente de un combo" << endl;
		cout << "7. Agregar componente a un combo" << endl;
		cout << "8. Calcular para porciones" << endl;
		cout << "9. Salir." << endl;
		cout << "" << endl;
		
		string opcion;
        cout << "Digite la opción: ";
        getline(cin, opcion);
        cout << "" << endl;
        
		if (opcion == "1"){
			//agregarCombo();
			
		}else if(opcion == "2"){
			
		}else if(opcion == "3"){
			
		}else if(opcion == "4"){
			//imprimirTodosCombos(array_combos);
			
		}else if(opcion == "5"){
			
		}else if(opcion == "6"){
			
		}else if(opcion == "7"){
			
		}else if(opcion == "8"){
			
		}else if(opcion == "9"){
			return;	
		}
	}
}

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	Menu();
	
	return 0;
}
