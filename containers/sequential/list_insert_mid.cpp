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

	list<int> ints1;

	//inserting elements at the begining
	ints1.insert(ints1.begin(),2);
	ints1.insert(ints1.begin(),1);

	//inserting elemets at the end
	ints1.insert(ints1.end(),-23);
	ints1.insert(ints1.end(),8);

	list<int> ints2{-11,5,-7,22};

	list<int> ints3{ints1};
	ints3.insert(ints3.begin(),ints2.begin(),ints2.end());


	DisplayContent(ints3);
}