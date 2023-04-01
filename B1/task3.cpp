#include <vector>
#include <iostream>
#include <stdexcept>
#include "details.h"

void task3()
{
  int elem = 0;
  std::vector<int> vector;
  while (std::cin >> elem)
  {
    if (elem == 0)
    {
      break;
    }
    vector.push_back(elem);
  }
  if (std::cin.fail() && !std::cin.eof())
  {
    throw std::runtime_error("input error");
  }
  if (vector.empty())
  {
    return;
  }
  if (elem != 0)
  {
    throw std::invalid_argument("last element must be 0");
  }
  if (vector.back() == 1)
  {
    for (auto i = vector.begin(); i != vector.end();)
      if (*i % 2 == 0)
      {
        i = vector.erase(i);
      }
      else
      {
        ++i;
      }
  }
  else if (vector.back() == 2)
  {
    for (auto i = vector.begin(); i != vector.end();)
    {
      if (*i % 3 == 0)
      {
        i = vector.insert(++i, 3, 1) + 3;
      }
      else
      {
        ++i;
      }
    }
  }
  detail::print(vector, " ");
}
