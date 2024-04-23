#include <iostream>
#include <string>

using namespace std;

void sort(long* tab, long size);
void HeapSort(long ile);
void buildHeap(long* tab, long size);
void heapify(long* tab, long idx, long max);
void printTable(long* tab, long size);

void sort(long* tab,long size) {
    
    buildHeap(tab,size);

    for (int i = size - 1; i > 0; i--) {
        printTable(tab, i + 1);
        swap(tab[0], tab[i]);
        heapify(tab, 0, i);
    }

    printTable(tab, size);
}

void printTable(long* tab, long size) {

    for (int i = 0; i < size; i++) {
        cout << tab[i]<<" ";
      
    }
        cout << "\n";
}

void HeapSort(long ile) {
    long* tab;
    tab = new long[ile];
    for (int i = 0; i < ile; i++) {
        cin >> tab[i];
    }
    sort(tab, ile);
}

void buildHeap(long* tab, long size) {
    long s = size;
    for (int i = (s - 2)/2; i >=0; i--) {
        heapify(tab, i, s);
    }
}

void heapify(long* tab,long idx, long max) {
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    int largest=idx;
    
    if (left<max && tab[left]>tab[idx]) {
        largest = left;
    }
    else
    {
        largest = idx;
    }

    if (right<max && tab[right]>tab[largest]) {
        largest = right;
    }
    if (largest != idx) {

        swap(tab[idx], tab[largest]);
        heapify(tab, largest, max);
    }
}

int main(long* tab) {
    long ileliczb, size;
    int razy=0,podanailoscrazy;
    cin >> podanailoscrazy;
    while (razy <= podanailoscrazy) {
    cin >> ileliczb;
    HeapSort(ileliczb);
    razy++;
    }
}

