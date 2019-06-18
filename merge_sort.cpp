/*
merge sort
시간 복잡도
O(nlogn)
----------------------------------------------------*/

#include <iostream>
#include <vector>
using namespace std;

/* merge Sort class
----------------------------------------------------*/
class mergeS{
private:
	int n;
	vector<int> num;
	vector<int> sorted; // 임시 배열
public:
	// 테스트 벡터 생성
	mergeS(){
		// [5 3 8 4 9 1 6 2 7 0]
		num.push_back(5);num.push_back(3);num.push_back(8);
		num.push_back(4);num.push_back(9);num.push_back(1);
		num.push_back(6);num.push_back(2);num.push_back(7);
		num.push_back(0);
		n = num.size();
		sorted.resize(n,-1);
		// print(sorted);
	}
	void start_sort();
	void sort(int left, int right);
	void merge(int left, int mid, int right);
	void print();
	void print(vector<int> v);
};
void mergeS::start_sort(){
	int left = 0;
	int right = n-1;
	sort(left, right);
}
void mergeS::sort(int left, int right){
	if(left<right){
		int mid = (left+right)/2;
		sort(left, mid);
		sort(mid+1,right);
		merge(left,mid,right);
	}
}
void mergeS::merge(int left, int mid, int right){
	int i=left, j=mid+1, k=left;
	while(i<=mid && j<=right){
		if(num[i]<=num[j]){
			sorted[k] = num[i];
			++k; ++i;
		}else{
			sorted[k] = num[j];
			++k; ++j;
		}
	}
	if(i>mid){
		while(j<=right){
			sorted[k] = num[j];
			++k; ++j;			
		}
	}
	if(j>right){
		while(i<=mid){
			sorted[k] = num[i];
			++k; ++i;			
		}

	}
	for(int index=left; index<right+1; ++index){
		num[index] = sorted[index];
	}
}
void mergeS::print(){
	for(int i=0; i<num.size(); ++i){
		cout << num[i] << " ";
		if(i==num.size()-1) cout << endl;
	}
}
void mergeS::print(vector<int> v){
	for(int i=0; i<v.size(); ++i){
		cout << v[i] << " ";
		if(i==v.size()-1) cout << endl;
	}
}

/* main
----------------------------------------------------*/
int main(){
	mergeS m;
	m.print();
	m.start_sort();
	m.print();
	return 0;
}
