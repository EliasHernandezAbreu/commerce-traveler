/**
 * DAA - Lab 6
 * The commerce traveler
 * 
 * @author Elías Hernández Abreu <alu0101487137@ull.edu.es>
 * @since 14/03/24
 * 
 * 
 * @file Definition of Graph clas
*/

#include "../lib/Graph.h"

Graph::Graph(std::ifstream& input) {
  int nodes_size;
  input >> nodes_size;
  for (int current_node = 0; current_node < nodes_size; current_node++) {
    nodes.push_back(new GraphNode);
  }
  for (int current_node = 0; current_node < nodes_size; current_node++) {
    for (int current_link = current_node + 1; current_link < nodes_size; current_link++) {
      input >> nodes[current_node]->name;
      input >> nodes[current_link]->name;
      int link_weight;
      input >> link_weight;
      nodes[current_node]->connections.push_back(nodes[current_link]);
      nodes[current_node]->weights.push_back(link_weight);
      nodes[current_link]->connections.push_back(nodes[current_node]);
      nodes[current_link]->weights.push_back(link_weight);
    }
  }
}

Graph::~Graph() {
  for (int current_node = 0; current_node < nodes.size(); current_node++) {
    if (nodes[current_node] == nullptr) continue;
    delete(nodes[current_node]);
    nodes[current_node] = nullptr;
  }
}