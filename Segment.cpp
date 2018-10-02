
#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;

int findSeg(int* segt, int qlow, int qhigh, int low, int high, int pos) {  

	if (qlow <= low && qhigh >= high) return segt[pos];
	if (qlow > high || qhigh < low) return 999999;
	int mid = low + high; mid /= 2;
	return std::min(findSeg(segt, qlow, qhigh, mid + 1, high, pos * 2 + 2),
		findSeg(segt, qlow, qhigh, low, mid, pos * 2 + 1));
}
void buildSegt(int* arr, int *segT, int low, int high, int pos) {

	if (low == high) {
		segT[pos] = arr[low];
		return;
	}
	int mid = low + high; mid /= 2;
	buildSegt(arr, segT, low, mid, 2 * pos + 1);
	buildSegt(arr, segT, mid + 1, high, 2 * pos + 2);
	segT[pos] = std::min(segT[2 * pos + 1], segT[2 * pos + 2]);
}
int prime() {
	int n = 10;
	int size = 1;
	int arr[] = { 11,2,6,3,17,8,15,5,9,10 };
	while (size < n) {
		size *= 2;
	}
	size *= 2;
	int* segT = new int[size];
	
	for (int i = 0; i < size; i++)
	{
		segT[i] = 999999;
	}

	cout << endl;
	buildSegt(arr, segT, 0, n - 1, 0);
	for (int i = 0; i < size; i++) {
		cout << segT[i] << " " ;
	}
	int test = findSeg(segT, 2, 7,0 ,n-1,0);
	free(segT);
	return test;
	
}
