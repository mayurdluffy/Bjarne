////Finding elements, given a value or a condition
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

int main(){
	vector<int> vec{3, 7, -1, 8, 11, 23};
    
    int num;
    cin>>num;

	auto element = find(vec.cbegin(), vec.cend(), num);
	if(element != vec.cend())
		cout<<*element<<" found at index "<<distance(vec.cbegin(), element)<<endl;
	else
		cout<<"Element not found"<<endl;

	//finding the first even element in the vector
	auto evenNum = find_if(vec.cbegin(), vec.cend(), [](int num){return ((num % 2) == 0);});
	if(evenNum != vec.cend())
		cout<<*evenNum<<" found at index "<<distance(vec.cbegin(), evenNum)<<endl;
	
	//Note that the find_if() takes a unary predicate, and return a pointer to the first element
	//for which unary prediacte return true
	return 0;
}