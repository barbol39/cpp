/*
 * @lc app=leetcode.cn id=885 lang=cpp
 *
 * [885] 螺旋矩阵 III
 */

// @lc code=start
#include <vector>
#include <string>
#include <unordered_set>
#include <iostream>
using namespace std;

static vector<pair<int,int>> direction{{0,1}, {1, 0}, {0, -1}, {-1, 0}};

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> rst;
        unordered_set<string> set;

        int cnt = 0;
        int dir = 3;
        rStart = rStart + 1;
        while(cnt < rows * cols) {
            int nextr = rStart + direction.at(dir).first;
            int nextc = cStart + direction.at(dir).second;
            string index = std::to_string(nextr) + ":" + std::to_string(nextc);
            if (set.count(index) == 0) {
                set.insert(index);
                if (nextr < rows && nextr >= 0 && nextc < cols && nextc >= 0) {
                    rst.emplace_back(vector{nextr, nextc});
                    ++cnt;
                }
                dir = (dir + 1) % 4;
                rStart = nextr;;
                cStart = nextc;
            } else {
                dir = (dir + 3) % 4;
            }
        }
        return rst;
    }
};
// @lc code=end

