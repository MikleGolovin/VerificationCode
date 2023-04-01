#ifndef ACCESS_HPP
#define ACCESS_HPP

template <typename Collection>
struct AccessByOperator
{
  typedef typename Collection::value_type valueType;
  typedef typename Collection::size_type iterator;
  static iterator begin(const Collection&)
  {
    return 0;
  }
  static iterator end(const Collection& data)
  {
    return data.size();
  }
  static valueType& getElem(Collection& data, iterator index)
  {
    return data[index];
  }
};

template <typename Collection>
struct AccessByAt
{
  typedef typename Collection::value_type valueType;
  typedef typename Collection::size_type iterator;
  static iterator begin(const Collection&)
  {
    return 0;
  }
  static iterator end(const Collection& data)
  {
    return data.size();
  }
  static valueType& getElem(Collection& data, iterator index)
  {
    return data.at(index);
  }
};

template <typename Collection>
struct AccessByIterator
{
  typedef typename Collection::value_type valueType;
  typedef typename Collection::iterator iterator;
  static iterator begin(Collection& data)
  {
    return data.begin();
  }
  static iterator end(Collection& data)
  {
    return data.end();
  }
  static valueType& getElem(Collection&, iterator index)
  {
    return *index;
  }
};

#endif
