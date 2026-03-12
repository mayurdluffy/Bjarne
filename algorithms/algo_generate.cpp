//Using std::generate() to initialize elements to a value generated at runtime
#include<list>
#include<ctime>
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

int main(){
	srand(time(NULL)); //seed random generator using time

	vector<int> vec(5);
	generate(vec.begin(), vec.end(), rand); //rand is the generator function

	display(vec);

	list<int> mylist(5);
	generate_n(mylist.begin(), 3, rand);

	display(mylist);
	
	return 0;
}
