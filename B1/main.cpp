#include <iostream>
#include <sstream>
#include <cstring>
#include <stdexcept>
#include <cstdlib>
#include "details.hpp"


void task1(std::function<bool(const int&, const int&)> sortOrder);
void task2(const char* file);
void task3();
void task4(std::function<bool(const double&, const double&)> sortType, size_t size);

int main(int argc, char* argv[])
{
  try
  {
    if (argc < 2)
    {
      throw std::invalid_argument("count of arguments is incorrect");
    }
    std::istringstream str(argv[1]);
    size_t taskNumber;
    str >> taskNumber;
    if (str.fail())
    {
      throw std::invalid_argument("fail read taskNumber");
    }
    switch (taskNumber)
    {
      case 1:
        if (argc != 3)
        {
          throw std::invalid_argument("count of arguments for task1 is incorrect");
        }
        try
        {
          auto sortOrder = detail::getComparator<int>(argv[2]);
          task1(sortOrder);
        }
        catch (const std::invalid_argument& error)
        {
          std::cerr << error.what();
          return 1;
        }
        break;
      case 2:
        if (argc != 3)
        {
          throw std::invalid_argument("count of arguments for task2 is incorrect");
        }
        try
        {
          task2(argv[2]);
        }
        catch (const std::invalid_argument& error)
        {
          std::cerr << error.what();
          return 1;
        }
        catch (const std::bad_alloc& error)
        {
          std::cerr << error.what();
          return -1;
        }

        break;
      case 3:
        if (argc != 2)
        {
          throw std::invalid_argument("count of arguments for task3 is incorrect");
        }
        try
        {
          task3();
        }
        catch (const std::invalid_argument& error)
        {
          std::cerr << error.what();
          return 1;
        }
        catch (const std::runtime_error& error)
        {
          std::cerr << error.what();
          return 1;
        }
        break;
      case 4:
        if (argc != 4)
        {
          throw std::invalid_argument("count of arguments for task3 is incorrect");
        }
        try
        {
          std::istringstream tempSize(argv[3]);
          size_t size;
          tempSize >> size;
          if (tempSize.fail())
          {
            throw std::invalid_argument("fail read size for task4");
          }
          auto sortOrder = detail::getComparator<double>(argv[2]);
          task4(sortOrder, size);
          break;
        }
        catch (const std::invalid_argument& error)
        {
          std::cerr << error.what();
          return 1;
        }
      default:
        throw std::invalid_argument("wrong task number");
    }
  }
  catch (const std::invalid_argument& error)
  {
    std::cerr << error.what();
    return 1;
  }
  catch (...)
  {
    std::cerr << "unexpected error";
    return -1;
  }
  return 0;
}
