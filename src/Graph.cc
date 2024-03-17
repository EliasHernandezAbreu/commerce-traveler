/**
 * DAA - Lab 6
 * The Traveling salesman
 * 
 * @author Elías Hernández Abreu <alu0101487137@ull.edu.es>
 * @since 14/03/24
 * 
 * 
 * @file Definition of Graph clas
*/

#include "../lib/Graph.h"

Graph::Graph(const std::string& file_path) {
  source_path = file_path;
  std::ifstream input(file_path);
  if (input.bad()) {
    throw std::runtime_error("Cant open input file");
  }
  
  input >> size;
  names = new std::string[size];
  weights = new int*[size];

  for (int i = 0; i < size; i++) {
    weights[i] = new int[size];
  }
  
  for (int current_node = 0; current_node < size; current_node++) {
    weights[current_node][current_node] = -1;
  
    for (int current_link = current_node + 1; current_link < size; current_link++) {
      input >> names[current_node];
      input >> names[current_link];
      int link_weight;
      input >> link_weight;
      weights[current_node][current_link] = link_weight;
      weights[current_link][current_node] = link_weight;
    }
  }
}

Graph::~Graph() {
  for (int current_node = 0; current_node < size; current_node++) {
    delete[] weights[current_node];
    weights[current_node] = nullptr;
  }
  delete[] names;
  delete[] weights;
}

int Graph::getWeight(int from, int to) const {
  return weights[from][to];
}

const std::string& Graph::getNodeName(int node) const {
  return names[node];
}

const std::string& Graph::getSourcePath() const {
  return source_path;
}

int Graph::getSize() const {
  return size;
}