/**
 * DAA - Lab 6
 * The Traveling salesman
 * 
 * @author Elías Hernández Abreu <alu0101487137@ull.edu.es>
 * @since 14/03/24
 * 
 * 
 * @file Traveling salesman problem solver using a dynamic algorithm
*/

#include <math.h>

#include "../lib/DynamicTS.h"
#include "../lib/utils.h"

#define MAX 2147483647
#define MIN(m1, m2) (m1 < m2 ? m1 : m2)

int DynamicTravelingSalesman::solve(const Graph& graph, long int time_limit) {
  starting_time = NOW;
  int n = graph.getSize();
  this->time_limit = time_limit;
  DP = new int*[n + 1];
  parent = new int*[n + 1];
  for (int i = 0; i < n + 1; i++) {
    DP[i] = new int[1 << (n + 1)];
    parent[i] = new int[1 << (n + 1)];
    for (int j = 0; j < (1 << (n + 1)); j++) {
      DP[i][j] = -1;
      parent[i][j] = -1;
    }
  }
  int cost = recursionTSP(graph, 0, 1);

  path = graph.getNodeName(0);
  int current_node = 0;
  int current_mask = 1;
  while (parent[current_node][current_mask] != -1) {
    path += " -> " + graph.getNodeName(parent[current_node][current_mask]);
    current_node = parent[current_node][current_mask];
    current_mask = current_mask | (1 << current_node);
  }
  path += " -> " + graph.getNodeName(0);

  time_took = TIME_DELTA(starting_time, NOW);
  return cost;
}

int DynamicTravelingSalesman::recursionTSP(const Graph& graph, int position, int mask) {
  if (TIME_DELTA(starting_time, NOW) > time_limit) {
    return graph.getWeight(position, 0);
  }
  if (mask == ((1 << graph.getSize()) - 1)) {
    return graph.getWeight(0, position);
  }
  if (DP[position][mask] != -1) {
    return DP[position][mask];
  }
 
  int answer = MAX;
  for (int j = 0; j < graph.getSize(); j++) {
    if (!(mask & (1 << j))) {
      int current_value = recursionTSP(graph, j, mask | (1 << j)) + graph.getWeight(j, position);
      if (current_value < answer) {
        answer = current_value;
        parent[position][mask] = j;
      }
    }
  }
  DP[position][mask] = answer;
  return answer;
}