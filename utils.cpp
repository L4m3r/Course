#include "utils.h"

void swape(graph::edge& l, graph::edge& r) {
    graph::edge tmp = l;
    l = r;
    r = tmp;
}

void sort(graph::edge *begin, graph::edge *end) {
    if (begin < end) {
        graph::edge* m = begin + (end - begin) / 2;
        graph::edge* l = begin, *r = end;

        while (l<=r) {
            while (l->val < m->val) {
                l++;
            }
            while (m->val < r->val) {
                r--;
            }
            if (l >= r) break;
            swape(*l, *r);
            l++; r--;
        }

        sort(begin, r);
        sort(r + 1, end);
    }
}

void sort(graph::edge *begin, graph::edge *end, std::function<bool(graph::edge*, graph::edge*)> comp) {
    if (begin < end) {
        graph::edge* m = begin + (end - begin) / 2;
        graph::edge* l = begin, *r = end;

        while (l<=r) {
            while (comp(l, m)) {
                l++;
            }
            while (comp(m, r)) {
                r--;
            }
            if (l >= r) break;
            swape(*l, *r);
            l++; r--;
        }

        sort(begin, r);
        sort(r + 1, end);
    }
}


void print(graph::edge *begin, graph::edge *end) {
    for (auto i=begin; i != end; i++) {
        std::cout << i->first << "->" << i->second << " Val: " << i->val << "\n";
    }
}

void print(graph::edge *begin, graph::edge *end, std::string *conv) {
    for (auto i=begin; i != end; i++) {
        std::cout << conv[i->first] << " " << conv[i->second] << "\n";
    }
}

std::string read_vertices(std::fstream& str) {
    std::string s;
    std::getline(str, s);
    return s;
}

int** read_matrix(std::fstream& str, int n) {
    int** matrix = new int*[n];

    for (int i=0; i<n; i++) {
        matrix[i] = new int[n];
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            str >> matrix[i][j];
        }
    }

    return matrix;
}

int count_vertices(std::string s) {
    int counter = 1;
    for (char a: s) if (a == ' ') counter++;
    return counter;
}

std::string* vertices_names(std::string s, int n) {
    int curr = 0;
    std::string tmp = "";
    std::string* conv = new std::string[n];

    for (int i = 0; i < (int)s.size(); i++) {
		if (s[i] == ' ') {
			conv[curr] = tmp;
			tmp = "";
			curr++;
		}
		else {
			tmp += s[i];
		}
	}

	conv[curr] = tmp;

    return conv;
}
