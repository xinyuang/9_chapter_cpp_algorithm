// Simplify Path

class Solution {
public:
	/**
	 * @param path: the original path
	 * @return: the simplified path
	 */
	string simplifyPath(string& path) {
		// write your code here
		//   /home/ced/../sd/sdf/../siz
		//   /home/sd/siz

		vector<string> res;
		stringstream ss(path);
		string line;
		while (getline(ss, line, '/'))
		{
			if (line == "" || line == ".") continue;
			if (line == ".." && !res.empty()) res.pop_back();
			else if (line != "..") res.push_back(line);
		}
		string ret = "";
		for (string path : res)
		{
			ret += "/";
			ret += path;
		}
		return ret.empty() ? "/" : ret;
	}
};