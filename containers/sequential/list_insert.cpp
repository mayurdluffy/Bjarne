#include<list>
#include<vector>
#include<iostream>

using namespace std;

template<typename T>
void DisplayContent(const T& container){
	for(auto element = container.cbegin(); element != container.cend(); element++)
		cout<<*element<<' ';
	cout<<endl;
}
int main(){

	list<int> ints{-101, 42};

	ints.push_back(10);
	ints.push_back(2022);
	ints.push_front(-11);
	ints.push_front(-23);

	DisplayContent(ints);
	return 0;
	
}