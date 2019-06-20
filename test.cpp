#include <iostream>
#include "./merge_sort.h"

int main(){
	mergeS m;
	m.print();
	m.start_sort();
	m.print();
	cout << m.operation_count << endl;
}