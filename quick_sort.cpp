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
	void sort();
	int partition();
};
void quickS::print(){
	for(int i : num){
		cout << i ;
		if(i==num.at(num.size()-1)) cout << endl;
	}
}
// pivot : 1/2 지점
void quickS::sort(){
	
}
int quickS::partition(){
	
}

void ssort(char arr[]){
	int i=0;
	while(arr[i]!='\0'){
		cout << arr[i];
		++i;
		cout << i << endl;
	}
}
/* main
----------------------------------------------------*/
int main(){
	vector<int> num;
	
	quickS q;
	q.print();
	
	
}
