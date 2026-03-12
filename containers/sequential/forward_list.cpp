#include<forward_list>
#include<iostream>

using namespace std;

template<typename T>
void DisplayContent(const T& container){
	for(auto elem = container.cbegin(); elem != container.cend(); elem++)
		cout<<*elem<<' ';
	cout<<endl;
}

int main(){

	forward_list<int> frwdlist{3, 4, -1, 9, 31};
	frwdlist.push_front(0);

	DisplayContent(frwdlist);

	frwdlist.remove(9);
	frwdlist.sort();

	DisplayContent(frwdlist);
}