//Partitioning values and elements, given a condition
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

bool multiple_of_three(const int& num){
	return ((num % 3)==0);   //unary predicate
}

/*
3 -1 5 7 11 9 
3 9 5 7 11 -1 
3 9 -1 5 7 11 
*/
int main(){
	vector<int> vec{3, -1, 5, 7, 11, 9};
	vector<int> copy_vec(vec);
	display(vec);

	partition(vec.begin(), vec.end(), multiple_of_three);
	display(vec);
    
    stable_partition(copy_vec.begin(), copy_vec.end(), multiple_of_three);
    display(copy_vec);

	return 0;
}
