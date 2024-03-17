/**
 * DAA - Lab 6
 * The Traveling salesman
 * 
 * @author Elías Hernández Abreu <alu0101487137@ull.edu.es>
 * @since 14/03/24
 * 
 * 
 * @file Traveling salesman problem solver parent class
*/

#include "../lib/TravelingSalesman.h"

const std::string& TravelingSalesman::getPath() const {
  return path;
}

long int TravelingSalesman::getTimeTook() const {
  return time_took;
}