/**
 * DAA - Lab 6
 * The commerce traveler
 * 
 * @author Elías Hernández Abreu <alu0101487137@ull.edu.es>
 * @since 14/03/24
 * 
 * 
 * @file Class that represents a complete graph with weights
*/

#pragma once

#include <vector>
#include <string>
#include <fstream>

struct GraphNode {
  std::string name;
  std::vector<GraphNode*> connections;
  std::vector<int> weights;
};

class Graph {
 public:
  /**
   * Initializates the object from an input stream
   * @param input The stream to get the definition from
  */
  Graph(std::ifstream& input);

  /**
   * Destructs the graph nodes
  */
  ~Graph();

 private:
  std::vector<GraphNode*> nodes;
};