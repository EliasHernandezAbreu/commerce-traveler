/**
 * DAA - Lab 6
 * The commerce traveler
 * 
 * @author Elías Hernández Abreu <alu0101487137@ull.edu.es>
 * @since 14/03/24
 * 
 * 
 * @file Commerce traveler problem solver using brute force
*/

#pragma once

#include <vector>
#include <string>

#include "./CommerceTraveler.h"

class BruteForceCommerceTraveler: public CommerceTraveler {
 public:
  /**
   * Solves the commerce traveler problem
   * @param solution The vector in which to store the solution
   * @returns The resulting path 
  */
  virtual std::vector<std::string> solve(const Graph& graph, int time_limit = FIVE_MINUTES) const override;
};