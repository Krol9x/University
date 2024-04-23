#include <iostream>
#include <list>
#include <cstring>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

struct DynamicTable {
    long key=NULL;
    string val="";
    bool keyexist = false;
};

class HashTable {
    public:
       int n = 0;
       DynamicTable* table;
       int hashFunction(int k);
       void insertItem(int k, string value);
       void removeItem(int key);
       int searchTable(int k);
       void printTable();
       void size(long size);
       void SwapFunction(int start, int frst, int index0);
};


void HashTable::size(long size) {
    table = new DynamicTable[size];
    n = size;
}

int HashTable::hashFunction(int k) {
    return (k % n);
}

void  HashTable::insertItem(int k, string value){
    int hashi = hashFunction(k);
    if (table[hashi].key == k) {
        table[hashi].val = value;
        table[hashi].keyexist = true;
    }
    else {
        for (int i=0; i < n; i++) {
            if (table[hashFunction(k + i)].key == NULL) {
                table[hashFunction(k + i)].key = k;
                table[hashFunction(k + i)].val = value;
                table[hashFunction(k + i)].keyexist = true;

                return;
            }
        }
    }
}



void  HashTable::removeItem(int k) {
    for (int i = 0; i < n; i++) {
        if (table[i].key == k) {
            table[i].key = NULL;
            table[i].val = "";
            table[i].keyexist = false;
            SwapFunction(i, i,-1);
        }
    }
    return;
}

void HashTable::SwapFunction(int l, int frst, int index0) {
    int sec = (l == n - 1) ? 0 : l + 1;
    if (frst == sec) return; 
    if (!table[sec].keyexist) return; 
    int hsh = table[sec].key % n;
    if (hsh != sec) {
        if (index0 == -1) {
            swap(table[l], table[sec]);
        }
        else {
            swap(table[index0], table[sec]);
        }
        index0 = sec;
    }
    else if (index0 == -1) {
        index0 = l;
    }
    SwapFunction(sec, frst, index0);
}

void HashTable::printTable() {
    for (int i=0; i < n; i++) {
            if (table[i].keyexist == true) {
                cout << i << " " << table[i].key << " " << table[i].val << endl;
            }
        }
}

int main()
{
    HashTable HT;
    string str1;
    int a;
    cin >> a;
        for (int i = 0; i < a; i++) {
            while (getline(cin, str1))
            {
                istringstream stream(str1);
                string token1;
                long token2;
                string token3;

                stream >> token1 >> token2 >> token3;

                if (token1 == "size")
                {
                    HT.size(token2);
                }

                if (token1 == "add")
                {
                    HT.insertItem(token2, token3);
                }

                if (token1 == "delete")
                {
                    HT.removeItem(token2);
                }

                if (token1 == "print")
                {
                    HT.printTable();
                }

                if (token1 == "stop")
                {
                    break;
                }
            }
        }
        return 0;
}

