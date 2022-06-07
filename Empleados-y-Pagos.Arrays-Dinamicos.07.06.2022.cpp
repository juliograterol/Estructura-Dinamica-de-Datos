#include<stdio.h>
#include<stdlib.h>

void pagoEmpleado();
void mostrarPagos();
void mejorPagado();
char nempresa[30];
int n, i, j, ax;
float *v, media;

int main (){
    
    pagoEmpleado();
	system("cls");
	mostrarPagos();
	mejorPagado();
    free(v);
    
    return 0;
}

void pagoEmpleado(){
	
	printf("Ingrese el nombre de la empresa: ");
	scanf("%s", &nempresa);
	printf("Ingrese el numero de empleados que trabajan en %s: ", nempresa);
	scanf("%d", &n);
		
    v = (float *) malloc (n* sizeof(float));

    for(i=0;i<n;i++){
        printf("Ingrese el sueldo del empleado #%d: ", i+1);
        scanf("%f", &v[i]);
        media = media + v[i];        
    }
}

void mostrarPagos(){
	
	media = media/n;
	printf("\t\t\t%s", nempresa);
	printf("\n\ Empleado\t|| Sueldo ($)\t|| Estado\n");
	for(i=0; i<n; i++){
		printf("\t #%d \t|| %f$\t|| ", i+1, v[i]);
		if(v[i]>media){
			printf("Encima de la Media\n");
		}
		else{
			printf("Debajo de la Media\n");
		}
	}
}

void mejorPagado(){
	
	printf("\nLa media de sueldo de todos los empleados es: %.2f", media);
    for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(v[j] > v[j+1]){
				ax = v[j];
				v[j] = v[j+1];
				v[j+1] = ax;
			}
		}
	}
	printf("\nEl sueldo mas bajo es de: %.2f%", v[0]);
	printf("\nEl sueldo mas alto es de: %.2f%", v[n-1]);
	
}
