
#include "stdafx.h"

#include <iostream>

using namespace std;
void maxhipi(int *arr, int s, int n) {
	int j = s * 2 + 1;
	int temp = arr[s];
	while (j<=n)
	{
		if (j + 1 <= n && arr[j] < arr[j + 1]) {
			j++;
		}
		if (arr[j] < temp) break;
		if (j%2==1)
			arr[j / 2] = arr[j];
		else arr[ (j-1) / 2] = arr[j];
		
		j = j * 2 + 1;
	}
	if (j % 2 == 1)
		arr[j / 2] = temp;
	else arr[(j - 1) / 2] = temp;
}


void buildHeap(int*arr, int s, int n) {

	for (int i = (n ) / 2; i >= 0; i--) {
		maxhipi(arr, i, n);
	}
}
void heapsort(int* arr , int n) {
	for (int i = 0;i < n;i++) {
		int temp = arr[0];
		arr[0] = arr[n - i];
		arr[n - i] = temp;
		maxhipi(arr, 0, n-i - 1);
	}
}
void heap(int *arr,int n) {
	buildHeap(arr,0,n);
	heapsort(arr,n);
}

