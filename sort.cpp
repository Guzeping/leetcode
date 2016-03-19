#include<iostream>
using namespace :: std;
//��ӡ��aΪ��������lengthΪ���鳤�ȣ�currentΪ��Ҫ��ӡ���ַ�����
void print(int a[], int length, int current);


//ֱ�Ӳ�������
void insertSort(int a[], int length);

//��dkΪ������beginΪ��ʼԪ�ص�һ��ֱ�Ӳ�������
void shellInsertSort(int a[], int length, int dk, int begin);
//ϣ������
void shellSort(int a[], int length);



//������a�У����±���begin��ʼ���ҳ���С��Ԫ�أ��������±�
int selectSort(int a[], int length, int begin);
//��ѡ������
void simpleSelectSort(int a[], int length);

//������С���ѣ��������������Ǵ�ͷ��β���ɴ�С��
void heapSort(int a[], int length);
//������
void down(int a[], int length,int last);
void up(int a[], int seq);
void swap(int a[], int m, int n);
//�����ѣ�С����
void buildHeap(int a[], int length);


//ð������
void bubbleSort(int a[], int length);

//��������
void quickSort(int a[], int length);
//���˿������򣨽�beginλ�õ�Ԫ�طŵ����յ�λ�ã�
void quickSort1(int a[], int begin, int end);

//�鲢����
void merge2Sort(int a[], int b[], int length);
//�ϲ���������
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
//��ӡ��aΪ��������lengthΪ���鳤�ȣ�currentΪ��Ҫ��ӡ���ַ�����
void print(int a[], int length, int current) {
	for (int i = 0; i < current; i++)
	{
		cout << a[i] << ",";
	}
	cout << endl;
}
//ֱ�Ӳ�������
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

//��dkΪ������beginΪ��ʼԪ�ص�һ��ֱ�Ӳ�������
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
//ϣ������
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

//������a�У����±���begin��ʼ���ҳ���С��Ԫ�أ��������±�
int selectSort(int a[], int length, int begin)
{
	int min = begin;
	for (int i = begin; i < length; i++)
	{
		min = a[i] < a[min] ? i : min;
	}
	return min;
}
//��ѡ������
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

//��������
void swap(int a[], int m, int n) {
	int tmp = a[m];
	a[m] = a[n];
	a[n] = tmp;
}

//�³�����
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
//�����ѣ�С����
void buildHeap(int a[], int length) {
	for (int i = 1; i < length; i++)
	{
		up(a, i);
	}
}
//�ϸ�����
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
//������
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

//��������
void quickSort(int a[], int length) {
	quickSort1(a, 0, length - 1);
}
//���˿������򣨽�beginλ�õ�Ԫ�طŵ����յ�λ�ã�
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


//�鲢����
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
//�ϲ���������
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