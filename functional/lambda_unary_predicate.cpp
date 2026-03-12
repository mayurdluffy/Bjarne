//lambda expression for unary predicate
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;



int main(){
	vector<int> vec{-1, 4, 7, 8, -11, 13};
	for_each(vec.cbegin(), vec.cend(), [](const int num){cout<<num<<' ';});
	cout<<endl;
	
	int divisor = 2;
	auto element = find_if(vec.begin(), vec.end(), [divisor](int dividend){return ((dividend % divisor) == 0);});
    if(element != vec.end())
    	cout<<*element<<' '<<distance(vec.begin(), element)<<endl;

	return 0;
}