//399. Nuts & Bolts Problem
//1. set referrence, calculate the rank, sort(start, rank - 1), sort(rank + 1, end)
//2. set nuts as anchor, partition bolts
//3. set bolts as anchor, partition buts

class Solution {
public:
	/**
	 * @param nuts: a vector of integers
	 * @param bolts: a vector of integers
	 * @param compare: a instance of Comparator
	 * @return: nothing
	 */
	void sortNutsAndBolts(vector<string>& nuts, vector<string>& bolts, Comparator compare) {
		// write your code here
		sort(nuts, bolts, 0, nuts.size() - 1, compare);
	}

	void sort(vector<string>& nuts, vector<string>& bolts, int start, int end, Comparator compare)
	{
		if (start >= end) return;
		int mid = (end - start) / 2 + start;
		int target = -1;
		int rank = start;
		for (int i = start; i <= end; i++)
		{
			if (compare.cmp(nuts[mid], bolts[i]) == 0) {
				target = i;
			}
			if (compare.cmp(nuts[mid], bolts[i]) == 1)
			{
				rank++;
			}
		}
		swap(bolts[target], bolts[rank]);
		swap(nuts[mid], nuts[rank]);
		partitionBolts(nuts, bolts, start, end, compare, rank);
		partitionNuts(nuts, bolts, start, end, compare, rank);
		sort(nuts, bolts, start, rank - 1, compare);
		sort(nuts, bolts, rank + 1, end, compare);
	}

	void partitionBolts(vector<string>& nuts, vector<string>& bolts, int start, int end, Comparator compare, int rank) {
		int left = start, right = end;
		int mid = rank;
		while (left < mid && right > mid)
		{
			while (compare.cmp(nuts[mid], bolts[left]) == 1) left++;
			while (compare.cmp(nuts[mid], bolts[right]) == -1) right--;
			if (left < mid && right > mid) swap(bolts[left++], bolts[right--]);
		}
	}

	void partitionNuts(vector<string>& nuts, vector<string>& bolts, int start, int end, Comparator compare, int rank) {
		int left = start, right = end;
		int mid = rank;
		while (left < mid && right > mid)
		{
			while (compare.cmp(nuts[left], bolts[mid]) == -1) left++;
			while (compare.cmp(nuts[right], bolts[mid]) == 1) right--;
			if (left < mid && right > mid)swap(nuts[left++], nuts[right--]);
		}
	}
};