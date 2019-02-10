#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fill_matrix(int *matrix_of_adjacency[], int *size) {
	FILE *fr;
	fr = fopen("matrix_of_adjacency.txt","r");

	char number[100];
	fgets(number,10,fr);
	number[strlen(number)-1] = '\0';

	*size = atoi(number);
	
	for(int i = 0; i < *size; i++)
		matrix_of_adjacency[i] = (int *) malloc((*size)*sizeof(int));

	int sign, i = 0, j = 0, n = 0;

	while((sign = getc(fr)) != EOF) {
		if(sign == ',' || sign == '\n')  {
			if(sign == ',') {
				matrix_of_adjacency[i][j++] = n;
				n = 0;
			}	
			else {
				i++;
				j = 0;
			}		
		}
		else {
			n *= 10;
			n += (sign-48);
		}
	}
}



int main() {
	int infinity = 10000;
	int size = infinity;

	int *matrix_of_adjacency[size];
	fill_matrix(matrix_of_adjacency, &size);
	

	int *visited_vetrices = (int*) malloc(size*sizeof(int));
	for(int i = 0; i < size; i++)
		visited_vetrices[i] = 0;

	int *distance_between_vertices = (int *) malloc(size*sizeof(int));
	for(int i = 0; i < size; i++)
		distance_between_vertices[i] = infinity;

	int current;
	printf("Select starting verticle from 0 to %d\n", size-1);
	scanf("%d",&current);
	int min = infinity;
	int index = -1;

	distance_between_vertices[current] = 0;

	for(int i =0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			if(visited_vetrices[j] != 1 && matrix_of_adjacency[current][j] != 0) {
				if(distance_between_vertices[current] + matrix_of_adjacency[current][j] < distance_between_vertices[j])
					distance_between_vertices[j] = distance_between_vertices[current] + matrix_of_adjacency[current][j];
				}
			visited_vetrices[current] = 1;
			if(visited_vetrices[j] != 1 && min > distance_between_vertices[j]) {
				min = distance_between_vertices[j];
				index = j;
			}
		}
	current = index;
	min = infinity;
	}

	for(int i = 0; i < size; i++)
		printf("%d ", distance_between_vertices[i]);
	putchar('\n');
	return 0;
}