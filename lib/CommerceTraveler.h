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
   * @param path The resulting path
   * @param time_took The time it took to execute
   * @param time_limit The time limit
   * @returns The resulting cost 
  */
  virtual int solve(const Graph& graph, std::string& path, long int& time_took, long int time_limit = FIVE_MINUTES) const = 0;
};