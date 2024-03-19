/**
 * DAA - Lab 6
 * The Traveling salesman
 * 
 * @author Elías Hernández Abreu <alu0101487137@ull.edu.es>
 * @since 14/03/24
 * 
 * 
 * @file Class that represents a complete graph with weights
*/

#pragma once

#include <string>
#include <fstream>

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
   * Returns the weight between two nodes
   * @param from One of the nodes
   * @param to The other node
   * @returns The weight of the link or -1 if doesnt exist
  */
  int getWeight(int from, int to) const;

  /**
   * Returns the name of a node
   * @param node The node to get the name of
   * @returns The name of the node
  */
 
  const std::string& getNodeName(int node) const;
  /**
   * Returns a string with the path to the file with this graph information
   * @returns The path to the source file of the graph
  */
  const std::string& getSourcePath() const;
  
  /**
   * Returns the size of the graph
   * @returns The amount of nodes the graph has
  */
  int getSize() const;

 private:
  int size;
  int** weights;
  std::string* names;
  std::string source_path;

};