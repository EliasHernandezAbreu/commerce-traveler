/**
 * DAA - Lab 6
 * The commerce traveler
 * 
 * @author Elías Hernández Abreu <alu0101487137@ull.edu.es>
 * @since 14/03/24
 * 
 * 
 * @file Commerce traveler problem solver using a dynamic algorithm
*/

#pragma once

#include <vector>
#include <string>

#include "./CommerceTraveler.h"

class DynamicCommerceTraveler: public CommerceTraveler {
 public:
  /**
   * Solves the commerce traveler problem
   * @param graph The graph to solve
   * @param path The resulting path
   * @param time_limit The time limit
   * @returns The resulting cost
  */
  virtual int solve(const Graph& graph, std::string& path, long int& time_took, long int time_limit = FIVE_MINUTES) const override;
};