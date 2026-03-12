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

typedef map<int, string> MAP_INT_STR;
typedef multimap<int, string> MMAP_INT_STR;

int main(){

	MAP_INT_STR mapIntStr;

	//inserting a key-value pair using value_type
	mapIntStr.insert(MAP_INT_STR::value_type(3, "Three"));

	//inserting a key-value pair using funtion make_pair()
	mapIntStr.insert(make_pair(-2, "Minus Two"));

	//insert a pair object directly
	mapIntStr.insert(pair<int, string>(1000, "One Thousand"));

	//using a array like syntax for inserting a key-value pair
	mapIntStr[100000] = "One Million";

	DisplayContent(mapIntStr);
	
	MMAP_INT_STR mmapIntStr;
	mmapIntStr.insert(mapIntStr.begin(), mapIntStr.end());

	mmapIntStr.insert(pair<int, string>(1000, "Thousand"));
	DisplayContent(mmapIntStr);
	
	cout<<mmapIntStr.count(1000)<<endl;

	return 0; 
}