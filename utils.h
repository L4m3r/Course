#include "graph.h"
#include <iostream>
#include <fstream>
#include <functional>

void swape(graph::edge& l, graph::edge& r);
void sort(graph::edge* begin, graph::edge* end);
void sort(graph::edge *begin, graph::edge *end, std::function<bool(graph::edge*, graph::edge*)> comp);

void print(graph::edge* begin, graph::edge* end);
void print(graph::edge *begin, graph::edge *end, std::string *conv);

std::string read_vertices(std::fstream& str);
int** read_matrix(std::fstream& str, int n);
int count_vertices(std::string s);
std::string* vertices_names(std::string s, int n);
