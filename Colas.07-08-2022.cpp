#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;

typedef struct Nodo {
	int cliente_pago;
	struct Nodo* siguiente;
} Nodo;

Nodo* CrearNodo(int *cliente_pago){
	Nodo* nodo = (Nodo*) malloc (sizeof (Nodo));
	nodo->cliente_pago=NULL;
	nodo->siguiente=NULL;
	return nodo;
}

typedef struct Cola {
	Nodo* cliente_pago;
	int espacio;
}Cola;

struct Cola* CrearCola(){
	struct Cola* Cola = (struct Cola*) malloc(sizeof(struct Cola));
	Cola->cliente_pago = NULL;
	Cola->espacio = 0;
	return Cola;
}

int espacio(Cola* Cola) {
	return Cola->espacio;
}

void LlegaCliente(Cola* Cola, int *cliente_pago){
	Nodo* nodo = CrearNodo(cliente_pago);
	nodo->siguiente = Cola->cliente_pago;
	Cola->cliente_pago = nodo;
	Cola->espacio++;
	}

void limpiar(Nodo* nodo) {
	free(nodo);
}

void SacarCliente(int n, Cola* Cola){
	if (Cola->cliente_pago) {
		if (n == 0) {
			Nodo* eliminado = Cola->cliente_pago;
			Cola->cliente_pago = Cola->cliente_pago->siguiente;
			limpiar(eliminado);
			Cola->espacio--;
		}
		else if (n < Cola->espacio){
			Nodo* puntero = Cola->cliente_pago;
		int posicion;
		while(posicion < (n - 1)) {
			puntero = puntero->siguiente;
			posicion++;
		}
		Nodo* eliminado = puntero->siguiente;
		puntero->siguiente = eliminado->siguiente;
		limpiar(eliminado);
		Cola->espacio--;
		}
	}
}



int main(){
	
	struct Cola* l = CrearCola();
	int opcion;
	int cantidad;
	do{
		printf("Cantidad de clientes en la Cola (%d) \n", cantidad);
		printf("Siendo el cajero en una tienda, llega un cliente a pagar por sus productos: \n");
		printf("1. Ingresar Cliente. \n");
		printf("2. Sacar Cliente. \n");
		printf("3. Sacar a todos los clientes. \n");
		printf("4. Salir. \n");
		printf("Opcion: ");
		scanf("%d", &opcion);
		printf("\n");
		n == 0;
		
	switch(opcion){
	
		case 1:{
			int *cliente_pago;
			printf("	Introduzca el monto del pago del cliente #%d: ", cantidad+1);
			scanf ("%s", &cliente_pago);
			opcion == 0;
			n++;
			cantidad++;
			LlegaCliente(l,cliente_pago);
			printf("	Cliente y su pago han ingresado en la cola.\n");
		break;
		}
		
		case 2:{
			opcion = 0;
			if(cantidad==0){
				printf("	No queda ningun cliente por pagar en la cola.\n");
			}
			else{
				SacarCliente(1,l);
				n--;
				cantidad--;
				printf("	El Cliente ha pagado y se ha retirado de la cola.\n");
			}
			break;
		}
		case 3:{
			opcion = 0;
			int cant = 0;
			do{
				if(cantidad==0){
					printf("	No queda ningun cliente por pagar en la cola.\n");
				}
				else{
					SacarCliente(1,l);
					cant++;
					n--;
					cantidad--;
					printf("	El Cliente #%d ha pagado y se ha retirado de la cola.\n", cant);
				}
			}while(cantidad>0);
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
	printf("\n");
}while(opcion != 4);

	return 0;
}
