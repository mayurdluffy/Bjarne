#include<map>
#include<iostream>

using namespace std;

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

	mapIntStr.insert(make_pair(3, "Three"));
	mapIntStr.insert(make_pair(-2, "Minus Two"));
	mapIntStr.insert(make_pair(1000, "Thousand"));
	mapIntStr.insert(make_pair(1000000, "One Million"));


	MMAP_INT_STR mmapIntStr(mapIntStr.begin(), mapIntStr.end());
	mmapIntStr.insert(make_pair(-1, "Minus One"));
	mmapIntStr.insert(make_pair(1000, "One Thousand"));


    DisplayContent(mmapIntStr);
    
    mmapIntStr.erase(1000);
    /*auto elem = mmapIntStr.find(1000);
    for(size_t i=0; i<=mmapIntStr.count(1000); i++){
    	mmapIntStr.erase(elem);
    	elem = mmapIntStr.find(1000);
    }*/
	
    DisplayContent(mmapIntStr);
    //cout<<mmapIntStr.count(1000);

	return 0; 
}