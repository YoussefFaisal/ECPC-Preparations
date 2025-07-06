# Cpp most useful Functions

## `My OLD Code`
```cpp

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long int ull;
typedef vector<int> vc;
typedef string str;
#define r0 return 0;
#define endl cout << "\n"
#define out cout <<
#define in cin >>
#define yes cout << "YES\n"
#define yesend     \
  cout << "YES\n"; \
  r0
#define noend     \
  cout << "NO\n"; \
  r0
#define no cout << "NO\n"
#define tc      \
  ll wloop;     \
  cin >> wloop; \
  while (wloop--)
#define flop(equl, flopnum) for (ll i = equl; i < flopnum; i++)
#define sor(s) sort(s.begin(), s.end());
#define why_are_we_still_here() (ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL));

void search(vc &v, ll num, ll numtosearch)
{
}

int main()
{
  why_are_we_still_here();
  tc
  {
    ll num;
    in num;
    ll m = num;
    for (ll i = 0; i * i <= num + m; i++)
    {
      if (num - i * i >= 0)
      {
        ll y = sqrt(num - i * i);
        for (ll j = 0; j <= 1; j++)
        {
          ll curr = abs((i * i + ((y + j) * (y + j))) - num);
          m = min(m, curr);
        }
      }
    }
    out m;
    endl;
  }
  endl;
}

```



## `Array`

```cpp
std::array<int, 5> arr = {1, 2, 3, 4, 5};
// size of the array
arr.size();
// Iterating over the array
for (int i : arr) { code }
// Sorting the array
sort(arr.begin(), arr.end());
// Finding an element
auto it = std::find(arr.begin(), arr.end(), 3);
if (it != arr.end()) {
// index of the element
std::distance(arr.begin(), it) ;
} else {code }
// reverse
std::reverse(arr.begin(), arr.end());
// get min
auto minElement = std::min_element(arr.begin(), arr.end());
// get max
auto maxElement = std::max_element(arr.begin(), arr.end());
```

## `Vectors`

```cpp
std::vector<int> vec = {1, 2, 3, 4, 5};
// size of the vector
vec.size();
// Iterating over the vector
for (int i : vec) { code }
// Sorting the vector
std::sort(vec.begin(), vec.end());
// Finding an element
auto it = std::find(vec.begin(), vec.end(), 3);
if (it != vec.end()) {
    // index of the element
    std::distance(vec.begin(), it);
} else { code }
// Adding elements to the vector
vec.push_back(6);
vec.insert(vec.begin() + 2, 7);
// Removing elements from the vector
vec.pop_back();
vec.erase(vec.begin() + 3);
// reverse
std::reverse(vec.begin(), vec.end());
// max element from vectro
int max_element = *max_element(vect.begin(), vect.end());
// min element from vector
int min_element = *min_element(vect.begin(), vect.end());
```

---

<table>
<thead>
<tr>
<th>
<p dir="ltr" style="text-align: center"><span>Vector Function</span></p>
</th>
<th>
<p dir="ltr" style="text-align: center"><span>Description</span></p>
</th>
</tr>
</thead>
<tbody>
<tr>
<th>
<p dir="ltr" style="text-align: center"><a href="https://www.geeksforgeeks.org/vectorpush_back-vectorpop_back-c-stl/"><span>push_back()</span></a></p>
</th>
<td><span>Adds an element to the end of the vector.</span></td>
</tr>
<tr>
<th>
<p dir="ltr" style="text-align: center"><a href="https://www.geeksforgeeks.org/vectorpush_back-vectorpop_back-c-stl/"><span>pop_back()</span></a></p>
</th>
<td><span>Removes the last element of the vector.</span></td>
</tr>
<tr>
<th>
<p dir="ltr" style="text-align: center"><a href="https://www.geeksforgeeks.org/vectorempty-vectorsize-c-stl/"><span>size()</span></a></p>
</th>
<td><span>Returns the number of elements in the vector.</span></td>
</tr>
<tr>
<th>
<p dir="ltr" style="text-align: center"><a href="https://www.geeksforgeeks.org/vector-max_size-function-in-c-stl/"><span>max_size()</span></a></p>
</th>
<td><span>Returns the maximum number of elements that the vector can hold.</span></td>
</tr>
<tr>
<th>
<p dir="ltr" style="text-align: center"><a href="https://www.geeksforgeeks.org/vector-resize-c-stl/"><span>resize()</span></a></p>
</th>
<td><span>Changes the size of the vector.</span></td>
</tr>
<tr>
<th>
<p dir="ltr" style="text-align: center"><a href="https://www.geeksforgeeks.org/vectorempty-vectorsize-c-stl/"><span>empty()</span></a></p>
</th>
<td><span>Checks if the vector is empty.</span></td>
</tr>
<tr>
<th>
<p dir="ltr" style="text-align: center"><a href="https://www.geeksforgeeks.org/vectoroperator-vectoroperator-c-stl/"><span>operator[]</span></a></p>
</th>
<td><span>Accesses the element at a specific position.</span></td>
</tr>
<tr>
<th>
<p dir="ltr" style="text-align: center"><a href="https://www.geeksforgeeks.org/vectorat-vectorswap-c-stl/"><span>at()</span></a></p>
</th>
<td><span>Accesses the element at a specific position, with bounds checking.</span></td>
</tr>
<tr>
<th>
<p dir="ltr" style="text-align: center"><a href="https://www.geeksforgeeks.org/vectorfront-vectorback-c-stl/"><span>front()</span></a></p>
</th>
<td><span>Accesses the first element of the vector.</span></td>
</tr>
<tr>
<th>
<p dir="ltr" style="text-align: center"><a href="https://www.geeksforgeeks.org/vectorfront-vectorback-c-stl/"><span>back()</span></a></p>
</th>
<td><span>Accesses the last element of the vector.</span></td>
</tr>
<tr>
<th>
<p dir="ltr" style="text-align: center"><a href="https://www.geeksforgeeks.org/vectorbegin-vectorend-c-stl/"><span>begin()</span></a></p>
</th>
<td><span>Returns an iterator pointing to the first element of the vector.</span></td>
</tr>
<tr>
<th>
<p dir="ltr" style="text-align: center"><a href="https://www.geeksforgeeks.org/vectorbegin-vectorend-c-stl/"><span>end()</span></a></p>
</th>
<td><span>Returns an iterator pointing to the past-the-end element of the vector.</span></td>
</tr>
<tr>
<th>
<p dir="ltr" style="text-align: center"><a href="https://www.geeksforgeeks.org/vector-rbegin-and-rend-function-in-c-stl/"><span>rbegin()</span></a></p>
</th>
<td><span>Returns a reverse iterator pointing to the last element of the vector.</span></td>
</tr>
<tr>
<th>
<p dir="ltr" style="text-align: center"><a href="https://www.geeksforgeeks.org/vector-rbegin-and-rend-function-in-c-stl/"><span>rend()</span></a></p>
</th>
<td><span>Returns a reverse iterator pointing to the element preceding the first element of the vector.</span></td>
</tr>
<tr>
<th>
<p dir="ltr" style="text-align: center"><a href="https://www.geeksforgeeks.org/vector-cbegin-vector-cend-c-stl/"><span>cbegin</span></a></p>
</th>
<td><span>Returns const_iterator to beginning&nbsp;</span></td>
</tr>
<tr>
<th>
<p dir="ltr" style="text-align: center"><a href="https://www.geeksforgeeks.org/vector-cbegin-vector-cend-c-stl/"><span>cend</span></a></p>
</th>
<td><span>Returns const_iterator to end</span></td>
</tr>
<tr>
<th>
<p dir="ltr" style="text-align: center"><a href="https://www.geeksforgeeks.org/vectorcrend-vectorcrbegin-examples/"><span>crbegin</span></a></p>
</th>
<td><span>Returns const_reverse_iterator to reverse beginning</span></td>
</tr>
<tr>
<th>
<p dir="ltr" style="text-align: center"><a href="https://www.geeksforgeeks.org/vectorcrend-vectorcrbegin-examples/"><span>crend</span></a></p>
</th>
<td><span>Returns const_reverse_iterator to reverse end</span></td>
</tr>
<tr>
<th>
<p dir="ltr" style="text-align: center"><a href="https://www.geeksforgeeks.org/vector-insert-function-in-cpp-stl/"><span>insert()</span></a></p>
</th>
<td><span>Inserts elements at a specific position in the vector.</span></td>
</tr>
<tr>
<th>
<p dir="ltr" style="text-align: center"><a href="https://www.geeksforgeeks.org/vector-erase-and-clear-in-cpp/"><span>erase()</span></a></p>
</th>
<td><span>Removes elements from a specific position or range in the vector.</span></td>
</tr>
<tr>
<th>
<p dir="ltr" style="text-align: center"><a href="https://www.geeksforgeeks.org/vectorat-vectorswap-c-stl/"><span>swap()</span></a></p>
</th>
<td><span>Swaps the contents of the vector with those of another vector.</span></td>
</tr>
<tr>
<th>
<p dir="ltr" style="text-align: center"><a href="https://www.geeksforgeeks.org/vector-erase-and-clear-in-cpp/"><span>clear()</span></a></p>
</th>
<td><span>Removes all elements from the vector.</span></td>
</tr>
<tr>
<th>
<p dir="ltr" style="text-align: center"><a href="https://www.geeksforgeeks.org/vector-emplace-function-in-c-stl/"><span>emplace()</span></a></p>
</th>
<td><span>Constructs and inserts an element in the vector.</span></td>
</tr>
<tr>
<th>
<p dir="ltr" style="text-align: center"><a href="https://www.geeksforgeeks.org/vectoremplace_back-c-stl/"><span>emplace_back()</span></a></p>
</th>
<td><span>Constructs and inserts an element at the end of the vector.</span></td>
</tr>
<tr>
<th>
<p dir="ltr" style="text-align: center"><a href="https://www.geeksforgeeks.org/vector-assign-in-c-stl/"><span>assign()</span></a></p>
</th>
<td><span>Assigns new values to the vector elements by replacing old ones.</span></td>
</tr>
<tr>
<th>
<p dir="ltr" style="text-align: center"><a href="https://www.geeksforgeeks.org/vector-capacity-function-in-c-stl/"><span>capacity()</span></a></p>
</th>
<td><span>Returns the size of the storage space currently allocated to the vector.</span></td>
</tr>
<tr>
<th>
<p dir="ltr" style="text-align: center"><a href="https://www.geeksforgeeks.org/using-stdvectorreserve-whenever-possible/"><span>reserve()</span></a></p>
</th>
<td><span>Requests that the vector capacity be at least enough to contain a specified number of elements.</span></td>
</tr>
<tr>
<th>
<p dir="ltr" style="text-align: center"><a href="https://www.geeksforgeeks.org/vector-shrink_to_fit-function-in-c-stl/"><span>shrink_to_fit()</span></a></p>
</th>
<td><span>Reduces memory usage by freeing unused space.</span></td>
</tr>
<tr>
<th>
<p dir="ltr" style="text-align: center"><a href="https://www.geeksforgeeks.org/vector-data-function-in-c-stl/"><span>data()</span></a></p>
</th>
<td><span>Returns a direct pointer to the memory array used internally by the vector to store its owned elements.&nbsp;</span></td>
</tr>
<tr>
<th>
<p dir="ltr" style="text-align: center"><a href="https://www.geeksforgeeks.org/get_allocator-in-cpp/"><span>get_allocator</span></a></p>
</th>
<td><span>Returns a copy of the allocator object associated with the&nbsp;vector.</span></td>
</tr>
</tbody>
</table>

---

## `deque`

```cpp
std::deque<int> dq = {1, 2, 3, 4, 5};
// size of the deque
dq.size();
// Iterating over the deque
for (int i : dq) { code }
// Sorting the deque
std::sort(dq.begin(), dq.end());
// Finding an element
auto it = std::find(dq.begin(), dq.end(), 3);
if (it != dq.end()) {
    // index of the element
    std::distance(dq.begin(), it);
} else { code }
// Adding elements to the deque
dq.push_back(6);
dq.push_front(0);
dq.insert(dq.begin() + 2, 7);
// Removing elements from the deque
dq.pop_back();
dq.pop_front();
dq.erase(dq.begin() + 3);
// reverse
std::reverse(dq.begin(), dq.end());
```

---

<table class="GFGEditorTheme__table">
<colgroup>
<col>
<col></colgroup>
<thead>
<tr>
<th class="GFGEditorTheme__tableCell GFGEditorTheme__tableCellHeader"><span>Function</span></th>
<th class="GFGEditorTheme__tableCell GFGEditorTheme__tableCellHeader"><span>Description</span></th>
</tr>
</thead>
<tbody>
<tr>
<td class="GFGEditorTheme__tableCell"><a href="https://www.geeksforgeeks.org/setbegin-setend-c-stl/"><span>begin()</span></a></td>
<td class="GFGEditorTheme__tableCell"><span>Returns an iterator to the first element in the set.</span></td>
</tr>
<tr>
<td class="GFGEditorTheme__tableCell"><a href="https://www.geeksforgeeks.org/setbegin-setend-c-stl/"><span>end()</span></a></td>
<td class="GFGEditorTheme__tableCell"><span>Returns an iterator to the theoretical element that follows the last element in the set.</span></td>
</tr>
<tr>
<td class="GFGEditorTheme__tableCell"><a href="https://www.geeksforgeeks.org/setrbegin-and-setrend-in-c-stl/"><span>rbegin()</span></a></td>
<td class="GFGEditorTheme__tableCell"><span>Returns a reverse iterator pointing to the last element in the container.</span></td>
</tr>
<tr>
<td class="GFGEditorTheme__tableCell"><a href="https://www.geeksforgeeks.org/setrbegin-and-setrend-in-c-stl/"><span>rend()</span></a></td>
<td class="GFGEditorTheme__tableCell"><span>Returns a reverse iterator pointing to the theoretical element right before the first element in the set container.</span></td>
</tr>
<tr>
<td class="GFGEditorTheme__tableCell"><a href="https://www.geeksforgeeks.org/set-crbegin-and-crend-function-in-c-stl/"><span>crbegin()</span></a></td>
<td class="GFGEditorTheme__tableCell"><span>Returns a constant iterator pointing to the last element in the container.</span></td>
</tr>
<tr>
<td class="GFGEditorTheme__tableCell"><a href="https://www.geeksforgeeks.org/set-crbegin-and-crend-function-in-c-stl/"><span>crend()</span></a></td>
<td class="GFGEditorTheme__tableCell"><span>Returns a constant iterator pointing to the position just before the first element in the container.</span></td>
</tr>
<tr>
<td class="GFGEditorTheme__tableCell"><a href="https://www.geeksforgeeks.org/set-cbegin-and-cend-function-in-c-stl/"><span>cbegin()</span></a></td>
<td class="GFGEditorTheme__tableCell"><span>Returns a constant iterator pointing to the first element in the container.</span></td>
</tr>
<tr>
<td class="GFGEditorTheme__tableCell"><a href="https://www.geeksforgeeks.org/set-cbegin-and-cend-function-in-c-stl/"><span>cend()</span></a></td>
<td class="GFGEditorTheme__tableCell"><span>Returns a constant iterator pointing to the position past the last element in the container.</span></td>
</tr>
<tr>
<td class="GFGEditorTheme__tableCell"><a href="https://www.geeksforgeeks.org/setsize-c-stl/"><span>size()</span></a></td>
<td class="GFGEditorTheme__tableCell"><span>Returns the number of elements in the set.</span></td>
</tr>
<tr>
<td class="GFGEditorTheme__tableCell"><a href="https://www.geeksforgeeks.org/set-max_size-function-in-c-stl/"><span>max_size()</span></a></td>
<td class="GFGEditorTheme__tableCell"><span>Returns the maximum number of elements that the set can hold.</span></td>
</tr>
<tr>
<td class="GFGEditorTheme__tableCell"><a href="https://www.geeksforgeeks.org/setempty-c-stl/"><span>empty()</span></a></td>
<td class="GFGEditorTheme__tableCell"><span>Returns whether the set is empty.</span></td>
</tr>
<tr>
<td class="GFGEditorTheme__tableCell"><a href="https://www.geeksforgeeks.org/set-insert-function-in-c-stl/"><span>insert(const g)&nbsp;</span></a></td>
<td class="GFGEditorTheme__tableCell"><span>Adds a new element ‘g’ to the set.</span></td>
</tr>
<tr>
<td class="GFGEditorTheme__tableCell"><a href="https://www.geeksforgeeks.org/set-insert-function-in-c-stl/"><span>iterator insert (iterator position, const g)</span></a></td>
<td class="GFGEditorTheme__tableCell"><span>Adds a new element ‘g’ at the position pointed by the iterator.</span></td>
</tr>
<tr>
<td class="GFGEditorTheme__tableCell"><a href="https://www.geeksforgeeks.org/seterase-c-stl/"><span>erase(iterator position)&nbsp;</span></a></td>
<td class="GFGEditorTheme__tableCell"><span>Removes the element at the position pointed by the iterator.</span></td>
</tr>
<tr>
<td class="GFGEditorTheme__tableCell"><a href="https://www.geeksforgeeks.org/seterase-c-stl/"><span>erase(const g)</span></a></td>
<td class="GFGEditorTheme__tableCell"><span>Removes the value ‘g’ from the set.</span></td>
</tr>
<tr>
<td class="GFGEditorTheme__tableCell"><a href="https://www.geeksforgeeks.org/setclear-c-stl/"><span>clear()&nbsp;</span></a></td>
<td class="GFGEditorTheme__tableCell"><span>Removes all the elements from the set.</span></td>
</tr>
<tr>
<td class="GFGEditorTheme__tableCell"><a href="https://www.geeksforgeeks.org/setkey_comp-in-c-stl/"><span>key_comp()</span></a><span> /</span><a href="https://www.geeksforgeeks.org/set-value_comp-function-in-c-stl/"><span> value_comp()</span></a></td>
<td class="GFGEditorTheme__tableCell"><span>Returns the object that determines how the elements in the set are ordered (‘&lt;‘ by default).</span></td>
</tr>
<tr>
<td class="GFGEditorTheme__tableCell"><a href="https://www.geeksforgeeks.org/set-find-function-in-c-stl/"><span>find(const g)</span></a></td>
<td class="GFGEditorTheme__tableCell"><span>Returns an iterator to the element ‘g’ in the set if found, else returns the iterator to the end.</span></td>
</tr>
<tr>
<td class="GFGEditorTheme__tableCell"><a href="https://www.geeksforgeeks.org/set-count-function-in-c-stl/"><span>count(const g)</span></a></td>
<td class="GFGEditorTheme__tableCell"><span>Returns 1 or 0 based on whether the element ‘g’ is present in the set or not.</span></td>
</tr>
<tr>
<td class="GFGEditorTheme__tableCell"><a href="https://www.geeksforgeeks.org/set-lower_bound-function-in-c-stl/"><span>lower_bound(const g)</span></a></td>
<td class="GFGEditorTheme__tableCell"><span>Returns an iterator to the first element that is equivalent to ‘g’ or definitely will not go before the element ‘g’ in the set.</span></td>
</tr>
<tr>
<td class="GFGEditorTheme__tableCell"><a href="https://www.geeksforgeeks.org/set-upper_bound-function-in-c-stl/"><span>upper_bound(const g)</span></a></td>
<td class="GFGEditorTheme__tableCell"><span>Returns an iterator to the first element that will go after the element ‘g’ in the set.</span></td>
</tr>
<tr>
<td class="GFGEditorTheme__tableCell"><a href="https://www.geeksforgeeks.org/set-equal_range-function-in-c-stl/"><span>equal_range()</span></a></td>
<td class="GFGEditorTheme__tableCell"><span>The function returns an iterator of pairs. (key_comp). The pair refers to the range that includes all the elements in the container which have a key equivalent to k.</span></td>
</tr>
<tr>
<td class="GFGEditorTheme__tableCell"><a href="https://www.geeksforgeeks.org/setemplace-c-stl/"><span>emplace()</span></a></td>
<td class="GFGEditorTheme__tableCell"><span>This function is used to insert a new element into the set container, only if the element to be inserted is unique and does not already exist in the set.</span></td>
</tr>
<tr>
<td class="GFGEditorTheme__tableCell"><a href="https://www.geeksforgeeks.org/set-emplace_hint-function-in-c-stl/"><span>emplace_hint()</span></a></td>
<td class="GFGEditorTheme__tableCell"><span>Returns an iterator pointing to the position where the insertion is done. If the element passed in the parameter already exists, then it returns an iterator pointing to the position where the existing element is.</span></td>
</tr>
<tr>
<td class="GFGEditorTheme__tableCell"><a href="https://www.geeksforgeeks.org/setswap-c-stl/"><span>swap()</span></a></td>
<td class="GFGEditorTheme__tableCell"><span>This function is used to exchange the contents of two sets but the sets must be of the same type, although sizes may differ.</span></td>
</tr>
<tr>
<td class="GFGEditorTheme__tableCell"><a href="https://www.geeksforgeeks.org/set-operator-in-c-stl/"><span>operator=</span></a></td>
<td class="GFGEditorTheme__tableCell"><span>The ‘=’ is an operator in C++ STL that copies (or moves) a set to another set and set::operator= is the corresponding operator function.</span></td>
</tr>
<tr>
<td class="GFGEditorTheme__tableCell"><a href="https://www.geeksforgeeks.org/set-get_allocator-in-c-stl/"><span>get_allocator()</span></a></td>
<td class="GFGEditorTheme__tableCell"><span>Returns the copy of the allocator object associated with the set.</span></td>
</tr>
</tbody>
</table>

---

## `list`

```cpp
std::list<int> myList;

// Insertion functions
myList.push_back(5); // Adds an element to the end of the list
myList.push_front(2); // Adds an element to the beginning of the list
myList.insert(myList.begin(), 8); // Inserts an element at a specific position

// Access functions
int firstElement = myList.front(); // Returns the first element of the list
int lastElement = myList.back(); // Returns the last element of the list

// Modification functions
mylist.sort();
myList.pop_back(); // Removes the last element of the list
myList.pop_front(); // Removes the first element of the list
myList.erase(myList.begin()); // Removes an element at a specific position
myList.clear(); // Removes all elements from the list

// Size functions
int listSize = myList.size(); // Returns the number of elements in the list
bool isEmpty = myList.empty(); // Checks if the list is empty

// Iteration functions
for (auto it = myList.begin(); it != myList.end(); ++it) {
    // Access and modify elements using the iterator
    int element = *it;
    *it = element + 1;
}

```
---

## `list`

```cpp
std::set <data_type> set_name;
set<int> val; // defining an empty set
set<int> val = {6, 10, 5, 1}; // defining a set with values

// C++ Program to Demonstrate
// the basic working of STL
#include <iostream>
#include <set>

int main()
{
    std::set<char> a;
    a.insert('G');
    a.insert('F');
    a.insert('G');
    for (auto& str : a) {
        std::cout << str << ' ';
    }
    std::cout << '\n';
    return 0;
} // out F G

// Set Sorted in Descending Order
// By default, the std::set is sorted in ascending order. However, we have the option to change the sorting order by using the following syntax.

std::set <data_type, greater<data_type>> set_name;

// C++ program to demonstrate the creation of descending
// order set container
#include <iostream>
#include <set>
using namespace std;

int main()
{

    set<int, greater<int> > s1;
    s1.insert(10);
    s1.insert(5);
    s1.insert(12);
    s1.insert(4);

    for (auto i : s1) {
        cout << i << ' ';
    }
    return 0;
} //out 12 10 5 4
// C++ program to demonstrate various functions of
// STL
#include <iostream>
#include <iterator>
#include <set>
using namespace std;

int main()
{
    // empty set container
    set<int, greater<int> > s1;

    // insert elements in random order
    s1.insert(40);
    s1.insert(30);
    s1.insert(60);
    s1.insert(20);
    s1.insert(50);

    // only one 50 will be added to the set
    s1.insert(50);
    s1.insert(10);

    // printing set s1
    set<int, greater<int> >::iterator itr;
    cout << "\nThe set s1 is : \n";
    for (itr = s1.begin(); itr != s1.end(); itr++) {
        cout << *itr << " ";
    }
    cout << endl;

    // assigning the elements from s1 to s2
    set<int> s2(s1.begin(), s1.end());

    // print all elements of the set s2
    cout << "\nThe set s2 after assign from s1 is : \n";
    for (itr = s2.begin(); itr != s2.end(); itr++) {
        cout << *itr << " ";
    }
    cout << endl;

    // remove all elements up to 30 in s2
    cout << "\ns2 after removal of elements less than 30 "
            ":\n";
    s2.erase(s2.begin(), s2.find(30));
    for (itr = s2.begin(); itr != s2.end(); itr++) {
        cout << *itr << " ";
    }

    // remove element with value 50 in s2
    int num;
    num = s2.erase(50);
    cout << "\ns2.erase(50) : ";
    cout << num << " removed\n";
    for (itr = s2.begin(); itr != s2.end(); itr++) {
        cout << *itr << " ";
    }

    cout << endl;

    // lower bound and upper bound for set s1
    cout << "s1.lower_bound(40) : "
         << *s1.lower_bound(40) << endl;
    cout << "s1.upper_bound(40) : "
         << *s1.upper_bound(40) << endl;

    // lower bound and upper bound for set s2
    cout << "s2.lower_bound(40) : "
         << *s2.lower_bound(40) << endl;
    cout << "s2.upper_bound(40) : "
         << *s2.upper_bound(40) << endl;

    return 0;
}

/* out
The set s1 is : 
60 50 40 30 20 10 

The set s2 after assign from s1 is : 
10 20 30 40 50 60 

s2 after removal of elements less than 30 :
30 40 50 60 
s2.erase(50) : 1 removed
30 40 60 
s1.lower_bound(40) : 40
s1.upper_bound(40) : 30
s2.lower_bound(40) : 40
s2.upper_bound(40) : 60
*/


```
<table><thead><tr><th><span>Function</span></th><th><span>Description</span></th></tr></thead><tbody><tr><td><a href="https://www.geeksforgeeks.org/setbegin-setend-c-stl/" rel="noopener"><span>begin()</span></a></td><td><span>Returns an iterator to the first element in the set.</span></td></tr><tr><td><a href="https://www.geeksforgeeks.org/setbegin-setend-c-stl/" rel="noopener"><span>end()</span></a></td><td><span>Returns an iterator to the theoretical element that follows the last element in the set.</span></td></tr><tr><td><a href="https://www.geeksforgeeks.org/setrbegin-and-setrend-in-c-stl/" rel="noopener"><span>rbegin()</span></a></td><td><span>Returns a reverse iterator pointing to the last element in the container.</span></td></tr><tr><td><a href="https://www.geeksforgeeks.org/setrbegin-and-setrend-in-c-stl/" rel="noopener"><span>rend()</span></a></td><td><span>Returns a reverse iterator pointing to the theoretical element right before the first element in the set container.</span></td></tr><tr><td><a href="https://www.geeksforgeeks.org/set-crbegin-and-crend-function-in-c-stl/" rel="noopener"><span>crbegin()</span></a></td><td><span>Returns a constant iterator pointing to the last element in the container.</span></td></tr><tr><td><a href="https://www.geeksforgeeks.org/set-crbegin-and-crend-function-in-c-stl/" rel="noopener"><span>crend()</span></a></td><td><span>Returns a constant iterator pointing to the position just before the first element in the container.</span></td></tr><tr><td><a href="https://www.geeksforgeeks.org/set-cbegin-and-cend-function-in-c-stl/" rel="noopener"><span>cbegin()</span></a></td><td><span>Returns a constant iterator pointing to the first element in the container.</span></td></tr><tr><td><a href="https://www.geeksforgeeks.org/set-cbegin-and-cend-function-in-c-stl/" rel="noopener"><span>cend()</span></a></td><td><span>Returns a constant iterator pointing to the position past the last element in the container.</span></td></tr><tr><td><a href="https://www.geeksforgeeks.org/setsize-c-stl/" rel="noopener"><span>size()</span></a></td><td><span>Returns the number of elements in the set.</span></td></tr><tr><td><a href="https://www.geeksforgeeks.org/set-max_size-function-in-c-stl/" rel="noopener"><span>max_size()</span></a></td><td><span>Returns the maximum number of elements that the set can hold.</span></td></tr><tr><td><a href="https://www.geeksforgeeks.org/setempty-c-stl/" rel="noopener"><span>empty()</span></a></td><td><span>Returns whether the set is empty.</span></td></tr><tr><td><a href="https://www.geeksforgeeks.org/set-insert-function-in-c-stl/" rel="noopener"><span>insert(const g)&nbsp;</span></a></td><td><span>Adds a new element ‘g’ to the set.</span></td></tr><tr><td><a href="https://www.geeksforgeeks.org/set-insert-function-in-c-stl/" rel="noopener"><span>iterator insert (iterator position, const g)</span></a></td><td><span>Adds a new element ‘g’ at the position pointed by the iterator.</span></td></tr><tr><td><a href="https://www.geeksforgeeks.org/seterase-c-stl/" rel="noopener"><span>erase(iterator position)&nbsp;</span></a></td><td><span>Removes the element at the position pointed by the iterator.</span></td></tr><tr><td><a href="https://www.geeksforgeeks.org/seterase-c-stl/" rel="noopener"><span>erase(const g)</span></a></td><td><span>Removes the value ‘g’ from the set.</span></td></tr><tr><td><a href="https://www.geeksforgeeks.org/setclear-c-stl/" rel="noopener"><span>clear()&nbsp;</span></a></td><td><span>Removes all the elements from the set.</span></td></tr><tr><td><a href="https://www.geeksforgeeks.org/setkey_comp-in-c-stl/" rel="noopener"><span>key_comp()</span></a><span> /</span><a href="https://www.geeksforgeeks.org/set-value_comp-function-in-c-stl/" rel="noopener"><span> value_comp()</span></a></td><td><span>Returns the object that determines how the elements in the set are ordered (‘&lt;‘ by default).</span></td></tr><tr><td><a href="https://www.geeksforgeeks.org/set-find-function-in-c-stl/" rel="noopener"><span>find(const g)</span></a></td><td><span>Returns an iterator to the element ‘g’ in the set if found, else returns the iterator to the end.</span></td></tr><tr><td><a href="https://www.geeksforgeeks.org/set-count-function-in-c-stl/" rel="noopener"><span>count(const g)</span></a></td><td><span>Returns 1 or 0 based on whether the element ‘g’ is present in the set or not.</span></td></tr><tr><td><a href="https://www.geeksforgeeks.org/set-lower_bound-function-in-c-stl/" rel="noopener"><span>lower_bound(const g)</span></a></td><td><span>Returns an iterator to the first element that is equivalent to ‘g’ or definitely will not go before the element ‘g’ in the set.</span></td></tr><tr><td><a href="https://www.geeksforgeeks.org/set-upper_bound-function-in-c-stl/" rel="noopener"><span>upper_bound(const g)</span></a></td><td><span>Returns an iterator to the first element that will go after the element ‘g’ in the set.</span></td></tr><tr><td><a href="https://www.geeksforgeeks.org/set-equal_range-function-in-c-stl/" rel="noopener"><span>equal_range()</span></a></td><td><span>The function returns an iterator of pairs. (key_comp). The pair refers to the range that includes all the elements in the container which have a key equivalent to k.</span></td></tr><tr><td><a href="https://www.geeksforgeeks.org/setemplace-c-stl/" rel="noopener"><span>emplace()</span></a></td><td><span>This function is used to insert a new element into the set container, only if the element to be inserted is unique and does not already exist in the set.</span></td></tr><tr><td><a href="https://www.geeksforgeeks.org/set-emplace_hint-function-in-c-stl/" rel="noopener"><span>emplace_hint()</span></a></td><td><span>Returns an iterator pointing to the position where the insertion is done. If the element passed in the parameter already exists, then it returns an iterator pointing to the position where the existing element is.</span></td></tr><tr><td><a href="https://www.geeksforgeeks.org/setswap-c-stl/" rel="noopener"><span>swap()</span></a></td><td><span>This function is used to exchange the contents of two sets but the sets must be of the same type, although sizes may differ.</span></td></tr><tr><td><a href="https://www.geeksforgeeks.org/set-operator-in-c-stl/" rel="noopener"><span>operator=</span></a></td><td><span>The ‘=’ is an operator in C++ STL that copies (or moves) a set to another set and set::operator= is the corresponding operator function.</span></td></tr><tr><td><a href="https://www.geeksforgeeks.org/set-get_allocator-in-c-stl/" rel="noopener"><span>get_allocator()</span></a></td><td><span>Returns the copy of the allocator object associated with the set.</span></td></tr></tbody></table>

Difference between Set and Unordered Set

<table><thead><tr><th><p dir="ltr" style="text-align: center;"><span>Set</span></p>
</th><th><p dir="ltr" style="text-align: center;"><span>Unordered Set</span></p>
</th></tr></thead><tbody><tr><td><span>Set stores elements in a sorted order</span></td><td><span>Unordered Set stores elements in an unsorted order</span></td></tr><tr><td><span>Set stores/acquire unique elements only</span></td><td><span>Unordered Set stores/acquire only unique values</span></td></tr><tr><td><span>Set uses Binary Search Trees for implementation</span></td><td><span>Unordered Set uses Hash Tables for implementation</span></td></tr><tr><td><span>More than one element can be erased by giving the starting and ending iterator</span></td><td><span>We can erase that element for which the iterator position is given</span></td></tr><tr><td><b><strong>set&lt;datatype&gt; Set_Name;</strong></b></td><td><b><strong>unordered_set&lt;datatype&gt; UnorderedSet_Name;</strong></b></td></tr></tbody></table>



---
## `list`

```cpp
// C++ program to illustrate the begin and end iterator
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    // Create a map of strings to integers
    map<string, int> mp;

    // Insert some values into the map
    mp["one"] = 1;
    mp["two"] = 2;
    mp["three"] = 3;

    // Get an iterator pointing to the first element in the
    // map
    map<string, int>::iterator it = mp.begin();

    // Iterate through the map and print the elements
    while (it != mp.end()) {
        cout << "Key: " << it->first
             << ", Value: " << it->second << endl;
        ++it;
    }

    return 0;
}

/*
Output
Key: one, Value: 1
Key: three, Value: 3
Key: two, Value: 2
*/

// C++ program to illustrate the size() function
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    // Create a map of strings to integers
    map<string, int> map;

    // Insert some values into the map
    map["one"] = 1;
    map["two"] = 2;
    map["three"] = 3;

    // Print the size of the map
    cout << "Size of map: " << map.size() << endl;

    return 0;
}

/*
Output
Size of map: 3
*/

// CPP Program to demonstrate the implementation in Map
// divyansh mishra --> divyanshmishra101010
#include <iostream>
#include <iterator>
#include <map>
using namespace std;

int main()
{

    // empty map container
    map<int, int> gquiz1;

    // insert elements in random order
    gquiz1.insert(pair<int, int>(1, 40));
    gquiz1.insert(pair<int, int>(2, 30));
    gquiz1.insert(pair<int, int>(3, 60));
    gquiz1.insert(pair<int, int>(4, 20));
    gquiz1.insert(pair<int, int>(5, 50));
    gquiz1.insert(pair<int, int>(6, 50));

    // another way of inserting a value in a map
    gquiz1[7] = 10;

    // printing map gquiz1
    map<int, int>::iterator itr;
    cout << "\nThe map gquiz1 is : \n";
    cout << "\tKEY\tELEMENT\n";
    for (itr = gquiz1.begin(); itr != gquiz1.end(); ++itr) {
        cout << '\t' << itr->first << '\t' << itr->second
             << '\n';
    }
    cout << endl;

    // assigning the elements from gquiz1 to gquiz2
    map<int, int> gquiz2(gquiz1.begin(), gquiz1.end());

    // print all elements of the map gquiz2
    cout << "\nThe map gquiz2 after"
         << " assign from gquiz1 is : \n";
    cout << "\tKEY\tELEMENT\n";
    for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) {
        cout << '\t' << itr->first << '\t' << itr->second
             << '\n';
    }
    cout << endl;

    // remove all elements up to
    // element with key=3 in gquiz2
    cout << "\ngquiz2 after removal of"
            " elements less than key=3 : \n";
    cout << "\tKEY\tELEMENT\n";
    gquiz2.erase(gquiz2.begin(), gquiz2.find(3));
    for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) {
        cout << '\t' << itr->first << '\t' << itr->second
             << '\n';
    }

    // remove all elements with key = 4
    int num;
    num = gquiz2.erase(4);
    cout << "\ngquiz2.erase(4) : ";
    cout << num << " removed \n";
    cout << "\tKEY\tELEMENT\n";
    for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) {
        cout << '\t' << itr->first << '\t' << itr->second
             << '\n';
    }

    cout << endl;

    // lower bound and upper bound for map gquiz1 key = 5
    cout << "gquiz1.lower_bound(5) : "
         << "\tKEY = ";
    cout << gquiz1.lower_bound(5)->first << '\t';
    cout << "\tELEMENT = " << gquiz1.lower_bound(5)->second
         << endl;
    cout << "gquiz1.upper_bound(5) : "
         << "\tKEY = ";
    cout << gquiz1.upper_bound(5)->first << '\t';
    cout << "\tELEMENT = " << gquiz1.upper_bound(5)->second
         << endl;

    return 0;
}

/*
Output
The map gquiz1 is : 
    KEY    ELEMENT
    1    40
    2    30
    3    60
    4    20
    5    50
    6    50
    7    10


The map gquiz2 after assign from gquiz1 is : 
    KEY    ELEMENT
    1    40
    2    30
    3    60
    4    20
    5    50
    6    50
    7    10


gquiz2 after remov...
*/
// C++ program to implement map container
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    // Create a map of strings to integers
    map<string, int> map;

    // Insert some values into the map
    map["one"] = 1;
    map["two"] = 2;
    map["three"] = 3;

    // Print the values in the map
    cout << "Key: one, Value: " << map["one"] << endl;
    cout << "Key: two, Value: " << map["two"] << endl;
    cout << "Key: three, Value: " << map["three"] << endl;

    // Check if a key is in the map
    if (map.count("four") > 0) {
        cout << "Key 'four' is in the map" << endl;
    }
    else {
        cout << "Key 'four' is not in the map" << endl;
    }

    return 0;
}
Output
Key: one, Value: 1
Key: two, Value: 2
Key: three, Value: 3
Key 'four' is not in the map


```
<table><thead><tr><th><p dir="ltr"><span>Function</span></p>
</th><th><p dir="ltr"><span>Definition</span></p>
</th></tr></thead><tbody><tr><td><a href="https://www.geeksforgeeks.org/map-insert-in-c-stl/" rel="noopener"><span>map::insert()</span></a></td><td><p dir="ltr"><span>Insert elements with a particular key in the map container –&gt; O(log n)</span></p>
</td></tr><tr><td><a href="https://www.geeksforgeeks.org/map-count-function-in-c-stl/" rel="noopener"><span>map:: count()</span></a></td><td><p dir="ltr"><span>Returns the number of matches to element with key-value ‘g’ in the map. –&gt; O(log n)</span></p>
</td></tr><tr><td><a href="https://www.geeksforgeeks.org/map-equal_range-in-c-stl/" rel="noopener"><span>map equal_range()</span></a></td><td><p dir="ltr"><span>Returns an iterator of pairs. The pair refers to the bounds of a range that includes all the elements in the container which have a key equivalent to k.</span></p>
</td></tr><tr><td><a href="https://www.geeksforgeeks.org/map-erase-function-in-c-stl/" rel="noopener"><span>map erase()</span></a></td><td><p dir="ltr"><span>Used to erase elements from the container –&gt; O(log n)</span></p>
</td></tr><tr><td><a href="https://www.geeksforgeeks.org/map-rend-function-in-c-stl/" rel="noopener"><span>map rend()</span></a></td><td><p dir="ltr"><span>Returns a reverse iterator pointing to the theoretical element right before the first key-value pair in the map(which is considered its reverse end).</span></p>
</td></tr><tr><td><a href="https://www.geeksforgeeks.org/map-rbegin-function-in-c-stl-2/" rel="noopener"><span>map rbegin()</span></a>
<p><span>&nbsp;</span></p>
</td><td><p dir="ltr"><span>Returns a reverse iterator which points to the last element of the map.</span></p>
</td></tr><tr><td><a href="https://www.geeksforgeeks.org/map-find-function-in-c-stl/" rel="noopener"><span>map find()</span></a></td><td><p dir="ltr"><span>Returns an iterator to the element with key-value ‘g’ in the map if found, else returns the iterator to end.</span></p>
</td></tr><tr><td><a href="https://www.geeksforgeeks.org/map-crbegin-and-crend-function-in-c-stl/" rel="noopener"><span>map crbegin() and crend()&nbsp;</span></a></td><td><p dir="ltr"><span>crbegin() returns a constant reverse iterator referring to the last element in the map container. crend() returns a constant reverse iterator pointing to the theoretical element before the first element in the map.</span></p>
</td></tr><tr><td><a href="https://www.geeksforgeeks.org/map-cbegin-and-cend-function-in-c-stl/" rel="noopener"><span>map cbegin() and cend()</span></a></td><td><p dir="ltr"><span>&nbsp;cbegin() returns a constant iterator referring to the first element in the map container. cend() returns a constant iterator pointing to the theoretical element that follows the last element in the multimap.</span></p>
</td></tr><tr><td><a href="https://www.geeksforgeeks.org/map-emplace-in-c-stl/" rel="noopener"><span>map emplace()</span></a></td><td><p dir="ltr"><span>Inserts the key and its element in the map container.</span></p>
</td></tr><tr><td><a href="https://www.geeksforgeeks.org/map-max_size-in-c-stl/" rel="noopener"><span>map max_size()&nbsp;</span></a></td><td><p dir="ltr"><span>Returns the maximum number of elements a map container can hold –&gt; O(1)</span></p>
</td></tr><tr><td><a href="https://www.geeksforgeeks.org/map-upper_bound-function-in-c-stl/" rel="noopener"><span>map upper_bound()</span></a></td><td><p dir="ltr"><span>Returns an iterator to the first element that is equivalent to mapped value with key-value ‘g’ or definitely will go after the element with key-value ‘g’ in the map</span></p>
</td></tr><tr><td><a href="https://www.geeksforgeeks.org/map-operator-in-c-stl/" rel="noopener"><span>map operator=</span></a></td><td><p dir="ltr"><span>Assigns contents of a container to a different container, replacing its current content.</span></p>
</td></tr><tr><td><a href="https://www.geeksforgeeks.org/map-lower_bound-function-in-c-stl/" rel="noopener"><span>map lower_bound()</span></a></td><td><p dir="ltr"><span>Returns an iterator to the first element that is equivalent to the mapped value with key-value ‘g’ or definitely will not go before the element with key-value ‘g’ in the map –&gt; O(log n)</span></p>
</td></tr><tr><td><a href="https://www.geeksforgeeks.org/map-emplace_hint-function-in-c-stl/" rel="noopener"><span>map emplace_hint()</span></a></td><td><p dir="ltr"><span>Inserts the key and its element in the map container with a given hint.</span></p>
</td></tr><tr><td><a href="https://www.geeksforgeeks.org/map-value_comp-in-c-stl/" rel="noopener"><span>map value_comp()&nbsp;</span></a></td><td><p dir="ltr"><span>Returns the object that determines how the elements in the map are ordered (‘&lt;‘ by default).</span></p>
</td></tr><tr><td><a href="https://www.geeksforgeeks.org/map-key_comp-function-in-c-stl/" rel="noopener"><span>map key_comp()&nbsp;</span></a></td><td><p dir="ltr"><span>Returns the object that determines how the elements in the map are ordered (‘&lt;‘ by default).</span></p>
</td></tr><tr><td><a href="https://www.geeksforgeeks.org/mapsize-c-stl/" rel="noopener"><span>map::size()</span></a></td><td><p dir="ltr"><span>Returns the number of elements in the map.</span></p>
</td></tr><tr><td><a href="https://www.geeksforgeeks.org/mapempty-c-stl/" rel="noopener"><span>map::empty()</span></a></td><td><p dir="ltr"><span>Returns whether the map is empty</span></p>
</td></tr><tr><td><a href="https://www.geeksforgeeks.org/mapbegin-end-c-stl/" rel="noopener"><span>map::begin() and end()</span></a></td><td><p dir="ltr"><span>begin() returns an iterator to the first element in the map. end() returns an iterator to the theoretical element that follows the last element in the map</span></p>
</td></tr><tr><td><a href="https://www.geeksforgeeks.org/map-operator-cpp-stl/" rel="noopener"><span>map::operator[]</span></a></td><td><p dir="ltr"><span>This operator is used to reference the element present at the position given inside the operator.</span></p>
</td></tr><tr><td><a href="https://www.geeksforgeeks.org/mapclear-c-stl/" rel="noopener"><span>map::clear()&nbsp;</span></a></td><td><p dir="ltr"><span>Removes all the elements from the map.</span></p>
</td></tr><tr><td><a href="https://www.geeksforgeeks.org/mapat-mapswap-c-stl/" rel="noopener"><span>map::at() and map::swap()</span></a></td><td><p dir="ltr"><span>at() function is used to return the reference to the element associated with the key k. swap() function is used to exchange the contents of two maps but the maps must be of the same type, although sizes may differ.</span></p>
</td></tr></tbody></table>

----
----

## `Stack`

```cpp
List of functions of Stack: 

stack::top() in C++ STL
stack::empty() and stack::size() in C++ STL
stack::push() and stack::pop() in C++ STL
stack::swap() in C++ STL
stack::emplace() in C++ STL

#include <iostream> 
#include <stack>
using namespace std;
int main() {
	stack<int> stack;
	stack.push(21);// The values pushed in the stack should be of the same data which is written during declaration of stack
	stack.push(22);
	stack.push(24);
	stack.push(25);
	int num=0;
	stack.push(num);
	stack.pop();
	stack.pop();
	stack.pop();

	while (!stack.empty()) {
		cout << stack.top() <<" ";
		stack.pop();
	}
}
22 21
```
