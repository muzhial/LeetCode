class Solution {
public:
    string ZigzagConversion(string s) {
        int s_len = s.size();
        int rows = 2;
        string zigzag_str;
        for (int i = 0; i < rows; ++i) {
            int count = 0;
            int cur_index = 0;
            while (cur_index + i < s_len) {
                zigzag_str.push_back(s.at(cur_index + i));
                ++count;
                cur_index = rows * count;
            }
        }

        std::cout << zigzag_str << std::endl;
        return zigzag_str;
    }
};

class Solution {
public:
    string convert(string s, int numRows) {
        int s_len = s.size();
        if (numRows > s_len || numRows == 1 || numRows == 0) {
            // std::cout << "convert result: " << s << std::endl;
            return s;
        }
        else {
            string zigzag_str;
            for (int i = 0; i < numRows; ++i) {
                int count = 0;
                int cur_index = 0;
                while (cur_index + i < s_len) {
                    zigzag_str.push_back(s.at(cur_index + i));
                    // 添加对角线处元素
                    if (i != 0 && i != numRows - 1) {
                        cur_index = cur_index + (2 * numRows - 2) - i;
                        if (cur_index < s_len) {
                            zigzag_str.push_back(s.at(cur_index));
                        }
                    }
                    ++count;
                    cur_index = (2 * numRows - 2) * count;
                }
            }
            // std::cout << "converted result: " << zigzag_str << std::endl;
            return zigzag_str;
        }
    }
};