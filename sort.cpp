#include<iostream>
using namespace :: std;
//打印：a为数组名，length为数组长度，current为需要打印的字符个数
void print(int a[], int length, int current);


//直接插入排序
void insertSort(int a[], int length);

//以dk为增量，begin为起始元素的一次直接插入排序
void shellInsertSort(int a[], int length, int dk, int begin);
//希尔排序
void shellSort(int a[], int length);



//从数组a中，由下表是begin开始，找出最小的元素，返回其下标
int selectSort(int a[], int length, int begin);
//简单选择排序
void simpleSelectSort(int a[], int length);

//堆排序（小顶堆，最后排序规则结果是从头至尾，由大到小）
void heapSort(int a[], int length);
//调整堆
void down(int a[], int length,int last);
void up(int a[], int seq);
void swap(int a[], int m, int n);
//建立堆（小顶）
void buildHeap(int a[], int length);


//冒泡排序
void bubbleSort(int a[], int length);

//快速排序
void quickSort(int a[], int length);
//单趟快速排序（将begin位置的元素放到最终的位置）
void quickSort1(int a[], int begin, int end);

//归并排序
void merge2Sort(int a[], int b[], int length);
//合并两个序列
void merge(int a[], int b[], int i, int m, int n);


int main() {
	int a[] = { 1, 2, 5, 3, 4, 7, 8, 9, 6, 5 };
	int b[10]{ 0 };
	merge2Sort(a,b, 10);
	print(a, 10, 10);
	int k=0;
	cin >> k;
	return 0;
}
//打印：a为数组名，length为数组长度，current为需要打印的字符个数
void print(int a[], int length, int current) {
	for (int i = 0; i < current; i++)
	{
		cout << a[i] << ",";
	}
	cout << endl;
}
//直接插入排序
void insertSort(int a[], int length) {
	for (int i = 1; i < length; i++)
	{
		if (a[i] < a[i - 1]) {
			int x = a[i], j = i - 1;
			while (j >= 0 && a[j] > x) {
				a[j + 1] = a[j];
				j--;
			}
			a[j + 1] = x;
		}
		print(a, length, i);
	}
}

//以dk为增量，begin为起始元素的一次直接插入排序
void shellInsertSort(int a[], int length, int dk, int begin)
{
	for (int i = begin + dk; i < length; i += dk)
	{
		if (a[i] < a[i - dk])
		{
			int x = a[i], j = i - dk;
			while (j >= 0 && a[j]>x) {
				a[j + dk] = a[j];
				j -= dk;
			}
			a[j + dk] = x;
		}
	}
}
//希尔排序
void shellSort(int a[], int length) {
	int dk = length / 2;
	while (dk > 0) {
		for (int i = 0; i < dk; i++)
		{
			shellInsertSort(a, length, dk, i);
		}
		print(a, length, length);
		dk = dk / 2;
	}
}

//从数组a中，由下表是begin开始，找出最小的元素，返回其下标
int selectSort(int a[], int length, int begin)
{
	int min = begin;
	for (int i = begin; i < length; i++)
	{
		min = a[i] < a[min] ? i : min;
	}
	return min;
}
//简单选择排序
void simpleSelectSort(int a[], int length) {
	for (int i = 0; i < length; i++)
	{
		int min = selectSort(a, length, i);
		int tmp = a[min];
		a[min] = a[i];
		a[i] = tmp;
		print(a, length, i);
	}
}

//交换函数
void swap(int a[], int m, int n) {
	int tmp = a[m];
	a[m] = a[n];
	a[n] = tmp;
}

//下沉函数
void down(int a[], int last) 
{
	int i = 0, j = 2 * i + 1, tmp = a[0];
	while (j <= last)
	{
		if (j + 1 <= last && a[j + 1] < a[j])
			j++;
		if (tmp <= a[j])
			break;
		a[i] = a[j];
		a[j] = tmp;
		i = j; j = 2 * j + 1;
	}
}
//建立堆（小顶）
void buildHeap(int a[], int length) {
	for (int i = 1; i < length; i++)
	{
		up(a, i);
	}
}
//上浮函数
void up(int a[], int seq) 
{
	int tmp = a[seq];
	int j = seq, i = (seq - 1) / 2;
	while (i>=0 && a[i]>tmp)
	{
		a[j] = a[i];
		j = i;
		i = (i - 1) / 2;
	}
	a[j] = tmp;
}
//堆排序
void heapSort(int a[], int length) {
	int L = length;
	buildHeap(a, length);
	while (length>0)
	{
		swap(a, 0, length - 1);
		print(a, L, L);
		length--;
		down(a, length - 1);
	}
	return;
}

void bubbleSort(int a[], int length) {
	for (int i = length-1; i >0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (a[j]<a[j+1])
				swap(a, j, j + 1);
		}
		print(a, length, length);
	}
}

//快速排序
void quickSort(int a[], int length) {
	quickSort1(a, 0, length - 1);
}
//单趟快速排序（将begin位置的元素放到最终的位置）
void quickSort1(int a[], int begin, int end) {
	if (begin < end) 
	{
		int i = begin, j = end;
		int tmp = a[begin];
		while (i < j)
		{
			while (j > i && a[j] >= tmp)
			{
				j--;
			}
			if (j > i)
			{
				a[i] = a[j];
				i++;
			}
			while (i < j&&a[i] <= tmp) {
				i++;
			}
			if (i < j)
			{
				a[j] = a[i];
				j--;
			}
		}
		a[i] = tmp;
		quickSort1(a, begin, i - 1);
		quickSort1(a, i + 1, end);
	}
}


//归并排序
void merge2Sort(int a[], int b[], int length) {
	int k = 1;
	while (k<length)
	{
		int i = 0;
		for ( i; i+2*k -1 <length; i=i+2*k)
		{
			merge(a, b, i, i + k, i + 2 * k - 1);
		}
		if (i + k - 1 < length - 1) {
			merge(a, b, i, i + k, length - 1);
		}
		int *tmp = a;a = b;b = tmp;
		k = 2 * k;
	}
}
//合并两个序列
void merge(int a[], int b[], int i, int m, int n) 
{
	int k = i, j = m;
	while (k<=m-1&&j<=n)
	{
		if (a[k] <= a[j])
			b[i++] = a[k++];
		else
			b[i++] = a[j++];
	}
	if (j<=n)
		while (j <= n)	b[i++] = a[j++];
	else
		while (k<=m-1)	b[i++] = a[k++];
	
}