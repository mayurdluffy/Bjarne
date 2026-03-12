//Counting element, given a value or a condition
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

//unary predicate
template<typename T>
bool IsEven(const T& num){
	return ((num % 2) == 0);
}

int main(){
	vector<int> vec{3, 7, -1, 8, 11, 23, -1};
     
	size_t cnt = count(vec.cbegin(), vec.cend(), -1);
	cout<<cnt<<endl;

	size_t evenCnt = count_if(vec.cbegin(), vec.cend(), IsEven<int>);
	cout<<evenCnt<<endl;

	return 0;
}