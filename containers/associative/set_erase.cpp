#include<set>
#include<iostream>

using namespace std;

template<typename T>
void DisplayContent(const T& container){
	for(auto elem = container.cbegin(); elem != container.cend(); elem++)
		cout<<*elem<<' ';
	cout<<endl;
}

typedef set<int> SETINT;
typedef multiset<int> MSETINT;


int main(){

	SETINT setInts{-1, 5, 6, 8, -9};
	MSETINT msetInts;

	msetInts.insert(setInts.begin(), setInts.end());
	msetInts.insert(5);

	DisplayContent(msetInts);

	msetInts.erase(5);
	DisplayContent(msetInts);	

	return 0; 


}