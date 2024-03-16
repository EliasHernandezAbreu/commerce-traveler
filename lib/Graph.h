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
   * Default constructor: builds an empty graph
  */
  Graph() {}

  /**
   * Initializates the object from an input stream
   * @param file_path The path to the file with the information
  */
  Graph(const std::string& file_path);

  /**
   * Destructs the graph nodes
  */
  ~Graph();

  /**
   * Returns a string with the path to the file with this graph information
   * @returns The path to the source file of the graph
  */
  const std::string& sourcePath() const;

 private:
  std::vector<GraphNode*> nodes;
  std::string source_path;
};