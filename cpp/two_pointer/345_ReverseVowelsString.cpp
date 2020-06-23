#include "../common.hpp"
using namespace std;
using std::string;
using std::unordered_map;

/***************
****************/
class Solution {
public:
    string reverseVowels(string s) {
        unordered_map<char, bool> vowel = {{'a', true}, {'A', true},
                                           {'e', true}, {'E', true},
                                           {'i', true}, {'I', true},
                                           {'o', true}, {'O', true},
                                           {'u', true}, {'U', true}};
        int l = 0;
        int r = s.size() - 1;
        while (l < r) {
            if (vowel.count(s[l]) && vowel.count(s[r])) {
                std::swap(s[l], s[r]);
                l++;
                r--;
            } else {
                if (!vowel.count(s[l])) {
                    l++;
                }
                if (!vowel.count(s[r])) {
                    r--;
                }
            }
        }
        return s;
    }
};
