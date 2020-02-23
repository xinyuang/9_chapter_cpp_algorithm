//600. Smallest Rectangle Enclosing Black Pixels
//1. < -, ->, up, down 4 direction binary search, find bind boundary
//2. area = (up - down + 1) * (right - left + 1)

class Solution {
public:
	/**
	 * @param image: a binary matrix with '0' and '1'
	 * @param x: the location of one of the black pixels
	 * @param y: the location of one of the black pixels
	 * @return: an integer
	 */
	int minArea(vector<vector<char>>& image, int x, int y) {
		// write your code here
		if (image.size() == 0 || image[0].size() == 0) return 0;
		int left_board = findLeft(image, x, y);
		int right_board = findRight(image, x, y);
		int up_board = findUp(image, x, y);
		int down_board = findDown(image, x, y);
		int area = (right_board - left_board + 1) * (down_board - up_board + 1);
		return area;
	}

	int findLeft(vector<vector<char>>& image, int x, int y)
	{
		int left = 0, right = y;
		while (left + 1 < right)
		{
			int mid = (right - left) / 2 + left;
			if (findCol(mid, image)) right = mid;
			else left = mid;
		}
		if (findCol(left, image)) return left;
		return right;
	}

	int findRight(vector<vector<char>>& image, int x, int y)
	{
		int left = y, right = image[0].size() - 1;
		while (left + 1 < right)
		{
			int mid = (right - left) / 2 + left;
			if (findCol(mid, image)) left = mid;
			else right = mid;
		}
		if (findCol(right, image)) return right;
		return left;
	}

	bool findCol(int c, vector<vector<char>>& image)
	{
		for (int i = 0; i < image.size(); i++)
		{
			if (image[i][c] == '1') return true;
		}
		return false;
	}

	int findUp(vector<vector<char>>& image, int x, int y)
	{
		int upper = 0, lower = x;
		while (upper + 1 < lower)
		{
			int mid = (lower - upper) / 2 + upper;
			if (findRow(mid, image)) lower = mid;
			else upper = mid;
		}
		if (findRow(upper, image)) return upper;
		return lower;
	}

	int findDown(vector<vector<char>>& image, int x, int y)
	{
		int upper = x, lower = image.size() - 1;
		while (upper + 1 < lower)
		{
			int mid = (lower - upper) / 2 + upper;
			if (findRow(mid, image)) upper = mid;
			else lower = mid;
		}
		if (findRow(lower, image)) return lower;
		return upper;
	}

	bool findRow(int r, vector<vector<char>>& image)
	{
		for (int i = 0; i < image[0].size(); i++)
		{
			if (image[r][i] == '1') return true;
		}
		return false;
	}

};