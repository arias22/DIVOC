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
PaPaciente p_register(PaPaciente head){
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
  //PEDIMOS QUE ESCOJA OTRO SINTOMA
  char sintoma;
  sintoma=get_character("(FSTMN)","Symptom");

  //CREAMOS UN NODO CON EL PACIENTE Y LO AÑADIMOS A LA LISTA

  head=InsertaPaciente(nombre,edad,DNI,fever,cough,sintoma,head);
  fprintf(stdout,"New patient:\n ");
  display_patient(head);

  return head;}

//FUNCION PARA BUSCAR PACIENTES POR DNI
int p_search(PaPaciente phead){
  PaPaciente pAux;
  fprintf(stdout,"Search\n");
  char DNI[9];

  if(phead==NULL){
    fprintf(stdout,"No patients yet\n");
    return -1;
  }
  get_string("DNI",DNI,9,9);

  pAux = Busca_paciente(DNI,phead);
  if(pAux==NULL)fprintf(stdout,"Unknown patient\n");
  else{
    fprintf(stdout,"Patient data:\n");
    display_patient(pAux);}
  
  return 0;}


//FUNCION QUE ELIMINA UN PACIENTE
PaPaciente p_discharge(PaPaciente phead){
  char DNI[9];
  PaPaciente pAux;
  fprintf(stdout,"Discharge\n");
  //SI LA LISTA ESTA VACIA LO INDICAMOS Y RETORNAMOS NULL
  if(phead==NULL){fprintf(stdout,"No patients yet\n");return NULL;}
  //LE PEDIMOS EL DNI
  get_string("DNI",DNI,9,9);
  //USAMOS LA FUNCION ELMINA
  pAux=Elimina_paciente(DNI,phead);
  //SI NO ENCONTRAMOS EL PACIENTE
  if(pAux==NULL){fprintf(stdout,"Unknown patient\n");return phead;}
  //SI LO ENCONTRAMOS DEVOLVEMOS LA CABECERA
  else
    {
      phead=pAux;
      fprintf(stdout,"Discharged patient\n");
      return phead;

    }}

//FUNCION PARA MOSTRAR LOS PACIENTES DE UNA DETERMINADA EDAD
int p_list(PaPaciente phead){
  int fecha;
  fprintf(stdout,"List\n");
  if(phead==NULL)fprintf(stdout,"No patients yet\n");
  else{
   fecha = get_integer("Date",1900,2020);
   fprintf(stdout,"Patients born before %d:\n",fecha);
   Imprime_pacientes(phead,fecha);
  } 
 
  return 0;
  }
//FUNCION PARA MARCAR POSITIVOS

int p_mark(PaPaciente phead){
  fprintf(stdout,"Postives\n");
  if(phead==NULL){fprintf(stdout,"No patients yet");return -1;}
  fprintf(stdout,"Postive patients:\n");
  
  Busca_positivos(phead);
  return 0;
}

//FUNCION PARA SALIR DE PROGRAMA Y SOBREEESCRIBIR EL FICHERO
 int p_exit(FILE *fichero,PaPaciente phead){
   int k;
   k=yes_no("Are you sure you want to exit the program? (y/n)");
   if(k==0)return 0;
   else{
     fclose(fichero);
     fichero = fopen("patients.txt","w");
     Imprime_fichero(fichero,phead);
     fclose(fichero);
     return 1;
   }}
   
//FUNCION PARA INSERTAR PACIENTES
PaPaciente InsertaPaciente(char *nombre,int edad,char *DNI,int fever,int cough,char sympton,PaPaciente head){
  //CREAMOS UN NODO CON LAS CARACTERISTICAS DADAS
  PaPaciente pAux;
  pAux=Creanodo(nombre,edad,DNI,fever,cough,sympton);
  //SI head ES NULL (NO HABIA PACIENTES EN EL FICHERO) SOLO IGUALAMOS
  if(head==NULL)head=pAux;
  if(head!=NULL){
    pAux->sig=head;
    head=pAux;}
  
  return head;
}
//FUNCION PARA ENSEÑAR UN PACIENTE
void display_patient(PaPaciente phead){
  fprintf(stdout,">%s;%s;%d;%d;%d;%c;\n",phead->nombre,phead->DNI,phead->edad,phead->fever,phead->cough,phead->sympton);
  return;
}

//FUNCION PARA BUSCAR PACIENTES POR DNI

PaPaciente Busca_paciente(char *DNI,PaPaciente phead){

  while(phead!=NULL){
    if(strcmp(phead->DNI,DNI)==0)return phead;
    else
      phead=phead->sig;
  }
  return NULL;
    }
//FUNCION QUE ELIMINA UN PACIENTE Y RETORNA LA CABECERA DE LA LISTA
PaPaciente Elimina_paciente(char *DNI,PaPaciente phead){
  PaPaciente remove,anterior;
  //SI EL PRIMER PACIENTE COINCIDE CON EL DNI SE CUMPLE EL PRIMER IF
  if(strcmp(phead->DNI,DNI)==0)remove=phead;
  else
    {
      anterior = phead;
      //ESTE SOLO SE CUMPLE SI SOLO HAY UN PACIENTE Y NO COINCIDE CON EL DNI
      if(anterior->sig==NULL) return NULL;
      else{
	while(strcmp(anterior->sig->DNI,DNI)!=0){
	  anterior=anterior->sig;
	  //SE CUMPLE SI LLEGAMOS AL FINAL DE LA LISTA Y NO ENCONTRAMOS AL PACIENTE
	  if(anterior->sig==NULL)return NULL;
	}
	remove=anterior->sig;
      }
    
    }
  //ESTA SOLO SE CUMPLE SI ES EL PRIMER PACIENTE
  if(remove==phead){
    phead=phead->sig;
    free(remove);
  }
  else{
    anterior->sig=remove->sig;
    free(remove);
      }
  return phead;
}
//FUNCION PARA IMPRIMIR LOS PACIENTES MENORES QUE FECHA
 void Imprime_pacientes(PaPaciente phead,int fecha){
   while(phead!=NULL){
     if(phead->edad<=fecha)display_patient(phead);
     phead=phead->sig;
   }
 }
//FUNCION PARA BUSCAR E IMPRIMIR POSITIVOS
void Busca_positivos(PaPaciente phead){
  while(phead!=NULL){
    if(phead->fever==1){
      if(phead->cough==1){
	if(phead->sympton!='N'){
	  display_patient(phead);
	    }}}
    phead=phead->sig;
  }
  return ;
}
//FUNCION QUE IMPRIME LA TABLA DE PACIENTES EN EL FICHERO
 void Imprime_fichero(FILE *fichero,PaPaciente phead){
   while(phead!=NULL){
     fputs(phead->nombre,fichero);
     fprintf(fichero," ");
     fputs(phead->DNI,fichero);
     fprintf(fichero," ");
     fprintf(fichero,"%d ",phead->edad);
     fprintf(fichero,"%d ",phead->fever);
     fprintf(fichero,"%d ",phead->cough);
     fprintf(fichero,"%c\n",phead->sympton);

     phead=phead->sig;
   }
 }
     

     
     
   
   
					   
  
  
