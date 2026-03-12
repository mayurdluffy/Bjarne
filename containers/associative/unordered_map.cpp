#include<unordered_map>
#include<iostream>

using namespace std;

template<typename T>
void DisplayContent(const T& cont){
	for(auto elem = cont.cbegin(); elem != cont.cend(); elem++)
		cout<<elem->first<<" -> "<<elem->second<<endl;
	cout<<endl;
}

void erasePair(unordered_map<int, string>& unmap, const int& key){
	auto elem = unmap.find(key);
	if(elem == unmap.cend())
		cout<<"key not found"<<endl;
	else
		unmap.erase(elem);
}

typedef unordered_map<int, string> UNMAP_INT_STR;

int main(){

	UNMAP_INT_STR unmapIntstr;

	unmapIntstr.insert(make_pair(1, "One"));
 	unmapIntstr.insert(make_pair(45, "Forty Five"));
 	unmapIntstr.insert(make_pair(1001, "Thousand One"));
 	unmapIntstr.insert(make_pair(-2, "Minus Two"));
 	unmapIntstr.insert(make_pair(-1000, "Minus One Thousand"));
	unmapIntstr.insert(make_pair(100, "One Hundred"));
	unmapIntstr.insert(make_pair(12, "Twelve"));
	unmapIntstr.insert(make_pair(-100, "Minus One Hundred"));

	DisplayContent(unmapIntstr);
    
    erasePair(unmapIntstr, -11);
    erasePair(unmapIntstr, 1001);

	DisplayContent(unmapIntstr);

	return 0;

}