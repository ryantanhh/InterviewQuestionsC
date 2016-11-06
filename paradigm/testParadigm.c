#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define INVALID_ARGUMENT 1
#define TRUE 1
#define FALSE 0
#define ALPHABET_COUNT 26

int isParadigm(char str1[], char str2[]);

int main(int argc, char* argv[]) {
	if (argc != 3) {
		printf("Invalid arguments supplied.");
		return INVALID_ARGUMENT;
	}

	printf("%s and %s %s paradigm.",
			argv[1],
			argv[2],
			(isParadigm(argv[1], argv[2])) ? "are" : "are not"
			);
	return 0;
}

int isParadigm(char* str1, char* str2) {
	size_t l1;
	size_t l2;
	size_t i;
	int c;

	int vocabulary[ALPHABET_COUNT] = {0};

	l1 = strlen(str1);
	l2 = strlen(str2);

	if (l1 != l2) {
		return FALSE;
	}

	for (i = 0; i < l1; i++) {
		c = tolower(str1[i]);
		vocabulary[c-'a']++;
	}

	for (i = 0; i < l2; i++) {
		c = tolower(str2[i]);
		vocabulary[c-'a']--;
	}

	for (i = 0; i < ALPHABET_COUNT; i++) {
		if (vocabulary[i] !=0) {
			return FALSE;
		}
	}

	return TRUE; 
}

