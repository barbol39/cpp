/*
 * @lc app=leetcode.cn id=838 lang=cpp
 *
 * [838] 推多米诺
 */
#include <string>
#include <vector>

using namespace std;
// @lc code=start
class Solution {
public:
    string pushDominoes(string dominoes) {
        int left = 0, size = dominoes.size();
        int right = 0;
        char begin = 'L';
        char end = 'R';
        while(right < size) {
            while(right < size && dominoes[right] == '.') {
                ++right;
            }
            if (right == size) {
                end = 'R';
            } else {
                end = dominoes[right];
            }
            if (begin == end) {
                for(int j = left; j < right; ++j) {
                    dominoes[j] = begin;
                }
            } else if (begin == 'R' && end == 'L') {
                int a = left + 1;
                int b = right - 1;
                while(a < b) {
                    dominoes[a++] = 'R';
                    dominoes[b--] = 'L';
                }
            }
            begin = end;
            left = right;
            ++right;
        }
        return dominoes;
    }

};
// @lc code=end

