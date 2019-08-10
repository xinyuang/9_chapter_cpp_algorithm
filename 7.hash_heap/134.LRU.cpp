#include <list>
class LRUCache {
	class LRUNode {
	public:
		int key;
		int value;
		LRUNode(int k, int v) : key(k), value(v) {}
	};
public:
	/*
	* @param capacity: An integer
	*/LRUCache(int capacity) {
	// do intialization if necessary
	cache_size = capacity;
}

	  /*
	   * @param key: An integer
	   * @return: An integer
	   */
	  int get(int key) {
		  // write your code here
		  if (!map.count(key)) return -1;
		  int res = map[key]->value;
		  move_end(key);
		  return res;
	  }

	  /*
	   * @param key: An integer
	   * @param value: An integer
	   * @return: nothing
	   */
	  void set(int key, int value) {
		  // write your code here
		  if (!map.count(key))
		  {
			  LRUNode newNode = LRUNode(key, value);
			  cache.push_back(newNode);
			  map[key] = --cache.end();
			  if (map.size() > cache_size)
			  {
				  map.erase(cache.front().key);
				  cache.pop_front();
			  }
		  }
		  else {
			  map[key]->value = value;
			  move_end(key);
		  }
	  }
private:
	int cache_size = 0;
	unordered_map<int, std::list<LRUNode>::iterator>   map;
	std::list<LRUNode> cache;
	void move_end(int key)
	{
		cache.splice(cache.end(), cache, map[key]);
		map[key] = --cache.end();
	}
};