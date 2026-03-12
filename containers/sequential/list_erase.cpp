#include<list>
#include <vector>
# include<iostream>
 
using namespace std;

template<typename T>
void DisplayContent(const T& container){
	for(auto element = container.cbegin(); element != container.cend(); element++)
		cout<<*element<<' ';
	cout<<endl;
}

int main(){

	list<int> ints{4, -3, 7, 2021};

	//store an iterator obtained in using insert
	auto val = ints.insert(ints.begin(), 2);

	DisplayContent(ints);

	//erasing element stored in val
	ints.erase(val);
	DisplayContent(ints);

	//cout<<*val<<endl;
	return 0;
}