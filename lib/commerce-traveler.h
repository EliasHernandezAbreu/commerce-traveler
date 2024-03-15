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

class CommerceTraveler {
 
 public:
  
  /**
   * Solves the problem
   * @param solution The vector in which to store the solution
   * @returns The cost of the solution 
  */
  virtual int solve(std::vector<int>& solution) const = 0;
};