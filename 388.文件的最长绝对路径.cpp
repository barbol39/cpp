/*
 * @lc app=leetcode.cn id=388 lang=cpp
 *
 * [388] 文件的最长绝对路径
 */

// @lc code=start
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int lengthLongestPath(string input) {
        int begin = 0;
        std::vector<std::string> dirs_name;
        int max = 0;
        int cur_size = 0;
        int size = input.size();
        int last_level = -1;
        while(begin < size) {
            auto next_n = input.find("\n", begin);
            if (next_n == std::string::npos) {
                next_n = size;
            }
            int tab_cnt = 0;
            int left = begin;
            int right = next_n;
            int last_t = begin;
            auto iter = input.find("\t", left);
            while(iter != std::string::npos && iter < next_n) {
                ++tab_cnt;
                last_t = iter + 1;
                iter = input.find("\t", iter + 1);
            }
            auto cur_dir = input.substr(last_t, next_n - last_t);
            if (tab_cnt > last_level) {
                cur_size += next_n - last_t;
                dirs_name.push_back(cur_dir);
                ++last_level;
            } else if (tab_cnt == last_level) {
                if (cur_dir.size() > dirs_name.back().size() || cur_dir.find(".") == std::string::npos) {
                    cur_size += cur_dir.size() - dirs_name.back().size();
                    dirs_name.pop_back();
                    dirs_name.push_back(cur_dir);
                }
            } else {
                int less = last_level - tab_cnt;
                while(less >= 0) {
                    cur_size -= dirs_name.back().size();
                    dirs_name.pop_back();
                    --less;
                }
                cur_size += next_n - last_t;
                dirs_name.push_back(cur_dir);
                last_level = tab_cnt;
            }
            if (cur_size + dirs_name.size() - 1 > max && dirs_name.back().find(".") != std::string::npos) {
                max = cur_size + dirs_name.size() - 1;
            }
            begin = next_n + 1;
        }
        return max;
    }
};
// @lc code=end

