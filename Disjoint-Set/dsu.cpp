#include <iostream>
#include <cstdio>
using namespace std;

int root[1001], Rank[1001];

void makeSet (int x) {
    root[x] = x;
    Rank[x] = 0;
}

int findSet (int x) {
    if (root[x] != x)
        root[x] = findSet (root[x]);
    return root[x];
}

void unionSet (int x, int y) {
    int Rx = findSet(x), Ry = findSet(y);
    if (Rx == Ry)
        return;
    if (Rank[Rx] > Rank[Ry])
        root[Ry] = Rx;
    else {
        root[Rx] = Ry;
        if (Rank[Rx] == Rank[Ry])
            Rank[Ry]++;
    }
}

int main () {

	return 0;
}
