#include<stdio.h>
#include "database.h"
#include "inout.h"

int p_register(){
  fprintf(stdout,"Register\n");
  char cadena_vuelta[30];

  get_string("Name",cadena_vuelta);

  fprintf(stdout,"%s\n",cadena_vuelta);

  return 0;}


int p_search(){
  fprintf(stdout,"Search\n");
  return 0;}



int p_discharge(){
  fprintf(stdout,"Discharge\n");
  return 0;}



int p_list(struct unPaciente *tabla, int numero){
  int i;
  fprintf(stdout,"Tabla de pacientes:\n");
  for(i=0;i<numero;i++){
    fprintf(stdout,"%s : %d\n",tabla[i].nombre,tabla[i].edad);}
 
  return 0;}
