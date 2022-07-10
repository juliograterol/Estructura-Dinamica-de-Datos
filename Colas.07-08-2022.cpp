#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ElementoLista {
    char *dato;
    struct ElementoLista *siguiente;
}Elemento;

typedef struct ListaUbicacion{
  Elemento *inicio;
  Elemento *fin;
  int tamanio;
} Cola;

void inicializacion_cola (Cola * serie){
  serie->inicio = NULL;
  serie->fin = NULL;
  serie->tamanio = 0;
}

int insertar_cola (Cola * serie, Elemento * actual, char *dato){
  
  Elemento *nuevo_elemento;
  
  if ((nuevo_elemento = (Elemento *) malloc (sizeof (Elemento))) == NULL)
        return -1;
  if ((nuevo_elemento->dato = (char *) malloc (50 * sizeof (char)))== NULL)
        return -1;
  
  strcpy (nuevo_elemento->dato, dato);

  if(actual == NULL)
  {
    if(serie->tamanio == 0)
    {
                
        serie->fin = nuevo_elemento;
        }
        nuevo_elemento->siguiente = serie->inicio;
        serie->inicio = nuevo_elemento;
  } 
  else 
  {
    if(actual->siguiente == NULL)
        serie->fin = nuevo_elemento;
        
        nuevo_elemento->siguiente = actual->siguiente;
        actual->siguiente = nuevo_elemento;
  }
  serie->tamanio++;
  return 0;
}

int quitar_cola (Cola * serie)
{
  Elemento *sup_elemento;
  
  if (serie->tamanio == 0)
    return -1;
  
  sup_elemento = serie->inicio;
  serie->inicio = serie->inicio->siguiente;
  
  free (sup_elemento->dato);
  free (sup_elemento);
  
  serie->tamanio--;
  return 0;
}

void imprimir_cola(Cola *serie){
  Elemento *actual;
  int i;
  actual = serie->inicio;

  for(i=0;i<serie->tamanio;++i){
    printf("%p - %s \n",actual, actual->dato);
    actual = actual->siguiente;
  }
}


int main()
{
        Cola *serie;
        inicializacion_cola(serie);
        
        insertar_cola (serie, serie->fin, "1");
        insertar_cola (serie, serie->fin, "2");
        insertar_cola (serie, serie->fin, "3");
        insertar_cola (serie, serie->fin, "4");
        insertar_cola (serie, serie->fin, "5");
        insertar_cola (serie, serie->fin, "6");
        insertar_cola (serie, serie->fin, "7");
        insertar_cola (serie, serie->fin, "8");
        insertar_cola (serie, serie->fin, "9");
        
        
        imprimir_cola(serie);
        

        printf("\n");
        
        quitar_cola(serie);
        quitar_cola(serie);
        quitar_cola(serie);
        quitar_cola(serie);
        
        imprimir_cola(serie);
        
        
        printf("\n");
        
        system("pause");
        
        return 0;
}
