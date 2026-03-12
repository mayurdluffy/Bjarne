//Copy and remove opreations
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
	list<int> mylist{-1, 7, 9, 11, 3};
	vector<int> vec(mylist.size()*2);

	auto last_element = copy(mylist.cbegin(), mylist.cend(), vec.begin());
	//copying all multiples of three 
	copy_if(mylist.cbegin(), mylist.cend(), last_element, [](int num){return ((num % 3) == 0);});

	display(vec);

	//removing all 0s
	auto new_end = remove(vec.begin(), vec.end(), 0);
	vec.erase(new_end, vec.end()); //resizing 
	display(vec);

	//removing all the multiples of 3
	new_end = remove_if(vec.begin(), vec.end(), [](int num){return ((num % 3)==0);});
    vec.erase(new_end, vec.end());//resize
    display(vec);

	return 0;
}
