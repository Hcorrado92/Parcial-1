/*
 * Pedidos.c
 *
 *  Created on: Oct 8, 2021
 *      Author: hernan.j.corrado
 */

#include "Pedidos.h"



int iPedido = 0;
int idElegidoPedido = 0;
int idPedido = 0;
char localidad1[50];
int acumuladorDeC = 0;





int EncontrarPrimerEspacioLibreP (ePedido listaP[], int tam)
	{
	 int i;
	  int index;



	  index = -1;
	  for (i = 0; i < tam; i++)
	    {
	      if (listaP[i].isEmpty == 0)
		{
		  index = i;
		  break;
		}
	    }
	  return index;
	}

ePedido IngresarPedido(int ID, char local[])
{

	ePedido pedido;

	pedido.idPedido = GenerarIdPedido(&idPedido);
	pedido.kilos = PedirEntero(" \n Ingrese la cantidad de kilos del pedido: \n");
	pedido.cliente = ID;
	pedido.estado = PENDIENTE;
	strcpy(pedido.localidad, local);
	pedido.isEmpty = 1;



	return pedido;

}



int GenerarIdPedido(int* ultimoPedido)
{

	    int idPedido;
		int idAuxiliar = *ultimoPedido;

		if (idAuxiliar > -1)
		{
			idPedido =  *ultimoPedido+1;
		}

		*ultimoPedido = idPedido;


		return idPedido;
}

int CargarPedido(ePedido listaP[], int tam, int ID, char localidad[])
{

	int index = EncontrarPrimerEspacioLibreP(listaP, tam);

		   if(index != -1)
		   {
		      listaP[index] = IngresarPedido(ID, localidad);
		   }
		return index;
}

void MostrarPedidos2(ePedido listaP[], int tam)
{
	int i;

	for (i=0;i<tam;i++)
	{

		if (listaP[i].isEmpty == 1)
		{


		printf("%d     ", listaP[i].idPedido);
		printf("%d     ", listaP[i].cliente);
		printf("%d     ", listaP[i].kilos);
		printf("%d     ", listaP[i].estado);
		printf("%s     \n", listaP[i].localidad);

		}

	}


}

int BuscarPedido(char mensaje[])
{
	int idPedido;

		idPedido = PedirEntero(mensaje);


		return idPedido;

}

int VerificarExistenciaPedido(ePedido listaP[], int tam, int* pedido, int* ipedido)
{
	    int i;
		int idPedido = -1;
		int retorno;

		retorno = 0;
		idPedido = BuscarPedido(" \n Ingrese ID del pedido \n");

		 for (i = 0; i < tam; i++)
		   {

			   if (listaP[i].idPedido == idPedido && listaP[i].estado == PENDIENTE)
			   {
				   retorno = 1;
				   *ipedido = i;
				   *pedido = idPedido;
				   break;
	           }

		   }

	   //printf("El retorno es  %d", retorno);
		 return retorno;


}

int CallerI(int *iPedido)
{

	int iDelPedido;
	iDelPedido = *iPedido;

	return iDelPedido;
}


int ProcesamientoDeResiduos(ePedido listaP[], int tam, int* acumC)
{
	int retorno = 0 ;
	int pedido;
	int iDelPedido;
	int A;
	int B;
	int C;
	int acumulador = 0;
	int acumuladorC = *acumC;


	pedido = VerificarExistenciaPedido(listaP, tam, &idPedido, &iPedido);

	iDelPedido = CallerI(&iPedido);



	if (pedido == 1 )
	{

		do {
		acumulador = listaP[iDelPedido].kilos;

		printf("ESTE PEDIDO TIENE K %d   ", acumulador);

		printf("Cuantos kilos son del tipo A \n ");
		fflush(stdin);
		scanf("%d", &A);

		acumulador = acumulador - A;

		printf("Quedan %d Kilos restantes\n", acumulador);

		printf("Cuantos kilos son del tipo B \n ");
				fflush(stdin);
				scanf("%d", &B);

		acumulador = acumulador - B;

		printf("Quedan %d Kilos restantes \n", acumulador);
		printf("Cuantos kilos son del tipo C \n ");
				fflush(stdin);
				scanf("%d", &C);


	    acumulador = acumulador - C;
	    acumuladorC += C;
        *acumC = acumuladorC;

	    if (acumulador != 0)
	    {
	    	printf("ERROR - Resta inconrrecta, por favor vuelva a intentarlo \n");
	    }
	    retorno = 0;

		}while (acumulador != 0);


     listaP[iDelPedido].estado = COMPLETADO;

     retorno = 1;
	}

	return retorno;

}



int FiltrarPorLocalidad(ePedido listaP[], int tam)
{
	int i;
	int contador;
	char local[50];
	//int j;
	int validacion;

	PedirString(local, "Ingrese una localidad \n", 50);

	//printf("%s", local);
	contador = 0;



	for (i = 0; i<tam; i++)
	{
		if (listaP[i].isEmpty == 1 && listaP[i].estado == PENDIENTE)
		{


		validacion = strcmp(listaP[i].localidad, local);


		   if (validacion == 0)

		   {
			   contador++;
		   }

		}



	}


	printf("\n La cantidad de pedidos pendientas para %s es %d \n" , local, contador);
	return contador;

}

void FiltrarPedidosLocalidad(ePedido listaP[], int tam)
{
	int i;
	int cantidadLocalidad;
	int contador = 0;

	cantidadLocalidad = FiltrarPorLocalidad(listaP, tam);

	for (i = 0; i < cantidadLocalidad; i++)
	{
		if (listaP[i].estado == PENDIENTE)
		{
			contador++;
		}

	}
	printf("\n La cantidad de pedidos pendientes son %d \n", contador);
}

void InicializarListaPedido(ePedido listaP[], int tam){


	for(int i = 0;i < tam; i++)
	    {
	        listaP[i].isEmpty = 0;
	    }
}
