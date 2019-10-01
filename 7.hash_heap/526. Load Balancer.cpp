// Load Balancer

class LoadBalancer {
public:
	LoadBalancer() {
		// do intialization if necessary
	}

	/*
	 * @param server_id: add a new server to the cluster
	 * @return: nothing
	 */
	void add(int server_id) {
		// write your code here
		if (ids.count(server_id)) return;
		machine.push_back(server_id);
		ids[server_id] = machine.size() - 1;
	}

	/*
	 * @param server_id: server_id remove a bad server from the cluster
	 * @return: nothing
	 */
	void remove(int server_id) {
		// write your code here
		if (!ids.count(server_id)) return;
		int idx = ids[server_id];

		int backup = machine.back();
		machine[idx] = backup;
		ids[backup] = idx;

		machine.pop_back();
		ids.erase(server_id);
	}

	/*
	 * @return: pick a server in the cluster randomly with equal probability
	 */
	int pick() {
		// write your code here
		return machine[rand() % machine.size()];
	}

private:
	unordered_map<int, int> ids;
	vector<int> machine;
};