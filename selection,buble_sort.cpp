#include <iostream>
#include <array>
using namespace std;

/* 공통 함수 (swap)
----------------------------------------------------*/
void swap(int &a, int &b){
	int tmp;
	tmp = b;
	b = a;
	a = tmp;
}

/* select Sort class
----------------------------------------------------*/
class selectS{
private:
	int n;
	array<int,1000> num;
public:
	selectS(int n,array<int,1000>num):n(n),num(num){}
	void sort();
	void print();
};
void selectS::sort(){
	for(int i=0; i<n; ++i){
		for(int j=i+1; j<n; ++j){
			if(num[j]<num[i]) swap(num[j], num[i]);
		}
	}
	print();
}
void selectS::print(){
	for(int i=0; i<n; ++i){
		cout << num[i];
		if(i==n-1) cout << endl;
	}
}

/* bubble Sort class
----------------------------------------------------*/
class bubbleS{
private:
	int n;
	array<int,1000> num;
public:
	bubbleS(int n,array<int,1000>num):n(n),num(num){}
	void sort();
	void print();
};
void bubbleS::sort(){
	for(int i=0; i<n-1; ++i){
		for(int j=i+1; j<n; ++j){
			if(num[j]<num[i]) swap(num[j], num[i]);
		}
	}
	print();
}
void bubbleS::print(){
	for(int i=0; i<n; ++i){
		cout << num[i] << endl;
		// if(i==n-1) cout << endl;
	}
}

/* main
----------------------------------------------------*/
int main(){
	int n;
	array<int,1000> num;
	cin >> n;

	for(int i=0; i<n; ++i){
		cin >> num[i];
	}
	// selectS(n,num).sort();
	bubbleS(n,num).sort();
}