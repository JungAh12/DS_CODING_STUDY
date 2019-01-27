#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main() {
	int user;

	scanf("%d", &user);

	for (int i = 1; i <= user; i++) {
		for (int j = 1; j <= i; j++){
			printf("*");
	}
		printf("\n");
	}
	return 0;
}
