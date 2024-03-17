/**
 * DAA - Lab 6
 * The Traveling salesman
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
    try {
      graphs[current_entry] = new Graph(entry.path().string());
    } catch (std::runtime_error e) {
      printf("Couldn't open file %s.\n", entry.path().c_str());
    }
    current_entry++;
  }
  return graphs;
}