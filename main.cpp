#include <iostream>
#include <fstream>
#include <string>
#include "solver.h"

int main() {
    std::fstream fs;
    fs.open("in");

    std::string vert = read_vertices(fs);
    int n = count_vertices(vert);
    int **mat;
    mat = read_matrix(fs, n);

    graph g = graph(mat, n);
    solver sol = solver(&g);

    graph::edge* tree = sol.get_tree();
    sort(tree, tree + g.get_num_vertices() - 2, 
    [](graph::edge* x, graph::edge* y) {
        if (x->first < y->first) return true;
        if (x->first > y->first) return false;
        if (x->second < y->second) return true;
        return false;
    });

    print(tree, tree + g.get_num_vertices() - 2, vertices_names(vert, n));
    std::cout << sol.get_ans() << "\n";
    
    return 0;
}
