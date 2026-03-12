#include<set>
#include<iostream>

using namespace std;

template<typename T>
struct SortDecending{
	bool operator()(const T& lhs, const T& rhs) const{
		return(lhs > rhs);
	}
};

template<typename T>
void DisplayContent(const T& container){
	for(auto elem = container.cbegin(); elem != container.cend(); elem++)
		cout<<*elem<<' ';
	cout<<endl;
}

int main(){

	set<int> setInts{-1, 5, 6, 8, -9};
	multiset<int> msetInts;

	msetInts.insert(setInts.begin(), setInts.end());

	DisplayContent(setInts);
	DisplayContent(msetInts);

	set<int, SortDecending<int>> setInts2{-1, 5, 6, 8, -9};
	multiset<int, SortDecending<int>> msetInts2;

	msetInts2.insert(setInts2.begin(), setInts2.end());

	DisplayContent(setInts2);
	DisplayContent(msetInts2); 


}