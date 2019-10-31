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
    linkedList list;    //create list object


    // generate vector of random integers
    cout<<"Sorted Vector List:"<<endl;
    for (int i = 0; i < v.size(); i++) {
        v[i] = rand() % 100;
        list.Append(v[i]);      //create linked list

    }
   /* clock_t start_vInsertionSort = clock();
    // sort vector using mergeSort
    insertionSort(v, v.size());
    clock_t end_vInsertionSort = clock();


    clock_t start_lInsertionSort = clock();
    // sort array using bubbleSort
    list.insertionSort();
    clock_t end_lInsertionSort = clock();*/


    // binary insertion sort
    insertionSort(v, v.size());

    list.insertionSort();       //Call insertion sort function

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


    /*double elapsed_vInsertionSort = double(end_vInsertionSort - start_vInsertionSort) / CLOCKS_PER_SEC;
    /double elapsed_lInsertionSort = double(end_lInsertionSort - start_lInsertionSort) / CLOCKS_PER_SEC;

    cout << std::scientific;
    cout << elapsed_vInsertionSort << " " << elapsed_lInsertionSort << endl;
     */
}