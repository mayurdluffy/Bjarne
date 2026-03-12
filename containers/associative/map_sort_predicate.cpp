#include<map>
#include<iostream>

using namespace std;

struct SortPredicate{
	bool operator()(const int& key1, const int& key2){
		return(key1 > key2);
	}
};

template<typename T>
void DisplayContent(const T& cont){
	for(auto elem = cont.cbegin(); elem != cont.cend(); elem++)
		cout<<elem->first<<" -> "<<elem->second<<endl;
	cout<<endl;
}

typedef map<int, string, SortPredicate> MAP_INT_STR;



int main(){

	MAP_INT_STR mapIntStr;

	mapIntStr.insert(make_pair(3, "Three"));
	mapIntStr.insert(make_pair(-2, "Minus Two"));
	mapIntStr.insert(make_pair(1000, "Thousand"));
	mapIntStr.insert(make_pair(1000000, "One Million"));

    DisplayContent(mapIntStr);
    
	return 0; 
}