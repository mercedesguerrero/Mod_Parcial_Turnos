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
    printf("3- PROXIMO PACIENTE\n");
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

Pacient* newPacient()//CONSTRUCTOR
{
    Pacient* returnAux = NULL;

    Pacient* pPacient = (Pacient*)malloc(sizeof(Pacient));

    if(pPacient!=NULL)
    {
       returnAux = pPacient;
    }

    return returnAux;
}

Pacient* newPacientUrgente(int dni, int num_turno)
{
    Pacient* pPacient = newPacient();

    if(pPacient != NULL)
    {
        pPacient->dni= dni;
        pPacient->idTramite=100;
        pPacient->turno_numero= num_turno;

        printf("\nSe cargo tramite urgente\nTurno numero:%d\n\n", pPacient->turno_numero);
    }

    return pPacient;
}

Pacient* newPacientRegular(int dni, int num_turno)
{
    Pacient* pPacient = newPacient();

    if(pPacient != NULL)
    {
        pPacient->dni= dni;
        pPacient->turno_numero= num_turno;

        printf("\nSe cargo tramite regular\nTurno numero:%d\n\n", pPacient->turno_numero);
    }

    return pPacient;
}

void printPacient(Pacient* p)
{
    printf("DNI: %d Tramite: %d\r\n", p->dni, p->turno_numero);
}

void Pacient_siguiente(ArrayList* listaUrgentes, ArrayList* listaRegulares, ArrayList* listaAtendidos)
{
    Pacient* aux;
    Pacient* atendido;

    if(listaUrgentes->size!=0)
            {
                printf("Proximo paciente: \n");
                aux=(Pacient*)al_get(listaUrgentes,0);
                printf("Tramite urgente.\nTurno:%d \nDNI:%ld \n\n", aux->turno_numero, aux->dni);
                atendido=(Pacient*)al_pop(listaUrgentes,0);
                al_add(listaAtendidos,aux);
            }
            else if(listaRegulares->size!=0)
            {
                printf("Proximo paciente: \n");
                aux=(Pacient*)al_get(listaRegulares,0);
                printf("Tramite regular.\nTurno:%d \nDNI:%ld \n\n",aux->turno_numero,aux->dni);
                atendido=(Pacient*) al_pop(listaRegulares,0);
                al_add(listaAtendidos,atendido);
            }
            else
            {
                printf("\nYa no hay mas pacientes en espera.\n\n");
            }
}

void Pacient_listarPendientes(ArrayList* listaUrgentes, ArrayList* listaRegulares)
{
    Pacient* aux;
    int i;
    if(listaUrgentes->size!=0)
            {
                for(i=0;i<listaUrgentes->size;i++)
                {
                    aux=(Pacient*) al_get(listaUrgentes,i);
                    printf("Tramite urgente:\n");
                    printf("Turno: %d\n",aux->turno_numero);
                    printf("DNI: %ld\n\n",aux->dni);
                }
            }
            else
            {
                printf("No hay tramites urgentes pendientes.\n");
            }

            if(listaRegulares->size!=0)
            {
                for(i=0;i<listaRegulares->size;i++)
                {
                    aux=(Pacient*) al_get(listaRegulares,i);
                    printf("Tramite Regular:\n");
                    printf("Turno: %d\n",aux->turno_numero);
                    printf("DNI: %ld\n\n",aux->dni);
                }
            }
                else
                {
                    printf("No hay tramites regulares pendientes.\n");
                }
}
int Pacient_ordenarDNI(void* Pacient1, void* Pacient2)
{
    int returnAux;
    Pacient* PacientUno = (Pacient*) Pacient1;
    Pacient* PacientDos = (Pacient*) Pacient2;
        if(PacientUno->dni > PacientDos->dni)
        {
            returnAux =1;
        }
            else if( PacientUno->dni < PacientDos->dni)
            {
                returnAux =-1;
            }
                else
                {
                    returnAux = 0;
                }
    return returnAux;
}

