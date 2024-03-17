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

#pragma once

#include <string>
#include <vector>
#include <chrono>

#include "Graph.h"

#define NOW std::chrono::high_resolution_clock::now()
#define TIME_POINT std::chrono::high_resolution_clock::time_point
#define TIME_DELTA(t1, t2) std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count()

/**
 * Constructs graphs from a folder with inputs
 * @param folder_path The name of the folder
 * @returns An array with the graphs
*/
Graph** graphsFromFolder(const std::string& folder_path, int& graphs_size);