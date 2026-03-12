//Initializing elements in a container to a specific value
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

int main(){
	vector<int> vec(3);

	//fill all the elements in the container with value -1
	fill(vec.begin(), vec.end(), 1);

	//resizing the vector to hold 6 elements
	vec.resize(6);

	//fill three elements starting at offset position 3 with 1
	fill_n(vec.begin() + 3, 3, -1);

	display(vec);

	return 0;
}
