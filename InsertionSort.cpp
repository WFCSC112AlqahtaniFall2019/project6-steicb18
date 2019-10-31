#include <iostream>
#include <vector>
#include <cassert>
#include "BinaryInsertionSort.h"
#include "Node.h"
#include "LinkedList.h"
#include <ctime>
using namespace std;

using namespace std;

int main() {


    int seed, length;
    cin >> seed >> length;
    srand(seed);

    vector<int> v(length);
    linkedList list;


    // generate vector of random integers
    for (int i = 0; i < v.size(); i++) {
        v[i] = rand() % 100;
        list.Append(v[i]);
    }
    // binary insertion sort
    insertionSort(v, v.size());
    list.insertionSort();

    // check if sorted
    for (int i = 1; i < v.size(); i++) {
        assert(v[i-1] <= v[i]);
    }
    // print out sorted list
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }
    list.printList();

    // FINISH ME

}