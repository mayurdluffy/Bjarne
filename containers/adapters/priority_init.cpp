#include <queue>
#include <functional>

using namespace std;

//Note: by default priority queue in stl implements a max heap but you can create
// a min heap using priority_queue<<int>, deque<int>, greater<int>>

//further note that greater<int> is written in <functional>
//so it must be included ...
 int main (){

    // Priority queue of int sorted using std::less <> (default)
    priority_queue <int> numsInPrioQ;

    // A priority queue of doubles
    priority_queue <double> dblsInPrioQ;

    // A priority queue of integers sorted using std::greater <>
    priority_queue <int, deque <int>, greater<int>> numsInDescendingQ;

     // a priority queue created as a copy of another
    priority_queue <int> copyQ(numsInPrioQ);

    return 0;
}