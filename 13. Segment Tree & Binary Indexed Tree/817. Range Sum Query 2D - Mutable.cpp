// 817. Range Sum Query 2D - Mutable

// 1. lowbit = x & (-x)
// 2. for i += lowbit(i), j += lowbit(j) update bit[i][j] += diff      range  [1,m],[1,n]
// 3. queryPrefix: for i -= lowbit(i) j -= lowbit(j)   sum += bit[i][j]

class NumMatrix {
private:
    vector<vector<int>> arr,bit;
    int m,n;
public:
    NumMatrix(vector<vector<int>> matrix) {
        arr = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size(),0));
        bit = vector<vector<int>>(matrix.size()+1,vector<int>(matrix[0].size()+1,0));
        m = matrix.size();
        n = matrix[0].size();
        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix[0].size(); j++)
            {
                update(i,j,matrix[i][j]);
            }
        }
    }
    
    void update(int row, int col, int val) {
        int diff = val - arr[row][col];
        arr[row][col] = val;
        for(int i = row+1; i <= m; i += lowbit(i))
        {
            for(int j = col+1; j <= n; j += lowbit(j))
            {
                bit[i][j] += diff;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int br = rangeSum(row2,col2);
        int bl = rangeSum(row2,col1-1);
        int ur = rangeSum(row1-1,col2);
        int ul = rangeSum(row1-1,col1-1);
        return br - bl - ur + ul;
    }
    
    int rangeSum(int x, int y)
    {
        int sum = 0;
        for(int i = x + 1; i > 0; i -= lowbit(i))
        {
            for(int j = y+1; j > 0; j -= lowbit(j))
            {
                sum += bit[i][j];
            }
        }
        return sum;
    }
    
    int lowbit(int x)
    {
        return x & (-x);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * obj.update(row,col,val);
 * int param_2 = obj.sumRegion(row1,col1,row2,col2);
 */