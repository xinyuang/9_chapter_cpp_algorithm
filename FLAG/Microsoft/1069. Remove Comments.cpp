//1069. Remove Comments
//check "/*" && !comment, "*/"&& comment, "//" && !comment
//check cur line "*/" connect to prev "/*" pushback new subresult or append to prev res

class Solution {
public:
	/**
	 * @param source: List[str]
	 * @return: return List[str]
	 */
	vector<string> removeComments(vector<string>& source) {
		// write your code here
		vector<string> target;
		bool comment = false;
		bool prev = false;
		for (int i = 0; i < source.size(); i++)
		{
			if (source[i].find("/*", 0) == string::npos && comment == false &&
				source[i].find("//", 0) == string::npos)
			{
				if (comment) continue;
				target.push_back(source[i]);
			}
			else
			{
				string line = source[i];
				int ptr = 0;
				string sub = "";
				bool new_comment = false;
				while (ptr < line.size())
				{
					if (line.substr(ptr, 2) == "/*" && !comment)
					{
						new_comment = true;
						comment = true;
						ptr += 2;
					}
					else if (line.substr(ptr, 2) == "*/" && comment)
					{
						if (new_comment) prev = false;
						comment = false;
						ptr += 2;
					}
					else if (line.substr(ptr, 2) == "//" && !comment)
					{
						break;
					}
					else
					{
						if (comment) {
							ptr++;
							continue;
						}
						sub.push_back(line[ptr++]);
					}
				}
				if (prev) target.back() = target.back() + sub;
				else if (sub != "") target.push_back(sub);
				prev = comment;
			}
		}
		return target;
	}
};