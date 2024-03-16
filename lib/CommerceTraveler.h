/**
 * DAA - Lab 6
 * The commerce traveler
 * 
 * @author Elías Hernández Abreu <alu0101487137@ull.edu.es>
 * @since 14/03/24
 * 
 * 
 * @file Commerce traveler problem solver parent class
*/

#pragma once

#include <vector>
#include <string>

#include "Graph.h"

#define FIVE_MINUTES (long long)300000

class CommerceTraveler {
 public:
  /**
   * Solves the commerce traveler problem
   * @param graph The graph to solve
   * @param time_limit The time limit
   * @returns The resulting path 
  */
  virtual std::vector<std::string> solve(const Graph& graph, int time_limit = FIVE_MINUTES) const = 0;
};