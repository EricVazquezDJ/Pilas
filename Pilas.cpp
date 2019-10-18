#include <iostream>
#include <conio.h>

using namespace std;
struct PILA{ ///Pila de numeros enteros
  int valor; ///La pila guardar un solo dato entero
  PILA* abajo; /// Este nodo mantendra la referencia a el elemento que este abajo de el
};
PILA *pila=NULL; ///Se crea una pila
PILA *aux=NULL; ///pila para agregar nuevos elementos


void insertarDato(){
	int numero;
	cout<<"Ingrese un valor: ";
	cin>>numero;
	if (pila==NULL){
		pila= new PILA();
		pila->valor=numero;
		pila->abajo=NULL;
	}else{
		aux= new PILA();
		aux->valor=numero;
		aux->abajo=pila;
		pila=aux;
	}
}

void mostrarPila(){
	cout<<"El elemento superior de la pila es: "<<endl;
	if(pila==NULL){
		cout<<"No hay datos en la pila"<<endl;
	}else{
		cout<<pila->valor<<endl;
	}
}

void eliminar(){
	aux=pila;
 	pila=pila->abajo; 
  	delete aux;
}

void menu(){
    cout<<"\nMenú de opciones \n"<<endl;
    cout<<"1 Agregar valor \n"<<"2 Mostrar valor \n"<<"3 Eliminar valor \n"<<"4 Salir \n"<<endl;
    cout<<"Elige una opción del menú: \n"<<endl;
}

int main(){
	char *locale;
    locale=setlocale(LC_ALL,"");
	int opcion;
	int repetir=true;
	while(repetir){
		system("CLS");
		menu();
		cin>>opcion;
		if(opcion==1){
            system("CLS");
			insertarDato(); 
		}else if(opcion==2){
			system("CLS");
			mostrarPila();
			system("pause");
		}else if(opcion==3){
			system("CLS");
			eliminar();
			cout<<"\nDato eliminado\n"<<endl;
			system("pause");
		}else {
			break;
		}
	}
	return 0;
	getch();
}

