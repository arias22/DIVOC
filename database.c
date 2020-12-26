#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "database.h"
#include "inout.h"

//FUNCION CREANODOS
PaPaciente Creanodo(char *nombre,int edad,char *DNI,int fever,int cough,char sympton){
  PaPaciente pAux = (PaPaciente) malloc(sizeof (Paciente));
  pAux->edad=edad;
  pAux->fever=fever;
  pAux->cough=cough;
  pAux->sympton=sympton;
  strcpy(pAux->nombre,nombre);
  
  strcpy(pAux->DNI,DNI);

  return pAux;
}
//FUNCION QUE CREA LA LISTA DEL FICHERO
PaPaciente Crealista(FILE *fichero){
  PaPaciente pFin;
  PaPaciente pIni;
  PaPaciente pAux;
  char nombre[25];
  int edad;
  char DNI [20];
  int fever,cough;
  char sympton;
  int i =0;
  while(i!=15){
    fscanf(fichero,"%s %s %d %d %d %c",nombre,DNI,&edad,&fever,&cough,&sympton);
    if(feof(fichero)!=0)break;
    pAux=Creanodo(nombre,edad,DNI,fever,cough,sympton);
    if (i==0){pIni=pFin=pAux;i++;}
    else
      {
	pFin->sig=pAux;
	pFin=pAux;
      }	  
  }
  return pIni; 
}
//FUNCION DE REGISTRAR PACIENTES
int p_register(){
  fprintf(stdout,"Register\n");
  char nombre[30];
  char DNI[30];
  int edad;
  int fever,cough;
  //PEDIMOS EL NOMBRE
  get_string("Name",nombre,1,24);
  //PEDIMOS Y COMPROBAMOS EL DNI
  do{
  get_string("DNI",DNI,9,9);
  if(verify_DNI(DNI)==0)fprintf(stdout,"INVALID DNI\n");
  }while(verify_DNI(DNI)==0);
  //PEDIMOS LA EDAD
  edad = get_integer("DATE",1900,2020);
  //PEDIMOS LA FIEBRE Y TOS
  fever=yes_no("Fever? (y/n): ");
  cough=yes_no("Cough? (y/n): ");
  

  return 0;}


int p_search(){
  fprintf(stdout,"Search\n");
  return 0;}



int p_discharge(){
  fprintf(stdout,"Discharge\n");
  return 0;}



int p_list(PaPaciente tabla, int numero){
  int i;
  fprintf(stdout,"Tabla de pacientes:\n");
  for(i=0;i<numero;i++){
    fprintf(stdout,"%s : %d\n",tabla[i].nombre,tabla[i].edad);}
 
  return 0;}
