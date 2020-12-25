#include "inout.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>





void get_string(char *mensaje,char *la_cadena){
 
  int l;
  char cadena[30];
   do {
     fprintf (stdout,"%s\n",mensaje);
     fscanf(stdin,"%s",cadena);
    
     l = strlen(cadena);
     if (l>24)
       fprintf (stdout,"Longitud excesiva\n");
   } while(l>24);
   
   strcpy(la_cadena,cadena);
   return;
 
}
int get_integer (char *mensaje){
  int numero;
  do {
    fprintf(stdout,"%s\n",mensaje);
    fscanf(stdin,"%d",&numero);
  }while((numero<1)||(numero>25));
  return numero;
}

void stripe(char signo,int Tam_Linea){
  int i;
  for(i=0;i<Tam_Linea;i++)fprintf(stdout,"%c",signo);
  fprintf(stdout,"\n");
  return;}

void headline (char palabra[],char signo,int Tam_Linea){

  int l = strlen(palabra);
  int espacio = ((Tam_Linea-2)-l);
  int cont1;
  int cont2;
   fprintf(stdout,"%c",signo);
  for(cont1=0;cont1<espacio/2;cont1++)fprintf(stdout," ");
  fprintf(stdout,"%s",palabra);
  for(cont2=0;cont2<espacio/2;cont2++)fprintf(stdout," ");
  if(espacio%2!=0)fprintf(stdout," ");
  fprintf(stdout,"%c\n",signo);
  return;
   
}
int yes_no(){
  char opcion;
  do {
    
    fprintf(stdout,"Are you sure you want to exitthe program? (y/n): ");
    fscanf(stdin," %c",&opcion);
    if(toupper(opcion)=='Y')return 1;
    else if (toupper(opcion)=='N')
    return 0;
  }while((toupper(opcion)!= 'Y' || toupper(opcion)!= 'N'));

}
