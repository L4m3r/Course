#include "graph.h"
#include <iostream>
graph::graph(int** matrix, int n) {
    count_edges(matrix, n);
    num_vertices = n;

    int amount = num_edges;
    g = new edge[amount];

    int counter = 0;
    for (int i=0; i<n; i++) {
        for (int j=i; j<n; j++) {
            if (matrix[i][j] > 0) {
                g[counter++] = {matrix[i][j], i, j};
            }
        }
    }
}

graph::~graph() {
    delete [] g;
}

graph::edge* graph::get_graph() {
    return g;
}

int graph::get_num_edges() {
    return num_edges;
}

int graph::get_num_vertices() {
    return num_vertices;
}

int graph::count_edges(int** matrix, int n) {
    int edges = 0;

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (matrix[i][j] > 0) {
                edges++;
            }    
        }
    }
    num_edges = edges/2;
    return num_edges;
}
