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

	vector<int> integers(5,0);
	vector<int> intVec{1,9,-23, 2021};
	vector<int> copyVector(intVec);
	vector<int> partialCopyVector(intVec.begin(),intVec.end()-1);

	cout<<"First vector is: ";
	DisplayVector(integers);
	cout<<"Second vector is: ";
	DisplayVector(intVec);
	cout<<"copyVector is: ";
	DisplayVector(copyVector);
	cout<<"partialCopyVector is: ";
	DisplayVector(partialCopyVector);
    
    return 0;

}