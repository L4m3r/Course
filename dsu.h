class dsu {
private:
    int* p;
public:
    dsu(int n);
    ~dsu();
    int find(int x);
    void unite(int x, int y);
};

