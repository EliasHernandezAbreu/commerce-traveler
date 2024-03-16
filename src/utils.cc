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

Graph** graphsFromFolder(const std::string& folder_path, int& graphs_size) {
  if (!std::filesystem::is_directory(folder_path)) {
    throw std::runtime_error("Folder is not a directory!");    
  }
  
  graphs_size = std::distance(std::filesystem::directory_iterator{folder_path}, std::filesystem::directory_iterator{});
  Graph** graphs = new Graph*[graphs_size];
  int current_entry = 0;
  for (std::filesystem::directory_entry entry : std::filesystem::directory_iterator(folder_path)) {
    std::ifstream input_file(entry.path().c_str());
    if (input_file.bad()) {
      printf("Couldn't open file %s.\n", entry.path().c_str());
      continue;
    }
    graphs[current_entry] = new Graph(input_file);
    current_entry++;
  }
  return graphs;
}