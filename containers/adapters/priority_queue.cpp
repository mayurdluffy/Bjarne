// CPP Program to demonstrate Priority Queue
#include <iostream>
#include <queue>
using namespace std;

void showpq(priority_queue<int> pq)
{
	priority_queue<int> q = pq;
	while (!q.empty()) {
		cout << '\t' << q.top();
		q.pop();
	}
	cout << '\n';
}

// Driver Code
int main()
{
	priority_queue<int> pq;
	pq.push(10);
	pq.push(30);
	pq.push(20);
	pq.push(5);
	pq.push(1);

	showpq(pq);

	//pq.size();
	//pq.top();

	pq.pop();
	showpq(pq);

	return 0;
}
