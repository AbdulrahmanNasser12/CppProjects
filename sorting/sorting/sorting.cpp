
#include <iostream>
using namespace std;
void swap(int &x, int &y) {
	int bar = x;
	x = y;
	y = bar;
}
void print(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

}
/*
--------------------------------------------------------------
*/
//Quadratic sorting : time complexity -> n^2
                                          //Space complexity -> 1
										                       //in place 
// #1
//Selection Sorting
//Time complexity : best = n^2      avg = n^2      worst = n^2
//Space Complexity = 1
void SelectionSort(int arr[], int size) {
	for (int i = 0; i < size - 1; i++) {
		int temp;
		int	minIndx = i;
		for (int j = i + 1; j < size; j++) {
			if (arr[j] < arr[minIndx]) {
				minIndx = j;
			}
			swap(arr[minIndx], arr[i]);
		}
	}
}
/*
--------------------------------------------------------------
*/
// #2
//Bubble Sorting
//Time complexity : best = n      avg = n^2      worst = n^2
//Space Complexity = 1
void BubbleSort(int arr[], int size) {
	bool flag = false;
	int counter=0;
	for (int i = 0; i < size - 1;i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j + 1] < arr[j]){
				swap(arr[j], arr[j + 1]);
				flag = true;
			}
			counter++;
		}
		if (!flag)
			break;
	}
	cout << "# number of eterations " << counter << endl;
	
}
// This Flag and counter to show that bubble sort is a smart algorithm that if the array passed is already sorted the time complexity will be 
// big O of 1
/*
--------------------------------------------------------------
*/
// #3
//insertion Sorting
//Time complexity : best = n      avg = n^2      worst = n^2
//Space Complexity = 1
void InsertionSort(int arr[],int size) {
	for (int i = 1; i < size;i++) {
		int temp = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > temp) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j+1] = temp;
	}

}
                                         // With for loop
                                            /*void InsertionSort(int arr[], int size) {
	                                               for (int i = 1, j; i < size; i++) {
		                                               int temp = arr[i];
		                                               for (j = i; j > 0 && temp < arr[j - 1]; j--)
			                                               arr[j] = arr[j - 1];
                                                     	arr[j] = temp;
	                                               }
                                            }*/

/*
--------------------------------------------------------------
*/
/*
---------------------------------------------------------------------------------
---------------------------------------------------------------------------------
*/
//Sub-quadratic Sorting
                     // More space complexity less time complexity
/*
--------------------------------------------------------------
*/
// #1 
//Merge Sorting
//Time complexity : best = n * log n      avg = n * log n      worst = n * log n
//Space Complexity = n
 
//First Merge Function
//To colect divided arrays in one sorted array
void merge(int arr[] , int left , int right , int middle) { // Middle calc = l+(r-l)/2
	int i, j, k;
	int size1 = middle - left + 1;
	int size2 = right - middle;
	int *l = new int[size1]; // to alocate an array for the left sub array 
	int* r = new int[size2]; // to alocate an array for the right sub array 

	for (i = 0; i < size1;i++) {
		l[i] = arr[left + i];
	}
	for (j = 0; j < size2;j++) {
		r[j] = arr[middle + 1 + j];

	}

	i = j = 0;
	k = left;
	while (i<size1&&j<size2) {
		if (l[i]<=r[j]) {
			arr[k] = l[i];
			i++;
		}
		else
		{
			arr[k] = r[j];
			j++;
		}
		
		k++;
	}
	while (i < size1) {
		arr[k] = l[i];
		i++;
		k++;
	}
	while (j < size2) {
		arr[k] = r[j];
		j++;
		k++;
	}
}
//Seconde Merge Sort Function
//To divide the unsorted array into smaller arrays step by step and finally it will be divided into many single items
void MergeSort(int arr[],int left, int right) {
	if (left < right) {
		int middle = left + (right - left) / 2;
		MergeSort(arr, left, middle);
		MergeSort(arr, middle + 1, right);
		merge(arr, left, right, middle);
	}
}
/*
--------------------------------------------------------------
*/
// #2 
//Quick Sorting
//Time complexity : best = n * log n      avg = n * log n      worst = n^2
//Space Complexity = n * log n

//First Partition Function : put the pivot element in the correct place that all elements on his left is smaller
//and all elements on his right is greater and then return the pivot location(index) in the array after partition operation
// !!!! NOTE : There are many ways to emplement the partition function with many algorithms the most important thing
//and the common perpous of all of them is to put the pivot element in the correct place as i mentioned before and return its location
//I will eplement the algorithm that doctor used in this code
int partition(int arr[], int left, int right) {
    int temp = arr[left];
	int i = left;
	for (int j = left + 1; j <= right; j++) {
		if (arr[j] <= temp) {
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[left], arr[i]);
	return i;
}

//Seconde quick Sort function
//To partition the left sub array then the right sub array of the pivot element
void QuickSort(int arr[],int left,int right) {
	if (right > left) {
		int pivotLocation = partition(arr, left, right);
		QuickSort(arr, left, pivotLocation - 1);
		QuickSort(arr, pivotLocation + 1, right);
	}
}
/*
--------------------------------------------------------------
*/
// #3
// Shell Sorting
//Time complexity : best = n * log n      avg = n^1.5      worst = n^2     !!!!!!!! < Not sure about worst and best case > 
//Space Complexity = 1
//Uses the insertion sort to sort the divided arays
void ShellSort(int arr [],int size) {
	for (int gap = size / 2; gap >0;gap/=2) {
		for (int i = gap; i < size;i++) {
			int temp = arr[i];
			int j;
			for ( j = i; j >= gap && arr[j - gap] > temp;j-=gap) {
				arr[j] = arr[j - gap];

			}
			arr[j] = temp;
		}


	}

}
/*
--------------------------------------------------------------
*/
//#4 
//Heap Sorting
//Depends on binary tree (complete tree)
//Time complexity = n * log n
//Space complexity = 1
void heapify(int arr[], int size, int i) {
	int l = i * 2 + 1;
	int r = i * 2 + 2;
	int max = i;
	if (l<size && arr[l]>arr[max])
		max = l;
	if (r<size && arr[r]>arr[max])
		max = r;
	if (max != i) {
		swap(arr[max], arr[i]);
		heapify(arr, size, max);

	}


}


void BuildHeap(int arr[], int size) {
	for (int i = size / 2-1; i >= 0; i--) {
		heapify(arr, size, i);
	}

}

void HeapSort(int arr[],int size){
	BuildHeap(arr, size);
	for (int i = size - 1; i >= 0; i--) {
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}


int main()
{
	int arr2[] = { 1,2,3,4,5,6 };
	int arr1[6] = { 50,60,40,10,30,20 };
	print(arr1, 6);
	/*SelectionSort(arr1, 6);
	print(arr1, 6);

	BubbleSort(arr1, 6);
	print(arr1, 6);

	InsertionSort(arr1,6);
	print(arr1, 6);

	MergeSort(arr1, 0, 5);
	print(arr1, 6);

	QuickSort(arr1, 0, 5);
	print(arr1, 6);

	ShellSort(arr1, 6);
	print(arr1, 6);*/
	HeapSort(arr1, 6);
	print(arr1, 6);
}
