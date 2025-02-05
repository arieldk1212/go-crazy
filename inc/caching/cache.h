#ifndef CACHE_H
#define CACHE_H

#include <memory>
#include <vector>

class cache {
public:
  cache();
  ~cache();

  std::vector<int> get_cache_data() const { return m_cache_data.m_data; }

private:
  struct cache_data {
    size_t m_data_size;
    std::vector<int> m_data;
  };

private:
  int m_cache_level;
  int m_cache_limit;
  cache_data m_cache_data;
};

#endif