// LRU    LRUNode<key,value>
//   list<LRUNode>          when delete, find the key in list can help to delete it in map
//   unordered_map<int,list<LRUNode>::iterator>
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

class LRUCache {
public:

	class LRUNode {
	public:
		int key;
		int value;
		LRUNode* next;
		LRUNode(int k, int v, LRUNode* n) : key(k), value(v), next(n) {};
	};
	/*
	* @param capacity: An integer
	*/LRUCache(int capacity) {
	// do intialization if necessary
		cache_size = capacity;
		dummy = new LRUNode(0, 0, nullptr);
		tail = dummy;
	}

	/*
	 * @param key: An integer
	 * @return: An integer
	 */
	int get(int key) {
		// write your code here
		if (!map.count(key)) return -1;
		int res = map[key]->next->value;
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
			LRUNode* newNode = new LRUNode(key, value, nullptr);
			map[key] = tail;
			tail->next = newNode;
			tail = tail->next;
			if (map.size() > cache_size)
			{
				map.erase(dummy->next->key);
				LRUNode* old_head = dummy->next;
				dummy->next = old_head->next;
				map[dummy->next->key] = dummy;
				old_head->next = nullptr;

			}
		}
		else
		{
			map[key]->next->value = value;
			move_end(key);
		}
	}

private:
	int cache_size = 0;
	unordered_map<int, LRUNode*> map;
	LRUNode* dummy = nullptr;
	LRUNode* tail = nullptr;
	void move_end(int key)
	{
		LRUNode* cur = map[key]->next;
		if (cur == tail) return;
		map[key]->next = cur->next;
		map[cur->next->key] = map[key];
		cur->next = nullptr;

		tail->next = cur;
		map[key] = tail;
		tail = tail->next;

	}

};