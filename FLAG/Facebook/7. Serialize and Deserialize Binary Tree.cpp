7. Serialize and Deserialize Binary Tree

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */


	class Solution {
	public:
		/**
		 * This method will be invoked first, you should design your own algorithm
		 * to serialize a binary tree which denote by a root node to a string which
		 * can be easily deserialized by your own "deserialize" method later.
		 */
		string serialize(TreeNode* root) {
			// write your code here
			ostringstream out;
			serializeTree(root, out);
			return out.str();
		}

		/**
		 * This method will be invoked second, the argument data is what exactly
		 * you serialized at method "serialize", that means the data is not given by
		 * system, it's given by your own serialize method. So the format of data is
		 * designed by yourself, and deserialize it here as you serialize it in
		 * "serialize" method.
		 */
		TreeNode* deserialize(string& data) {
			// write your code here
			istringstream in(data);
			return deserializeTree(in);
		}

		void serializeTree(TreeNode* root, ostringstream& out)
		{
			if (!root) {
				out << "# ";
				return;
			}
			out << root->val << " ";
			serializeTree(root->left, out);
			serializeTree(root->right, out);
		}

		TreeNode* deserializeTree(istringstream& in)
		{
			string val;
			in >> val;
			if (val == "#") return nullptr;
			TreeNode* root = new TreeNode(stoi(val));
			root->left = deserializeTree(in);
			root->right = deserializeTree(in);
			return root;
		}
};

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */


	class Solution {
	public:
		/**
		 * This method will be invoked first, you should design your own algorithm
		 * to serialize a binary tree which denote by a root node to a string which
		 * can be easily deserialized by your own "deserialize" method later.
		 */
		string serialize(TreeNode* root) {
			// write your code here
			queue<TreeNode*> q;
			q.push(root);
			string res = "{";
			while (!q.empty())
			{
				int q_size = q.size();
				for (int i = 0; i < q_size; i++)
				{
					TreeNode* cur = q.front(); q.pop();
					if (cur) {
						res += to_string(cur->val) + ",";
						q.push(cur->left);
						q.push(cur->right);
					}
					else res += "#,";
				}
			}
			res.pop_back();
			res += "}";
			return res;
		}

		/**
		 * This method will be invoked second, the argument data is what exactly
		 * you serialized at method "serialize", that means the data is not given by
		 * system, it's given by your own serialize method. So the format of data is
		 * designed by yourself, and deserialize it here as you serialize it in
		 * "serialize" method.
		 */
		TreeNode* deserialize(string& data) {
			// write your code here
			vector<string> nodes = split(data, ',');
			if (nodes.size() == 0 || nodes[0] == "#") return nullptr;
			TreeNode* root = new TreeNode(stoi(nodes[0]));
			queue<TreeNode*> q;
			q.push(root);
			bool isRight = false;
			for (int i = 1; i < nodes.size(); i++)
			{
				if (nodes[i] != "#")
				{
					TreeNode* next = new TreeNode(stoi(nodes[i]));
					if (!isRight)
					{
						q.front()->left = next;
					}
					else q.front()->right = next;
					q.push(next);
				}
				if (isRight) q.pop();
				isRight = !isRight;
			}
			return root;
		}

		vector<string> split(string& data, char del)
		{
			vector<string> res;
			string tmp = "";
			int i = 1;
			while (i + 1 < data.size())
			{
				if (data[i] != del) tmp.push_back(data[i]);
				else {
					res.push_back(tmp);
					tmp = "";
				}
				i++;
			}
			return res;
		}
};