#include <memory>
#include <vector>
#include <fstream>
#include <stdexcept>
#include "details.hpp"

void task2(const char* file)
{
  if (!file)
  {
    throw std::invalid_argument("file name is nullptr!");
  }
  std::ifstream fin(file);
  if (!fin)
  {
    throw std::invalid_argument("file is not open!\n");
  }
  size_t space = 32;
  std::unique_ptr<char[], decltype(&std::free)> array(static_cast<char *>(std::malloc(space)), &std::free);
  if (!array)
  {
    throw std::bad_alloc();
  }
  size_t size = 0;
  while (fin)
  {
    fin.read(&array[size], space - size);
    size += fin.gcount();
    if (space == size)
    {
      space = static_cast<size_t>(space * 1.8);
      std::unique_ptr<char[], decltype(&std::free)> tempArray(static_cast<char *>(std::realloc(array.get(), space)), &std::free);
      if (!tempArray)
      {
        throw std::bad_alloc();
      }
      array.release();
      std::swap(array, tempArray);
    }
  }

  std::vector<char> vector(array.get(), array.get() + size);
  detail::print(vector, "");
}
