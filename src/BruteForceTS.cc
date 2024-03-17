/**
 * DAA - Lab 6
 * The Traveling salesman
 * 
 * @author Elías Hernández Abreu <alu0101487137@ull.edu.es>
 * @since 14/03/24
 * 
 * 
 * @file Traveling salesman problem solver using brute force
*/

#include <set>

#include "../lib/BruteForceTS.h"
#include "../lib/utils.h"

#define MAX_INT 2147483647

#define PRINTPATH(p, n) for(int i = 0; i < n; i++) printf("%d " ,p[i]); printf("\n")

int BruteForceTravelingSalesman::solve(const Graph& graph, long int time_limit) const {
  TIME_POINT starting_time = NOW;
  int* current_path = new int[graph.getSize() + 1]();
  int* best_path = new int[graph.getSize() + 1]();
  int best_cost = MAX_INT;
  for (int iteration = 0; ; iteration++) {
    if (TIME_DELTA(starting_time, NOW) > time_limit) {
      path = graph.getNodeName(best_path[0]);
      for (int i = 1; i <= graph.getSize(); i++) {
        path += " -> " + graph.getNodeName(best_path[i]);
      }
      time_took = -1;
      delete[] current_path;
      delete[] best_path;
      return best_cost;
    }
    for (int node_position = 1; node_position <= graph.getSize(); node_position++) {
      if (node_position == graph.getSize()) {
        time_took = TIME_DELTA(starting_time, NOW);
        path = graph.getNodeName(best_path[0]);
        for (int i = 1; i <= graph.getSize(); i++) {
          path += " -> " + graph.getNodeName(best_path[i]);
        }
        delete[] current_path;
        delete[] best_path;
        return best_cost;
      }
      if (++current_path[node_position] >= graph.getSize()) {
        current_path[node_position] = 0;
      } else {
        break;
      }
    }
    current_path[graph.getSize()] = current_path[0];
    int current_cost = 0;
    std::set<int> used;
    used.insert(current_path[0]);
    for (int node_position = 1; node_position <= graph.getSize(); node_position++) {
      if (node_position < graph.getSize() && used.find(current_path[node_position]) != used.end()) {
        current_cost = MAX_INT;
        break;
      }
      used.insert(current_path[node_position]);
      current_cost += graph.getWeight(current_path[node_position], current_path[node_position - 1]);
    }
    if (current_cost < best_cost) {
      best_cost = current_cost;
      for (int i = 0; i <= graph.getSize(); i++) {
        best_path[i] = current_path[i];
      }
    }
  }
}