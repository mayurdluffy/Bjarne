#include<iostream>
#include<tuple>
#include<string>

using namespace std;

//We can access the tuple members using standard library function std::get
template<typename tupleType>
void DisplayTupleInfo(tupleType tuple){
	const int numMembers = tuple_size<tupleType>::value;
	cout << "Num elements in tuple: " << numMembers << endl;
	cout << "Last element value: " << get<numMembers - 1>(tuple) << endl;

}

/*std::tie in Line 31 demonstrates how the contents of a tuple can be unpacked
or copied into individual objects. We use std::ignore to instruct tie to ignore the
tuple members that were not of any interest to the application.*/

int main(){
    tuple<int, char, string> tuple1(make_tuple(101, 's', "Hello Tuple!"));
    DisplayTupleInfo(tuple1);

    auto tuple2(make_tuple(3.14, false));
    DisplayTupleInfo(tuple2);

    auto concatTuple(tuple_cat(tuple2, tuple1)); // contains tup2, tup1 members
    DisplayTupleInfo(concatTuple);

	double pi;
	string sentence;
	tie(pi, ignore, ignore, ignore, sentence) = concatTuple;
	cout << "Unpacked! Pi: " << pi << " and \"" << sentence << "\"" << endl;
	return 0;
}