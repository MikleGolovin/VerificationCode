#include <ctime>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <random>
#include "details.hpp"

void fillRandom(double* array, int size)
{
  if(!array)
  {
    throw std::invalid_argument("array is nullptr");
  }
  if (size < 0)
  {
    throw std::invalid_argument("array size must be > 0");
  }
  std::uniform_real_distribution<double> distribution(-1, 1);
  std::default_random_engine randomizer;
  for (int i = 0; i < size; ++i)
  {
    array[i] = distribution(randomizer);
  }
}

void task4(std::function<bool(const double&, const double&)> sortOrder, size_t size)
{
  std::vector<double> vector(size);

  fillRandom(vector.data(), size);
  detail::print(vector, " ");
  std::cout << '\n';

  detail::sort<AccessByAt>(vector, sortOrder);

  detail::print(vector, " ");
}
