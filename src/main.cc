/**
 * DAA - Lab 6
 * The commerce traveler
 * 
 * @author Elías Hernández Abreu <alu0101487137@ull.edu.es>
 * @since 14/03/24
 * 
 * 
 * @file Main file
*/

#include <stdio.h>
#include <chrono>
#include <string>
#include <filesystem>
#include <fstream>

#include "../lib/Graph.h"
#include "../lib/utils.h"

#define NOW std::chrono::high_resolution_clock::now()
#define TIME_POINT std::chrono::system_clock::time_point
#define TIME_DELTA(t1, t2) std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count()


int main(int argc, char** argv) {
  if (argc != 2) {
    printf("The program must receive one argument with the name of the folder with the tests.\n");
    printf("Usage: commerce.out <folderpath>\n");
  }

  std::string folder_path = argv[1];
  std::vector<Graph> graphs = graphsFromFolder(folder_path);

  printf("Longlong size: %lu\n", sizeof(long long));
  
}