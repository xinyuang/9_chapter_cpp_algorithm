class Solution {
public:
	/**
	 * @param colors: A list of integer
	 * @param k: An integer
	 * @return: nothing
	 */
	void sortColors2(vector<int>& colors, int k) {
		// write your code here
		quickSort(colors, 0, colors.size() - 1, 1, k);
	}

	void quickSort(vector<int>& colors, int start, int end, int lower, int upper)
	{
		if (start >= end || lower >= upper)
		{
			return;
		}
		int small = start - 1, smallSeeker = start;
		int pivot = (upper - lower) / 2 + lower;
		while (smallSeeker <= end)
		{
			if (colors[smallSeeker] <= pivot)
			{
				small++;
				swap(colors, small, smallSeeker);
			}
			smallSeeker++;
		}

		quickSort(colors, start, small, lower, pivot);
		quickSort(colors, small + 1, end, pivot + 1, upper);
	}

	void swap(vector<int>& colors, int a, int b)
	{
		int tmp = colors[a];
		colors[a] = colors[b];
		colors[b] = tmp;
	}
};