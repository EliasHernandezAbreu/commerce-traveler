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

#include "../lib/DynamicTS.h"


int DynamicTravelingSalesman::solve(const Graph& graph, long int time_limit) const {
  int size = graph.getSize();
  int** table = new int*[size];
  for (int i = 0; i < size; i++) {
    table[i] = new int[size];
  }

  

  for (int i = 0; i < size; i++) {
    delete[] table[i];
  }
  delete[] table;
  return 0;
}