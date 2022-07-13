#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;

typedef struct Nodo {
	char articulo[30];
	struct Nodo* siguiente;
} Nodo;

Nodo* CrearNodo(char *articulo){
	Nodo* nodo = (Nodo*) malloc (sizeof (Nodo));
	strncpy(nodo->articulo, articulo, 30);
	nodo->siguiente=NULL;
	return nodo;
}

typedef struct Lista {
	Nodo* articulo;
	int espacio;
}Lista;

struct Lista* CrearLista(){
	struct Lista* lista = (struct Lista*) malloc(sizeof(struct Lista));
	lista->articulo = NULL;
	lista->espacio = 0;
	return lista;
}

int espacio(Lista* lista) {
	return lista->espacio;
}

void Inicio(Lista* lista, char *articulo){
	Nodo* nodo = CrearNodo(articulo);
	nodo->siguiente = lista->articulo;
	lista->articulo = nodo;
	lista->espacio++;
	}
void Final(Lista* lista, char *articulo){
	Nodo*nodo = CrearNodo(articulo);
	if (lista->articulo == NULL) {
		lista->articulo = nodo;
	} else {
Nodo* puntero = lista->articulo;
	while (puntero->siguiente){
		puntero = puntero->siguiente;	
}
puntero->siguiente = nodo;
}
lista->espacio++;
}
void ElegirPosicion(int n, Lista* lista, char *articulo){
	n = n-1;
	Nodo* nodo = CrearNodo(articulo);
	if (lista->articulo == NULL) {
		lista->articulo == nodo;
	} else {
		Nodo* puntero = lista->articulo;
		int posicion = 0;
		while (posicion < n && puntero->siguiente){
			puntero = puntero->siguiente;
			posicion++;
		}
		nodo->siguiente = puntero->siguiente;
		puntero->siguiente = nodo;
	}
	lista->espacio++;
}

void limpiar(Nodo* nodo) {
	free(nodo);
}

void Eliminar(int n, Lista* lista){
	if (lista->articulo) {
		if (n == 0) {
			Nodo* eliminado = lista->articulo;
			lista->articulo = lista->articulo->siguiente;
			limpiar(eliminado);
			lista->espacio--;
			printf ("Se ha eliminado el articulo de la lista\n");
		} else if (n < lista->espacio) {
			Nodo* puntero = lista->articulo;
		int posicion = 0;
		while(posicion < (n - 1)) {
			puntero = puntero->siguiente;
			posicion++;
		}
		Nodo* eliminado = puntero->siguiente;
		puntero->siguiente = eliminado->siguiente;
		limpiar(eliminado);
		lista->espacio--;	
		printf ("Se ha eliminado el articulo de la lista\n");
		}else{
			printf("\nNo hay ningun articulo en esta posicion \n");
		}
	}
}

void MostrarLista(Lista* lista){
	
	Nodo* puntero = lista->articulo;
	int posicion = 0;
	printf("==================\n");
	printf(" Lista de Compras \n");
	printf("==================\n");
	while (puntero != NULL){
		printf(" %d. %s \n", posicion+1, &puntero->articulo);
		puntero = puntero->siguiente;
		posicion++;
	}
	printf("==================\n\n");
}

int main(){
	
	struct Lista* l = CrearLista();
	int opcion;
	int cantidad;
	do{
		printf("Cantidad de Articulos en la Lista (%d) \n", cantidad);
		printf("Escoja una opcion para llenar la lista de compras: \n");
		printf("1. Ingresar Articulo. \n");
		printf("2. Eliminar Articulo. \n");
		printf("3. Mostrar Lista. \n");
		printf("4. Salir. \n");
		printf("Opcion: ");
		scanf("%d", &opcion);
		printf("\n");
		
	switch(opcion){
	
		case 1:{
		opcion == 0;
		
		printf("	Agrege su articulo a la lista segun la prioridad de este: \n");
		printf("	1. Agregar a la lista. \n");
		printf("	2. Seleccionar posicion. \n");
		printf("	3. Agregar al final. \n");
		printf("	Opcion: ");
		scanf ("%d", &opcion);
		char articulo[30];
		printf("\n");
		printf("	Introduzca el articulo: ");
		scanf ("%s", &articulo);
		n == 0;
		
		switch(opcion){
			case 1:{
				n++;
				cantidad++;
				Inicio(l,articulo);
				printf("	Guardado en la posicion %d\n\n", n);
				break;
			}
			case 2:{
				n++;
				cantidad++;
				int nuevaposicion;
				printf("	Introduzca la posicion: ");
				scanf ("%d", &nuevaposicion);
				ElegirPosicion(nuevaposicion,l,articulo);
				printf("	Guardado en la posicion %d\n\n", nuevaposicion);
				break;
			}
			case 3:{
				cantidad++;
				Final(l,articulo);
				printf("	Guardado en la posicion %d\n\n", cantidad);
				n++;
				if(n==cantidad){
					n--;
				}
				break;
			}
			default:
			break;
		}
		break;
		}
		case 2:{
			opcion = 0;
			printf("	Introduzca el numero de la opcion a eliminar: ");
			scanf("%d", &n);
			Eliminar(n,l);
			n--;
			cantidad--;
			break;
		}
		case 3:{			
			MostrarLista(l);
			break;
		}
		case 4:{
			printf("El programa ha finalizado");
			break;
		}
		default:{
			printf("Ha ingresado una opcion invalidad \n");
			break;
		}	
	}
}while(opcion != 4);

	return 0;
}
