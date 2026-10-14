class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int row,
                int col, char num) {

        for (int i = 0; i < 9; i++) {
            if (board[row][i] == num)
                return false;

            if (board[i][col] == num)
                return false;

            int r = 3 * (row / 3) + i / 3;
            int c = 3 * (col / 3) + i % 3;

            if (board[r][c] == num)
                return false;
        }

        return true;
    }

    bool solve(vector<vector<char>>& board) {
        for (int row = 0; row < 