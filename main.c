#include <stdio.h>
#include <stdlib.h>
#include "arraylist.h"
#include "Funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;

    ArrayList* listaUrgentes= al_newArrayList();
    ArrayList* listaRegulares= al_newArrayList();
    ArrayList* listaAtendidos= al_newArrayList();
    ArrayList* listaRegularAtendidos= al_newArrayList();

    Pacient* nPacient;
    Pacient* aux;


    do
    {
        mostrarMenu();
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                //TRAMITE URGENTE
                nPacient = newPacientUrgente(pedir_dni(), num_turno);
                if(nPacient != NULL)
                {
                    num_turno++;
                    listaUrgentes->add(listaUrgentes,nPacient);
                }
                else
                {
                    printf("No se pudo cargar su tramite.");
                }
                getche();
                system("cls");
                presionarContinuar();
                break;
            case 2:
                //TRAMITE REGULAR
                nuevoTramite= tramite_turnoRegular(numTurno);

            if(nuevoTramite != NULL)
            {
                numTurno++;
                listaRegular->add(listaRegular,nuevoTramite);
            }
                else
                {
                    printf("No se pudo cargar su tramite.");
                }

                    getche();
                    system("cls");
                presionarContinuar();
                break;
            case 3:
                //PROXIMO CLIENTE
                 tramite_siguiente(listaUrgente,listaRegular,listaAtendido);
                getche();
                system("cls");
                presionarContinuar();
                break;
            case 4:
                //LISTAR
                 tramite_listarPendientes(listaUrgente,listaRegular);
                getche();
                system("cls");
                presionarContinuar();
                break;
            case 5:
                //INFORMAR
                al_sort(listaAtendido,tramite_ordenarDNI,0);

            printf("Tramites urgentes atendidos:\n");

                for(i=0; i<al_len(listaAtendido); i++)
                {
                    aux=(eTramite*)al_get(listaAtendido,i);
                    if(aux->idTramite==100)
                    {
                        printf("DNI:%ld\tTurno: %d\n",aux->dni,aux->turno);
                    }
                }
            printf("\nTramites regulares atendidos:\n");

                for(i=0; i<al_len(listaAtendido); i++)
                {
                    aux=(eTramite*)al_get(listaAtendido,i);
                    if(aux->idTramite==102)
                    {
                        printf("DNI:%ld\tTurno: %d\n",aux->dni,aux->turno);
                    }
                }
                getche();
                system("cls");
                presionarContinuar();
                break;
            case 6:
                seguir = 'n';
                break;
            case 7:
            clon=al_clone(listaAtendido);

            printf("Lista clonada\n");
                for(i=0; i<al_len(clon); i++)
                {
                    aux=(eTramite*)al_get(clon,i);
                    if(aux->idTramite==100)
                    {
                        printf("DNI:%ld\tTurno: %d\n",aux->dni,aux->turno);
                    }
                }
                printf("\n");

                getche();
                system("cls");
                break;
        case 8:

            clon=al_subList(listaAtendido,0,2);
            printf("Lista subLista");
            for(i=0; i<al_len(clon); i++)
            {
                aux=(eTramite*)al_get(clon,i);
                if(aux->idTramite==100)
                {
                    printf("DNI:%ld\tTurno: %d\n",aux->dni,aux->turno);
                }
            }
                printf("\n");
                getche();
                system("cls");
                break;

        case 9:
                nuevoTramite =(eTramite*) malloc(sizeof(eTramite));
                nuevoTramite->dni=10;
                nuevoTramite->idTramite=100;
                nuevoTramite->turno =58;
                if(al_set(listaAtendido,0,nuevoTramite))
                    {
                    printf("se seteo");
                    }
            break;
        case 10:
            printf("al_containsAll\n");

            if(!al_containsAll(listaAtendido,listaUrgente))
                printf("No lo contiene/n");
                else
                     printf("Lo contiene/n");

                    break;
        case 11:
            al_clear(listaAtendido);
            printf("clear");
                    break;
        case 12:
            printf("push\n");
             nuevoTramite =(eTramite*) malloc(sizeof(eTramite));
            nuevoTramite->dni=10;
            nuevoTramite->idTramite=100;
            nuevoTramite->turno =58;

            al_push(listaAtendido,0,nuevoTramite);
                    break;
        case 13:
            printf("Is empty");
            if(al_isEmpty(listaAtendido))
                printf("esta vacio");
                else if(al_isEmpty(listaRegular)==0)
                    printf("No esta vacio");
                    else
                        printf("null");
                    break;
        }

    }while(seguir=='s');


    return 0;
}
