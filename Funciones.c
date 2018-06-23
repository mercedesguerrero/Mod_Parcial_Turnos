#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraylist.h"
#include "Funciones.h"

#define URGENTE 1
#define REGULAR 0


void mostrarMenu()
{
    system("cls");

    printf("\nRR EMERGENCIAS>>> Seleccione una opcion: \n\n");

    printf("1- TRAMITE URGENTE \n");
    printf("2- TRAMITE REGULAR\n");
    printf("3- PROXIMO CLIENTE\n");
    printf("4- LISTAR\n");
    printf("5- INFORMAR\n");
    printf("6- SALIR\n");

    printf("\nLa opcion es: ");
}

void presionarContinuar()
{
    printf("\nPresione cualquier tecla para continuar ");
    getch();
}

int getInt(char* mensaje)
{
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);

    return auxiliar;
}

int pedir_dni()
{
    int dni;

    dni= getInt("Ingrese dni: ");

    return dni;
}

Pacient* newPacient(int dni, int num_turno)
{
    Pacient* returnAux = NULL;
    Pacient* pPacient = malloc(sizeof(Pacient));

    if(pPacient != NULL)
    {
        pPacient->dni= dni;
        pPacient->turno_numero= num_turno;

        returnAux = pPacient;
    }

    return returnAux;
}

void printPacient(Pacient* p)
{
    printf("DNI: %d Tramite: %d\r\n", p->dni, p->status);
}



