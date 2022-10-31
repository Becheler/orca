
#include "orca.h"

// Parameter 1 : path to graph file
int main(int argc, char* argv[])
{
  std::cout << "0 ... Reading " << argc << " input parameters" << std::endl;

  std::cout << "Initialize ORCA from file " << argv[1] << std::endl;
  OrcaParser parser;
  parser.parse(argv[1]);
  std::cout << parser << std::endl;
  std::cout << "Using default matrix implementation" << std::endl;
  graphlet_degree_vector_analysis<>(parser, generate_output_filename_from(argv[1]));

  return 0;
}
