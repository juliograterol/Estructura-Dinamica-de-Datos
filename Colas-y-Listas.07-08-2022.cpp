#include <iostream>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
using namespace std;

class Nodo
{
    public:
        Nodo(int numero, Nodo *siguiente = NULL) 
        {
            this->numero = numero;
            this->siguiente = siguiente;
        }

    private:
        int numero;
        Nodo *siguiente;
        
    friend class Cola;
};

class Cola
{
    public:
        Cola() : ultimo(NULL), primero(NULL) {}

        ~Cola()
        {
            this->Vaciar();
        }
    
    void Meter(int numero){
        
		Nodo *nuevo;
    	nuevo = new Nodo(numero);
        if(!this->primero){
        	this->primero = nuevo;
		}
        else{
        	this->ultimo->siguiente = nuevo;
            this->ultimo = nuevo;
		}
    }

    int Sacar(){
        
		Nodo *nodo;
    	int numero;
		if(this->estaVacia()){
			return 0;
		}               

    	nodo = this->primero;
        this->primero = nodo->siguiente;
		numero = nodo->numero;    
        delete nodo;

        if(this->estaVacia()){
        	this->ultimo = NULL;
			return numero;
        }

    void Mostrar() {
        	
    	Nodo *nodo;
        nodo = this->primero;
    	while(nodo){
            printf(" %d", nodo->numero);
            nodo = nodo->siguiente;
        }
        if (this->estaVacia()){
            printf("Cola vacia...");
        }

    private:
        Nodo *primero;
        Nodo *ultimo;
};

void menu()
{
    cout << " IMPLEMENTACION DE COLAS EN C++" << endl;
    cout << " ==============================" << endl << endl;
    cout << " 1. METER" << endl;
    cout << " 2. SACAR" << endl;
    cout << " 3. MOSTRAR" << endl;
    cout << " 4. SALIR" << endl;

    cout << endl << "INGRESE OPCION: ";
}

int main() {

    Cola cola;
    int numero; 
    int opcion; 

    do
    {
        menu();  
        cin >> opcion;

        switch(opcion)
        {
            case 1:
                 cout << endl << "NUMERO A METER: "; cin >> numero;
                 cola.Meter(numero);
                 cout << endl << "Numero " << numero << " en cola..." << endl << endl;
            break; 

            case 2:
                 numero = cola.Sacar();
                 cout << endl << "Numero "<< numero <<" sacado..." << endl << endl;
            break; 

            case 3:
                 cout << endl << "MOSTRANDO COLA" << endl;
                 cola.Mostrar();
            break;  
         }

        cout << endl << endl;

    } while(opcion != 5);
    
    
    return 0;
}
