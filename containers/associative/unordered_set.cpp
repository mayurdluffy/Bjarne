#include<unordered_set>
#include<iostream>

using namespace std;

template<typename T>
void DisplayContent(const T& cont){
	for(auto elem = cont.cbegin(); elem != cont.end(); elem++)
		cout<<*elem<<' ';
	cout<<endl;

	cout<<cont.size()<<endl;
	cout<<cont.bucket_count()<<endl;
	cout<<cont.max_load_factor()<<endl;
	cout<<cont.load_factor()<<endl;
}

typedef unordered_set<int> UNSETINT;

int main(){
 
	UNSETINT unsetInts{-1, 5, 9, -11, 31};

	DisplayContent(unsetInts);

	unsetInts.insert(-23);
	DisplayContent(unsetInts);

	unsetInts.erase(-11);
	DisplayContent(unsetInts);

	return 0;
}
