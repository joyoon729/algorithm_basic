/*
binary search

[조건]
오름차순 정렬되어 있는 데이터에 대해서만 정상적으로 작동

[시간복잡도]
O(logn)
----------------------------------------------------*/

#include <iostream>
#include <cstdlib>
#include <ctime>

#define MAX 20

using namespace std;

/* 배열 arr 채우기
난수 생성 + 중복 제거
----------------------------------------------------*/
void gen_random(int *arr){
	srand((unsigned)time(NULL));
	for(int i=0; i<MAX; ++i){
		arr[i] = rand()%20+1;
		for(int j=0; j<i; ++j){
			if(arr[i] == arr[j]){
				--i;
				break;
			}
		}
	}
}

/* print
----------------------------------------------------*/
void print(int *arr){
	for(int i=0; i<MAX; ++i){
		cout << arr[i] << " ";
		if(i==MAX-1) cout << endl;
	}
}

/* main
----------------------------------------------------*/
int main(){
	int arr[MAX];

	gen_random(arr);
	print(arr);

	
	return 0;
}
