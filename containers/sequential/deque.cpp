#include<deque>
#include<algorithm>
#include<iostream>

using namespace std;

template<typename T>
void DisplayDeque(const deque<T> deq){
	for(auto iter = deq.begin(); iter != deq.end(); iter++)
		cout<<*iter<<' ';
	cout<<endl;
}

int main(){

	deque<int> intDeque;
	
	intDeque.push_back(23);
	intDeque.push_back(-999);
	intDeque.push_front(11);
	intDeque.push_front(-1);

	cout<<"The deque is: ";
	DisplayDeque(intDeque);

	intDeque.pop_front();
	intDeque.pop_back();

	cout<<"The deque after removing one element from the front and from the end: ";
	DisplayDeque(intDeque);

	//distance(intDeque.begin(),intDeque.end()-1);

	return 0;
}