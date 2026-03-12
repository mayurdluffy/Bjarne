#include<list>
#include<vector>
#include<iostream>

using namespace std;

//binary predicate or functional objects
bool SortPredicate(const int& lhs, int& rhs){
	return (lhs>rhs);
}

template<typename T>
void DisplayContent(const T& container){
	for(auto elem = container.cbegin(); elem != container.cend(); elem++)
		cout<<*elem<<' ';
	cout<<endl;
}

int main(){

	list<int> ints{-1, 23, 57, -9, 83};

	ints.sort();
	DisplayContent(ints);

	ints.sort(SortPredicate);
	DisplayContent(ints);	
}