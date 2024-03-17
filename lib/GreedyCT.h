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

#pragma once

#include <vector>
#include <string>

#include "./CommerceTraveler.h"

class GreedyCommerceTraveler: public CommerceTraveler {
 public:
  GreedyCommerceTraveler(): CommerceTraveler() {}

  /**
   * Solves the commerce traveler problem
   * @param graph The graph to solve
   * @param time_limit The time limit
   * @returns The resulting cost
  */
  virtual int solve(const Graph& graph, long int time_limit = FIVE_MINUTES) const override;
};