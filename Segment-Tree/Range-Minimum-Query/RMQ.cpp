#include <iostream>
#include <climits>

using namespace std;

int buildSegmentTree (int *a, int l, int r, int *st, int i) {
        if (l == r)
                return (st[i] = a[l]);
        int mid = (l + r) / 2;
        st[i] = min (buildSegmentTree (a, l, mid, st, i * 2 + 1), buildSegmentTree (a, mid + 1, r, st, i * 2 + 2));
        return st[i];
}

int query (int *st, int l, int r, int s, int e, int i) {
        if (s >= l && e <= r)
                return st[i];
        if (s > r || e < l)
                return INT_MAX;
        int mid = (s + e) / 2;
        return min (query (st, l, r, s, mid, i * 2 + 1), query (st, l, r, mid + 1, e, i * 2 + 2));
}

int main () {
        
        return 0;
}
