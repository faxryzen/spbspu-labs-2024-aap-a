#include <cstddef>
#include <iostream>
#include "taylor.hpp"
#include "outres.hpp"

int main()
{
  double left = 0.0, right = 0.0;
  size_t series = 0;
  std::cin >> left >> right >> series;
  if (!std::cin) {
    std::cerr << "ERROR WITH ENTER";
    std::cerr << "\n";
    return 1;
  }
  if ((left > right) || (left <= -1 || right >= 1)) {
    std::cerr << "ERROR WITH GAP";
    std::cerr << "\n";
    return 1;
  }

  constexpr double error = 0.001;
  constexpr double step = 0.01;
  dribas::outall(left, right, step, series, error);

  return 0;
}
