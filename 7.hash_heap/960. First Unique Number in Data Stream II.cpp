
class NumNode {
public:
	int value;
	NumNode* pre;
	NumNode* next;
	NumNode(int value) : value(value), pre(nullptr), next(nullptr) {}
};
class DataStream {
public:

	DataStream() : head(new NumNode(-1)), tail(new NumNode(-1)) {
		head->next = tail;
		tail->pre = head;
	}

	~DataStream() {
		for (auto& item : pointers) {
			delete item;
		}
		delete head;
		delete tail;
	}
	/**
	 * @param num: next number in stream
	 * @return: nothing
	 */
	void add(int num) {
		if (duplicate.count(num)) {
			return;
		}
		if (hash.count(num)) {
			remove(num);
			duplicate.insert(num);
			return;
		}
		NumNode* node = new_node(num);
		hash.insert(make_pair(num, node));
		node->pre = tail->pre;
		node->next = tail;
		node->pre->next = node;
		tail->pre = node;
	}

	/**
	 * @return: the first unique number in stream
	 */
	int firstUnique() {
		return head->next->value;
	}
private:
	NumNode* head;
	NumNode* tail;
	unordered_map<int, NumNode*> hash;
	unordered_set<int> duplicate;
	vector<NumNode*> pointers;
	NumNode* new_node(int value) {
		NumNode* node = new NumNode(value);
		pointers.push_back(node);
		return node;
	}
	void remove(int number) {
		NumNode* node = hash.at(number);
		node->pre->next = node->next;
		node->next->pre = node->pre;
		hash.erase(number);
	}
};