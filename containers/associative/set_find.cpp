#include<set>
#include<iostream>

using namespace std;

template<typename T>
void DisplayContent(const T& container){
	for(auto elem = container.cbegin(); elem != container.cend(); elem++)
		cout<<*elem<<' ';
	cout<<endl;
}

int findPos(const set<int>& set, const int& val){
	int pos =-1;
	for(auto elem = set.cbegin(); elem != set.cend(); elem++){
		pos++;
		if(*elem == val)
			break;
	}
	return pos;
}

int main(){

	set<int> setInts{-1, 3, 5, 7, -11};

	DisplayContent(setInts);

	auto elem = setInts.find(5);
    if(elem != setInts.end())
    	cout<<findPos(setInts, 5)<<endl;
    else
    	cout<<"Not found"<<endl;

    return 0;

}