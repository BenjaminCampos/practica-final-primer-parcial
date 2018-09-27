#include<iostream>
#include<stdlib.h>

using namespace std;

struct Nodo{
	string nombreDelPro;
	string nom2;
	int costo;
	int saldo;
	float cobrar;
	float saldoAct;
	
	struct Nodo *siguiente;

}*inicio,*aux,*actual,*anterior;

void menu();
void insertarProductos(string,int);
void insertarSaldo(int);
void comprarProducto(string ,int,float,string);
void mostrarProductos();

int main(int argc, char** argv)
{
	inicio=NULL;
	//variables para dentro del main
	int opcion;
    string nom;//nombre del producto que se pasara 
    int precio;//se pasara a el nodo el precio que  tendra el producto
    int credit;//este sera el saldo con el que contamos actualmente que se pasara a la funcion 
    string date2;//nombre del producto a buscar
	float saldoEnd;//saldo que sera restado de nuestro credito 
	//
	system("color 0b");
	
	do{
	menu();

	cout<<"\n ingrese la opcion que requiera \n";
	
	cin>>opcion;
	switch(opcion)
	{
		case 1:{
			cout<<"\n ingrese productos \n";
			//ingreamos los productos dentro del main y los pasamos a la funcion
			cout<<"\n ingrese el nombre del producto \n";
			cin>>nom;
			cout<<"\n Ahora inserte el costo que tendra este producto \n ";
			cin>>precio;
			insertarProductos(nom,precio);
						
			break;
		}
		case 2:{
			system("pause");
			system("cls");
			
			cout<<"\n Antes de comprar un producto debera ingresar con cunato saldo cuenta \n";
			cout<<"\n introdusca su saldo actual \n";
			cin>>credit;
			insertarSaldo(credit);
			
			cout<<"\nproductos disponibles\n";
			mostrarProductos();
			cout<<"\n que producto desea comprar\n";
			cin>>date2;
			comprarProducto(date2,credit,saldoEnd,nom);
			
			break;
		}
		case 3:{
			mostrarProductos();
			break;
		}
	}
	
	
    }while(opcion<4);
	
	return 0;
}

 void menu(){
 	cout<<"\n BIENVENIDO A ESTA TIENDA QUE DESEA HACER \n";
 	cout<<"\n 1.- DAR DE ALTA PRODUCTOS \n";
 	cout<<"\n 2.- COMPRAR PRODUCTOS \n";
 	cout<<"\n 3.- MOSTRAR PRODUCTOS \n";
 	
 }
 
void insertarProductos(string nom,int precio){
 	
 	actual=inicio;
 	if(actual==NULL){
 		aux=new Nodo();
 		aux->nombreDelPro=nom;
 		aux->costo=precio;
 		aux->siguiente=NULL;
 		inicio=aux;
	 }else{
	 	while(actual->siguiente !=NULL)
	 	{
	 		actual=actual->siguiente;
		 }
		 aux=new Nodo();
		 aux->nombreDelPro=nom;
		 aux->costo=precio;
		 aux->siguiente=NULL;
		 actual->siguiente=NULL;
	 }
 	
 }
 
 void mostrarProductos(){
 		actual=inicio;
	cout<<"\t \t LISTA DE PRODUCTOS\n ";
	while(actual!=NULL){
		//cout<<" -> "<<actual->dato<<" ";
		cout<<"\t producto"<<"\t costo"<<"\n ";
		cout<<"\t "<<actual->nombreDelPro<<"\t \t"<<actual->costo<<"\n";
		actual=actual->siguiente;
	}
	cout<<"\n";
 }
 
 void insertarSaldo(int credit){
 	actual=inicio;
 	if(actual==NULL){
 		aux=new Nodo();
 		aux->saldo=credit;
 		aux->siguiente=NULL;
 		inicio=aux;
	 }else{
	 	while(actual->siguiente !=NULL)
	 	{
	 		actual=actual->siguiente;
		 }
		 aux=new Nodo();
         aux->saldo=credit;
		 aux->siguiente=NULL;
		 actual->siguiente=NULL;
	 }
	 cout<<"\n su saldo es de "<<aux->saldo<<"\n";		
 }
 
 void comprarProducto(string date2,int credit,float saldoEnd,string nom){
 	if(inicio!=NULL){
		aux=NULL;
		actual=inicio;
		while((actual!=NULL) && (actual->nombreDelPro!=nom)){
			aux=actual;
			actual=actual->siguiente;
		}
		if(actual==NULL){
			cout<<"no encontrado"<<endl;
		}else if(aux==NULL){
			inicio=inicio->siguiente;
			cout<<"\n producto encontrado\n";
	
			aux->nombreDelPro=date2;
			aux->saldoAct=credit-aux->costo;
			//delete actual;
		}else{
			aux->siguiente=actual->siguiente;
			aux->nombreDelPro=date2;
			aux->saldoAct=credit-aux->costo;
			//delete actual;
		}
	}
 }
