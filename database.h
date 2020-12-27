#include <stdio.h>
struct unPaciente{
  char nombre[25];
  int edad;
  char DNI[20];
  int fever;
  int cough;
  char sympton;
  struct unPaciente *sig;
};
typedef struct unPaciente Paciente;
typedef struct unPaciente * PaPaciente;
PaPaciente Creanodo(char*,int,char*,int,int,char);
PaPaciente Crealista(FILE*);
PaPaciente InsertaPaciente(char*,int,char*,int,int,char,PaPaciente);
PaPaciente p_register(PaPaciente);
int p_search(PaPaciente);
PaPaciente p_discharge(PaPaciente);
int p_list(PaPaciente);
void display_patient(PaPaciente);
PaPaciente Busca_paciente(char*,PaPaciente);
PaPaciente Elimina_paciente(char*,PaPaciente);
void Imprime_pacientes(PaPaciente,int);
