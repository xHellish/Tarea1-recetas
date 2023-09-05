#include "structComponente.h"
#include "structCombo.h"
#include "structCombos.h"
#include "Declaraciones.h"

// Base de datos. //
Combo array_combos[100];

// --- Declaraciones --- //
Combo crearCombo();
void agregarCombo();
void buscarCombo();
void borrarCombo();
void imprimirTodosCombos(Combo array[]);
void modificarNombre();
void cambiarCantidadComponente();
void agregarComponente();
void calcularPorciones();

//------------------Funciones aux------------------- //

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

// --------------- Funciones principales ---------------- //

// Función 1: Agregar combo. Pide datos para crear el combo al array de combos.	
Combo crearCombo(){
	
	string combo_nom = "";
	string porciones_str = "";
	Componente combo_componentes[30];
	float porciones_int = 0;
	
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

// Función 2: Buscar combo por nombre. Si encuentra el nombre dado aplica el método imprimirCombo().
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

// Función 3: Borrar combo. Si encuentra el nombre del combo, borra ese índice del array de combos.
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
// Función 4: Imprime todos los combos del array de combos.
void imprimirTodosCombos(Combo array[]){
	
	for (int i = 0; i < 100; i++){
		array[i].imprimirCombo();
	};

	cout << endl;	
}

// Función 5: Modificar nombre de un combo.
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
					cout << "Combo ya existe, no se puede cambiar nombre. Intente de nuevo." << endl;
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

// Función 6: Modificar cantidad de un componente de un combo.
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
			cout << "Componente no existe." << endl;
			return;	
		}	
	}
	cout << "Combo no existe." << endl;
	return;	
}

// Función 7: Agregar componente a un combo.
void agregarComponente(){
	
	string nombreCombo;
	string nuevoComponente;
	string cantidadComp;
	
	cout << "Digite el nombre del combo: ";
	getline(cin, nombreCombo);
	
	for (int i = 0; i < 100; i++){
		if(array_combos[i].nombre_combo == nombreCombo){
			cout << "Digite el nombre del componente a agregar y su medida: ";
			getline(cin, nuevoComponente);
			
			for(int j = 0; j < 30; j++){
				if(array_combos[i].componentes[j].nombre_comp == nuevoComponente){
					cout << "Componente ya existe, intente de nuevo." << endl;
					return;
				}	
			}
			for(int j = 0; j < 30; j++){
				if(array_combos[i].componentes[j].nombre_comp == ""){
					cout << "Digite la cantidad: ";
					getline(cin, cantidadComp);
					
					array_combos[i].componentes[j].nombre_comp = nuevoComponente;
					array_combos[i].componentes[j].cantidad = convertir_Str_Int(cantidadComp);
					array_combos[i].sizeCombo += 1;
					
					cout << "Se agregó nuevo componente con éxito." << endl;
					return;	
				}
			}			
		}
	}
	cout << "Combo no existe.";
	return;	
}

// Función 8: Calcular para porciones.
void calcularPorciones(){
	
	string nombreCombo;
	string porcionesDadas;
	float cantidadNueva;
	
	cout << "Digite un combo existente: ";
	getline(cin, nombreCombo);
	
	for (int i = 0; i < 100; i++){
		if (array_combos[i].nombre_combo == nombreCombo){
			cout << "Indique las porciones a calcular: ";
			getline(cin, porcionesDadas);
			
			cout << "-----------------" << endl;
			cout << "Combo "+ nombreCombo + " para " + porcionesDadas + " porciones." << endl;
			cout << "COMPONENTES para " + porcionesDadas + " porciones: "<< endl;
			
			for (int j = 0; j < 30; j++){
				if (array_combos[i].componentes[j].nombre_comp != ""){
					
					cantidadNueva = (array_combos[i].componentes[j].cantidad * convertir_Str_Int(porcionesDadas))/array_combos[i].num_porciones;
					cout << array_combos[i].componentes[j].nombre_comp + " " << cantidadNueva << endl;	
				}		
			}
			return;	
		}	
	}
	cout << "Combo no existe." << endl;
	return;	
}

// Función menú que llama a las demás funciones.
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
			agregarComponente();
			
		}else if(opcion == "8"){
			calcularPorciones();
			
		}else if(opcion == "9"){
			return;	
		}
	}
}
