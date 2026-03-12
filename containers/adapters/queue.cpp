// CPP code to illustrate Queue in
// Standard Template Library (STL)
#include <iostream>
#include <queue>

using namespace std;

// Print the queue
void showq(queue<int> que)
{
	queue<int> q = que;
	while (!q.empty()) {
		cout<< q.front()<<' ';
		q.pop();
	}
	cout<<endl;
}

// Driver Code
int main()
{
	queue<int> myqueue;
	myqueue.push(10);
	myqueue.push(20);
	myqueue.push(30);

	showq(myqueue);

    //myqueue.size();
	//myqueue.front();
	//myqueue.back();

	myqueue.pop();
	showq(myqueue);

	return 0;
}
