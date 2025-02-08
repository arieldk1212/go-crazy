#ifndef CACHE_H
#define CACHE_H

/**
 * @brief l3 slowest in disk is a shared cache, l1 smallest and fastest on the
 * cpu, l2 larger closer to main memory ram.
 */

#include <vector>

template <typename CacheType> class cache {
public:
  cache();
  ~cache();
  /** 1.const cant change outside(obj.get_cache_data = 0), 2.const cant change
   * in function body(m_cache_data[1] = 0) */
  const std::vector<CacheType> get_cache_data() const { return m_cache_data; }

private:
  int m_cache_level;
  int m_cache_limit; /* mem limit? */
  size_t m_cache_size;
  std::vector<std::unique_ptr<CacheType>>
      m_cache_data; /** buffer to hold the memory/copy of the data. */
};

/**
 * @brief 2. **Cache Line or Cache Block:**
   - Data is stored in fixed-sized blocks called "cache lines" or "cache
 blocks."
   - Each block typically contains multiple bytes (e.g., 4 bytes, 8 bytes).
   - This allows the CPU to retrieve data in larger chunks efficiently,
 improving memory access speed.

 * cache hit, cache miss
 */

/*
       1.	Cache Size: How much data will your cache store? Is it fixed or
dynamic? 2.	Replacement Policy: What happens when the cache is full? Common
policies include: •	LRU (Least Recently Used): Evict the least recently
accessed item. •	LFU (Least Frequently Used): Evict the least accessed
item over time. •	FIFO (First In, First Out): Evict the oldest item. 3.
Concurrency: Will multiple threads access the cache? 4.	Storage Medium: Should
the cache be in memory (CPU/RAM) or involve disk (e.g., hybrid caches)?

Basic Components of a Cache

A simple cache can be implemented as a key-value store. Here’s an outline:
       1.	Data Storage:
Use an efficient data structure like std::unordered_map for key-value lookups.
       2.	Eviction Policy:
Combine the map with a std::list to implement policies like LRU.
       3.	Thread Safety (Optional):
Use std::mutex or higher-level abstractions like std::shared_mutex for
multithreaded access.
*/

#endif