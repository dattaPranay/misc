

#include"stdafx.h"
#include <iostream>

using namespace std;

int *bit;  

int getParent(int x) {
	return x - (x & (-x));  
}
void treeUtil(int*arr, int n, int * bit) {

}
int getNext(int x) {
	return x + (x & (-x));
}
void createTree(int n , int *arr) {
	int *temp = new int[n+1];
	bit = temp;

	treeUtil(arr, n, bit);

}
