#include "inout.h"
#include"database.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define P_Exit 'X'
#define P_Search 'S'
#define P_Discharge 'D'
#define P_Register 'R'
#define P_List 'L'
#define Tam_Linea 50
#define Car_Caja '-'
#define Aplicacion "DIVOC_"

int p_init(struct unPaciente *tabla,int *numero);
//HOA




int p_init (struct unPaciente *tabla, int *numero) {
  int edad;
  *numero = 0;
  edad = get_integer("Date");
  while (edad!=1) {
    tabla[*numero].edad= edad;
    get_string ("Name",tabla[*numero].nombre);
    (*numero)++;
    edad = get_integer("Date");  }
  return 0;
}


/////////////////////////////////////////////////CUERPO

 
int main (){

  struct unPaciente losPacientes[100];
  int numPacientes;
  p_init(losPacientes,&numPacientes);

  
 
  //variable para cuerpo:
  int k=0;
  char eleccion;
 
  stripe(Car_Caja,Tam_Linea);
  headline("DIVOC_",'|',Tam_Linea);
  stripe(Car_Caja,Tam_Linea);
   
 
  do{

    fprintf (stdout, "R) Register a patient\nS) Search for a patient\nD) Discharge a patient\nL) List patients by age\nP) Mark Positive\n\nX) Exit the program\n\n\n");
    fprintf(stdout,"Choose an option(RSDLPX): ");
    fscanf(stdin," %c",&eleccion);

    switch(toupper(eleccion)){
    case P_Register:
      p_register();
      break;
    case P_Search:
      p_search();
      break;
    case P_Discharge:
      p_discharge();
      break;
    case P_List:
      p_list(losPacientes,numPacientes);
      break;
    case P_Exit:
      k=yes_no();
      break;
 
    }}while(k==0);
  
  return 0;
}
