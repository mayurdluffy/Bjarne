//Searching for an element or a range in a collection
#include<list>
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

template<typename T>
void DisplayContent(const T& cont){
	for(auto iter = cont.cbegin(); iter != cont.cend(); iter++)
		cout<<*iter<<' ';
	cout<<endl;
}

//Sequence found starting from index 2
//Sequence found starting from index 6
int main(){
	list<int> mylist{-1, 8, 11}; //sequence
	vector<int> vec{3, 7, -1, 8, 11, 23, -1, -1, -1, 31};

    auto range = search(vec.cbegin(), vec.cend(),mylist.cbegin(), mylist.cend());
    if(range != vec.cend())
    	cout<<"Sequence found starting from index "<<distance(vec.cbegin(), range)<<endl;

    auto partial_range = search_n(vec.cbegin(), vec.cend(), 3, -1);
    if(partial_range != vec.cend())
    	cout<<"Sequence found starting from index "<<distance(vec.cbegin(), partial_range);

	return 0;
}