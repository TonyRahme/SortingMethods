#include <iostream>
#include <ctime>
using namespace std;
int partition(int *,int,int);
int median3(int*,int,int);
void quickSort(int *,int, int);
void displayArray(int*, int, int);
void swap(int *, int *);
void insertionSort(int *, int);
void mergeSort(int *, int *, int, int);
void merge(int*,int*,int,int,int);
void selectionSort(int *, int);
void mergeSort(int*a,int*aux,int lo, int hi)
{
	if(lo>=hi) return;
	int mid = (lo+hi)/2;
	mergeSort(a,aux,lo,mid);
	mergeSort(a,aux,mid+1,hi);
	merge(a,aux,lo,mid,hi);
}
void merge(int*a,int*aux,int lo, int mid, int hi)
{
	int i=lo, j=mid+1, k=lo;
	for(k;k<=hi;k++)
	{
		if(i>mid) a[k]=aux[j++];
		else if(j>hi) a[k]=aux[i++];
		else if(aux[i]>aux[j]) a[k]=aux[j++];
		else a[k]=aux[i++];
	}
}
void selectionSort(int *a, int N)
{
	int min;
	for(int i=0;i<N;i++)
	{
		min = i;
		for (int j=i+1;j<N;j++)
			if(a[j]<a[min])
				min=j;
		swap(&a[i],&a[min]);
	}
}
void insertionSort(int *a, int N)
{
	for(int i=1;i<N;i++)	
		for(int j=i;j>0;j--)
			if(a[j]>a[j-1])
				swap(&a[j],&a[j-1]);
			else break;
}
int median3(int *a, int lo, int hi)
{
	int center = (lo+hi)/2;
	if(a[lo]>a[center]) swap(&a[lo],&a[center]);
	if(a[center]>a[hi]) swap(&a[center],&a[hi]);
	if(a[lo]>a[hi]) swap(&a[lo],&a[hi]);
	return center;
}
int partition(int *a, int lo, int hi)
{
	int i=lo, j=hi, pivot=a[lo];
	while (true)
	{
		while(a[++i]<pivot) if(i==hi) break;
		while(a[--j]>pivot) if(j==lo) break;
		if (i<j)
		swap(&a[i],&a[j]);
		else
			break;
	}
	swap(&a[lo],&a[j]);
	return j;
}
void swap(int *x,int  *y)
{
	int tmp;
	tmp = *x; *x = *y; *y = tmp;
}
void quickSort(int *a,int lo,int hi)
{
	int median = median3(a,lo,hi);
	swap(&a[lo],&a[median]);
	displayArray(a,lo,hi);
	if(hi<=lo) return;
	int j = partition(a,lo,hi);
	quickSort(a,lo,j);
	quickSort(a,j+1,hi);
	displayArray(a,lo,hi);
}
void displayArray(int *a, int lo, int hi)
{
	for(int i=lo;i<=hi;i++)
		cout<<a[i]<<"\t";
	cout<<endl;
}

int main()
{
	srand(time(0));
	int a[10];
	cout<<"Enter numbers for array\n";
	for(int i=0;i<10;i++)
		a[i]=rand()%101;
	cout<<"Unsorted array is:\n";
	displayArray(a,0,9);
	cout<<"Step-by-step sorting:\n";
	insertionSort(a,10);
	displayArray(a,0,9);
	return 0;
}