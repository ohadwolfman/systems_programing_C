#include <stdio.h>
#include <math.h>
#include "NumClass.h"

// check if given number is a prime number
int isPrime(int n) {
	if (n <= 0) {
		return 0;
	}
	int limit = (int)sqrt(n);
	for(int i = 2; i <= limit; i++){
		if(n % i == 0){
			return 0;
		}
	}
	return 1;
}

// calculate factorial of given number
int factorial(int n){
    if (n == 0){
        return 0;
    }
	if (n == 1){
		return 1;
	} else {
		return (n*factorial(n-1));
	}
}

// check if given number is a strong number
int isStrong(int n) {
	int numLength = 0;
	int num = n;
	int result = n;
	while(n>0){
		n = n/10;
		numLength++;
	}
	int digits[numLength];
	for(int x = 0; x < numLength; x++){
		digits[x] = num%10;
		num /= 10;
	}
	int strongValue = 0;
	for (int i = 0; i < numLength; i++){
		strongValue += factorial(digits[i]);
	}
	int ans = (strongValue == result)? 1 : 0;
	return ans;
}
