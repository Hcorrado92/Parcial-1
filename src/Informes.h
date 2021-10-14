/*
 * Informes.h
 *
 *  Created on: Oct 8, 2021
 *      Author: hernan.j.corrado
 */

#ifndef INFORMES_H_
#define INFORMES_H_


#include "Union.h"
//#include "Clientes.h"
#include "Pedidos.h"


void MostrarListaClientes(eCliente lista[], ePedido listaP[], int tam, int tamP, int estado);
void InicializarListaProducto(eCliente lista[], int tam);
void VisualizarListaClientes(eCliente lista[], int tam);
void VisualizarListaPedidosPendientes(ePedido listaP[], int tamp);
void VisualizarListaPedidosCompletados(ePedido listaP[], int tamp);
void ImprimirPedidosCompletados(eCliente lista[], ePedido listaP[], int tam, int tamp);
void ImprimirPedidosPendientes(eCliente lista[], ePedido listaP[], int tam, int tamp);



#endif /* INFORMES_H_ */
