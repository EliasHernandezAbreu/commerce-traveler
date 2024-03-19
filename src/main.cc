/**
 * DAA - Lab 6
 * The Traveling salesman
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
#include <map>

#include "../lib/Graph.h"
#include "../lib/utils.h"

#include "../lib/BruteForceTS.h"
#include "../lib/GreedyTS.h"
#include "../lib/DynamicTS.h"


int main(int argc, char** argv) {
  long long time_limit = FIVE_MINUTES;
  std::string output_file = "";
  std::string folder_path = "";
  for (int param = 1; param < argc; ++param) {
    if (strcmp(argv[param], "-h") == 0) {
      printf("Usage: %s [options] <inputfolder>\n", argv[0]);
      printf("Solves the Traveling salesman problem using brute force, greedy and dynamic algorithms.\n");
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

  BruteForceTravelingSalesman brute_force_ts;
  GreedyTravelingSalesman greedy_ts;
  DynamicTravelingSalesman dynamic_ts;

  // int is node amount, pair first is total time, pair second is amount of executions
  std::map<int, std::pair<long int, int>> per_node_brute_mean;
  std::map<int, std::pair<long int, int>> per_node_greedy_mean;
  std::map<int, std::pair<long int, int>> per_node_dynamic_mean;

  if (output_file != "") {
    out << "| Nodes | Cost brute force | Time brute force (ms) | Cost greedy | Time greedy (ms) | Cost dynamic | Time dynamic (ms) |\n"
        << "| -------- | ---------------- | --------------------- | ----------- | ---------------- | ------------ | ----------------- |\n";
  }

  for (int current_graph = 0; current_graph < graphs_size; current_graph++) {

    printf("Starting file %s.\n", graphs[current_graph]->getSourcePath().c_str());

    int brute_force_cost = brute_force_ts.solve(*graphs[current_graph], time_limit);
    int greedy_cost = greedy_ts.solve(*graphs[current_graph], time_limit);
    int dynamic_cost = dynamic_ts.solve(*graphs[current_graph], time_limit);

    int current_node_amount = graphs[current_graph]->getSize();
    if (per_node_brute_mean.count(current_node_amount)) {
      per_node_brute_mean[current_node_amount].first += brute_force_ts.getTimeTook();
      per_node_brute_mean[current_node_amount].second += 1;
    } else {
      per_node_brute_mean.emplace(current_node_amount, std::pair<int, int>(brute_force_ts.getTimeTook(), 1));
    }

    int current_node_amount = graphs[current_graph]->getSize();
    if (per_node_greedy_mean.count(current_node_amount)) {
      per_node_greedy_mean[current_node_amount].first += brute_force_ts.getTimeTook();
      per_node_greedy_mean[current_node_amount].second += 1;
    } else {
      per_node_greedy_mean.emplace(current_node_amount, std::pair<int, int>(brute_force_ts.getTimeTook(), 1));
    }

    int current_node_amount = graphs[current_graph]->getSize();
    if (per_node_dynamic_mean.count(current_node_amount)) {
      per_node_dynamic_mean[current_node_amount].first += brute_force_ts.getTimeTook();
      per_node_dynamic_mean[current_node_amount].second += 1;
    } else {
      per_node_dynamic_mean.emplace(current_node_amount, std::pair<int, int>(brute_force_ts.getTimeTook(), 1));
    }


  }
  for (std::pair<int, std::pair<long int, int>> pair : per_node_brute_mean) {
    int node = pair.first;
    if (output_file == "") {
      printf("\n== NODES == : %s\n", std::to_string(node).c_str());

      if (brute_force_ts.getTimeTook() == -1) printf("Brute force: Time: %s, Cost: %d\n", "EXCESSIVE", 1);
      else printf("Brute force: Time: %ldms, Cost: %d\n", per_node_brute_mean[node].first / per_node_brute_mean[node].second, 1);
      // printf("Path: %s", brute_force_ct.getPath().c_str());

      if (greedy_ts.getTimeTook() == -1) printf("Greedy: Time: %s, Cost: %d\n", "EXCESSIVE", 1);
      else printf("Greedy: Time: %ldms, Cost: %d\n", per_node_greedy_mean[node].first / per_node_greedy_mean[node].second, 1);
      // printf("Path: %s", greedy_ct.getPath().c_str());
      
      if (dynamic_ts.getTimeTook() == -1) printf("Dynamic: Time: %s, Cost: %d\n", "EXCESSIVE", 1);
      else printf("Dynamic: Time: %ldms, Cost: %d\n", per_node_dynamic_mean[node].first / per_node_dynamic_mean[node].second, 1);
      // printf("Path: %s", dynamic_ct.getPath().c_str());
    } else {
      out << "| "  << std::to_string(node).c_str()
          << " | " << std::to_string(1).c_str()
          << " | " << (brute_force_ts.getTimeTook() == -1 ? "EXCESSIVE" : std::to_string(per_node_brute_mean[node].first / per_node_brute_mean[node].second).c_str())
          << " | " << std::to_string(1).c_str()
          << " | " << (greedy_ts.getTimeTook() == -1 ? "EXCESSIVE" : std::to_string(per_node_greedy_mean[node].first / per_node_greedy_mean[node].second).c_str())
          << " | " << std::to_string(1).c_str()
          << " | " << (dynamic_ts.getTimeTook() == -1 ? "EXCESSIVE" : std::to_string(per_node_dynamic_mean[node].first / per_node_dynamic_mean[node].second).c_str()) 
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