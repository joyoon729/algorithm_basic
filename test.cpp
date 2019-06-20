#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include "merge_sort.h"

#define MAX 10000000

/* 중복 제거 난수 생성
-----------------------------------------------*/
void random_number_generator(vector<int> &arr, int n){
	// srand(). seedrand : seed 값 넣기
	// time(NULL) 도 되지만, 
	// unsigned 로 캐스팅 하는것이 실행 속도 빨랐음
	srand((unsigned)time(NULL));
	for(int i=0; i<n; ++i){
		arr[i] = rand()%(n*2)+1; // 1부터 MAX*2까지 난수 생성
		// cout << arr[i] << endl;
		for(int j=0; j<i; ++j){
			// bool a = arr[i] == arr[j] && arr[j]!=-1 && arr[i]!=-1;
			// cout << a << endl;
			if(arr[i] == arr[j] && arr[j]!=-1 && arr[i]!=-1){
				--i;
				break;
			}
		}
	}
}

int main(){
	clock_t start, end;

	vector<int> arr;

	arr.resize(MAX,-1);
	// random_number_generator(arr, MAX);
	mergeS m(MAX,arr);
	start = clock();
	m.start_sort();
	end = clock();
	cout << "(" << MAX << ", " << m.operation_count << ")  ";
	cout << (double)(end-start) << "(ms)" << endl;

	// for(int i=1; i<=MAX; ++i){
	// 	arr.resize(i,-1);
	// 	random_number_generator(arr, i);
	// 	mergeS m(i,arr);
	// 	m.start_sort();
	// 	cout << "(" << i <<", "<< m.operation_count << ")" << endl;
	// }
}