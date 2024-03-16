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
#include <cstring>

#include "../lib/Graph.h"
#include "../lib/utils.h"

#include "../lib/BruteForceCT.h"
#include "../lib/GreedyCT.h"
#include "../lib/DynamicCT.h"

#define NOW std::chrono::high_resolution_clock::now()
#define TIME_POINT std::chrono::system_clock::time_point
#define TIME_DELTA(t1, t2) std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count()


int main(int argc, char** argv) {
  long long time_limit = FIVE_MINUTES;
  std::string output_file = "";
  std::string folder_path = "";
  for (int param = 1; param < argc; param++) {
    if (strcmp(argv[param], "-h") == 0) {
      printf("Usage: %s [options] <inputfolder>\n", argv[0]);
      printf("Solves the commerce traveler problem using brute force, greedy and dynamic algorithms.\n");
      printf("-h : Displays this message.\n");
      printf("-o <filename> : Writes the output as a markdown file to <filename>.\n");
      printf("-t <timelimit> : Sets the time limit of the executions (in seconds).\n");
      return 0;
    } else if (strcmp(argv[param], "-o") == 0) {
      output_file = argv[++param];
    } else if (strcmp(argv[param], "-t") == 0) {
      try {
        time_limit = std::stoi(argv[++param]);
      } catch (...) {
        printf("Option -t must receive a number. Received '%s'", argv[param - 1]);
        return 1;
      }
    } else {
      folder_path = argv[param];
    }
  }

  if (folder_path == "") {
    printf("Program must receive the path to the folder with input files as an argument.\n");
    return 1;
  }

  std::vector<Graph> graphs;
  try {
    graphs = graphsFromFolder(folder_path);
  } catch (...) {
    printf("The path specified (%s) does not lead to a folder!\n", folder_path.c_str());
    return 1;
  }

  BruteForceCommerceTraveler brute_force_ct;
  GreedyCommerceTraveler greedy_ct;
  DynamicCommerceTraveler dynamic_ct;

  for (Graph current_graph : graphs) {

    

    std::vector<std::string> brute_force_solution = brute_force_ct.solve(current_graph, time_limit);
    std::vector<std::string> greedy_solution = greedy_ct.solve(current_graph, time_limit);
    std::vector<std::string> dynamic_solution = dynamic_ct.solve(current_graph, time_limit);
  }

  return 0;
}