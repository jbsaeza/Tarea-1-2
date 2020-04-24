#include "red.h"


// ***********************************
int asignaciones, comparaciones;
// ***********************************
void swap1(struct node x[],int j);

void swap2(struct node x[],int j, int y);
/*
void bublesort(struct node x[], int y);
*/
void bubblesort();

/*
void selectionsort(struct node x[],int y);
*/
void selectionsort();

int comparaciones_is, asignaciones_is;
/*
void insertionsort(struct node x[],int y);
*/
void insertionsort();

int partition (struct node x[], int low, int high); //void quicksort(struct node x[], int low, int high);
void quicksort();

/*
void merge(struct node x[], int l, int m, int r);

void mergesort(struct node x[], int l, int r);
*/

void merge(struct node x[], int l, int m, int r);

void mergesort();

void guardar_nodos_ordenados(char* filename);










//void bublesort(struct node x[],int y)