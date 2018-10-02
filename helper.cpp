#include "stdafx.h"
#include <iostream>
/*


// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

extern void heap(int*arr, int n);
extern void primee();
using namespace std;
struct Node {
int value;
Node* next;
};
Node *arrPointer[10];
int count1 = 0;
void create() {
Node *temp = new Node;
temp->value = count1;
arrPointer[count1++] = temp;
}
int partition(int high, int low, int* arr) {
int pivot = arr[high];
int lower = low - 1;
for (int i = low; i < high;i++) {
if (arr[i] <= pivot) {
lower++;
int temp = arr[i];
arr[i] = arr[lower];
arr[lower] = temp;
}
}
//lower++;
int temp = arr[lower + 1];
arr[lower + 1] = arr[high];
arr[high] = temp;
return lower + 1;
}
void quickSort(int high, int low, int* arr) {
if (high <= low) return;
int pivot = partition(high, low, arr);
quickSort(high, pivot + 1, arr);
quickSort(pivot - 1, low, arr);

}

void bubleSort(int n, int* arr) {

for (int i = 0; i < n; i++) {

for (int j = 1; j < n - i;j++) {
if (arr[j] < arr[j - 1]) {
int temp = arr[j];
arr[j] = arr[j - 1];
arr[j - 1] = temp;
}
}

}
}

void insertNode(Node* input, Node** head, int data) {
if ((*head) == NULL) {
input->next = NULL;
input->value = data;
*head = input;
return;
}
input->value = data;
input->next = *head;
*head = input;


}
void display(Node* head) {
while (head) {
cout << (*head).value << endl;
head = (*head).next;
}
}
int main()
{
Node *head = NULL;
for (int i = 0;i < 3;i++) {
Node *temp = new Node;
insertNode(temp, &head, i + 11);
}
display(head);
Node *ff = head;
head = head->next;
free(ff);
int ar[] = { 2,55,4,22,100,22,123,6,2 };
//quickSort(8,0,ar);
heap(ar, 8);
for (int i = 0;i < 9;i++) {
cout << ar[i] << " " << endl;
}
create();
create();
cout << count1 << endl;
for (int i = 0; i< 2; i++) {
cout << (arrPointer[i]->value) << endl;
}
primee();

system("pause");
return 0;
}


*/

using namespace std;
char str[300];

void permute(int n, int o,int pointer) {
	if (n == 0) {
		while (o--)
		{
			str[pointer++] = '}';
		}
		str[pointer] = '\0';

		cout << str << endl;
		return;

	}
	if (n > 0) {
		n++;
		str[pointer]= '{';
		permute(n - 1, o + 1,pointer+1);

	}
	str[pointer + 1] = '}';
	permute(n - 1, o, pointer+2);
}
