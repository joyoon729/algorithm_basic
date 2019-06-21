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

void sort(int *arr){
	void divide(int left, int right){
		if(left<right){
			int mid = (left+right)/2;
			divide(left, mid);
			divide(mid+1,right);
			merge(left,mid,right);
	}
	void merge(int left, int mid, int right){
		int i=left, j=mid+1, k=left;
		while(i<=mid && j<=right){
			if(num[i]<=num[j]){
				++operation_count;
				sorted[k] = num[i];
				++k; ++i;
			}else{
				++operation_count;
				sorted[k] = num[j];
				++k; ++j;
			}
		}
		if(i>mid){
			while(j<=right){
				++operation_count;
				sorted[k] = num[j];
				++k; ++j;			
			}
		}
		if(j>right){
			while(i<=mid){
				++operation_count;
				sorted[k] = num[i];
				++k; ++i;			
			}

		}
		for(int index=left; index<right+1; ++index){
			++operation_count;
			num[index] = sorted[index];
		}
	}
}

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
