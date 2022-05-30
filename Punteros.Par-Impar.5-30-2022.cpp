/*Ejercicio 1 . Comprobar si un numero es par o impar, y senialar la posicion de memoria  donde se esta guardando numero, Com punteros

*/

#include<stdio.h>
int main(){

    int    numero;
    int  *dirNumero;

    printf("Digita un nemro: \n");

    scanf("%d", &numero);  //Guardando en memoria

    dirNumero = &numero; //Posicion de la memoria donde fue guardada la variable

    if( *dirNumero %2 ==0 ){

        printf("El numero %d es par \n",  *dirNumero);
        printf("Posicion en  memoria es: %d ", dirNumero);

    }else{

        printf("El numero %d es Impar \n",  *dirNumero);
        printf("Posicion en  memoria es: %d ", dirNumero);

    }

    return 0 ;

}
