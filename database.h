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
PaPaciente InsertaPaciente();
int p_register();
int p_search();
int p_discharge();
int p_list(PaPaciente,int);

