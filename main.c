#include <stdio.h>
#include "NumClass.h"

int main() {

	// Recieve input of 2 integers from user
	int a, b;
	printf("Please enter 2 positive integers: ");
	scanf("%d%d", &a, &b);
	
	// Make sure that a is not greater than b
	if (a > b){
		int temp = a;
		a = b;
		b = temp;
	}

	// Print out all armstrong numbers between a and b (included)
	printf("The Armstrong numbers are:");
	for (int i = a; i <= b; i++) {
		if (isArmstorng(i) == 1) {
			printf(" %d", i);
		}
	}

	// Print out all palindorme numbers between a and b (included)
	printf("\nThe Palindromes are:");
	for (int i = a; i <= b; i++) {
		if (isPalindrome(i) == 1) {
			printf(" %d", i);
		}
	}

	// Print out all prime numbers between a and b (included)
	printf("\nThe Prime numbers are:");
	for (int i = a; i <= b; i++) {
		if (isPrime(i) == 1) {
			printf(" %d", i);
		}
	}

	// Print out all strong numbers between a and b (included)
	printf("\nThe Strong numbers are:");
	for (int i = a; i <= b; i++) {
		if (isStrong(i) == 1) {
			printf(" %d", i);
		}
	}
	return 0;
}
