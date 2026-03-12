//lambda expression for binary predicate
#include<vector>
#include<string>
#include<iostream>
#include<algorithm>

using namespace std;



int main(){
	vector<string> str{"Me", "you", "us", "We"};
	for_each(str.cbegin(), str.cend(), [](const string& str){cout<<str<<' ';});
	cout<<endl;

	//lambda function working as a binary predicate
	//implementation of CompareStringNoCase
	sort(str.begin(), str.end(), 
		[](const string& str1, const string& str2)->bool{
			string str1_lc, str2_lc;

			str1_lc.resize(str1.size());
			str2_lc.resize(str2.size());

			transform(str1.begin(), str1.end(), str1_lc.begin(), ::tolower);
			transform(str2.begin(), str2.end(), str2_lc.begin(), ::tolower);

			return (str1_lc < str2_lc);
		});

	for_each(str.cbegin(), str.cend(), [](const string& str){cout<<str<<' ';});

	return 0;
}