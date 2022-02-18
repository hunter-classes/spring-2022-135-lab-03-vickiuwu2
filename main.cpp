#include "reservoir.h"
#include "reverseorder.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <string>

int main()
{
  double x = get_east_storage("05/20/2018");
  std::cout << x << std::endl;

  double y = get_min_east();
  std::cout << y << std::endl;

  double z = get_max_east();
  std::cout << z << std::endl;

  std::string str = compare_basins("09/13/2018");
  std::cout << str << std::endl;

  reverse_order("05/29/2018", "06/02/2018");

  return 0;
}
