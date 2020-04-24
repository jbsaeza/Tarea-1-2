#include <stdio.h>
#include <stdlib.h>
#include "ordenamiento.h"
  int asignaciones,comparaciones;
  int qs;
  int ms;
 void guardar_nodos_ordenados(char *filename)
 {
   FILE *fp;
//-----------------------
   if(filename=="out_bs.txt"){
 
  fp = fopen (filename, "w+");
  
  fprintf(fp, "%s \n", "BubbleSort");
  for(int i=0; i<dat[0]; i++)
  { 
    fprintf(fp,"%d ", nodes[i].id);
  }
  fprintf(fp, "\n");
  fprintf(fp, "comparaciones: %d \n",comparaciones);
  fprintf(fp, "asignaciones: %d \n", asignaciones);
  fprintf(fp, "\n");
  fclose(fp);
  asignaciones = 0;
  comparaciones = 0;
  }
//-----------------------
  if(filename=="out_ms.txt"){
     fp = fopen (filename, "w+");
  
  fprintf(fp, "%s \n", "MergeSort");
  for(int i=0; i<dat[0]; i++)
  { 
    fprintf(fp,"%d ", nodes[i].id);
  }
  fprintf(fp, "\n");
  fprintf(fp, "comparaciones: %d \n",comparaciones);
  fprintf(fp, "asignaciones: %d \n", asignaciones);
  fprintf(fp, "\n");
  fclose(fp);
    asignaciones = 0;
  comparaciones = 0;
  }

//---------------------------
  if(filename=="out_qs.txt"){

      fp = fopen (filename, "w+");
  
  fprintf(fp, "%s \n", "QuickSort");
  for(int i=0; i<dat[0]; i++)
  { 
    fprintf(fp, "%d ", nodes[i].id);
  }
  fprintf(fp, "\n");
  fprintf(fp, "comparaciones: %d \n",comparaciones);
  fprintf(fp, "asignaciones: %d \n", asignaciones);
  fprintf(fp, "\n");
  fclose(fp);
    asignaciones = 0;
  comparaciones = 0;

    }
//---------------------------
  if(filename=="out_ss.txt"){
        
       fp = fopen (filename, "w+");
  
  fprintf(fp, "%s \n", "SelectionSort");
  for(int i=0; i<dat[0]; i++)
  { 
    fprintf(fp, "%d ", nodes[i].id);
  }
  fprintf(fp, "\n");
  fprintf(fp, "comparaciones: %d \n",comparaciones);
  fprintf(fp, "asignaciones: %d \n", asignaciones);
  fprintf(fp, "\n");
  fclose(fp);
    asignaciones = 0;
  comparaciones = 0;
  }
//---------------------
     if(filename=="out_is.txt"){
    
    fp = fopen (filename, "w+");
  
  fprintf(fp, "%s \n", "InsertionSort");
  for(int i=0; i<dat[0]; i++)
  { 
    fprintf(fp, "%d ", nodes[i].id);
  }
  fprintf(fp, "\n");
  fprintf(fp, "comparaciones: %d \n",comparaciones);
  fprintf(fp, "asignaciones: %d \n", asignaciones);
  fprintf(fp, "\n");
  fclose(fp);
    asignaciones = 0;
  comparaciones = 0;
     }

 }
//-----------------------------

void swap1(struct node x[],int j){
  struct node swp=x[j];
  x[j]=x[j+1];
  x[j+1]=swp;
};

//*************************

void swap2(struct node x[],int j, int y){ 
  struct node swp=x[j];
  x[j]=x[y];
  x[y]=swp;
};

//************************
/*
void bubblesort(struct node x[],int y)*/
void bubblesort()
{

  int i,j;
  for(i=0;i<dat[0]-1;i++){
    
    comparaciones++;
    for(j=0;j<dat[0]-i-1;j++){
      comparaciones++;
      if(nodes[j].links>nodes[j+1].links){
        comparaciones++;
        swap1(nodes, j);
      asignaciones=asignaciones+2;
      
      }
    }
  }
  printf("bublersort\n");
  printf("comparaciones: %d\n",comparaciones);
  printf("asiganciones: %d \n", asignaciones);
        for(int i=0; i<dat[0]; i++){ 
    printf("%d ", nodes[i].id);
        }
printf("\n \n ");    
}


// **********************
/*
void selectionsort(struct node x[],int y)
*/
void selectionsort()
{ 
     int i, j, minimum; 
    for (i = 0; i < dat[0]-1; i++) 
    { 
      comparaciones++;
        minimum = i; 
        for (j = i+1; j < dat[0]; j++) 
        comparaciones++;
          if (nodes[j].links < nodes[minimum].links) 
          comparaciones++;
            minimum = j; 
        
        swap1(nodes, j); 
        asignaciones=asignaciones+2;
    } 
    printf("selectionsort\n");
      printf("comparaciones: %d\n",comparaciones);
  printf("asiganciones: %d \n", asignaciones);
  for(int i=0; i<dat[0]; i++){ 
    printf("%d ", nodes[i].id);
  }
 
}

//*****************************

void insertionsort()
{
  int i, key, j;
  for (i = 1; i < dat[0]; i++)
    {   
     comparaciones++;
      key = nodes[i].links; 
      struct node key1 = nodes[i];
      j = i - 1; 
     // printf("hello");
      while (j >= 0 && nodes[j].links >= key) 
      {
       comparaciones++;
       comparaciones++; 
        nodes[j + 1].links = nodes[j].links; 
        nodes[j + 1] = nodes[j];
       asignaciones++;
        j = j - 1; 
       asignaciones=asignaciones+1;   
      }         
      nodes[j + 1].links = key; 
     // nodes[j+1] = key1;
  }
  printf("\n");
  printf("\n");
  printf("insertionsort\n");
  printf("comparaciones: %d\n",comparaciones);
  printf("asiganciones: %d \n",asignaciones);
  for(int i=0; i<dat[0]; i++)
  { 
    printf("%d ", nodes[i].id);
  }

}

//-------------------------------

int partition (struct node x[], int low, int high)  
{
 
  struct node pivot = x[high];
  int i = (low - 1); 
  for (int j = low; j <= high - 1; j++)  
    {  
      comparaciones++;
      if (nodes[j].links < pivot.links)  
        {
          comparaciones++;
          i++; 
          swap2(x, i, j);
          asignaciones=asignaciones+3;
        }  
    }  
  swap2(x, i+1, high);  
  asignaciones=asignaciones+3;
  return (i + 1);       
}  

// --------------------------------

void quicksort(struct node nodes[], int low,int high)  
{  
  if (qs== 0)  
  {  qs++;
  high =dat[0]-1;
  low=0;
    comparaciones++;

    int pi = partition(nodes, low, high);  // indice de particion
    quicksort(nodes, low, pi - 1);  
    quicksort(nodes, pi + 1, high);  
  }
  if (low < high )  
  {
    comparaciones++;
    int pi = partition(nodes, low, high);  // indice de particion
    quicksort(nodes, low, pi - 1);  
    quicksort(nodes, pi + 1, high);  
  }
      
}  


//--------------------------------

void merge(struct node x[], int l, int m, int r) 
{ 
    int i, j; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
   
    struct node L[n1];
    struct node R[n2]; 
    
    for (i = 0; i < n1; i++) 
    {
      comparaciones++;
      L[i].links = nodes[l + i].links; 
    }
   
    for (j = 0; j < n2; j++) 
    {
      comparaciones++;
      R[j].links = nodes[m + 1+ j].links; 
    }
    
    i = 0; 
   
    j = 0;
    
    int k = l; 
    while (i < n1 && j < n2) 
    {  comparaciones=comparaciones+2;
        if (L[i].links <= R[j].links) 
        {  comparaciones=comparaciones+1;

          

            nodes[k].links = L[i].links; 
            
        //   swap2(x, i, k);
           
          asignaciones++;
            i++; 
        } 
        else
        { 
           
           //   swap2(x, j, k);
            nodes[k].links = R[j].links; 
          
            asignaciones++;
            j++;
          
        } 
        k++; 
    } 
   
    while (i < n1) 
    {  comparaciones=comparaciones+1;

         //swap2(x, i, k);
       nodes[k].links = L[i].links;
    
        asignaciones++;
        i++; 
        k++; 
    } 

      
    while (j < n2) 
    {  comparaciones=comparaciones+1;

       // swap2(x, j, k);
        nodes[k].links = R[j].links;
  
       asignaciones++;
        j++; 
        k++; 
    } 
} 

// ++++

void mergesort(struct node x[], int l, int r) 
{  if (ms == 0)  
  {  ms++;
  r =dat[0]-1;
  l=0;
    comparaciones++;
     int m = l+(r-l)/2; 
        mergesort(nodes, l, m); 
        mergesort(nodes, m+1, r); 
  
        merge(nodes, l, m, r); 
  } 
    if (l < r) 
    { comparaciones++;
       
        int m = l+(r-l)/2; 
        mergesort(nodes, l, m); 
        mergesort(nodes, m+1, r); 
  
        merge(nodes, l, m, r); 
    } 
    
} 

// ------------------------




























