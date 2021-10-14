/*
 * Pedidos.h
 *
 *  Created on: Oct 8, 2021
 *      Author: hernan.j.corrado
 */

#ifndef PEDIDOS_H_
#define PEDIDOS_H_

#define PENDIENTE 1
#define COMPLETADO 2


#include "Inputs.h"


typedef struct{

	int idPedido;
    int cliente;
	int kilos;
	int estado;
	int isEmpty;
	char localidad[50];

}ePedido;


void MostrarPedidos(ePedido lista[], int TAM);

ePedido IngresarPedido(int ID, char local[]);
int FiltrarPorLocalidad(ePedido listaP[], int tam);
void FiltrarPedidosLocalidad(ePedido listaP[], int tam);
int CargarPedido(ePedido listaP[], int tam, int ID, char localidad[]);
int GenerarIdPedido(int* ultimoPedido);
void InicializarListaPedido(ePedido listaP[], int tam);
int EncontrarPrimerEspacioLibreP (ePedido listaP[], int tam);
int BuscarPedido(char mensaje[]);
int VerificarExistenciaPedido(ePedido listaP[], int tam, int* pedido, int* ipedido);
int ProcesamientoDeResiduos(ePedido listaP[], int tam, int* acumC);
void MostrarPedidos2(ePedido listaP[], int tam);
int CallerI(int *iPedido);


#endif /* PEDIDOS_H_ */
