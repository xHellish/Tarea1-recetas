#include "Estructuras.h"

// Base de datos.
Combo array_combos[100];

// -----------Funciones aux------------

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

// Funci�n 1: Agregar combo. Pide datos para crear el combo al array de combos.	
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
	
	cout << "Seleccione los componentes y su cantidad: " + porciones_str << endl;
	
	int sizeCont = 0;
	
	for (int i = 0; i <= 30; i++){
		
		if(i == 30){
			cout << "No se pueden agregar m�s componentes. (m�x 30) \n" << endl;
			break;
		}
		
		string _componente = "";
		string _cantidad = "0";
		
		cout << "COMPONENTE: ";
		getline(cin, _componente); 
		
		cout << "CANTIDAD: ";
		getline(cin, _cantidad);
		
		string _confirm = "";
		
		cout << "�Desea agregar otro componente? (y/n) ";
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

// Funci�n 2: Buscar combo por nombre. Si encuentra el nombre dado aplica el m�todo imprimirCombo().
void buscarCombo(){
	
	string nombreCombo;
	
	cout << "DIGITE EL NOMBRE DEL COMBO: ";
	getline(cin, nombreCombo);
	
	for (int i = 0; i < 100; i++){
		if (array_combos[i].nombre_combo == nombreCombo){
			array_combos[i].imprimirCombo();
			return;
		} 
	}
	cout << "\n NOMBRE NO EXISTE";		
}

// Funci�n 3: Borrar combo. Si encuentra el nombre del combo, borra ese �ndice del array de combos.
void borrarCombo(){
	
	string nombreCombo;
	
	cout << "Digite nombre del combo a borrar: ";
	getline(cin, nombreCombo);
	
	for (int i = 0; i < 100; i++){
		if (array_combos[i].nombre_combo == nombreCombo){
			for(; i < 99; i++){
				array_combos[i] = array_combos[i+1];		
			}
			cout << "Combo eliminado" << endl;
			return;
		}	
	}
	
	cout << "Ningun combo tiene ese nombre." << endl;
	
}
// Funci�n 4: Imprime todos los combos del array de combos.
void imprimirTodosCombos(Combo array[]){
	
	for (int i = 0; i < 100; i++){
		array[i].imprimirCombo();
	};

	cout << endl;	
}

// Funci�n 5: Modificar nombre de un combo.
void modificarNombre(){
	
	string nombreCombo;
	string nuevoNombre;
	cout << "Ingrese un combo existente: ";
	getline(cin, nombreCombo);
	
	for (int i = 0; i < 100; i++){
		if (array_combos[i].nombre_combo == nombreCombo){
			cout << "Digite nuevo nombre: ";
			getline(cin, nuevoNombre);
			
			for (; i < 100; i++){
				if (array_combos[i].nombre_combo == nuevoNombre){
					cout << "Combo ya existe, no se puede cambiar nombre. Intente de nuevo.";
					return;
				}
			}
			array_combos[i].nombre_combo = nuevoNombre;
			cout << "Nombre cambiado." << endl;
			return;		
		}
	}
	cout << "Combo no existe." << endl;
	return;
}

// Funci�n 6: Modificar cantidad de un componente de un combo.
void cambiarCantidadComponente(){
	
	string nombreCombo;
	string nombreComponente;
	string nuevaCantidad;
	
	cout << "Digite el nombre del combo: ";
	getline(cin, nombreCombo);
	
	for (int i = 0; i < 100; i++){
		if(array_combos[i].nombre_combo == nombreCombo){
			cout << "Digite el nombre del componente: ";
			getline(cin, nombreComponente);
			
			for (; i < 100; i++){
				for(int j = 0; j < 30; j++){
					if(array_combos[i].componentes[j].nombre_comp == nombreComponente){
						cout << "Ingrese nueva cantidad: ";
						getline(cin, nuevaCantidad);
						array_combos[i].componentes[j].cantidad = convertir_Str_Int(nuevaCantidad);
						cout << "Cambio de cantidad exitoso." << endl;
						return;
						
					}
				}
			}
			cout << "Componente no existe.";
			return;	
		}	
	}
	cout << "Combo no existe.";
	return;	
}

// Funci�n 7: Agregar componente a un combo.

// Funci�n 8: Calcular para porciones.

// Funci�n men� que llama a las dem�s funciones.
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
        cout << "Digite la opci�n: ";
        getline(cin, opcion);
        cout << "" << endl;
        
		if (opcion == "1"){
			agregarCombo();
			
		}else if(opcion == "2"){
			buscarCombo();
			
		}else if(opcion == "3"){
			borrarCombo();
			
		}else if(opcion == "4"){
			imprimirTodosCombos(array_combos);
			
		}else if(opcion == "5"){
			modificarNombre();
			
		}else if(opcion == "6"){
			cambiarCantidadComponente();
			
		}else if(opcion == "7"){
			
		}else if(opcion == "8"){
			
		}else if(opcion == "9"){
			return;	
		}
	}
}


int main(int argc, char** argv) {
	
	Menu();
	
	return 0;
}
