#pragma once
#include<stdio.h>
#include<stdlib.h>
#include <assert.h>
void Swap(int* pa, int* pb);
void printArr(int* a, int n);
void AdjustDown(int* a,int n,int root);

void InsertSort(int* a, int n);

void ShellSort(int* a, int n);

void SelectSort(int* a, int n);

void HeapSort(int* a,int n);

void BubbleSort(int* a, int n);


int GetMidIndex(int* a, int begin, int end);
int PartSort1(int* a, int begin, int end);
int PartSort2(int* a, int begin, int end);
int PartSort3(int* a, int begin, int end);
void QuickSort(int* a, int left,int right);

