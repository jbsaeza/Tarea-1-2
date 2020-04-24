#include <stdio.h>
#include <stdlib.h>
#include <string.h>
  
struct node{
  int id;
  int *link_ids;
  int links;
};
int dat[2];
char palabras1[50];
char palabras2[50];
char palabras3[50];
char palabras4[50];
char palabras5[50];
char palabras6[50];
int h;
int a1;
int a2;
int a3;
int a4;


struct node *nodes;
int number_of_nodes;
int number_of_links;

void leer_archivo(char* filename);
void guardar_nodos_ordenados(char* filename);