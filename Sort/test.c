#include"Sort.h"
void TestInsertSort() {
	int a[] = { 12,214421,124,312,523,33,3,532,523,34,2,52,523,523,523,42,41,5,43,654,7,464,37,4652,4231,65,3245,423};
	int n = sizeof(a) / sizeof(int);
	printArr(a, n);
	InsertSort(a, n);
	printArr(a, n);
}
void TestShellSort() {
	int a[] = { 12,214421,124,312,523,33,3,532,523,34,2,52,523,523,523,42,41,5,43,654,7,464,37,4652,4231,65,3245,423 };
	int n = sizeof(a) / sizeof(int);
	printArr(a, n);
	ShellSort(a, n);
	printArr(a, n);
}
void TestSelectSort() {
	int a[] = { 12,214421,124,312,523,33,3,532,523,34,2,52,523,523,523,42,41,5,43,654,7,464,37,4652,4231,65,3245,423 };
	int n = sizeof(a) / sizeof(int);
	printArr(a, n);
	SelectSort(a, n);
	printArr(a, n);
}
void TestHeapSort() {
	int a[] = { 12,214421,124,312,523,33,3,532,523,34,2,52,523,523,523,42,41,5,43,654,7,464,37,4652,4231,65,3245,423 };
	int n = sizeof(a) / sizeof(int);
	printArr(a, n);
	HeapSort(a, n);
	printArr(a, n);
}
void TestBubbleSort() {
	int a[] = { 12,214421,124,312,523,33,3,532,523,34,2,52,523,523,523,42,41,5,43,654,7,464,37,4652,4231,65,3245,423 };
	int n = sizeof(a) / sizeof(int);
	printArr(a, n);
	BubbleSort(a, n);
	printArr(a, n);
}
void TestQuickSort() {
	int a[] = { 12,214421,124,312,523,33,3,532,523,34,2,52,528,52773,4643523,42,41,5,43,654,7,464,37,4652,4231,65,3245,423 };
	int n = sizeof(a) / sizeof(int);
	printArr(a, n);
	QuickSort(a, 0,n-1);
	printArr(a, n);
}
int main() {
	
	//TestInsertSort();
	//TestShellSort();
	//TestSelectSort();
	//TestHeapSort();
	//TestBubbleSort();
	TestQuickSort();
	return 0;
}