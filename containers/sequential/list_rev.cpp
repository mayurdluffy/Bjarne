#include<list>
#include <vector>
# include<iostream>
 
using namespace std;

template<typename T>
void DisplayContent(const T& container){
	for(auto element = container.cbegin(); element != container.cend(); element++)
		cout<<*element<<' ';
	cout<<endl;
}

int main(){

	list<int> ints{0, 1, 2, 3, 4, 5};
	DisplayContent(ints);
    
    ints.reverse();
    DisplayContent(ints);
	return 0;
}