#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;

void showData(double *,int,int);

void randData(double *,int,int);

void findRowSum(const double *,double *,int,int);

void findColSum(const double *,double *,int,int);

int main(){
	srand(time(0));
	const int N = 6, M = 8;
	double data[N][M] = {};
	double sum1[N] = {};
	double sum2[M] = {};
	double *dPtr = data[0];
	randData(dPtr,N,M);
	showData(dPtr,N,M);
	
	cout << "---------------------------------------------\n";
	
	findRowSum(dPtr,sum1,N,M);
	showData(sum1,N,1);
	
	cout << "---------------------------------------------\n";
	
	findColSum(dPtr,sum2,N,M); 
	showData(sum2,1,M);
}
void showData(double *arr, int rows, int cols){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout << fixed << setprecision(2) << *(arr + i * cols + j) << " ";
        }
        cout << endl;
    }
}

void randData(double *data, int N, int M)
{
	for (int i = 0; i < N * M; i++)
	{
		data[i] = rand() % 101 / 100.0;
	}
}


void findRowSum(const double *arr, double *sumArr, int rows, int cols){
    for(int i = 0; i < rows; i++){
        *(sumArr + i) = 0;
        for(int j = 0; j < cols; j++){
            *(sumArr + i) += *(arr + i * cols + j);
        }
    }
}

void findColSum(const double *arr, double *sumArr, int rows, int cols){
    for(int j = 0; j < cols; j++){
        *(sumArr + j) = 0;
        for(int i = 0; i < rows; i++){
            *(sumArr + j) += *(arr + i * cols + j);
        }
    }
}