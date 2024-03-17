/**
 * DAA - Lab 6
 * The Traveling salesman
 * 
 * @author Elías Hernández Abreu <alu0101487137@ull.edu.es>
 * @since 14/03/24
 * 
 * 
 * @file Traveling salesman problem solver using greedy algorithm
*/

#include <set>

#include "../lib/utils.h"
#include "../lib/GreedyTS.h"

int GreedyTravelingSalesman::solve(const Graph& graph, long int time_limit) {
  TIME_POINT starting_time = NOW;
  std::set<int> used_nodes;
  int current_node = 0;
  path = graph.getNodeName(0);
  int cost = 0;

  for (int current_node_index = 1; current_node_index < graph.getSize(); current_node_index++) {
    if (TIME_DELTA(starting_time, NOW) > time_limit) {
      time_took = -1;
      return cost;
    }

    used_nodes.insert(current_node);
    
    int best_connection = 0;
    for (int current_connection = 1; current_connection < graph.getSize(); current_connection++) {
      if (used_nodes.find(current_connection) != used_nodes.end()) {
        // used node
        continue;
      }
      if (graph.getWeight(current_node, current_connection) < graph.getWeight(current_node, best_connection) ||
          used_nodes.find(best_connection) != used_nodes.end()) {
        best_connection = current_connection;
      }
    }

    cost += graph.getWeight(current_node, best_connection);
    path += " -> " + graph.getNodeName(best_connection);
    current_node = best_connection;
  }

  cost += graph.getWeight(current_node, 0);
  path += " -> " + graph.getNodeName(0);

  time_took = TIME_DELTA(starting_time, NOW);
  return cost;
}