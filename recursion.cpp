#include <iostream>
using namespace std;

// 호출시 n 1씩 증가
void recursion(int n){
	if(n > 2) return; // n 2까지 허용
	++n;
	
	// make indent
	for(int i=n; i>0; --i){
		cout << " ";
	}
	cout << "call   \tn: " << n << endl;
	
	recursion(n);

	// make indent 0 1 2
	for(int i=0; i<n; ++i){
		cout << " ";
	}
	cout << "return   \tn: " << n << endl;
}

int main(){
	recursion(0);
}