#ifndef DETAILS_HPP
#define DETAILS_HPP

#include <functional>
#include <stdexcept>
#include <iostream>
#include <cstring>
#include "getAccess.h"

namespace detail
{
  template<typename T>
  std::function<bool(const T, const T)> getComparator(const char* sortOrder)
  {
    if(!sortOrder)
    {
      throw std::invalid_argument("sortType = nullptr");
    }
    if (std::strcmp(sortOrder, "descending") == 0)
    {
      return std::less<const T>();
    }
    else if(std::strcmp(sortOrder, "ascending") == 0)
    {
      return std::greater<const T>();
    }
    else
    {
      throw std::invalid_argument("sortType is incorrect");
    }
  }

  template<template<typename> class Access, typename ContainerType>
  void sort(ContainerType &data, std::function<bool(typename ContainerType::value_type,
      typename ContainerType::value_type)> compare)
  {
    typedef Access<ContainerType> access;
    for (auto i = access::begin(data); i != access::end(data); ++i)
    {
      for (auto j = access::begin(data); j != access::end(data); ++j)
      {
        if (compare(access::getElem(data, j), access::getElem(data, i)))
        {
          std::swap(access::getElem(data, j), access::getElem(data, i));
        }
      }
    }
  }

  template<typename T>
  void print(const T &collection, const char* separator)
  {
    if (!separator)
    {
      throw::std::invalid_argument("separator is incorrect");
    }
    for (typename T::const_iterator temp = collection.begin(); temp != collection.end(); temp++)
    {
      std::cout << *temp << separator;
    }
  }
}

#endif
