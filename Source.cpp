#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	char string1[400];
	char string2[300];
	int array[20];
	char esc;
	printf("\033[31mfor exit press esc\033[0m");
	do {
		printf("\ninput number of numbers: ");
		fgets(string1, sizeof(string1), stdin);
		int size = atoi(string1);
		if (size < 2 || size>20) { return 1; }

		printf("input number :");
		fgets(string2, sizeof(string2), stdin);
		char* next_token;
		int j = 0;
		char* token = strtok_s(string2, " ", &next_token);
		while (token != NULL && j < size) {
			array[j] = atoi(token);
			token = strtok_s(NULL, " ", &next_token);
			j++;
		}
		int comparison = array[0];
		int indexarray = 0;
		for (j = 1; j < size; j++) {
			if (comparison < array[j]) {
				comparison = array[j];
				indexarray = j;
			}
		}
		//printf("\nMax   %d", comparison);

		int index = 0;
		while (true) {
			for (j = 0; j < size; j++) {
				if (comparison % array[j] != 0) {
					comparison += array[indexarray];
					//printf("\n ++  : %d", comparison);
					break;
				}

				index = j;
			}
			//printf("\nindex  %d", index);
			if (index + 1 == size) {
				printf("\nMultiple: %d", comparison);
				break;
			}

		}
		
		esc = getchar();
	} while (esc != 27);

	return 0; 
 }

