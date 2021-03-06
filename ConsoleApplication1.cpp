#include "stdafx.h"
#include <iostream>
using namespace std;
const int MAX = 99999999;

extern void permute(int n , int o, int pointer);

void upUtil(int x, int y, int*arr, int s, int e, int pos, int diff) {
	if (x>e || y<s) return;
	if (x <= s && y >= e) { if (arr[pos]> diff) arr[pos] = diff; return; }
	int mid = (s + e) / 2;
	upUtil(x, y, arr, s, mid, 2 * pos, diff);
	upUtil(x, y, arr, mid + 1, e, 2 * pos + 1, diff);
	if (arr[pos]> diff) arr[pos] = diff;
}


void update(int x, int y, int *segArr, int *arr, int e) {

	upUtil(x, x, segArr, 0, e, 1, y);


}

void fromSeg(int *arr, int s, int e, int *seg, int pos) {

	if (s == e) {
		seg[pos] = arr[s];
		return;
	}
	int mid = (s + e) / 2;
	fromSeg(arr, s, mid, seg, 2 * pos);
	fromSeg(arr, mid + 1, e, seg, 2 * pos + 1);
	seg[pos] = seg[2 * pos]>seg[2 * pos + 1] ? seg[2 * pos + 1] : seg[2 * pos];
}
int utilS(int x, int y, int*arr, int s, int e, int pos) {
	if (x>e || y<s) return MAX;
	if (x <= s && y >= e) return arr[pos];
	int mid = (s + e) / 2;
	int temp = utilS(x, y, arr, s, mid, 2 * pos);
	int temp1 = utilS(x, y, arr, mid + 1, e, 2 * pos + 1);
	temp = temp>temp1 ? temp1 : temp;
	return temp;
}

int main() {
	int size, q;
	cin >> size;

	permute(size, 0, 0);
	cin >> q;
	
	int *arr = new int[size];
	for (int i = 0; i < size;i++) {
		cin >> arr[i];

	}
	int x, y; char type;
	int segSize = 1;
	while (segSize < (2 * size - 1)) segSize *= 2;
	segSize *= 2;

	int *segArr = new int[segSize];
	for (int i = 0; i < segSize; i++)
	{
		segArr[i] = 999999;
	}
	fromSeg(arr, 0, size - 1, segArr, 1);
	/*for (int i = 0; i < segSize; i++)
	{
	cout << segArr[i] << " # " << i << endl;
	}*/
	for (int i = 0;i<size;i++) {
		cin >> type;
		cin >> x;
		cin >> y;

		if (type == 'q') { cout << utilS(x - 1, y - 1, segArr, 0, size - 1, 1) << endl; }
		else {
			update(x-1, y, segArr, arr, size - 1);
		}

	}
	system("pause");
}