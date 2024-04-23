#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
const int MAX = 1e4 + 5;
int id[MAX], nodes, edges;
pair <long long, pair<int, int> > p[MAX];

void init()
{
    for (int i = 0; i < MAX; ++i)
        id[i] = i;
}

int root(int a)
{
    while (id[a] != a)
    {
        id[a] = id[id[a]];
        a = id[a];
    }
    return a;
}

void unionab(int a, int b)
{
    int p = root(a);
    int q = root(b);
    id[p] = id[q];
}

void kruskal(pair<long long, pair<int, int> > p[], vector<string>& vec)
{
    int a, b;
    long long cost;
    cout <<"MST: " << endl;
    for (int i = 0; i < edges; ++i)
    {
        a = p[i].second.first;
        b = p[i].second.second;
        cost = p[i].first;
        if (root(a) != root(b))
        {
            unionab(a, b);
            cout << a <<"."<< vec[a-1] <<" "<< b << "." << vec[b-1] << " weight: " << cost << endl;
        }
    }
    
}

int main()
{
    int a, b;
    long long weight, cost;
    init();
    cout << "Enter number of Nodes: "<<endl;
    cin >> nodes;
    cout << endl;
    string c;
    int nodewhile = 0;
 
    vector<string> vecnode;
    cout << "Enter Nodes: " << endl;
    while (nodewhile < nodes) {
        cout << nodewhile+1 << ". ";
        cin >> c;
        if ((c.size()) <= 8) {
            char* arrayofchar = new char[c.size() + 1];
            strcpy_s(arrayofchar, c.size() + 1, c.c_str());
            vecnode.push_back(arrayofchar);
            delete[] arrayofchar;
            nodewhile++;
        }
        else
        {
            cout << "Error: MAX size of name is 8 char. " << endl;
        }
    }
    cout << endl;
    cout << "Enter number of Edges: "<<endl;
    cin >> edges;
    cout << endl;
    cout << "Enter Edges: " << endl;
    for (int i = 0; i < edges; ++i)
    {
        cout << "Enter the A, B and Weight value: ";
        cin >> a >> b >> weight;
        p[i] = make_pair(weight, make_pair(a, b));
    }
    cout << endl;
    sort(p, p + edges);
    kruskal(p, vecnode);
    
    return 0;
}