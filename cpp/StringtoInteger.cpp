
class Solution {
public:
    /** 
     * isspace and isdigit contanined by "ctype.h"
    */
    string DigitStr(const string &s) {
        string result = "";
        bool init_flag = true;
        for (auto &i : s) {
            if (isspace(i) && init_flag) {
                continue;
            }
            if (!isdigit(i)) {
                if ((i == '-' || i == '+') && init_flag) {
                    if (result.size() == 0) {
                        result.push_back(i);
                        init_flag = false;
                    }
                }
                else {
                    break;
                }
            }
            else {
                if (init_flag) {
                    result.push_back('+');
                }
                result.push_back(i);
                init_flag = false;
            }
        }
        return result;
    }

    int myAtoi(string str) {
        string digit_str = DigitStr(str);
        std::cout << "stracted digit string: " << digit_str << std::endl;
        const int M_INT_MAX = static_cast<int>(pow(2, 31) - 1);
        const int M_INT_MIN = static_cast<int>(pow(2, 31) * (-1));
        std::cout << M_INT_MAX << " " << M_INT_MIN << std::endl;
        int str_len = digit_str.size();
        int sum = 0;
        int sign = 1;

        if (str_len > 1) {
            if (digit_str.at(0) == '-') {
                sign = -1;
            }
            if (digit_str.at(0) == '+') {
                sign = 1;
            }
            for (int i = 1; i < str_len; ++i) {
                int ivalue = digit_str.at(i) - '0';
                if (sign == -1 && (sum < M_INT_MIN / 10 || sum < (M_INT_MIN + ivalue) / 10)) {
                    return M_INT_MIN;
                }
                if (sign == 1 && (sum > M_INT_MAX / 10 || sum > (M_INT_MAX - ivalue) / 10)) {
                    return M_INT_MAX;
                }
                sum = sum * 10 + ivalue * sign;
            }
            return sum;
        }
        else {
            return 0;
        }
    }
};