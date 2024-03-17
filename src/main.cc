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


int main(int argc, char** argv) {
  long long time_limit = FIVE_MINUTES;
  std::string output_file = "";
  std::string folder_path = "";
  for (int param = 1; param < argc; ++param) {
    if (strcmp(argv[param], "-h") == 0) {
      printf("Usage: %s [options] <inputfolder>\n", argv[0]);
      printf("Solves the commerce traveler problem using brute force, greedy and dynamic algorithms.\n");
      printf("-h : Displays this message.\n");
      printf("-o <filename> : Writes the output as a markdown file to <filename>.\n");
      printf("-t <timelimit> : Sets the time limit of the executions (in seconds).\n");
      return 0;
    } else if (strcmp(argv[param], "-o") == 0) {
      output_file = argv[++param];
      output_file += ".md";
    } else if (strcmp(argv[param], "-t") == 0) {
      try {
        time_limit = std::stoi(argv[++param]) * 1000;
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

  std::ofstream out;
  if (output_file != "") {
    out = std::ofstream(output_file);
    if (out.bad()) {
      printf("Cant write to output file '%s'", output_file.c_str());
      return 1;
    }
  }

  Graph** graphs;
  int graphs_size;
  try {
    graphs = graphsFromFolder(folder_path, graphs_size);
  } catch (...) {
    printf("The path specified (%s) does not lead to a folder!\n", folder_path.c_str());
    return 1;
  }

  BruteForceCommerceTraveler brute_force_ct;
  GreedyCommerceTraveler greedy_ct;
  DynamicCommerceTraveler dynamic_ct;

  if (output_file != "") {
    out << "| Instance | Cost brute force | Time brute force (ms) | Cost greedy | Time greedy (ms) | Cost dynamic | Time dynamic (ms) |\n"
        << "| -------- | ---------------- | --------------------- | ----------- | ---------------- | ------------ | ----------------- |\n";
  }

  for (int current_graph = 0; current_graph < graphs_size; current_graph++) {

    printf("Starting file %s.\n", graphs[current_graph]->getSourcePath().c_str());

    int brute_force_cost = brute_force_ct.solve(*graphs[current_graph], time_limit);
    int greedy_cost = greedy_ct.solve(*graphs[current_graph], time_limit);
    int dynamic_cost = dynamic_ct.solve(*graphs[current_graph], time_limit);

    if (output_file == "") {
      printf("\n== FILE == : %s\n", graphs[current_graph]->getSourcePath().c_str());

      if (brute_force_ct.getTimeTook() == -1) printf("Brute force: Time: %s, Cost: %d\n", "EXCESSIVE", brute_force_cost);
      else printf("Brute force: Time: %ldms, Cost: %d\n", brute_force_ct.getTimeTook(), brute_force_cost);
      // printf("Path: %s", brute_force_ct.getPath().c_str());

      if (greedy_ct.getTimeTook() == -1) printf("Greedy: Time: %s, Cost: %d\n", "EXCESSIVE", greedy_cost);
      else printf("Greedy: Time: %ldms, Cost: %d\n", greedy_ct.getTimeTook(), greedy_cost);
      // printf("Path: %s", greedy_ct.getPath().c_str());
      
      if (dynamic_ct.getTimeTook() == -1) printf("Dynamic: Time: %s, Cost: %d\n", "EXCESSIVE", dynamic_cost);
      else printf("Dynamic: Time: %ldms, Cost: %d\n", dynamic_ct.getTimeTook(), dynamic_cost);
      // printf("Path: %s", dynamic_ct.getPath().c_str());
    } else {
      out << "| "  << graphs[current_graph]->getSourcePath()
          << " | " << brute_force_cost
          << " | " << (brute_force_ct.getTimeTook() == -1 ? "EXCESSIVE" : std::to_string(brute_force_ct.getTimeTook()).c_str())
          << " | " + std::to_string(greedy_cost)
          << " | " << (greedy_ct.getTimeTook() == -1 ? "EXCESSIVE" : std::to_string(greedy_ct.getTimeTook()).c_str())
          << " | " + std::to_string(dynamic_cost)
          << " | " << (dynamic_ct.getTimeTook() == -1 ? "EXCESSIVE" : std::to_string(dynamic_ct.getTimeTook()).c_str()) 
          << " |\n";
      out.flush();
    }
  }

  out.close();
  for (int current_graph = 0; current_graph < graphs_size; current_graph++) {
    delete graphs[current_graph];
  }
  delete[] graphs;
  return 0;
}