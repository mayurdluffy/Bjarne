//Performing transformation on a range using std:: transform()
#include<vector>
#include<deque>
#include<string>
#include<iostream>
#include<algorithm>
#include<functional>

using namespace std;

int main(){
	string str{"this is a test string"};

	string restr;
	restr.resize(str.size());

	transform(str.cbegin(), str.cend(), restr.begin(), ::toupper);
	cout<<restr<<endl;

	vector<int> vec1{-1, 23, 7, 11};
	vector<int> vec2(vec1.size(), -1);

	deque<int> result(vec1.size());

	transform(vec1.cbegin(), vec1.cend(), vec2.cbegin(), result.begin() , plus<int>());//binary function
	
	for(size_t i = 0; i < vec1.size(); i++)
		cout<<vec1[i]<<" + "<<vec2[i]<<" = "<<result[i]<<endl;

	return 0;
}
