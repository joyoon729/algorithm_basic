#include <iostream>
#include <climits>
using namespace std;

// 호출시 n 1씩 증가
void recursion(signed int n){
	int a=1;
	int b=1;
	if(n > 2) return; // n 2까지 허용
	++n;
	
	// make indent
	for(int i=n; i>0; --i){
		cout << " ";
	}
	cout << "call   \tn: " << &n << "\ta:" << &a << "\tb:" << &b <<endl;
	
	recursion(n);

	// make indent 0 1 2
	for(int i=0; i<n; ++i){
		cout << " ";
	}
	cout << "return   \tn: " << &n << "\ta:" << &a << "\tb:" << &b <<endl;
}

// '리턴 주소값' 자리에 68 바이트나 차지하는 이유는?
int main(){
	int c=0;
	recursion(c);
}
