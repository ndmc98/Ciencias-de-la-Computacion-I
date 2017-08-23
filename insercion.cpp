#include <iostream>
#include <time.h>
#include <fstream>

using namespace std;

void inser(int a[], int N) {
  int i,j,temp;
  for(i=1;i<N;i++){
    temp = a[i];
    j=i-1;
    while ((a[j] > temp) && (j>=0)) {
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = temp;
  }
}

int main(int argc, char const *argv[]) {
  ofstream fs("insercion.txt");
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
		inser(A,n);
		t= clock() - t ;
		p[i]=((float)t)/CLOCKS_PER_SEC;
		fs << " n : " << n << " tiempo : " << ((float)t)/CLOCKS_PER_SEC << endl;
	}
	fs.close();
  return 0;
}
