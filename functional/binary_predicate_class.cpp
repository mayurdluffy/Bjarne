//Class based implementation of a binary predicate
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

/*template<typename T>
class Multiply{
public:
	T operator()(const T& num1, const T& num2){
		return num1*num2;
	}
};*/

int main(){
	vector<int> vec1{-1, 5, 7, 8, -11, 13};
	for_each(vec1.cbegin(), vec1.cend(), [](const int num){cout<<num<<' ';});
	cout<<endl;
	
	vector<int> vec2(vec1.size(), -1);
	for_each(vec2.cbegin(), vec2.cend(), [](const int& num){cout<<num<<' ';});

	vector<int> result;
	result.resize(vec1.size());
	transform(vec1.begin(), vec1.end(), vec2.begin(), result.begin(), [](int num1, int num2)->int{return (num1 * num2);});
	cout<<endl;

	for_each(result.cbegin(), result.cend(), [](auto& num){cout<<num<<' ';});

	return 0;
}