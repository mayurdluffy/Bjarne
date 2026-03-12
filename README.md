# Ultimate C++ STL Guide for Interview Preparation

A comprehensive guide covering all C++ STL concepts for DSA problem solving and interview preparation.

---

## Table of Contents
1. [Sequential Containers](#1-sequential-containers)
2. [Container Adapters](#2-container-adapters)
3. [Associative Containers](#3-associative-containers)
4. [STL Algorithms](#4-stl-algorithms)
5. [Strings](#5-strings)
6. [Templates](#6-templates)
7. [Functional Programming](#7-functional-programming)
8. [Utilities](#8-utilities)
9. [Quick Reference Cheat Sheet](#9-quick-reference-cheat-sheet)

---

## 1. Sequential Containers

### Overview Flow Chart
```
┌─────────────────────────────────────────────────────────────────┐
│                    SEQUENTIAL CONTAINERS                        │
├─────────────────┬─────────────────┬─────────────────┬───────────┤
│    vector       │      deque      │      list       │forward_list│
│ [■■■■■■■■■■■■■■]    │ [■ front ■ end]│ [■ ↔ ■ ↔ ■]    │[■ → ■ → ■] │
│ Random access   │ Fast insert/    │ Bidirectional   │ Single     │
│ Fast end ops    │ delete at both  │ Fast insert/    │ Linked     │
│                 │ ends            │ delete anywhere  │            │
└─────────────────┴─────────────────┴─────────────────┴───────────┘
```

### 1.1 vector - Dynamic Array

**When to use:** Default choice for sequential data. Random access needed. Fast iteration.

```cpp
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// Initialization methods
vector<int> v1;                    // Empty vector
vector<int> v2(5);                 // 5 elements, initialized to 0
vector<int> v3(5, 10);             // 5 elements, all = 10
vector<int> v4{1, 2, 3, 4, 5};     // Initializer list
vector<int> v5(v4);                // Copy constructor
vector<int> v6(v4.begin(), v4.end()); // Range copy

// Common operations
v.push_back(10);      // Add element at end - O(1) amortized
v.pop_back();         // Remove last element - O(1)
v.size();             // Number of elements
v.capacity();         // Allocated storage capacity
v.resize(n);          // Resize to n elements
v.reserve(n);         // Reserve space for n elements

// Accessing elements
v[0];                 // No bounds check (undefined if out of range)
v.at(0);              // Bounds check (throws out_of_range)
v.front();            // First element
v.back();             // Last element

// Iterators
for (auto it = v.begin(); it != v.end(); ++it) { }
for (int x : v) { }   // Range-based for loop

// Insert and erase (at end is fast, middle is slow)
v.insert(v.begin() + 2, 100);  // Insert at index 2 - O(n)
v.erase(v.begin() + 2);        // Erase at index 2 - O(n)
```

### 1.2 deque - Double-Ended Queue

**When to use:** Need fast insert/delete at both front and back. Random access needed.

```cpp
#include <deque>
using namespace std;

deque<int> dq;

// Operations at both ends - O(1)
dq.push_front(10);    // Insert at front
dq.push_back(20);     // Insert at back
dq.pop_front();       // Remove from front
dq.pop_back();        // Remove from back

// Random access - O(1)
dq[0];
dq.at(0);
dq.front();
dq.back();
```

### 1.3 list - Doubly Linked List

**When to use:** Frequent insert/delete in middle. Bidirectional traversal.

```cpp
#include <list>
using namespace std;

list<int> lst;

// Insert at both ends - O(1)
lst.push_front(10);
lst.push_back(20);

// Insert anywhere - O(1) if you have iterator
auto it = lst.begin();
++it;  // Move to second position
lst.insert(it, 15);  // Insert 15 before it

// Remove elements
lst.remove(15);     // Remove all elements equal to 15
lst.remove_if([](int x){ return x < 0; }); // Remove by condition

// List specific operations (not in vector)
lst.sort();         // Sort - O(n log n)
lst.reverse();       // Reverse - O(n)
lst.unique();       // Remove consecutive duplicates

// Splice - move elements between lists O(1)
list<int> lst2;
lst2.splice(lst2.begin(), lst, lst.begin(), lst.end());
```

### 1.4 forward_list - Singly Linked List

**When to use:** Memory-constrained environments. Only need forward traversal.

```cpp
#include <forward_list>
using namespace std;

forward_list<int> flst;

// Only front operations - O(1)
flst.push_front(10);
flst.pop_front();

// Insert after iterator - O(1)
auto it = flst.before_begin();  // Before first element
flst.insert_after(it, 20);       // Insert after it

// List specific
flst.sort();
flst.remove(10);
flst.remove_if([](int x){ return x < 0; });
```

### Container Choice Decision Tree

```
                    Need random access?
                          │
              ┌───────────┴───────────┐
              │ Yes                  │ No
              ▼                       ▼
        Need insert/           Frequent middle
        delete at front?        insertions?
              │                       │
      ┌───────┴───────┐       ┌───────┴───────┐
      │Yes            │No     │Yes            │No
      ▼               ▼       ▼               ▼
    deque          vector    list       forward_list
```

---

## 2. Container Adapters

### Overview
```
┌─────────────────────────────────────────────────────────────────┐
│                      CONTAINER ADAPTERS                         │
│                   (Restricted interfaces)                       │
├─────────────────┬─────────────────┬─────────────────────────────┤
│      STACK      │      QUEUE      │       PRIORITY_QUEUE       │
│   LIFO (Last    │   FIFO (First  │    Max-heap (by default)    │
│   In First Out) │   In First Out)│                             │
│                 │                 │  ┌─────┐                    │
│  ┌─────┐        │  ┌─────┐        │  │ 30  │ ← max element     │
│  │ 30  │ ←top   │  │ 10  │ ←front │  ├─────┤                    │
│  ├─────┤        │  ├─────┤        │  │ 20  │                    │
│  │ 20  │        │  │ 20  │        │  ├─────┤                    │
│  ├─────┤        │  ├─────┤        │  │ 10  │                    │
│  │ 10  │        │  │ 30  │ ←back  │  └─────┘                    │
│  └─────┘        │  └─────┘        │                             │
└─────────────────┴─────────────────┴─────────────────────────────┘
```

### 2.1 stack

**When to use:** LIFO operations. DFS, undo mechanisms, expression evaluation.

```cpp
#include <stack>
using namespace std;

// Default: uses deque internally
stack<int> s;

// Can specify container
stack<int, vector<int>> svec;  // Using vector
stack<int, list<int>> slist;   // Using list

// Operations - O(1)
s.push(10);      // Add to top
s.top();         // Access top element
s.pop();         // Remove top (doesn't return value)
s.empty();       // Check if empty
s.size();        // Number of elements
```

### 2.2 queue

**When to use:** FIFO operations. BFS, task scheduling, level-order traversal.

```cpp
#include <queue>
using namespace std;

queue<int> q;

// Default: uses deque
queue<int, list<int>> qlist;

// Operations - O(1)
q.push(10);      // Add to back (enqueue)
q.front();       // Access front element
q.back();        // Access back element
q.pop();         // Remove front (dequeue)
q.empty();
q.size();
```

### 2.3 priority_queue

**When to use:** Need max/min element quickly. Top-k problems, Dijkstra's algorithm.

```cpp
#include <queue>
using namespace std;

// Default: max-heap using vector
priority_queue<int> pq;

// Min-heap (greater comparator)
priority_queue<int, vector<int>, greater<int>> minHeap;

// Custom comparator for max-heap of custom objects
struct Compare {
    bool operator()(const Person& a, const Person& b) {
        return a.age < b.age;  // For max-heap: return true if a has lower priority
    }
};
priority_queue<Person, vector<Person>, Compare> pq;

// Operations - O(log n) for push/pop, O(1) for top
pq.push(10);
pq.top();      // Maximum element
pq.pop();      // Remove max element

// User-defined min-heap example
priority_queue<int, vector<int>, greater<int>> minpq;
minpq.push(5); minpq.push(2); minpq.push(8);
cout << minpq.top();  // Output: 2
```

---

## 3. Associative Containers

### Overview
```
┌─────────────────────────────────────────────────────────────────┐
│                    ASSOCIATIVE CONTAINERS                       │
├───────────────────────────┬─────────────────────────────────────┤
│      ORDERED              │        UNORDERED                    │
│  (Balanced Tree - O(log n))│      (Hash Table - O(1) avg)       │
├───────────────────────────┼─────────────────────────────────────┤
│  set, multiset           │    unordered_set, unordered_map      │
│  map, multimap          │    unordered_multiset, unordered_multimap│
└───────────────────────────┴─────────────────────────────────────┘

┌──────────────────────────────────────────────────────────────────┐
│                    CONTAINER COMPARISON                          │
├──────────────┬──────────────┬──────────────┬─────────────────────┤
│   set        │  multiset    │    map       │     multimap       │
├──────────────┼──────────────┼──────────────┼─────────────────────┤
│ Unique keys  │ Duplicate    │ Key-value    │ Duplicate keys     │
│ Sorted order │ keys         │ pairs        │ allowed            │
│   {1,2,3}   │ {1,1,2,3}    │ {1:"one"}    │ {1:"a", 1:"b"}     │
└──────────────┴──────────────┴──────────────┴─────────────────────┘
```

### 3.1 set / unordered_set

**When to use:** Need sorted unique elements. Fast lookup needed.

```cpp
#include <set>
using namespace std;

set<int> s;                     // Sorted, unique elements
multiset<int> ms;               // Sorted, duplicates allowed

// Insert - O(log n) for set, O(1) avg for unordered_set
s.insert(10);
s.insert(20);
s.insert(10);  // Ignored (duplicate)

// Find - O(log n) for set, O(1) avg for unordered_set
auto it = s.find(10);
if (it != s.end()) { /* found */ }

// Count
s.count(10);       // 0 or 1 for set, any number for multiset

// Erase
s.erase(10);       // Erase by value
s.erase(it);       // Erase by iterator

// Range operations
auto range = s.equal_range(10);  // pair of iterators
```

### 3.2 unordered_set

**When to use:** Fast lookup, order doesn't matter. Average O(1) operations.

```cpp
#include <unordered_set>
using namespace std;

unordered_set<string> us;

// Insert - O(1) average
us.insert("apple");
us.insert("banana");

// Find - O(1) average
auto it = us.find("apple");

// Load factor control
us.reserve(100);   // Reserve space for 100 elements
us.max_load_factor(0.7);  // Set max load factor
```

### 3.3 map / unordered_map

**When to use:** Key-value storage with fast lookup. Dictionary-like data.

```cpp
#include <map>
using namespace std;

map<string, int> m;              // Sorted by key
multimap<string, int> mm;        // Sorted, duplicate keys

// Insert - O(log n)
m.insert(make_pair("apple", 5));
m.insert({"banana", 3});
m["cherry"] = 10;                // Also inserts if not exists

// Access - O(log n) for map, O(1) avg for unordered_map
cout << m["apple"];              // Returns value or inserts default

// Safe access
if (m.count("apple")) {
    cout << m["apple"];
}

// Find
auto it = m.find("apple");
if (it != m.end()) {
    cout << it->first << " -> " << it->second;
}

// Erase
m.erase("apple");
m.erase(it);

// Custom comparator (reverse order)
struct ReverseSort {
    bool operator()(const string& a, const string& b) const {
        return a > b;
    }
};
map<string, int, ReverseSort> revMap;
```

### 3.4 unordered_map

**When to use:** Fast key-value lookup. Order irrelevant. Average O(1).

```cpp
#include <unordered_map>
using namespace std;

unordered_map<int, string> um;

// Insert
um[1] = "One";
um.insert({2, "Two"});
um.insert(make_pair(3, "Three"));

// Find - O(1) average
auto it = um.find(1);
if (it != um.end()) {
    cout << it->second;
}

// Iterate
for (const auto& [key, value] : um) {
    cout << key << " -> " << value;
}

// Count occurrences
um.count(key);       // Always 0 or 1 for unordered_map
```

### Container Selection Guide

```
                         Need key-value pairs?
                                  │
                    ┌─────────────┴─────────────┐
                    │ Yes                      │ No
                    ▼                           ▼
              Need sorted?                Need unique keys?
                    │                           │
        ┌───────────┴───────────┐     ┌─────────┴─────────┐
        │Yes                    │No    │Yes               │No
        ▼                       ▼      ▼                  ▼
       map               unordered_map  set          unordered_set

        Need duplicates?            Need duplicates?
              │                           │
      ┌───────┴───────┐           ┌───────┴───────┐
      ▼               ▼           ▼               ▼
    multimap      unordered_    multiset      unordered_
                  multimap                       multiset
```

---

## 4. STL Algorithms

### Overview Flow Chart
```
┌─────────────────────────────────────────────────────────────────┐
│                      STL ALGORITHMS                             │
├─────────────────┬─────────────────┬───────────────────────────┤
│    MUTATING     │    NON-MUTATING │    BINARY SEARCH           │
│  (Modify range) │  (Read only)   │    (On sorted ranges)      │
├─────────────────┼─────────────────┼───────────────────────────┤
│ transform       │ for_each        │ binary_search             │
│ copy/copy_if    │ find/find_if    │ lower_bound               │
│ remove/remove_if│ count/count_if  │ upper_bound               │
│ replace         │ all_of/any_of   │ equal_range               │
│ fill            │ none_of         │                           │
│ generate        │ search_n        │                           │
│ sort            │                 │                           │
│ partition       │                 │                           │
│ unique          │                 │                           │
└─────────────────┴─────────────────┴───────────────────────────┘
```

### 4.1 Search Algorithms

```cpp
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v{1, 3, 5, 7, 9, 11};

// find - O(n) - Find first occurrence
auto it = find(v.begin(), v.end(), 5);

// find_if - Find first element satisfying predicate
auto it = find_if(v.begin(), v.end(), [](int x){ return x > 5; });

// find_if_not - First element NOT satisfying
auto it = find_if_not(v.begin(), v.end(), [](int x){ return x < 0; });

// count - Count occurrences
int cnt = count(v.begin(), v.end(), 5);
int cnt = count_if(v.begin(), v.end(), [](int x){ return x % 2 == 0; });

// search_n - Find n consecutive occurrences
auto it = search_n(v.begin(), v.end(), 2, 5);  // Find two 5s in a row
```

### 4.2 Transform & Modify

```cpp
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;

vector<int> v1{1, 2, 3, 4};
vector<int> v2(4), v3(4);

// transform - Apply function to range (unary or binary)
transform(v1.begin(), v1.end(), v2.begin(), [](int x){ return x * 2; });
// v2 = {2, 4, 6, 8}

// Binary transform (combine two ranges)
transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), plus<int>());
// v3 = {3, 6, 9, 12}

// copy / copy_if
vector<int> dest;
copy(v1.begin(), v1.end(), back_inserter(dest));  // Copy all
copy_if(v1.begin(), v1.end(), back_inserter(dest), [](int x){ return x > 2; });

// remove / remove_if - Move elements to be kept to front
auto it = remove(v.begin(), v.end(), 5);  // Remove all 5s
v.erase(it, v.end());  // Actually remove from container

auto it = remove_if(v.begin(), v.end(), [](int x){ return x < 0; });
v.erase(it, v.end());

// replace
replace(v.begin(), v.end(), 5, 10);  // Replace all 5s with 10s
replace_if(v.begin(), v.end(), [](int x){ return x < 0; }, 0);

// fill / generate
fill(v.begin(), v.end(), 0);  // Fill with 0
generate(v.begin(), v.end(), [i=0]() mutable { return i++; });
```

### 4.3 Sorting & Related

```cpp
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

vector<int> v{3, 1, 4, 1, 5, 9, 2, 6};

// sort - O(n log n)
sort(v.begin(), v.end());           // Ascending
sort(v.begin(), v.end(), greater<int>());  // Descending
sort(v.begin(), v.end(), [](int a, int b){ return a > b; });

// stable_sort - Maintains relative order of equal elements
stable_sort(v.begin(), v.end());

// partial_sort - Sort first n elements
partial_sort(v.begin(), v.begin() + 3, v.end());  // Top 3 in order

// nth_element - Partition around nth element
nth_element(v.begin(), v.begin() + 3, v.end());  // Element at index 3 is correct

// is_sorted / is_sorted_until
bool sorted = is_sorted(v.begin(), v.end());
auto it = is_sorted_until(v.begin(), v.end());

// Binary search on sorted ranges - O(log n)
bool found = binary_search(v.begin(), v.end(), 5);

// lower_bound / upper_bound
auto low = lower_bound(v.begin(), v.end(), 5);   // First >= 5
auto high = upper_bound(v.begin(), v.end(), 5); // First > 5

// equal_range - Both bounds
auto range = equal_range(v.begin(), v.end(), 5);
```

### 4.4 Partition Operations

```cpp
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v{1, 2, 3, 4, 5, 6};

// partition - Partition based on predicate
auto it = partition(v.begin(), v.end(), [](int x){ return x % 2 == 0; });
// it points to first element of second partition

// stable_partition - Maintain relative order
stable_partition(v.begin(), v.end(), [](int x){ return x % 2 == 0; });

// is_partitioned / partition_point
bool partitioned = is_partitioned(v.begin(), v.end(), [](int x){ return x % 2 == 0; });
auto pp = partition_point(v.begin(), v.end(), [](int x){ return x % 2 == 0; });

// partition_copy - Partition into two containers
vector<int> even, odd;
partition_copy(v.begin(), v.end(), back_inserter(even), back_inserter(odd),
               [](int x){ return x % 2 == 0; });
```

### 4.5 Set Operations

```cpp
#include <algorithm>
#include <vector>
using namespace std;

vector<int> a{1, 2, 3, 4, 5};
vector<int> b{4, 5, 6, 7, 8};

// set_union - All unique elements from both
vector<int> result;
set_union(a.begin(), a.end(), b.begin(), b.end(), back_inserter(result));
// result = {1, 2, 3, 4, 5, 6, 7, 8}

// set_intersection - Common elements
vector<int> result;
set_intersection(a.begin(), a.end(), b.begin(), b.end(), back_inserter(result));
// result = {4, 5}

// set_difference - Elements in a but not in b
vector<int> result;
set_difference(a.begin(), a.end(), b.begin(), b.end(), back_inserter(result));
// result = {1, 2, 3}

// set_symmetric_difference - Elements in either but not both
vector<int> result;
set_symmetric_difference(a.begin(), a.end(), b.begin(), b.end(), back_inserter(result));
// result = {1, 2, 3, 6, 7, 8}

// includes - Check if one set is subset of another
bool result = includes(a.begin(), a.end(), b.begin(), b.end());
```

### 4.6 Heap Operations

```cpp
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v{3, 1, 4, 1, 5, 9};

// make_heap - Convert to heap O(n)
make_heap(v.begin(), v.end());
// v[0] is now maximum

// push_heap - Add element to heap
v.push_back(10);
push_heap(v.begin(), v.end());

// pop_heap - Move max to end
pop_heap(v.begin(), v.end());
v.pop_back();  // Remove max

// is_heap / is_heap_until
bool isHeap = is_heap(v.begin(), v.end());
auto it = is_heap_until(v.begin(), v.end());

// sort_heap - Sort heap (destroys heap property)
sort_heap(v.begin(), v.end());  // Result is sorted descending!
```

---

## 5. Strings

### Overview
```cpp
#include <string>
using namespace std;

// Creation
string s1;                    // Empty
string s2 = "Hello";          // From C-string
string s3("World");           // From C-string
string s4(5, 'a');           // 5 'a's: "aaaaa"
string s5 = s2;              // Copy
string s6 = s2 + " " + s3;   // Concatenation

// Common operations
s.length();                  // Size
s.size();
s.empty();                   // Check if empty
s.append(" text");           // Append
s += " more";                // Append operator

// Access
s[0];                        // No bounds check
s.at(0);                     // Bounds check

// Search
s.find("ell");              // Find substring, returns position or npos
s.rfind("ell");             // Find from end
s.find_first_of("aeiou");   // Find first vowel
s.find_last_of("aeiou");    // Find last vowel

// Substring
string sub = s.substr(1, 3);  // From position 1, length 3
string sub = s.substr(1);      // From position 1 to end

// Modification
s.insert(1, "XX");           // Insert at position
s.erase(1, 2);               // Erase from position, count
s.replace(1, 3, "YY");       // Replace from position, count

// Case conversion
transform(s.begin(), s.end(), s.begin(), ::toupper);
transform(s.begin(), s.end(), s.begin(), ::tolower);
```

### string_view (C++17) - Lightweight String Reference

```cpp
#include <string_view>
using namespace std;

// string_view - Non-owning reference to string data
string str = "Hello World";
string_view sv(str.c_str(), 5);  // "Hello" (no null termination needed)

// Advantages: No copy, no allocation, very fast
// Use when: Just reading, not modifying, don't need null-terminated

string_view sv = "Hello";   // From literal (C++17 adds null terminator)

// Operations (similar to string, but no modifying operations)
sv.length();
sv.empty();
sv.substr(1, 3);           // Returns string_view
sv.find("ell");
sv.remove_prefix(1);       // "ello"
sv.remove_suffix(2);       // "ell"

// Caution: Don't use after original string is modified/destroyed!
```

---

## 6. Templates

### 6.1 Function Templates

```cpp
#include <iostream>
using namespace std;

// Generic function - works with any type
template<typename T>
T getMax(T a, T b) {
    return (a > b) ? a : b;
}

// Multiple template parameters
template<typename T1, typename T2>
T1 getMax(T1 a, T2 b) {
    return (a > b) ? a : b;
}

// Default template parameters
template<typename T = int>
T getDefault() {
    return T();
}

// Usage
cout << getMax(3, 5);           // int
cout << getMax(3.14, 2.71);     // double
cout << getMax('a', 'z');       // char
```

### 6.2 Class Templates

```cpp
#include <iostream>
using namespace std;

// Template class with default parameters
template<typename T1 = int, typename T2 = double>
class Pair {
private:
    T1 first;
    T2 second;
public:
    Pair(T1 f, T2 s) : first(f), second(s) {}

    T1 getFirst() const { return first; }
    T2 getSecond() const { return second; }
};

// Usage
Pair<> p1(10, 3.14);           // Uses defaults: int, double
Pair<double, string> p2(3.14, "PI");

// Template class with member function defined outside
template<typename T>
class Container {
private:
    T data;
public:
    Container(T d);
    T getData();
};

template<typename T>
Container<T>::Container(T d) : data(d) {}

template<typename T>
T Container<T>::getData() { return data; }
```

### 6.3 Variable Templates (C++14)

```cpp
#include <iostream>
using namespace std;

// Variable template
template<typename T>
constexpr T pi = T(3.1415926535897932385);

// Specialization for different types
template<>
constexpr float pi<float> = 3.14159f;

template<>
constexpr long double pi<long double> = 3.1415926535897932385L;

int main() {
    cout << pi<int>;        // 3
    cout << pi<double>;     // 3.14159...
    cout << pi<float>;      // 3.14159
}
```

### 6.4 Template Specialization

```cpp
#include <iostream>
using namespace std;

// Primary template
template<typename T>
class Storage {
    T value;
public:
    Storage(T v) : value(v) {}
    void print() { cout << "General: " << value << endl; }
};

// Full specialization for bool
template<>
class Storage<bool> {
    bool value;
public:
    Storage(bool v) : value(v) {}
    void print() {
        cout << "Bool: " << (value ? "true" : "false") << endl;
    }
};

// Partial specialization for pointers
template<typename T>
class Storage<T*> {
    T* value;
public:
    Storage(T* v) : value(v) {}
    void print() { cout << "Pointer: " << *value << endl; }
};
```

---

## 7. Functional Programming

### 7.1 Function Objects (Functors)

```cpp
#include <functional>
#include <iostream>
using namespace std;

// Custom functor
class Multiply {
    int factor;
public:
    Multiply(int f) : factor(f) {}
    int operator()(int x) const { return x * factor; }
};

int main() {
    Multiply by2(2);
    Multiply by3(3);

    cout << by2(5);    // 10
    cout << by3(5);    // 15

    // Can be used with STL algorithms
    vector<int> v{1, 2, 3, 4, 5};
    transform(v.begin(), v.end(), v.begin(), Multiply(10));
    // v = {10, 20, 30, 40, 50}
}
```

### 7.2 Lambda Expressions

```cpp
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    vector<int> v{1, 2, 3, 4, 5, 6};

    // Lambda syntax: [capture](parameters) -> return_type { body }

    // Simple lambda
    auto print = [](int x) { cout << x << " "; };
    for_each(v.begin(), v.end(), print);

    // With capture by value
    int multiplier = 2;
    auto multiply = [multiplier](int x) { return x * multiplier; };

    // Capture by reference - can modify external variable
    [&multiplier](int x) { multiplier = 10; return x * multiplier; };

    // Capture all by value: [=]
    // Capture all by reference: [&]

    // Mutable lambda - can modify captured values
    int count = 0;
    auto counter = [count]() mutable { count++; return count; };

    // Generic lambda (C++14)
    auto printAny = [](auto x) { cout << x << " "; };
    printAny(42);
    printAny("hello");

    // Using with STL algorithms
    auto it = find_if(v.begin(), v.end(), [](int x){ return x > 3; });

    // Sort with custom lambda
    sort(v.begin(), v.end(), [](int a, int b){ return a > b; });
}
```

### 7.3 Standard Function Objects

```cpp
#include <functional>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    // Arithmetic
    plus<int> add;
    minus<int> sub;
    multiplies<int> mul;
    divides<int> div;
    modulus<int> mod;
    negate<int> neg;

    cout << add(3, 4);      // 7
    cout << neg(5);          // -5

    // Comparison
    greater<int> gt;
    greater_equal<int> gte;
    less<int> lt;
    less_equal<int> lte;
    equal_to<int> eq;
    not_equal_to<int> neq;

    // Logical
    logical_and<int> and_;
    logical_or<int> or_;
    logical_not<int> not_;

    // Using with algorithms
    vector<int> v{3, 1, 4, 1, 5, 9, 2, 6};
    sort(v.begin(), v.end(), greater<int>());  // Descending

    // With transform
    transform(v.begin(), v.end(), v.begin(), multiplies<int>(2));

    // With bind
    auto greaterThan10 = bind(greater<int>(), placeholders::_1, 10);
    // greaterThan10(5) = false, greaterThan10(15) = true
}
```

### Lambda Capture Guide

```
┌─────────────────────────────────────────────────────────────────┐
│                     LAMBDA CAPTURES                             │
├─────────────────────┬───────────────────────────────────────────┤
│  [ ]                │ Capture nothing                           │
│  [=]                │ Capture all by value (copy)              │
│  [&]                │ Capture all by reference                  │
│  [x]                │ Capture x by value                        │
│  [&x]               │ Capture x by reference                    │
│  [=, &x]            │ All by value, x by reference              │
│  [&, x]             │ All by reference, x by value              │
│  [this]             │ Capture this pointer                       │
├─────────────────────┴───────────────────────────────────────────┤
│  mutable keyword needed to modify captured variables by value   │
│  [x]() mutable { x = 10; }                                      │
└─────────────────────────────────────────────────────────────────┘
```

---

## 8. Utilities

### 8.1 tuple

```cpp
#include <tuple>
#include <iostream>
#include <string>
using namespace std;

// Creating tuples
tuple<int, string, double> t1(1, "hello", 3.14);
auto t2 = make_tuple(2, "world", 2.71);

// Accessing elements - C++11
cout << get<0>(t1);    // 1
cout << get<1>(t1);    // "hello"
cout << get<2>(t1);    // 3.14

// Accessing elements - C++14 (compile-time index)
auto& val = get<int>(t1);    // Must know type

// Tuple size
cout << tuple_size<decltype(t1)>::value;  // 3

// Tuple comparison - lexicographical
tuple<int, int> a(1, 2);
tuple<int, int> b(1, 3);
bool result = (a < b);  // true

// Concatenate tuples
auto combined = tuple_cat(t1, t2);

// Unpacking with tie
int num;
string str;
double dbl;
tie(num, str, dbl) = t1;
cout << num << " " << str << " " << dbl;

// Ignore certain values
int a, d;
tie(a, ignore, ignore, ignore, d) = combined;

// Structured bindings (C++17)
auto [id, name, value] = t1;
```

### 8.2 pair

```cpp
#include <utility>
#include <iostream>
using namespace std;

// Creating pairs
pair<int, string> p1(1, "one");
auto p2 = make_pair(2, "two");

// Access
cout << p1.first;   // 1
cout << p1.second;  // "one"

// Comparison (first then second)
pair<int, string> a(1, "a");
pair<int, string> b(1, "b");
bool result = (a < b);  // true (compares first, then second)

// Swap
p1.swap(p2);

// Structured bindings (C++17)
auto [key, value] = p1;
```

---

## 9. Quick Reference Cheat Sheet

### Complexity Overview

```
┌─────────────────────────────────────────────────────────────────┐
│                    COMPLEXITY CHEAT SHEET                        │
├─────────────────┬──────────────┬─────────────┬───────────────────┤
│ Container       │ Insert       │ Find        │ Sorted            │
├─────────────────┼──────────────┼─────────────┼───────────────────┤
│ vector          │ O(1) amort   │ O(n)        │ O(n)              │
│ deque           │ O(1)         │ O(n)        │ O(n)              │
│ list            │ O(1)         │ O(n)        │ O(n)              │
│ forward_list    │ O(1)         │ O(n)        │ O(n)              │
├─────────────────┼──────────────┼─────────────┼───────────────────┤
│ set/map         │ O(log n)     │ O(log n)    │ O(n)              │
│ multiset/multimap│ O(log n)    │ O(log n)    │ O(n)              │
├─────────────────┼──────────────┼─────────────┼───────────────────┤
│ unordered_set/  │ O(1) avg     │ O(1) avg    │ O(n)              │
│ unordered_map   │ O(1) avg     │ O(1) avg    │ O(n)              │
├─────────────────┼──────────────┼─────────────┼───────────────────┤
│ stack/queue     │ O(1)         │ N/A         │ N/A               │
│ priority_queue  │ O(log n)     │ O(1) top    │ N/A               │
└─────────────────┴──────────────┴─────────────┴───────────────────┘
```

### Iterator Categories

```
┌─────────────────────────────────────────────────────────────────┐
│                    ITERATOR CATEGORIES                          │
├──────────────────┬──────────────────────────────────────────────┤
│ Input Iterator   │ Read once, forward only (istream)            │
│ Output Iterator  │ Write once, forward only (ostream)           │
├──────────────────┼──────────────────────────────────────────────┤
│ Forward Iterator │ Read/Write multiple times, forward           │
│                  │ (forward_list, unordered_set/map)            │
├──────────────────┼──────────────────────────────────────────────┤
│ Bidirectional    │ Read/Write both directions                    │
│ Iterator         │ (list, set/map, their unordered counterparts)│
├──────────────────┼──────────────────────────────────────────────┤
│ Random Access    │ Read/Write with arithmetic, O(1) jump        │
│ Iterator         │ (vector, deque, string, array)               │
└──────────────────┴──────────────────────────────────────────────┘
```

### Common Algorithm Time Complexities

```
┌──────────────────────────┬───────────────────────────────────────┐
│ Algorithm                │ Time Complexity                        │
├──────────────────────────┼───────────────────────────────────────┤
│ find/find_if            │ O(n)                                   │
│ count/count_if          │ O(n)                                   │
│ transform               │ O(n)                                   │
│ copy/copy_if            │ O(n)                                   │
│ remove/remove_if        │ O(n)                                   │
│ sort                    │ O(n log n)                             │
│ stable_sort             │ O(n log n)                             │
│ nth_element             │ O(n) average                           │
│ binary_search           │ O(log n)                               │
│ lower/upper_bound       │ O(log n)                               │
│ set_union/intersection  │ O(n + m)                               │
│ merge                   │ O(n + m)                               │
│ heap operations         │ O(n) make, O(log n) push/pop          │
└──────────────────────────┴───────────────────────────────────────┘
```

### When to Use What

```
┌─────────────────────────────────────────────────────────────────┐
│                    DECISION GUIDE                               │
├─────────────────────────────────────────────────────────────────┤
│ Need sorted data? → set, map (ordered)                         │
│ Need fast lookup? → unordered_set, unordered_map               │
│ Need duplicates? → multiset, multimap                          │
│ Need key-value? → map, unordered_map                           │
│ Need stack behavior? → stack                                   │
│ Need queue behavior? → queue                                   │
│ Need priority queue? → priority_queue                          │
│ Need random access? → vector, deque                            │
│ Need frequent insert/delete in middle? → list                 │
│ Memory critical? → forward_list                               │
├─────────────────────────────────────────────────────────────────┤
│ Default choice: vector for most cases                           │
│ String data: string                                            │
│ Need hash table: unordered_set/map                             │
│ Need tree: set/map                                             │
└─────────────────────────────────────────────────────────────────┘
```

---

## Practice Problems for Each Topic

### Sequential Containers
- Implement stack using two queues
- Implement queue using two stacks
- Find median of sliding window (deque)
- LRU Cache (list + unordered_map)

### Associative Containers
- Find frequency of elements (unordered_map)
- Find first unique character (unordered_map)
- Two Sum problem (unordered_map)
- Implement phone directory (trie - advanced)

### Algorithms
- Sort colors (Dutch National Flag)
- Merge intervals
- Find kth largest element
- Implement binary search variants

### Strings
- Reverse words in a string
- Implement atoi
- Longest substring without repeating
- Palindrome problems

---

*This guide covers all essential C++ STL topics for DSA and interview preparation. Study the concepts, practice the code snippets, and solve related problems for mastery.*
