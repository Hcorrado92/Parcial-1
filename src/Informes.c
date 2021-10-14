/*
 * Informes.c
 *
 *  Created on: Oct 8, 2021
 *      Author: hernan.j.corrado
 */


#include "Informes.h"

void MostrarListaClientes(eCliente lista[], ePedido listaP[], int tam, int tamP, int estado)
{

	int i;
	int j;
	int contador;



	printf("Id\tCUIT\t\tDIRECCION\tLOCALIDAD\tPEDIDOS\n");
	for (i = 0; i < tam; i++)
	{

		if (lista[i].isEmpty == FULL)
		{ contador = 0;


		    printf("%d\t%d\t%10s\t%10s", lista[i].idCliente, lista[i].cuit,lista[i].calleEmpresa,lista[i].localidadEmpresa);

			for (j = 0; j < tamP; j++)
			{
				if (lista[i].idCliente == listaP[j].cliente)
				{

					if (listaP[j].estado == estado)
					{
						contador++;
					}

				}
			}

			printf("     %d \n", contador);

		}





	}
}

void InicializarListaProducto(eCliente lista[], int tam){


	for(int i = 0;i < tam; i++)
	    {
	        lista[i].isEmpty = EMPTY;
	    }
}


void VisualizarListaClientes(eCliente lista[], int tam)
{

	int i;
	printf("ID\tNOMBRE\t\tCUIT\t\tDIRECCION\tLOCALIDAD\n");
		for (i = 0; i<tam; i++)
		{
			if (lista[i].isEmpty == 1)
			{


				printf("%d\t%s\t%d\t\t%s\t%s\n", lista[i].idCliente, lista[i].nombreEmpresa,lista[i].cuit,lista[i].calleEmpresa,lista[i].localidadEmpresa);


			}

		}
}
void VisualizarListaPedidosPendientes(ePedido listaP[], int tamp){

	int i;
	printf("ID\tNCLIENTE\t\tKILOS\tLOCALIDAD\tESTADO\n");
			for (i = 0; i<tamp; i++)
			{
				if (listaP[i].estado == 1)
				{
	            printf("%d\t%d\t%d\t%s\t%d\n",listaP[i].idPedido, listaP[i].cliente, listaP[i].kilos, listaP[i].localidad, listaP[i].estado);


				}

			}

}

void VisualizarListaPedidosCompletados(ePedido listaP[], int tamp){

	int i;
	printf("ID\tNCLIENTE\t\tKILOS\tLOCALIDAD\tESTADO\n");
			for (i = 0; i<tamp; i++)
			{
				if (listaP[i].estado== 2)
				{
					printf("%d\t%d\t%d\t%s\t%d\n",listaP[i].idPedido, listaP[i].cliente, listaP[i].kilos, listaP[i].localidad, listaP[i].estado);

				}

			}

}

void ImprimirPedidosCompletados(eCliente lista[], ePedido listaP[], int tam, int tamp)
{
	int i;
	int j;
	int idCliente;
	int retorno;

	retorno = 0;

	for(i = 0; i < tamp; i++)
	{
		if (listaP[i].estado == 2 && listaP[i].isEmpty == 1)
		{

			idCliente = listaP[i].cliente;
            retorno = 1;
			printf ("IDPEDIDO   ");
			printf ("KILOS   ");
			printf("ID CLIENTE \n");
			printf("%d       ", listaP[i].idPedido);
			printf("%d       ", listaP[i].kilos);
			printf("%d        \n",listaP[i].cliente);

			for (j = 0; j < tam; j++)
			{
				if (idCliente == lista[j].idCliente)
				{

					printf("EMPRESA   ");
					printf("CALLE   ");
					printf("LOCALIDAD   \n");

					printf("%s   ",lista[j].nombreEmpresa);
					printf("%s   ", lista[j].calleEmpresa);
					printf("%s   ", lista[j].localidadEmpresa);
					break;
				}

			}
		}
		else
				{
			if (retorno == 0)
						{
					printf("No hay pedidos completados \n");
					break;
						}
				}
	}
}

void ImprimirPedidosPendientes(eCliente lista[], ePedido listaP[], int tam, int tamp)
{
	int i;
	int j;
	int idCliente;
    int retorno;

    retorno = 0;
	for(i = 0; i < tamp; i++)
	{
		if (listaP[i].estado == 1 && listaP[i].isEmpty == 1)
		{
			idCliente = listaP[i].cliente;
            retorno = 1;
			printf("%d   ", listaP[i].idPedido);
			printf("%d   ", listaP[i].kilos);
			printf("%d   \n",listaP[i].cliente);

			for (j = 0; j < tam; j++)
			{
				if (idCliente == lista[j].idCliente)
				{
					printf("%s   ",lista[j].nombreEmpresa);
					printf("%s   ", lista[j].localidadEmpresa);
					printf("%s   \n", lista[j].calleEmpresa);
					break;
				}

			}
		}
		else
		{
			if (retorno == 0)
			{
			printf("No hay pedidos pendientes \n");
			break;
			}
		}
	}
}
