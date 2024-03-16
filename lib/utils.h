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

#pragma once

#include <string>
#include <vector>

#include "Graph.h"

/**
 * Constructs graphs from a folder with inputs
 * @param folder_path The name of the folder
 * @returns A vector with the graphs
*/
std::vector<Graph> graphsFromFolder(const std::string& folder_path);