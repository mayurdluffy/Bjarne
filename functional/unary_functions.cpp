//Unary functions in function objects (functors)
#include<list>
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;
//unary function
void DisplayContent(const int& element){
	cout<<element<<' ';
}

//struct version of a unary function
/*struct DisplayContent{
	void opreator()(const int& element) const{
		cout<<element<<' ';
	}
};*/

int main(){
	vector<int> vec{-1, 5, 3, 7, 11, 8, 21};
	for_each(vec.cbegin(), vec.cend(), DisplayContent);

	return 0;
}