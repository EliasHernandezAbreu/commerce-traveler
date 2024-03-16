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

}

Graph::~Graph() {
  for (GraphNode* current_node: nodes) {
    delete(current_node);
    current_node = nullptr;
  }
}