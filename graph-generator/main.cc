/**
 * DAA - Lab 6
 * The commerce traveler
 * 
 * @author Elías Hernández Abreu <alu0101487137@ull.edu.es>
 * @since 14/03/24
 * 
 * 
 * @file Generates a graph with the given amount of nodes and saves it to a file
*/

#include <cstdio>
#include <cstdlib>
#include <string>
#include <fstream>

/**
 * Returns a string with the instance of the graph ready to be printed
 * @param size The amount of nodes
 * @returns The text definition of the graph
*/
std::string generateGraphInstance(int size) {
  std::string result = std::to_string(size) + '\n';
  for (int current_node = 0; current_node < size; current_node++) {
    for (int current_link = current_node + 1; current_link < size; current_link++) {
      result += std::to_string(current_node) + ' ' + std::to_string(current_link) + ' '
             + std::to_string(rand() % 100) + '\n';
    }
  }
  return result;
}

int main(int argc, char** argv) {
  srand(time(NULL));

  if (argc != 3) {
    printf("The program must take two arguments: The amount of nodes and the file to write.\n");
    printf("Usage: %s <amount> <filepath>\n", argv[0]);
    return 1;
  }

  int node_amount;
  try {
    node_amount = std::stoi(argv[1]);
  } catch (...) {
    printf("First argument must be a number! Received '%s", argv[1]);
    return 1;
  }

  std::ofstream out(argv[2]);
  if (out.bad()) {
    printf("Couldnt open file for writting '%s'", argv[2]);
  }

  out << generateGraphInstance(node_amount);

  out.flush();
  out.close();

  return 0;
}