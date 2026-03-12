//Sorting and searching elements in sorted containers, erasing duplicates
#include<list>
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

template<typename T>
void display(const T& cont){
	for(auto iter = cont.cbegin(); iter != cont.cend(); iter++)
		cout<<*iter<<' ';
	cout<<endl;
}

/*
me us we you you 
String found
me us we you 
*/
int main(){
	vector<string> words{"me", "you", "we", "us"};
	
	words.push_back("you");
	sort(words.begin(), words.end());

	display(words);

	string str;
	cin>>str;

	bool str_found = binary_search(words.cbegin(), words.cend(), str);
	if(str_found)
		cout<<"String found"<<endl;
	else
		cout<<"String not found"<<endl;

	//adjacent removing duplicates
	auto new_end = unique(words.begin(), words.end());
	words.erase(new_end, words.end()); //resizing
	display(words);
	
	return 0;
}
