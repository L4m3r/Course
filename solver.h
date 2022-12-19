#include "dsu.h"
#include "utils.h"

class solver {
public:
    solver(graph* g);
    ~solver();
    int get_ans();
    graph::edge* get_tree();
private:
    int ans;
    graph::edge* tree;
    void solve(graph* g);
};
