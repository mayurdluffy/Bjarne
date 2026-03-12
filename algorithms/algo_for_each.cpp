//Fetching element in a range using for_each
#include<vector>
#include <string>
#include<iostream>
#include<algorithm>

using namespace std;

//functor
/*template<typename T>
struct functor{
	int cnt;
	functor (): cnt(0) {}

	void opreator()(const T& num){
		++cnt;
		cout<<num<<" ";
	}
};*/

int main(){
	vector<int> vec{3, 7, -1, 8, 11, 23};

	for_each(vec.cbegin(), vec.cend(), [](int num){cout<<num<<' ';});
	//functor<int> func = for_each(vec.cbegin(), vec.cend(), functor<int>());
	cout<<endl;

	//cout<<func.cnt<<endl;
	string str{"for_each and strings"};
	int cnt = 0;
	for_each(str.cbegin(), str.cend(), [&cnt](char c){cout<<c; cnt++;});
	cout<<endl;

	cout<<&cnt<<endl; //0x61febc

	return 0;
}
