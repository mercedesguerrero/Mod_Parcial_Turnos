#ifndef __PACIENT
#define __PACIENT

struct
{
    int dni;
    int turno_numero;

}typedef Pacient;
#endif // __PACIENT


void mostrarMenu();
void presionarContinuar();

int getInt();

void printPacient(Pacient* p);
Pacient* newPacient(int dni, int num_turno);
