/*
 * Clientes.h
 *
 *  Created on: Oct 8, 2021
 *      Author: hernan.j.corrado
 */

#ifndef CLIENTES_H_
#define CLIENTES_H_

#define FULL 1
#define EMPTY 0


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "Informes.h"
//#include "Union.h"
#include "Pedidos.h"

typedef struct {
    int IdCliente;
	char nombre[50];

}eLocalidad;

//Estructura donde vamos a guardar los datos del cliente
typedef struct  {

	int idCliente;
	char nombreEmpresa[100];
	int cuit;
	char calleEmpresa[100];
    int pedido;
	//int alturaEmpresa;
	char localidadEmpresa[50];
    int isEmpty;


} eCliente;


typedef struct {

	int* iCliente;
	int* idCliente;
	int* idElegido;
}ePunteros;


void InicializarListaProducto(eCliente lista[], int tam);
eCliente AltaCliente();
void Mostrar(eCliente lista[], int tam);
int GenerarId(int* ultimoID);
int EncontrarPrimerEspacioLibre (eCliente lista[], int tam);
int CargarCliente(eCliente lista[], int tam);
int BuscarCliente( char mensaje[]);
int VerificarCliente(eCliente lista[], int tam, int* iCliente, int* idElegido );
void MostrarCliente(eCliente lista[], int tam, int* idCliente, int* iC);
void MostrarMenu(eCliente lista[], ePedido listap[], int tam, int tamp);
void preguntaYN(char mensaje[]);
int ModificarCliente(eCliente lista[], int tam, int* iClient);
int BorrarCliente (eCliente lista[], int tam, int*iClient);
int AgregarPedido(eCliente lista[], ePedido listaP[], int tam, int tamP, int* iClient, int* idElegid);
void MostrarListaClientes(eCliente lista[], ePedido listaP[], int tam, int tamP, int estado);
int ContadorPentiende (eCliente lista[], ePedido listaP[], int tam, int tamP, int* iClient, int* idElegid);
void FiltrarLocalidad(eCliente lista[], ePedido listaP[], int tam, int tamP);
int PromedioRecicladoC(int *clientes, int *cantidadkilos);
void ImprimirPedidosPendientes(eCliente lista[], ePedido listaP[], int tam, int tamp);
void ImprimirPedidosCompletados(eCliente lista[], ePedido listaP[], int tam, int tamp);
int IdChecker ( eCliente lista[], int tam);
int CallerID(int *idChecker);
int IdPass();
int CallerIdElegido(int *idElegido);
int IdElegidoPass();
int CallerICliente(int *iDelClient);
int IPass();
int PedidoIdChecker(ePedido listaP[], int tamp);
int BuscarIdLocalidad(int* idUltimo);
void VisualizarListaClientes(eCliente lista[], int tam);
void VisualizarListaPedidosPendientes(ePedido listaP[], int tamp);
eLocalidad VerificarLocalidad(char local[], int *ID);
int BuscaClienteConMasPendientes (eCliente lista[], ePedido listaP, int tam, int tamP, int estado);
void ClienteConMasPendientes(eCliente lista[], ePedido listaP, int tam, int tamP, int estado, int* masP);


#endif /* CLIENTES_H_ */
