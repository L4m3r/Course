#include "solver.h"

solver::solver(graph* g) {
    tree = new graph::edge[g->get_num_vertices()-1];
    solve(g);
}

solver::~solver() {
    delete [] tree;
}

void solver::solve(graph* g) {
    ans = 0;
    dsu p(g->get_num_vertices());

    graph::edge* sorted_graph = g->get_graph();
    sort(sorted_graph, sorted_graph + g->get_num_edges() - 1);
    
    int counter = 0;
    for (int i=0; i<g->get_num_edges(); i++) {
        if (counter == g->get_num_vertices() - 1) break;

        graph::edge edge = sorted_graph[i];

        if (p.find(edge.first) != p.find(edge.second)) {
            ans += edge.val;
            tree[counter] = edge;
            p.unite(edge.first, edge.second);
            counter++;
        }
    }

}

int solver::get_ans() {
    return ans;
}

graph::edge* solver::get_tree() {
    return tree;
}
