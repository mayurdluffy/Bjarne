//Replacing values and elements, given a condition
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
8 8 8 5 5 5 
5 8 5 8 8 5 
8 8 8 8 8 8 
2 2 2 2 2 2 
*/
int main(){
	vector<int> vec(6);

	fill(vec.begin(), vec.begin()+3, 8);
	fill_n(vec.begin()+3, 3, 5);
	display(vec);

	//shuffle the container
	random_shuffle(vec.begin(), vec.end());
	display(vec);

	replace(vec.begin(), vec.end(), 5, 8);
	display(vec);

	replace_if(vec.begin(), vec.end(), [](int num){return ((num % 2)==0);}, 2);
	display(vec);

	return 0;
}
