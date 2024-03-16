/**
 * DAA - Lab 6
 * The commerce traveler
 * 
 * @author Elías Hernández Abreu <alu0101487137@ull.edu.es>
 * @since 14/03/24
 * 
 * 
 * @file Commerce traveler problem solver using greedy algorithm
*/

#include <vector>
#include <string>
#include <algorithm>

#include "../lib/utils.h"
#include "./../lib/GreedyCT.h"

int GreedyCommerceTraveler::solve(const Graph& graph, std::string& path, int time_limit) const {
  TIME_POINT starting_time = NOW;
  std::vector<const GraphNode*> used_nodes;
  const GraphNode* current_node = graph.get(0);
  path = current_node->name;
  int cost = 0;


  for (int current_node_index = 1; current_node_index < graph.size(); current_node_index++) {
    if (TIME_DELTA(starting_time, NOW) > time_limit) {
      return cost;
    }

    used_nodes.push_back(current_node);
    
    int best_connection = 0;
    for (int current_connection = 1; current_connection < current_node->connections.size(); current_connection++) {
      if (std::find(used_nodes.begin(), used_nodes.end(), current_node->connections[current_connection]) != used_nodes.end()) {
        // ALREADY USED
        continue;
      }
      if (current_node->weights[current_connection] < current_node->weights[best_connection] ||
          std::find(used_nodes.begin(), used_nodes.end(), current_node->connections[best_connection]) != used_nodes.end()) {
        best_connection = current_connection;
      }
    }

    cost += current_node->weights[best_connection];
    current_node = current_node->connections[best_connection];
    path += " -> " + current_node->name;
  }

  int start_node_connection;
  for (int i = 0; i < current_node->connections.size(); i++) {
    if (current_node->connections[i] == graph.get(0)) {
      start_node_connection = i;
      break;
    }
  }
  path += " -> " + current_node->connections[start_node_connection]->name;
  cost += current_node->weights[start_node_connection];

  return cost;
}