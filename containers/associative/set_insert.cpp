#include<set>
#include<iostream>

using namespace std;

template<typename T>
void DisplayContent(const T& container){
	for(auto elem = container.cbegin(); elem != container.cend(); elem++)
		cout<<*elem<<' ';
	cout<<endl;
}


int main(){

	set<int> setInts{7, 9, -13, 31, -11};

    //duplicating -13;
    setInts.insert(-13);
    DisplayContent(setInts);

    multiset<int> msetInts;
	msetInts.insert(setInts.begin(), setInts.end());

	//duplicating -13
	msetInts.insert(-13);
	DisplayContent(msetInts);

	cout<<msetInts.count(-13)<<endl;

	return 0;
}