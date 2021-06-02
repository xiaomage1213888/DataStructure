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

//��������
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



//ϣ������ O(N^1.3 ~ N^2)
void ShellSort(int* a,int n) {
	assert(a);
	int gap=n;
	//gap>1���൱��Ԥ������������ӽ�����
	//gap=1���൱��ֱ�Ӳ������򣬱�֤����
	while (gap > 1) {
		gap = gap / 3 + 1;//��һ��֤��gap���һ��һ����1��
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

//ʱ�临�Ӷ�O(N^2)
void SelectSort(int* a, int n) {
	assert(a);
	int begin = 0;
	int end = n - 1;
	while (begin < end) {
		//��[begin,end]֮���ҳ���С������������±�
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
		//����Сֵ�ŵ���һ��λ��  ������
		Swap(&a[begin], &a[mini]);
		//���maxi��beginλ���ص�����maxiλ����Ҫ����
		if (begin == maxi) {
			maxi = mini;
		}
		//�����ֵ�ŵ�endλ�� һ�δ�������ֵ ������ʱ�����һ�� 
		Swap(&a[end], &a[maxi]);

		++begin;
		--end;
	}
}


//������
//���µ����㷨(���򽨴��)
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
//ʱ�临�Ӷ�O(N*lgN)
void HeapSort(int* a, int n){
	//�����
	//�����һ����Ҷ�ӽڵ㿪ʼ�Ӻ���ǰ����
	for (int i = (n - 1 - 1) / 2; i >=0 ; --i) {
		AdjustDown(a, n, i);
	}
	//�Ѹ��ڵ�����һ�������н���
	//��������ٽ������µ����㷨�ָ��ɶ�
	int end = n - 1;
	while (end) {
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
}
//ð������
//ʱ�临�Ӷ�O(N^2)
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




//����ȡ��
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
//����ָ�뷨
int PartSort1(int* a, int begin, int end){
	int midindex = GetMidIndex(a, begin, end);
	Swap(&a[midindex],&a[end]);
	int keyindex = end;
	while (begin < end) {
		//begin�Ҵ�
		while (begin<end && a[begin]<= a[keyindex]) {
			++begin;
		}
		//end��С
		while (begin<end && a[end] >= a[keyindex]) {
			--end;
		}
		//���߶��ҵ���С ����begin��endλ�õ�����
		Swap(&a[begin],&a[end]);
	}
	//begin��end���� ��������λ�ú�keyλ������
	Swap(&a[begin], &a[keyindex]);
	//����key����λ�õ��±�
	return begin;
}
//�ڿӷ�
int PartSort2(int* a, int begin, int end) {
	int midindex = GetMidIndex(a, begin, end);
	Swap(&a[end], &a[midindex]);
	//��
	int key = a[end];
	while (begin<end) {
		while (begin<end && a[begin] <= key) {
			++begin;
		}
		//����ҵ��ȿӴ��ֵ ��ұ߿ӵ�λ�� ��߱���µĿ�
		a[end] = a[begin];
		while (begin<end && a[end] >= key) {
			--end;
		}
		//�ұ��ҵ��ȿ�С��ֵ ���߿ӵ�λ�� �ұ߱���µĿ�
		a[begin] = a[end];
	}
	a[begin] = key;
	return begin;
}
//ǰ��ָ�뷨
int PartSort3(int* a, int begin, int end){
	int midindex = GetMidIndex(a, begin, end);
	int key = a[end];
	int cur = begin, prev = begin-1;
	while (cur<end) {
		//���curλ�õ�ֵС��key��ֵ ++prev �ٰ�curλ�õ�ֵ��prevλ�õ�ֵ����
		//������ڻ���� ��++cur prev����
		//���++prev�Ժ�prevλ�õ�ֵ��curλ�õ�ֵһ�� �򲻽�������Ӱ������
		if (a[cur] < key && ++prev!=cur) {
			Swap(&a[cur], &a[prev]);
		}
			++cur;
		
	}
	//cur���ڻ����end ����ѭ�� ��ʱprev��ֵ����С������ ��++prev �ٽ���prevλ�õ�ֵ��key��ֵ
	Swap(&a[++prev], &a[cur]);
	return prev;
}
void QuickSort(int* a, int left, int right){
	assert(a);
	if (left >= right) {
		return;
	}
	//�Ż��ø�������10������ݹ��������
	if (right - left + 1 > 10) {
		//�Ƚ���һ�ε������� �ҵ�key�Ļ���λ��
		int div = PartSort3(a, left, right);
		//[left,div-1] div [div+1,right]
		QuickSort(a, left, div - 1);
		QuickSort(a, div + 1, right);
	}
	else {
		//С�ڵ���10�����ڵ�����ʹ�ò������� ���ڵݹ��С����
		InsertSort(a + left, right - left + 1);
	}
}

