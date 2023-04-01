#include <iostream>
#include <stdexcept>
#include <vector>
#include <forward_list>
#include "getAccess.hpp"
#include "details.hpp"

void task1(std::function<bool(const int&, const int&)> sortOrder)
{
  std::vector<int> inputVector;
  int number;
  while (std::cin >> number)
  {
    inputVector.push_back(number);
  }
  if (!std::cin.eof())
  {
    throw std::invalid_argument("input error");
  }
  if (inputVector.empty())
  {
    return;
  }


  std::vector<int> vector2(inputVector);
  std::forward_list<int> list(inputVector.begin(), inputVector.end());

  detail::sort<AccessByOperator>(inputVector, sortOrder);
  detail::print(inputVector, " ");
  std::cout << '\n';

  detail::sort<AccessByAt>(vector2, sortOrder);
  detail::print(vector2, " ");
  std::cout << '\n';

  detail::sort<AccessByIterator>(list, sortOrder);
  detail::print(list, " ");
  std::cout << '\n';
}
