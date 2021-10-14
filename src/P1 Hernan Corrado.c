/*
 ============================================================================
 Name        : P1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>



#include "Informes.h"
#include "Pedidos.h"
//#include "Clientes.h"


#define TAM 100
#define TAMP 100





int main(void) {

     int i = 0;
     //int index = -1;


	setbuf (stdout, NULL);
	 eCliente ListaClientes [TAM]; //= {{1,"Hernan", 123, "Washington", 0, "Floresta", FULL} , {2,"Hernan", 123, "Wasasdhington127", 0, "Sarandi", FULL}};
     ePedido ListaPedidos [TAM];

	 InicializarListaProducto(ListaClientes, TAM);
	 InicializarListaPedido(ListaPedidos, TAMP);

	 ePunteros TraerPunteros();

	 for (i = 0; i <TAM; i++)
	 {

		MostrarMenu(ListaClientes, ListaPedidos, TAM, TAMP);
	 }


	 /*index = CargarCliente(ListaClientes, TAM);

	 if (index > -1)
	 {
		 printf("Se cargo correctamente \n");
		 printf("%d   ",L istaClientes[index].idCliente);

		 printf("%s   ",ListaCli ntes[index].nombreEmpresa);
		 printf("%d   ",ListaClientes[index].cuit);
		 printf("%s   ",ListaClientes[index].calleEmpresa);
		 printf("%s   ",ListaClientes[index].localidadEmpresa);
	 }*/

	  //Mostrar(ListaClientes, TAM);

	//return //EXIT_SUCCESS;
}

