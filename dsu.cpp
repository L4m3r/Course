#include "dsu.h"

dsu::dsu(int n) {
    p = new int[n];
    for (int i=0; i<n; i++) {
        p[i] = i;
    }
}

dsu::~dsu() {
    delete [] p;
}

int dsu::find(int x) {
    return p[x] == x ? x : find(p[x]);
}

void dsu::unite(int x, int y) {
    x = find(x);
    y = find(y);
    p[x] = y;
}

