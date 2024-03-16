/**
 * DAA - Lab 6
 * The commerce traveler
 * 
 * @author Elías Hernández Abreu <alu0101487137@ull.edu.es>
 * @since 14/03/24
 * 
 * 
 * @file Useful functions for the program
*/

#include <filesystem>

#include "../lib/utils.h"

std::vector<Graph> graphsFromFolder(const std::string& folder_path) {
  std::vector<Graph> graphs;
  for (std::filesystem::directory_entry entry : std::filesystem::directory_iterator(folder_path)) {
    std::ifstream input_file(entry.path().c_str());
    if (input_file.bad()) {
      printf("Couldn't open file %s.\n", entry.path().c_str());
      continue;
    }
    graphs.push_back(Graph(input_file));
  }
  return graphs;
}