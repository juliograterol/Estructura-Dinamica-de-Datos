#include<iostream>
#include<conio.h>
#include<stdlib.h>

void notasEstudiantes();
void mostrarDatos();

int nestudiantes, *notas;

int main(){
	
	notasEstudiantes();
	system("cls");
	mostrarDatos();
	delete[] notas;

	return 0;
}

void notasEstudiantes(){
	
	printf("Digite el numero de estudiantes en una seccion: ");
	scanf("%d", &nestudiantes);
	
	notas = new int[nestudiantes];
	
	for(int i=0; i<nestudiantes; i++){
		printf("Ingrese la nota del estudiante #%d: ", i+1);
		scanf("%d", &notas[i]);
	}	
}

void mostrarDatos(){
		
	float promedio, promtotal;
	printf("\n\ Estudiante\t|| Nota || Estado\n");
	for(int i=0; i<nestudiantes; i++){
		printf("\t #%d \t|| %d\t|| ", i+1, notas[i]);
		if(notas[i]>=10){
			printf("Aprobado\n");
		}
		else{
			printf("Aplazado\n");
		}
		promedio = promedio + notas[i];
	}
	promtotal = promedio/nestudiantes;
	printf("\nEl promedio de la seccion es de: %.2f", promtotal);
}
