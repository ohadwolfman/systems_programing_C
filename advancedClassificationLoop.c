#include <stdio.h>
#include <math.h>
#include "advancedClassificationLoop.h"

// check if a number is an Armstrong number, using loops
int isArmstorng(int n){
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
	int armstrongValue = 0;
	for (int i = 0; i<numLength; i++){
		int x = pow(digits[i], numLength);
		armstrongValue += x;
	}
	int ans = (armstrongValue == result)? 1 : 0;
	return ans;
}

// check if a number is a Palinndrome, using loops
int isPalindrome(int n){
	int numLength = 0;
	int num = n;
	while(n>0){
		n = n/10;
		numLength++;
	}
	int digits[numLength];
	for(int x = 0; x < numLength; x++){
		digits[x] = num%10;
		num /= 10;
	}
	int i = 0;
	int j = numLength-1;
	while (j>i){
		if ((digits[i]==digits[j])==0) {
			return 0;
		}
		i++, j--;
	}
	return 1;
}
