//Inserting elements in a sorted collection
#include<list>
#include<string>
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
me us we you 
1 1
me see see us we you 
*/
int main(){
	list<string> mylist{"me", "you", "we", "us"};
	mylist.sort();
	display(mylist);

	auto min_pos = lower_bound(mylist.begin(), mylist.end(), "see");
	auto max_pos = upper_bound(mylist.begin(), mylist.end(), "see");

	cout<<distance(mylist.begin(), min_pos)<<' '<<distance(mylist.begin(), max_pos)<<endl;

	mylist.insert(min_pos, "see");
	mylist.insert(max_pos, "see");
    display(mylist);

	return 0;
}
