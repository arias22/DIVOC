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




 
int main (){
  //DECLARAMOS EL PRIMER NODO DE LA LISTA
  PaPaciente head;
  //Declaramos un fichero que abre patients.txt solo para leerlo
  FILE *fichero;
  char c;
  fichero=fopen("patients.txt","r");
  //SI EL FICHERO NO EXISTE PASAMOS Y NO CREAMOS LA LISTA
  if(fichero!=NULL){
    //SI EL FICHERO ESTA VACIO NO CREAMOS LA LISTA
    if((c=fgetc(fichero))!=EOF){
      rewind(fichero);
    head = Crealista(fichero);  
    }}

  

  
  //CARATULA DEL PROGRAMA
  stripe(Car_Caja,Tam_Linea);
  headline("DIVOC_",'|',Tam_Linea);
  stripe(Car_Caja,Tam_Linea);
  //FIN DE LA CARATULA   
  int k=0;
  char eleccion;
  do{

    fprintf (stdout, "R) Register a patient\nS) Search for a patient\nD) Discharge a patient\nL) List patients by age\nP) Mark Positive\n\nX) Exit the program\n\n\n");
    eleccion=get_character("(RSDLPX)","Choose an option");

    switch(toupper(eleccion)){
    case P_Register:
       head=p_register(head);
      break;
    case P_Search:
       p_search(head);
      break;
    case P_Discharge:
     head =  p_discharge(head);
      break;
    case P_List:
     
      p_list(head);
      break;
    case P_Exit:
      fprintf(stdout,"Exit\n\n");
       k=yes_no("Are you sure you want to exit the program? (y/n): ");
      break;
 
    }}while(k==0);
  
  return 0;
}
