class graph {
public:
    struct edge {
        int val;
        int first;
        int second;
    };
    graph(int** matrix, int n);
    ~graph();
    edge* get_graph();
    int get_num_edges();
    int get_num_vertices();
private:
    edge* g;
    int num_edges;
    int num_vertices;
    int count_edges(int** matrix, int n);
};
