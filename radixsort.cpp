#include <iostream>
#include <time.h>
#include <fstream>

using namespace std;

// A utility function to get maximum value in arr[]
int getMax(int arr[], int n)
{
	int mx = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > mx)
			mx = arr[i];
	return mx;
}

// A function to do counting sort of arr[] according to
// the digit represented by exp.
void countSort(int arr[], int n, int exp)
{
	int output[n]; // output array
	int i, count[10] = {0};

	// Store count of occurrences in count[]
	for (i = 0; i < n; i++)
		count[ (arr[i]/exp)%10 ]++;

	// Change count[i] so that count[i] now contains actual
	// position of this digit in output[]
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	// Build the output array
	for (i = n - 1; i >= 0; i--)
	{
		output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
		count[ (arr[i]/exp)%10 ]--;
	}

	// Copy the output array to arr[], so that arr[] now
	// contains sorted numbers according to current digit
	for (i = 0; i < n; i++)
		arr[i] = output[i];
}

// The main function to that sorts arr[] of size n using
// Radix Sort
void radixsort(int arr[], int n)
{
	// Find the maximum number to know number of digits
	int m = getMax(arr, n);

	// Do counting sort for every digit. Note that instead
	// of passing digit number, exp is passed. exp is 10^i
	// where i is current digit number
	for (int exp = 1; m/exp > 0; exp *= 10)
		countSort(arr, n, exp);
}

// A utility function to print an array
void print(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << "/n";
}


int main()
{
	int n;
	clock_t t;
	float temp;
	ofstream fs("radix.txt");
	for(int i=0;i<20;i++){
		n=n+5;
		cout << "n : " << n << endl;
		int A[n];
		for(int j=0;j<n;j++){
				A[j]=n-j;
		}
		//cout << "arreglo" << endl;
		//muestraCadena(n,A);
		t = clock();
		for(int i=0;i<100;i++){
			t = clock();
			radixsort(A, n);
			t = clock() - t;
			temp = (((float)t)/CLOCKS_PER_SEC) + temp;
		}
		fs << " n : " << n << " tiempo : " << temp/100 << endl;
		//muestraCadena(n,A);
		std::cout << "n : " << n <<  '\n';
		print(A,n);
	}
	fs.close();
	return 0;
}
