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
	// 벡터 크기가 2이상 ex) [0][1] --> 크기 2, end-start = 1
	// cout << "start: "<<start<<" end: "<<end<<endl;
	if(end-start>0){
		int pivot = partition(start, end);
		cout << "pivot : "<<pivot << endl;
		// print();
		sort(start,pivot-1);
		sort(pivot+1,end);
	}
	cout << "end sort" << endl;	
}
// pivot : 1/2 지점
int quickS::partition(int start, int end){
	int pivot = (end-start)/2;
	while(start <= end){
		cout << num.at(start) << " "<< num.at(pivot) << endl;
		while(start <= end && num.at(start)<=num.at(pivot)){
			cout << "2";
			++start;
		}
		cout << num.at(end) << " "<< num.at(pivot) << endl;
		while(start <= end && num.at(end)>num.at(pivot)){
			// cout << "3";
			--end;
		}
		if(start <= end){
			// cout << "start: "<<start<<" end: "<<end<<endl;
			swap(num.at(start),num.at(end));
		}else{
			return start;
		}
	}
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
