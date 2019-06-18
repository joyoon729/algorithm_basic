/*
insertion sort

시간 복잡도
최선 : O(n) (이동없이 1번씩 비교만 하고 끝)
최악 : O(n^2) (입력자료가 역순일경우 n^2 까지 올라간다)

장점 : 레코드 수가 적을수록 타 정렬보다 유리할 수 있음
단점 : O(n^2)
----------------------------------------------------*/

#include <iostream>
#include <vector>
using namespace std;


class insertionS{
private:
	int n;
	vector<int> num;
public:
	// 테스트 벡터 생성
	insertionS(){
		// [5 3 8 4 9 1 6 2 7 0]
		num.push_back(5);num.push_back(3);num.push_back(8);
		num.push_back(4);num.push_back(9);num.push_back(1);
		num.push_back(6);num.push_back(2);num.push_back(7);
		num.push_back(0);
		n = num.size();
	}
	void start_sort();
	void sort();
	void print();
};
// 타 sorting 알고리즘과 같은 메소드 동작을 위해 넣어뒀음
void insertionS::start_sort(){
	sort();
}
void insertionS::sort(){
	int i,j,key;
	for(int i=1; i<n; ++i){
		key = num[i];
		for(j=i-1; j>=0 && num[j]>key; --j){
			num[j+1] = num[j];
		}
		num[j+1] = key;
	}
}
void insertionS::print(){
	for(int i=0; i<n; ++i){
		cout << num[i] << " ";
		if(i==n-1) cout << endl;
	}
}

int main(){
	insertionS i;
	i.print();
	i.start_sort();
	i.print();
	return 0;
}