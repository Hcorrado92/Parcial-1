/*
 * Clientes.c
 *
 *  Created on: Oct 8, 2021
 *      Author: hernan.j.corrado
 */

#include "Clientes.h"

int id = 0;
int idElegido = 0;
int iCliente = 0;

int recicladoC = 0;

int acumuladorC = 0;



eCliente AltaCliente(){

    eCliente cliente;

    //PedirString(empleado.nombre , "Ingrese el nombre del empleado", 50);

	cliente.idCliente = GenerarId(&id);
	PedirString(cliente.nombreEmpresa ,  "Ingrese el nombre de la empresa \n", 50);
	cliente.cuit = PedirEntero("Ingrese el CUIT del cliente \n");
	PedirString(cliente.calleEmpresa ,  "Ingrese la direccion de la empresa \n", 50);
	PedirString(cliente.localidadEmpresa ,  "Ingrese la localidad de la empresa  \n", 50);
	cliente.pedido = 0;
    cliente.isEmpty = FULL;


	return cliente;
}

ePunteros Punteros()
{
     ePunteros puntero;

     puntero.iCliente = &iCliente;
     puntero.idCliente = &id;
     puntero.idElegido = &idElegido;

     return puntero;


}

int CallerID(int *idChecker)
{
    int id;

    id = *idChecker;

    return id;
}


int IdPass ()
{
	int id;
    int retorno;

    retorno = 0;


	id = CallerID(&id);

	if (id > 0)
	{
		retorno = id;
	}

	return retorno;
}

int CallerIdElegido(int *idElegido){

	int idElegid;

	idElegid = *idElegido;

	return idElegid;


}
int IdElegidoPass()
{
	int idElegido;
	int retorno;

	retorno = 0;

	idElegido = CallerIdElegido(&idElegido);

	if (idElegido > 0)
	{
		retorno = idElegido;
	}

	return retorno;
}


int CallerICliente(int *iDelClient){

	int iClient;

	iClient = *iDelClient;

	return iClient;
}
int IPass()
{
	int i;
	int retorno;

	i = CallerICliente(&iCliente);

	if (i >= 0)
	{
		retorno = i;
	}

	return retorno;
}

void Mostrar(eCliente lista[], int tam)
{
	int i;

	for (i = 0; i<tam; i++)
	{


		printf("%d", lista[i].idCliente);
		printf("%d", lista[i].isEmpty);
	}
}

int CargarCliente(eCliente lista[], int tam)
{
	int index = EncontrarPrimerEspacioLibre(lista, tam);
	   if(index != -1)
	   {
	      lista[index] = AltaCliente();
	   }
	return index;
}

int EncontrarPrimerEspacioLibre (eCliente lista[], int tam)
	{
	 int i;
	  int index;

	  index = -1;
	  for (i = 0; i < tam; i++)
	    {
	      if (lista[i].isEmpty == EMPTY)
		{
		  index = i;
		  break;
		}
	    }
	  return index;
	}


int GenerarId(int* ultimoID)
{

	int id;
	int idAuxiliar = *ultimoID;

	if (idAuxiliar > -1)
	{
		id =  *ultimoID+1;
	}

	*ultimoID = id;
	return id;
}



int BuscarCliente( char mensaje[])

{

	int idCliente;

	idCliente = PedirEntero(mensaje);


	return idCliente;

}



int VerificarCliente(eCliente lista[], int tam, int* iCliente, int* idElegido )
{

	int i;
	int idCliente = -1;
	int retorno;

	retorno = 0;
	idCliente = BuscarCliente(" \n Ingrese ID del cliente \n");

	 for (i = 0; i < tam; i++)
	   {

		   if (lista[i].idCliente == idCliente)
		   {
			   if (lista[i].isEmpty == FULL)
			   {
			   retorno = 1;
			   *iCliente = i;
			   *idElegido = idCliente;
			   break;
			   }
           }

	   }

   //printf("El retorno es  %d", retorno);
	 return retorno;

}

int IdChecker ( eCliente lista[], int tam)
{
	int i;
	int retorno;

	retorno = 0;
	for (i = 0; i< tam; i++)
	{
		if (lista[i].isEmpty == FULL)
		{
			retorno = 1;
			break;

		}
	}

	return retorno;

}


int PedidoIdChecker(ePedido listaP[], int tamp)
{


	int i;
	int retorno;


	retorno = 0;
		for (i = 0; i< tamp; i++)
		{
			if (listaP[i].isEmpty == 1)
			{
				retorno = 1;
				break;

			}
		}

		return retorno;


}

void MostrarCliente(eCliente lista[], int tam, int* idElegid, int* iClient)
	 {
	 	int validarExistencia;
	 	int id;



	 	validarExistencia = VerificarCliente(lista, tam, &iCliente, &idElegido);

	 	  while (validarExistencia == 0)
	 	   {
              printf("\n ID NO ENCONTRADO POR FAVOR INTRODUZCA UN ID NUEVO \n");

              validarExistencia = VerificarCliente(lista, tam, &iCliente, &idElegido);
	 	   }

	 	              id = *iClient;
	 	 	 		  printf("La direccion del cliente es %s      \n", lista[id].calleEmpresa);
	 	 	 		  printf("La localidad del cliente es %s       \n", lista[id].localidadEmpresa);
	 	 	 		  //printf("LA POSICION EN I ES %d  ", id);


	}

int ModificarDireccion(eCliente lista[], int tam, int* iClient)
{  MostrarCliente(lista, tam, &idElegido, &iCliente );
	int retorno = 0;
	int ids = *iClient;
	int nuevaDireccion;
	int nuevaLocalidad;
	//printf("%d ", iCliente);
	nuevaDireccion = PedirString(lista[ids].calleEmpresa ,  "Ingrese el NUEVO domicilio de la empresa \n", 50);
	nuevaLocalidad = PedirString(lista[ids].localidadEmpresa ,  "Ingrese la NUEVA localidad de la empresa \n", 50);

	if (nuevaDireccion == 1)
	{
		printf("Se ha modificado la nueva direccion \n");

		if ( nuevaLocalidad == 1)
		{   printf("Se ha modificado la nueva localidad \n");
			printf("%s   ",lista[ids].nombreEmpresa);
					printf("%d   ",lista[ids].cuit);
					printf("%s   ",lista[ids].calleEmpresa);
					printf("%s   ",lista[ids].localidadEmpresa);
					retorno = 1;

		}

	}


   return retorno;
}


int BorrarCliente (eCliente lista[], int tam, int* iClient)
{
	int validarExistencia;
	int retorno = 0;
	int respuesta;
	int id;

	validarExistencia = VerificarCliente(lista, tam, &iCliente, &idElegido);

	 while (validarExistencia == 0)
	 {
	    printf("\n ID NO ENCONTRADO POR FAVOR INTRODUZCA UN ID NUEVO \n");

	 validarExistencia = VerificarCliente(lista, tam, &iCliente, &idElegido);
	 }



	id = *iClient;




	respuesta = PedirEntero("Desea borrar al cliente? (1-Y /  0- N)");

	if (respuesta == 1)
	{
		lista[id].isEmpty = EMPTY;
		printf("Se ha borrado existosament el perfil del cliente  \n");

		retorno = 1;
	}
	//printf("ESTE ES EL RETORNO %d", retorno);
	return retorno;

}

int AgregarPedido(eCliente lista[], ePedido listaP[], int tam, int tamP, int* iClient, int* idElegid)
{

	setbuf (stdout, NULL);
	int iDelCliente;
	int pedido = 0;
	int validarExistencia;
	int idDelCliente;
	char localidad [50];

	validarExistencia = VerificarCliente(lista, tam, &iCliente, &idElegido);


	while (validarExistencia == 0)
		 {
           printf("\n ID NO ENCONTRADO POR FAVOR INTRODUZCA UN ID NUEVO \n");

		   validarExistencia = VerificarCliente(lista, tam, &iCliente, &idElegido);
	     }

	 iDelCliente = *iClient;
	 idDelCliente = *idElegid;

	 strcpy(localidad, lista[iDelCliente].localidadEmpresa);

     pedido = CargarPedido(listaP, tamP, idDelCliente, localidad);

     if (pedido != -1)

     {printf("\n EL ID DEL PEDIDO ES EL %d ", listaP[pedido].idPedido);
     printf("\n LA CANTIDAD DE KILOS ES DE %d ", listaP[pedido].kilos);
     printf("\n EL CLIENTE DEL PEDIDO ES %d \n ", listaP[pedido].cliente);
     printf("\n EL ESTADO DEL PEDIDO ES %d \n ", listaP[pedido].estado);
     }




	 return pedido;


}
int ContadorPendientes(eCliente lista[], ePedido listaP[], int tam, int tamP, int* iClient, int* idElegid)
{
	int i;
	int validarExistencia;
	//int idDelCliente;
	int iCliente;
	int retorno = 0;
	int contador = 0;

		validarExistencia = VerificarCliente(lista, tam, &iCliente, &idElegido);
		while (validarExistencia == 0)
			 {
	           printf("\nID NO ENCONTRADO POR FAVOR INTRODUZCA UN ID NUEVO \n");

			   validarExistencia = VerificarCliente(lista, tam, &iCliente, &idElegido);
		     }

	//idDelCliente = *idElegid;
	iCliente = *iClient;

	for (i = 0 ; i < tamP; i++)
	{
		if (lista[iCliente].idCliente == listaP[i].cliente)
		{
			if (listaP[i].estado == 1)
			{
				contador++;
                retorno = 1;

			}
					}
	}
	printf("\n EL CLIENTE TIENE PENDIENTE %d PEDIDOS \n", contador);

	return retorno;
}





int PromedioRecicladoC(int *clientes, int *cantidadkilos)
{
	int promedio;
    int cantidad = *cantidadkilos;
    int cantidadclientes = *clientes;

    printf("%d \n", cantidad);
    printf("%d \n", cantidadclientes);

	promedio = cantidad / cantidadclientes;

	return promedio;

}








void MostrarMenu(eCliente lista[], ePedido listaP[], int tam, int tamp)
{

    int respuesta;
    int auxiliar = 0;
    int auxiliar2 = 0;



	    do {
	    	        printf("1. Alta\n");
	    		    printf("2. Modificar Domicilio y Localidad del cliente \n");
	    		    printf("3. Borrar cliente \n");
	    		    printf("4. Agregar Pedido\n");
	    		    printf("5. Procesar Pedido \n");
	    		    printf("6. Clientes con pedidos pendientes \n");
	    		    printf("7. Pedidos pendientes \n");
	    		    printf("8. Pedidos completados \n");
	    		    printf("9. Pedidos por localidad \n");
	    		    printf("8. Promedio de Propileno por cliente \n");




	    	 respuesta = PedirEntero("Ingrese una opcion \n");


	    	 switch (respuesta)
	    	 {

	    	 case 1:

	    		 auxiliar = CargarCliente(lista,tam);
	    		 if (auxiliar >= 0){
	    			 printf("\n Se ingreso correctamente el cliente. \n");
	    		 }

	    	 break;
	    	 case 2:

	    		 VisualizarListaClientes(lista, tam);
	    		 auxiliar = IdChecker(lista, tam);
	    		 if (auxiliar == 0)
	    		 {
	    			 printf("No se registran IDs en el sistema \n");
	    		 }
	    		 else
	    		 {
	    		  ModificarDireccion(lista,tam,&iCliente);
	    		 }
	    		 //MostrarPedidos2(listaP,tamp);
	    		 //ModificarDireccion(lista,tam,&iCliente);
	    		 //MostrarListaClientes(lista,listaP,tam,tamp,1);
	    	 break;
	    	 case 3:
	    		 auxiliar = IdChecker(lista, tam);

	    		 	 if (auxiliar == 0)
	    		 	 {
	    		 	 printf("No se registran IDs en el sistema \n");
	    		 	 }
	    		 	 else {
	    		 		 VisualizarListaClientes(lista, tam);
	    		 		 BorrarCliente(lista,tam,&iCliente);
	    		 	 }
	    		 //FiltrarPorLocalidad(listaP,tamp);
	    		 //BorrarCliente(lista,tam, &iCliente);
	    		 //MostrarListaClientes(lista,listaP,tam,tamp,2);
	    	 break;
	    	 case 4:
	    		 auxiliar = IdChecker(lista, tam);
                           if (auxiliar == 0)
	    		 	  	 	 {
	    		 	  		 	 printf("No se registran IDs en el sistema \n");
	    	    		 	 }
                           else{
                        	   AgregarPedido(lista, listaP, tam ,tamp , &iCliente, &idElegido);
                           }

	    		 //BorrarCliente(lista,tam, &iCliente);
	         break;
	    	 case 5:
	    		           auxiliar = PedidoIdChecker(listaP, tamp);

	    		                if (auxiliar == 0)
	    		 	    		 {
	    		 	    		 printf("No se registran IDs en el sistema \n");
	    		 	    		 }
	    		 	    		else
	    		 	    		{VisualizarListaPedidosPendientes(listaP,tamp);
	    			    		 auxiliar2 = ProcesamientoDeResiduos(listaP, tamp, &recicladoC);

	    			    		 if (auxiliar2 == 1)
	    			    		 {
	    			    			 printf("Se ha procesado correctamente su pedido \n");
	    			    		 }

	    			    		 else {

	    			    			 printf("No se ha podido procesar su pedido \n");

	    			    		 }

	    		 	    		}


	    		 //ModificarDireccion(lista,tam,&iCliente);
	    	 break;
	    	 case 6:
	    		 auxiliar = IdChecker(lista, tam);
	    		 if (auxiliar == 0)
	    		 {
	    			 printf("No se registran IDs en el sistema \n");

	    		 }else
	    		 {
	    			 MostrarListaClientes(lista,listaP,tam,tamp,1);
	    		 }

	    	 break;
	    	 case 7:
	    		 auxiliar = PedidoIdChecker(listaP, tamp);
	    		 if (auxiliar == 0)
	    		 {
	    			 printf("No se registran IDs en el sistema \n");
	    		 }
	    		 else
	    		 {


	    		 ImprimirPedidosPendientes(lista,listaP,tam,tamp);

	    		 }
	    		 //MostrarListaClientes(lista,listaP,tam,tamp,2);
	    	 break;
	    	 case 8:

	    		 auxiliar = PedidoIdChecker(listaP, tamp);
	    			    		 if (auxiliar == 0)
	    			    		 {
	    			    			 printf("No se registran IDs en el sistema \n");
	    			    		 }
	    			    		 else
	    			    		 {

	    				    		 ImprimirPedidosCompletados(lista,listaP,tam,tamp);
	    			    		 }
	    	 break;

	    	 case 9:

	    		 auxiliar = PedidoIdChecker(listaP, tamp);
	    		 if (auxiliar == 0)
	    		 {
	    		 printf("No se registran IDs en el sistema \n");
	    		 }
	    				 else
	    		{
	    		 FiltrarPorLocalidad(listaP,tamp);

	    		}
	    		 break;

	    	 case 10:
	    		 auxiliar = PromedioRecicladoC(&id , &recicladoC);
	    		 if(auxiliar == 0)
	    		 {
	    			 printf("NO hay material procesado \n");
	    		 }
	    		 else {
	    			 printf("El promedio reciclado por cliente es %d \n", auxiliar);

	    		 }

	    	 }




	    }while (respuesta != 20);

	//MostrarCliente(lista, tam, &idElegido, &iCliente );
	//meter if en direccion con retorno 1 o 0
    //ModificarDireccion(lista,tam, &iCliente);
    //BorrarCliente(lista, tam, &iCliente);
    //Mostrar(lista, tam);


}

