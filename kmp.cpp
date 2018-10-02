#include "stdafx.h"
#include <iostream>

using namespace std;

void kmpUtil(char* str, int* arr, int n) {

	int j, i;
	j = 0; i = 1;
	while(i<=n)
	{
		if (str[i] == str[j]) {
			arr[i] = arr[i-1] + 1;
			j++;
			i++;
		}
		else {
			if (j != 0) {
				j = arr[j - 1];
			}
			else {
				arr[i] = 0;
				i++;
			}
			
		}
	}
}
bool match(char* str, int  ns, char* p, int np, int *arr) {
	bool result = false;

	int i, j;
	i = 0;
	j = 0;
	while (i<=np )
	{
		if (str[j]== p[i])
		{
			j++;
			i++;
			if (j==ns+1)
			{
				result = true;
				break;

			}
		}
		else {
			if (j!=0)
			{
				j = arr[j - 1];
			}
			else
			{
				i++;
			}
		}
		
	}
	return result;

}

void primee() {

	char str[] = "abcabcc";
	char p[] = "abcabcabcc";
	int *arr = new int[sizeof(p)];
	arr[0] = 0;
	kmpUtil(str, arr,6);
	cout << match(str, 6, p, 9,arr) << " :this" << endl;
}