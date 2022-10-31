
#include "orca.h"

// Parameter 1 : path to graph file
int main(int argc, char* argv[])
{
  std::cout << "0 ... Reading " << argc << " input parameters" << std::endl;
  read_count_write_orca(argv[1]);
  return 0;
} 
