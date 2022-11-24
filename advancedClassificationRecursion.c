#include <stdio.h>
#include <math.h>
#include "NumClass.h"

// Check the number of digits in a given integer
int countDigits(int n){
	int counter = 0;
	while (n > 0) {
		counter++;
		n /= 10;
	}
	return counter;
}

// Recursive function to check if a number is an Armstrong Number
int isArmstorngRecursive(int n, int numDigits){
	if (n == 0) {
		return 0;
	}
	int digits = n%10;
	int x = pow(digits, numDigits);
	return (x + isArmstorngRecursive(n/10, numDigits));
}

// Function to check if a number is an Armstrong Number
// This function calls isArmstorngRecursive function
int isArmstorng(int n){
	int numDigits = countDigits(n);
	int sum = isArmstorngRecursive(n, numDigits);
	return (sum == n ? 1 : 0);
}

// Recursive function to check if a number a palindrome
// The number is represented as an array of digits
int isPalindromeRecursive(int arr[], int start, int end) {
	if ((end-start) < 2){
		return 1;
	}
	if (arr[start] != arr[end]) {
		return 0;
	} else {
		return isPalindromeRecursive(arr, ++start, --end);
	}
}

// Function to check if a number is a palindrome
// This function creates an array representing the digits of the given number
// and then calls isPalindromeRecursive function
int isPalindrome(int n){
	int numDigits = countDigits(n);
	int arr[numDigits];
	for (int i = 0; i < numDigits; i++) {
		arr[i] = n%10;
		n /= 10;
	}
	return isPalindromeRecursive(arr, 0, numDigits-1);
}
