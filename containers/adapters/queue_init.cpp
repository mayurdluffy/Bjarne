 #include <queue>
 #include <list>
 
 using namespace std;

//Note: you can change the intenal structure of a queue, stack or a priority queue 
// by default it is deque<T> but you can also change it to vector<T> or list<T>
 int main (){

    // A queue of integers
     queue <int> numsInQ;

    // A queue of doubles
    queue <double> dblsInQ;

     // A queue of doubles stored internally in a list
    queue <double, list <double>> dblsInQInList;

    // one queue created as a copy of another
    queue<int> copyQ(numsInQ);

    return 0;
 }