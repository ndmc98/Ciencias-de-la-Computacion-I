#include <iostream>
#include <time.h>
#include <fstream>

using namespace std;

void burbuja (int a[], int N){
	int i,j,temp;
  	for (i=1; i<N; i++)
     	for(j=0; j<N-1; j++)
           if(a[j] > a[j+1]){
           	temp = a[j];
           	a[j] = a[j+1];
           	a[j+1] = temp;
		   }
}
int main(){
	ofstream fs("burbuja.txt");
	clock_t t;
	int n=0;
	int temp;
	clock_t p[20];
	for (int i = 0; i < 20; i++) {
		n=n+5;
		int A[n];
		//cout << endl;
		for(int j=0;j<n;j++){
			temp = n-j;
			A[j]=temp;
			//cout << A[j] << endl;
		}
		t= clock();
		burbuja(A,n);
		t= clock() - t ;
		p[i]=((float)t)/CLOCKS_PER_SEC;
		fs << " n : " << n << " tiempo : " << ((float)t)/CLOCKS_PER_SEC << endl;
	}
	fs.close();
}
