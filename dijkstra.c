#include <stdio.h>

int main() {
	int infinity = 1000000;
	int n = 6;
	int matrix_of_adjacency[6][6] = {0,7,9,0,0,14,
									 7,0,10,15,0,0,
									 9,10,0,0,0,2,
									 0,15,0,0,6,0,
									 0,0,0,6,0,9,
									 14,0,2,0,9,0};

	int visited_vetrices[6] = {0,0,0,0,0,0};
	int distance_between_vertices[6] = {infinity,infinity,infinity,infinity,infinity,infinity};
 	
	int current;
	printf("Select starting verticle from 0 to %d\n", n-1);
	scanf("%d",&current);
	int min = infinity;
	int index = -1;

	distance_between_vertices[current] = 0;

	for(int i =0; i < n; i++) {
		for(int j = 0; j < n; j++) {
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
	
	for(int i = 0; i < n; i++)
		printf("%d ", distance_between_vertices[i]);
	putchar('\n');
	return 0;
}