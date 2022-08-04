#include <stdio.h>
#include <stdlib.h>

struct Nodo{
	int dato;
	Nodo *der;
	Nodo *izq;
};

Nodo *crearNodo(int);
void insertarNodo(Nodo *&,int);
void menu();
void mostrarArbol(Nodo *,int);
bool busqueda(Nodo *,int);
void search(Nodo *);
Nodo *arbol =NULL;


int main(){
	
	menu();
	
}

void menu(){
	int dato, opcion, contador=0;
	
	do{
		printf(" __  __  ___  __   _  _   _  \n");
		printf("|  \\/  || __]|  \\ | || | | | \n");
		printf("| |\\/| || __]| \\ \\| || |_| | \n");
		printf("|_|  |_||___]|_|\\___|\\_____/ \n");
		printf("\tARBOL BINARIO: \n\n");
		printf("1. Insertar un nuevo numero. \n2. Mostrar arbol completo. \n3. Recorrer el arbol. \n4. Salir.\n");
		printf(" Opcion: ");
		
		scanf("%d",&opcion);
		
		switch(opcion){
			case 1:
				printf(" Digite un numero: ");
					scanf("%d",&dato);
					insertarNodo(arbol,dato);
					printf("\n Numero insertado! ");
					break;
			case 2:{
				if(arbol==NULL){
					printf("\n No existe un arbol. Por favor, insertar algun numero primero.");
					printf("\n NOTA: Se recomienda insertar varios numeros para ver el arbol.");
				}
				else{
					printf("\n Mostrando el arbol: \n\n");
					mostrarArbol(arbol,contador);
				}
				printf("\n \n");
				break;
			}
			case 3:{
				printf("\n Recorriendo el arbol: \n ");
				search(arbol);
				printf("\n\n");
				break;
			}
			case 4:{
				system("cls");
				
				printf(" ___  _  __   _ \n");
				printf("| __]| ||  \\ | | \n");
				printf("| _] | || \\ \\| |\n");
				printf("|_|  |_||_|\\___| \n");
				printf("El programa ha finalizado... ");
				break;
			}
			default:{
				system("cls");
				printf(" ___  ____  ____  _____  ____ \n");
				printf("| __]| __ || __ ||  _  || __ | \n");
				printf("| __]|   \\ |   \\ | |_| ||   \\ \n");
				printf("|___]|_|\\_\\|_|\\_\\|_____||_|\\_\\ \n");
				printf("Haz escogido una opcion incorrecta. ");
				break;
			}
		}
		system("pause");
		system("cls");
	}while(opcion != 4);
}

 Nodo *crearNodo(int n){
	Nodo *nuevo_nodo = new Nodo();
		
	nuevo_nodo->dato =n;
	nuevo_nodo->der = NULL;
	nuevo_nodo->izq = NULL;	
		
		return nuevo_nodo;
}

void insertarNodo(Nodo *&arbol,int n){
	if(arbol==NULL){
		struct Nodo *nuevo_nodo = crearNodo(n);
		arbol=nuevo_nodo;
	}
	else{
	int valorRaiz = arbol ->dato;
	if(n<valorRaiz){
		insertarNodo(arbol->izq,n);
	}
	else{
	insertarNodo(arbol->der,n);
	}
	
	}
}

void mostrarArbol(Nodo *arbol,int contador){
	if(arbol==NULL){
		return;
		
	}
	else{
		mostrarArbol(arbol ->der,contador+1);
		for(int i=0;i<contador;i++){
			printf("   ");
		}
		printf("(%d)<\n",arbol->dato);
		mostrarArbol(arbol->izq,contador+1);
	}
}

bool busqueda(Nodo *arbol, int n){
	if(arbol==NULL){
		return false;
	}
	else if(arbol->dato==n){
		return true;
	}
	else if(n , arbol->dato){
		return busqueda(arbol->izq,n);
	}
	else{
		return busqueda(arbol->der,n);
	}
}

void search(Nodo *arbol){
	if(arbol == NULL){
		return;
	}
	else{
		printf("(%d)-", arbol->dato);
		search(arbol->izq);
		search(arbol->der);
	}
}
