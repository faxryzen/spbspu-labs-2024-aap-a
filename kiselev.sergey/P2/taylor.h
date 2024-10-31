#ifndef TAYLOR_H
#define TAYLOR_H
#include <cstddef>
namespace kiselev
{
  double f(double x, size_t k, double error);
  double sqr_unox(double x);
  void output_table(double number, size_t k, double error);
  bool check_interval(double left, double right);
}
#endif
