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
    ArrayList* listaUrgenteAtendidos= al_newArrayList();
    ArrayList* listaRegularAtendidos= al_newArrayList();


    do
    {
        mostrarMenu();
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                //TRAMITE URGENTE
                presionarContinuar();
                break;
            case 2:

                //TRAMITE REGULAR
                presionarContinuar();
                break;
            case 3:
                //PROXIMO CLIENTE
                presionarContinuar();
                break;
            case 4:
                //LISTAR
                presionarContinuar();
                break;
            case 5:
                //INFORMAR
                presionarContinuar();
                break;
            case 6:
                seguir = 'n';
                break;
        }
    }while(seguir=='s');


    return 0;
}
