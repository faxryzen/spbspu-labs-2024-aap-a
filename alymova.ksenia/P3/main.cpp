#include <fstream>
#include <iostream>
#include <cstddef>
#include <stdexcept>
#include "matrix.h"
#include "cmd_parameters.h"
int main(int argc, char** argv)
{
  int num = 0;
  try
  {
    alymova::check_argc(argc);
    num = alymova::check_num(argv[1]);
  }
  catch (const std::logic_error& e)
  {
    std::cout << e.what() << "\n";
    return 1;
  }
  std::ifstream input(argv[2]);
  std::ofstream output(argv[3]);
  size_t rows = 0, cols = 0;
  input >> rows >> cols;
  if (!(input.good()))
  {
    std::cerr << "Input fail\n";
    return 2;
  }
  size_t read = 0;
  if (num == 1)
  {
    constexpr size_t static_size = 10000;
    int matrix[static_size] = {0};
    if (!((alymova::input_matrix(input, matrix, rows, cols, read)).good()) || read < rows * cols)
    {
      std::cerr << "Input failed\n";
      return 2;
    }
    alymova::change_matrix(matrix, rows, cols);
    if (output.good())
    {
      alymova::print_matrix(output, matrix, read);
      std::cout << "\n";
    }
  }
  if (num == 2)
  {
    int* matrix = nullptr;
    try
    {
      matrix = new int[rows * cols];
    }
    catch(const std::bad_alloc& e)
    {
      delete[] matrix;
      std::cerr << "Memory not allocated for array\n";
      return 1;
    }
    if (!((alymova::input_matrix(input, matrix, rows, cols, read)).good()) || read < rows * cols)
    {
      delete[] matrix;
      std::cerr << "Input failed\n";
      return 2;
    }
    alymova::change_matrix(matrix, rows, cols);
    if (output.good())
    {
      alymova::print_matrix(output, matrix, read);
      std::cout << "\n";
    }
    delete[] matrix;
  }
  return 0;
}
