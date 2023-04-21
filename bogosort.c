#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10

void shuffle(int *array, int n) {
	for (int i = n - 1; i > 0; i--) {
		int j = rand() % (i + 1);
		int temp = array[i];
		array[i] = array[j];
		array[j] = temp;
	}
}

int is_sorted(int *array, int n) {
	for (int i = 1; i < n; i++) {
		if (array[i] < array[i - 1]) {
			return 0;
		}
	}
	return 1;
}

void print_array(int *array, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}

int main() {
	int array[ARRAY_SIZE] = {0};
	int iteration_count = 0;
	
	srand(time(NULL));
	
	// Získání vstupních čísel od uživatele
	printf("Zadejte %d cisel pro razeni:\n", ARRAY_SIZE);
	for (int i = 0; i < ARRAY_SIZE; i++) {
		scanf("%d", &array[i]);
	}
	
	// Řazení pomocí BOGOSORT
	while (!is_sorted(array, ARRAY_SIZE)) {
		shuffle(array, ARRAY_SIZE);
		iteration_count++;
		printf("Randomizace #%d: ", iteration_count);
		print_array(array, ARRAY_SIZE);
	}
	
	printf("Pole bylo uspesne razeno po %d randomizacich.\n", iteration_count);
	
	return 0;
}
