#include"Sort.h"



void printArr(int* a, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}


void Swap(int* pa, int* pb){
	int tem = *pa;
	*pa = *pb;
	*pb = tem;
}

//插入排序
void InsertSort(int* a, int n) {
	assert(a);
	for (int i = 0; i < n-1; i++) {
		int end=i;
		int tem = a[end + 1];
		while (end >= 0) {
			if (a[end] > tem) {
				a[end + 1] = a[end];
				--end;
			}
			else {
				break;
			}
		}
		a[end + 1] = tem;
	}
}



//希尔排序 O(N^1.3 ~ N^2)
void ShellSort(int* a,int n) {
	assert(a);
	int gap=n;
	//gap>1就相当于预排续，让数组接近有序
	//gap=1就相当于直接插入排序，保证有序
	while (gap > 1) {
		gap = gap / 3 + 1;//加一保证了gap最后一次一定是1；
		for (int i = 0; i < n - gap; i++) {
			int end = i;
			int tem = a[end + gap];
			while (end >= 0) {
				if (a[end] > tem) {
					a[end + gap] = a[end];
					end -= gap;
				}
				else {
					break;
				}
			}
			a[end + gap] = tem;
		}
		printArr(a, n);
	}
}

//时间复杂度O(N^2)
void SelectSort(int* a, int n) {
	assert(a);
	int begin = 0;
	int end = n - 1;
	while (begin < end) {
		//在[begin,end]之间找出最小数和最大数的下标
		int mini, maxi;
		mini = maxi = begin;
		for (int i = begin+1; i <= end; i++) {
			if (a[i] > a[maxi]) {
				maxi = i;
			}
			if (a[i] < a[mini]) {
				mini = i;
			}
		}
		//把最小值放到第一个位置  （升序）
		Swap(&a[begin], &a[mini]);
		//如果maxi和begin位置重叠，则maxi位置需要修正
		if (begin == maxi) {
			maxi = mini;
		}
		//把最大值放到end位置 一次处理两个值 可以让时间减少一半 
		Swap(&a[end], &a[maxi]);

		++begin;
		--end;
	}
}


//堆排序
//向下调整算法(升序建大堆)
void AdjustDown(int* a, int n, int root){
	int parent = root;
	int child = parent * 2 + 1;
	while (child<n) {
		if (child+1<n && a[child] < a[child + 1]) {
			child++;
		}
		if (a[child] > a[parent]) {
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else {
			break;
		}
	}
}
//时间复杂度O(N*lgN)
void HeapSort(int* a, int n){
	//建大堆
	//从最后一个非叶子节点开始从后往前遍历
	for (int i = (n - 1 - 1) / 2; i >=0 ; --i) {
		AdjustDown(a, n, i);
	}
	//把根节点和最后一个结点进行交换
	//交换完后再进行向下调整算法恢复成堆
	int end = n - 1;
	while (end) {
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
}
//冒泡排序
//时间复杂度O(N^2)
void BubbleSort(int* a, int n){
	int end = n - 1;
	int exchange = 0;
	while (end) {
		for (int i = 1; i < n; i++) {
			if (a[i - 1] > a[i]) {
				Swap(&a[i - 1], &a[i]);
				exchange = 1;
			}
		}
		if (exchange == 0) {
			break;
		}
		end--;
	}
	
}




//三数取中
int GetMidIndex(int *a,int begin,int end){
	int mid = (begin + end) / 2;
	if (a[begin] < a[mid]) {
		if (a[mid] < a[end]) {
			return mid;
		}
		else if (a[begin]>a[end]) {
			return begin;
		}
		else {
			return end;
		}
	}
	//a[begin]>a[mid]
	else {
		if (a[mid] > a[end]) {
			return mid;
		}
		else if (a[begin]<a[end]) {
			return begin;
		}
		else {
			return end;
		}
	}
}
//左右指针法
int PartSort1(int* a, int begin, int end){
	int midindex = GetMidIndex(a, begin, end);
	Swap(&a[midindex],&a[end]);
	int keyindex = end;
	while (begin < end) {
		//begin找大
		while (begin<end && a[begin]<= a[keyindex]) {
			++begin;
		}
		//end找小
		while (begin<end && a[end] >= a[keyindex]) {
			--end;
		}
		//两边都找到大小 交换begin和end位置的数据
		Swap(&a[begin],&a[end]);
	}
	//begin和end相遇 交换相遇位置和key位置数据
	Swap(&a[begin], &a[keyindex]);
	//返回key最终位置的下标
	return begin;
}
//挖坑法
int PartSort2(int* a, int begin, int end) {
	int midindex = GetMidIndex(a, begin, end);
	Swap(&a[end], &a[midindex]);
	//坑
	int key = a[end];
	while (begin<end) {
		while (begin<end && a[begin] <= key) {
			++begin;
		}
		//左边找到比坑大的值 填到右边坑的位置 左边变成新的坑
		a[end] = a[begin];
		while (begin<end && a[end] >= key) {
			--end;
		}
		//右边找到比坑小的值 填到左边坑的位置 右边变成新的坑
		a[begin] = a[end];
	}
	a[begin] = key;
	return begin;
}
//前后指针法
int PartSort3(int* a, int begin, int end){
	int midindex = GetMidIndex(a, begin, end);
	int key = a[end];
	int cur = begin, prev = begin-1;
	while (cur<end) {
		//如果cur位置的值小于key的值 ++prev 再把cur位置的值和prev位置的值交换
		//如果大于或等于 则++cur prev不动
		//如果++prev以后prev位置的值和cur位置的值一样 则不交换（不影响结果）
		if (a[cur] < key && ++prev!=cur) {
			Swap(&a[cur], &a[prev]);
		}
			++cur;
		
	}
	//cur大于或等于end 跳出循环 此时prev的值还在小的数上 先++prev 再交换prev位置的值和key的值
	Swap(&a[++prev], &a[cur]);
	return prev;
}
void QuickSort(int* a, int left, int right){
	assert(a);
	if (left >= right) {
		return;
	}
	//优化让个数大于10的区间递归快速排序
	if (right - left + 1 > 10) {
		//先进行一次单趟排序 找到key的划分位置
		int div = PartSort3(a, left, right);
		//[left,div-1] div [div+1,right]
		QuickSort(a, left, div - 1);
		QuickSort(a, div + 1, right);
	}
	else {
		//小于等于10个以内的区间使用插入排序 不在递归减小代价
		InsertSort(a + left, right - left + 1);
	}
}

