class Solution {
public:
    double dp[101][101];
    double champagneTower(int poured, int query_row, int query_glass) {
        dp[0][0] = (double) poured;

        for(int i = 0; i < query_row; i++) {
            for(int j = 0; j < query_row; j++) {
                double excess = (dp[i][j] - 1) / 2.0;
                if(excess > 0) {
                    dp[i+1][j] += excess;
                    dp[i+1][j+1] += excess;
                }
            }
        }
        return min(1.0, dp[query_row][query_glass]);
    }
};
//Approach -II (recursion + memoization)
class Solution {
public:
    double dp[101][101];
    double solve(int poured, int r, int c) {
        if(r < 0 ||r < c|| c < 0) {
            return 0.0;
        }
        if(r == 0 && c == 0) {
            return poured;
        }
        if(dp[r][c] != -1) {
            return dp[r][c];
        }
        double upper_left = (solve(poured, r-1, c - 1) - 1) / 2.0;
        double upper_right = (solve(poured, r-1, c) - 1) / 2.0;
        if(upper_left < 0) upper_left = 0.0;
        if(upper_right < 0) upper_right = 0.0;

        return dp[r][c] = upper_right + upper_left;


    }
    double champagneTower(int poured, int query_row, int query_glass) {
        for(int i = 0; i < 101; i++) {
            for(int j = 0; j < 101; j++) {
                dp[i][j] = -1;
            }
        }
        return min(1.0, solve(poured, query_row, query_glass));
    }
};