#include <iostream>
#include "Estructuras.h"

// Funciones

void agregarCombo(){
	
	string combo_nom = "";
	int porciones = 0;
	Componente combo_componentes[30];
	
	cout << "* AGREGAR COMBO * \n\n Ingrese el nombre del combo: ";
	getline(cin, combo_nom);
	
	cout << "Digite la cantidad de porciones: ";
	cin >> porciones;
	cin.ignore();
	
	cout << "Digite sus componentes: ";
			
}

void imprimirTodosCombos(){
	
	for (int i = 0; i < 100; i++){
		cout <<  " -";
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
		
		int opcion;
        cout << "Digite la opción: ";
        cin >> opcion;
        cout << "" << endl;
        
        switch (opcion) {
            case 1:
                agregarCombo();
                break;
            case 2:
                // Lógica para buscar combo
                break;
            case 3:
                // Lógica para borrar combo
                break;
            case 4:
                imprimirTodosCombos();
                break;
            case 5:
                // Lógica para modificar nombre de un combo
                break;
            case 6:
                // Lógica para modificar cantidad de un componente de un combo
                break;
            case 7:
                // Lógica para agregar componente a un combo
                break;
            case 8:
                // Lógica para calcular para porciones
                break;
            case 9:
                cout << "Saliendo del programa..." << endl;
                return;
            default:
                cout << "Opción no válida. Por favor, seleccione una opción válida." << endl;
        }
			
	}
}
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	Menu();
	
	return 0;
}
