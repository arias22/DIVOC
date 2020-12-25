struct unPaciente{
  char nombre[25];
  int edad;
};



int p_register();
int p_search();
int p_discharge();
int p_list(struct unPaciente*,int);

