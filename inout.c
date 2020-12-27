#include "inout.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>




//FUNCION PARA EL DNI Y EL NOMBRE
void get_string(char *mensaje,char *la_cadena,int min,int max){
 
  int l;
  char cadena[30];
   do {
     fprintf (stdout,"%s",mensaje);
     fprintf(stdout," (%d-%d char): ",min,max);
     fscanf(stdin,"%s",cadena);
    
     l = strlen(cadena);
     
     
   } while(l<min||l>max);
   
   strcpy(la_cadena,cadena);
   return;
 
}
//FUNCION PARA LA EDAD
int get_integer (char *mensaje,int min,int max){
  int numero;
  do {
    fprintf(stdout,"%s",mensaje);
    fprintf(stdout,"[%d-%d]: ",min,max);
    fscanf(stdin,"%d",&numero);
  }while((numero<min)||(numero>max));
  return numero;
}
//FUNCIONES CABECERA !!!!!!!!!
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

//FUNCION PARA COSAS DE SI O NO
int yes_no(char *cadena){
 

  char opcion;
  do {
    
    fprintf(stdout,"%s",cadena);
    fscanf(stdin," %c",&opcion);
    if(toupper(opcion)=='Y')return 1;
    else if (toupper(opcion)=='N')
      return 0;
  }while((toupper(opcion)!= 'Y' || toupper(opcion)!= 'N'));

}
//FUNCION PARA VERIFICAR DNI
int verify_DNI(char *DNI){

  int i;
  char num[8];
  int nums;
  int indice;
  char palabra[23]={"TRWAGMYFPDXBNJZSQVHLCKE"};
  int j=0;
  //CON ESTE FOR SEPARAMOS LOS NUMEROS DE LA LETRA DEL DNI Y LOS COLOCAMOS EN NUM
  for(i=0;i<8;i++){
    num[j]=*(DNI+i);
    j++;
  }
  //CONVERTIMOS LA CADENA NUM EN UN ENTERO
  nums=atoi(num);
  indice=nums%23;
  
  if(*(DNI+8)==*(palabra+indice))return 1;
  else
    return 0;
}
//FUNCION PARA VERIFICAR CARACTERES
char get_character(char *cadena,char *invitacion){
  char caracter;
  char recadena[10];
  int i=0;
  
  //CON
  do{
    
    fprintf(stdout,"%s %s: ",invitacion,cadena);
    
    fgets(recadena,15,stdin);
    caracter=toupper(*(recadena));


  }while(strchr(cadena,caracter)==NULL||strlen(recadena)>2);

  return toupper(caracter);
}



  
