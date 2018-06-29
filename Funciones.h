#ifndef __PACIENT
#define __PACIENT

struct
{
    int dni;
    int idTramite;
    int turno_numero;

}typedef Pacient;
#endif // __PACIENT


void mostrarMenu();
void presionarContinuar();

int getInt();

void printPacient(Pacient* p);
Pacient* newPacient();
Pacient* newPacientUrgente(int dni, int num_turno);
