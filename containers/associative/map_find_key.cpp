#include<map>
#include<iostream>

using namespace std;


template<typename Key>
struct ReverseSort{
	bool operator()(const Key& key1, const Key& key2){
		return (key1 > key2);
	}
};

template<typename T>
void DisplayContent(const T& cont){
	for(auto elem = cont.cbegin(); elem != cont.cend(); elem++)
		cout<<elem->first<<" -> "<<elem->second<<endl;
	cout<<endl;
}

void findKey(const map<int, string>& map, const int& key){
	auto elem = map.find(key);
	if(elem != map.end())
		cout<<"key found"<<endl;
	else
		cout<<"key not found"<<endl;
}

typedef map<int, string> MAP_INT_STR;
typedef map<int, string, ReverseSort<int>> MAP_INT_STR_REV;


int main(){

	MAP_INT_STR mapIntStr;

	mapIntStr.insert(make_pair(3, "Three"));
	mapIntStr.insert(make_pair(-2, "Minus Two"));
	mapIntStr.insert(make_pair(1000, "Thousand"));
	mapIntStr.insert(make_pair(1000000, "One Million"));

	DisplayContent(mapIntStr);

	MAP_INT_STR_REV mapIntStrRev(mapIntStr.begin(), mapIntStr.end());
	mapIntStrRev.insert(make_pair(-1, "Minus One"));

    DisplayContent(mapIntStrRev);

    findKey(mapIntStr, 1000000);

	return 0; 
}