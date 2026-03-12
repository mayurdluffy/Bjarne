#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

void DisplayVector(const vector<int>& vector ){
	for(auto iter = vector.begin(); iter != vector.end();iter++)
		cout<<*iter<<' ';
	cout<<endl<<endl;
}
 
int  main(){

	vector<int> intVec1;
	intVec1.push_back(55);
	intVec1.push_back(24);
	intVec1.push_back(-89);
	intVec1.push_back(999);

    cout<<"Size of the vector is: "<<intVec1.size()<<endl;
	cout<<"First vector is: ";
	DisplayVector(intVec1);

    //Inserting element at a given position
    intVec1.insert(intVec1.begin(),-1);
    intVec1.insert(intVec1.end(),2,0);
    cout<<"First vector is: ";
    DisplayVector(intVec1);

    vector<int> intVec2;
    intVec2.insert(intVec2.begin(),intVec1.begin(),intVec1.begin()+2);
    cout<<"Second vector is: ";
    DisplayVector(intVec2);

    cout<<"Element at index 1 is: "<<intVec2.at(1)<<endl;

    intVec1.pop_back();
    cout<<"First vector after a pop_back call: ";
    DisplayVector(intVec1);
    
    return 0;

}