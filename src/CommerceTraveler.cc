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

#include "../lib/CommerceTraveler.h"

const std::string& CommerceTraveler::getPath() const {
  return path;
}

long int CommerceTraveler::getTimeTook() const {
  return time_took;
}