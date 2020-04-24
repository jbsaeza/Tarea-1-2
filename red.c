#include "red.h"
//****************************

//****************************
//****************************


void leer_archivo(char* texto){
  data = fopen(texto, "r"); 
  
  if(data==NULL){
    printf("No se encuentra el archivo.\n");
  }

  for(int i=0; i<5; i++){ 
    if(i<2) // para leer las 2 primeras lineas y obtener number of nodes y number of links
    {
      fscanf(data, "%s %s %s %d", palabras1, palabras2 , palabras3, &dat[i]);
    }
  
    if(i==3){ //para eliminar indices de columnas
      fscanf(data, "%s %s %s %s %s %s", palabras1, palabras2 , palabras3, palabras4, palabras5, palabras6);
    }
  }
  nodes = malloc(dat[0]*sizeof(struct node));   
  number_of_nodes = dat[0];
  number_of_links = dat[1];
//**************************************
//**************************************

// void info_archivo(char* texto){
 
  for(int i=0; i<dat[0]; i++)
  { 
    nodes[i].id = i;
    nodes[i].links = 0;
  }

  for(int i=0; i<dat[0]; i++)
  { 
    for(int j=0; j<(dat[0]-1); j++)
    { 
      fscanf(data, "%s %s %d %s", palabras1, palabras2, &h, palabras3); //busca el valor de "hops" entre nodos
      if(h==1)
      { //asegura que el link sea de un nodo a otro directamente
        nodes[i].links = nodes[i].links + 1; //suma 1 a la cantidad de links  
        if(i<=j)
        { 
          nodes[j+1].links = nodes[j+1].links+1;
        }
        if(i>j)
        { 
          nodes[j].links = nodes[j].links+1;
        }
      }
    }
  }

  fclose(data); 
  data = fopen(texto, "r"); 
  if(data==NULL)
  {
    printf("No se encuentra el archivo.\n");
  }

  for(int i=0; i<5; i++)
  { 
    if(i<2)
    {
      fscanf(data, "%s %s %s %d", palabras1, palabras2 , palabras3, &dat[i]);
    }
    if(i==2 || i==4){
      fscanf(data, "%s", palabras1);
    }
    else
    {
      fscanf(data, "%s %s %s %s %s %s", palabras1, palabras2, palabras3, palabras4, palabras5, palabras6);
    }
  }

  for(int i=0; i<dat[0]; i++)//crea los links_id
  {  
    nodes[i].link_ids = malloc(nodes[i].links*sizeof(int));
    for(int j=0; j<nodes[i].links; j++)//se llena el array de links id
    { 
      nodes[i].link_ids[j] = -1;
    }  
    
  }
  
  for(int i=0; i<dat[0]; i++){ 
    for(int j=0; j<(dat[0]-1); j++){ //rota el nodes de llegada o entrada
      fscanf(data, "%s %s %d %s", palabras1, palabras2, &h, palabras3); //escanea la fila del archivo
      if(h==1){ //condiciona que el salto sea unico (link directo)
        if(palabras3[0]!=NULL && palabras3[1]==NULL){ //identifica el id del link unidad
          a1=(palabras3[0]-'0');
        }
        if(palabras3[0]!=NULL && palabras3[1]!=NULL && palabras3[2]==NULL){ //identifica el id del link decena
          a3=(palabras3[0]-'0');
          a3=(palabras3[1]-'0');
          a1=10*a3+a3;
        }
        if(palabras3[0]!=NULL && palabras3[1]!=NULL && palabras3[2]!=NULL){ //identifica el id del link centena
          a4=(palabras3[0]-'0');
          a3=(palabras3[1]-'0');
          a3=(palabras3[2]-'0');
          a1=100*a4+10*a3+a3;
          
        }
    
      }
    }
  }
}



