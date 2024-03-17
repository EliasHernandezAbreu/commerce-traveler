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
#include <set>

#include "./TravelingSalesman.h"
#include "utils.h"

class DynamicTravelingSalesman: public TravelingSalesman {
 public:
  /**
   * Solves the Traveling salesman problem
   * @param graph The graph to solve
   * @param time_limit The time limit
   * @returns The resulting cost
  */
  virtual int solve(const Graph& graph, long int time_limit = FIVE_MINUTES) override;

 private:
  /**
   * Recursive function to solve the TSP
   * @param graph The graph with the nodes
   * @param position The number of cities added to the solution
   * @param mark A number whose bits represent the already visited cities
  */
  int recursionTSP(const Graph& graph, int position, int mask);

  TIME_POINT starting_time;
  long int time_limit;
  int** DP;
  int** parent;
};