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
   * @returns The resulting cost 
  */
  virtual int solve(const Graph& graph, long int time_limit = FIVE_MINUTES) const = 0;

  /**
   * Gets the time it took to solve the last problem
   * @returns The time it took in the previous execution or -1 if it didnt finish
  */
  long int getTimeTook() const;

  /**
   * Gets the path of the solution of the last problem
   * @returns A string with the solution path of the last problem
  */
  const std::string& getPath() const;

 protected:
  mutable std::string path;
  mutable long int time_took;
};