#include <stdio.h>

int main() {
	int infinity = 1000;
	int n = 6;
	int matica_susednosti[6][6] = {0,7,9,0,0,14,7,0,10,15,0,0,9,10,0,0,0,2,0,15,0,0,6,0,0,0,0,6,0,9,14,0,2,0,9,0};

	int navstivene_vrcholy[6] = {0,0,0,0,0,0};
	int dlzka_mezdi_vrchomi[6] = {infinity,infinity,infinity,infinity,infinity,infinity};

	int start = 0;
	int min = infinity;
	int index = infinity;

	for(int i = 0; i < n; i++) {
		if(min > matica_susednosti[start][i] && matica_susednosti[start][i] != 0 && navstivene_vrcholy[i] == 0) {	//hladanie minima
			min = matica_susednosti[start][i];
			index = i;
			}
		if(i != i && )

		}

	printf("%d %d\n", min, index);

	return 0;
}