/*
시간 복잡도
평균 : O(nlogn)
최악 : O(n^2)
----------------------------------------------------*/

#include <iostream>
#include <vector>
using namespace std;

/* swap
----------------------------------------------------*/
void swap(int& a, int& b){
	int tmp;
	tmp = b;
	b = a;
	a = tmp;
}

/* quick Sort class
----------------------------------------------------*/
class quickS{
private:
	int n;
	vector<int> num;
public:
	// 테스트 벡터 생성
	quickS(){
		// [5 3 8 4 9 1 6 2 7 0]
		num.push_back(5);num.push_back(3);num.push_back(8);
		num.push_back(4);num.push_back(9);num.push_back(1);
		num.push_back(6);num.push_back(2);num.push_back(7);
		num.push_back(0);
		n = num.size();
	}
	quickS(int n, vector<int> num):n(n), num(num){}
	void print();
	void start_sort();
	void sort(int start, int end);
	int partition(int start, int end);
};
void quickS::print(){
	for(int i : num){
		cout << i ;
		if(i==num.at(num.size()-1)) cout << endl;
	}
}
void quickS::start_sort(){
	int start = 0;
	int end = n-1;

	sort(start, end); 
}
void quickS::sort(int start, int end){
	int pivot;
	if(end-start>0){
		pivot = partition(start,end);
		sort(start,pivot-1);
		sort(pivot+1,end);
	}
}
// pivot : 첫번째 인덱스
int quickS::partition(int start, int end){
	int pivot = start;
	int o_start = start;
	int o_end = end;
	while(start < end){
		while(num.at(start)<=num.at(pivot) && start < o_end){
			++start;
		}
		while(num.at(end)>num.at(pivot) && end > o_start){
			--end;
		}
		if(start < end){
			swap(num.at(start),num.at(end));
		}else{
			swap(num.at(pivot), num.at(end));
			pivot = end;
			return pivot;
		}
	}
	pivot = end;
	return pivot;
}

/* main
----------------------------------------------------*/
int main(){
	vector<int> num;

	quickS q;
	q.print();
	q.start_sort();
	q.print();
}
