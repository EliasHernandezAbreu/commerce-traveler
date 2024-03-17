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

#pragma once

#include <vector>
#include <string>

#include "./TravelingSalesman.h"

class DynamicTravelingSalesman: public TravelingSalesman {
 public:
  /**
   * Solves the Traveling salesman problem
   * @param graph The graph to solve
   * @param time_limit The time limit
   * @returns The resulting cost
  */
  virtual int solve(const Graph& graph, long int time_limit = FIVE_MINUTES) const override;
};