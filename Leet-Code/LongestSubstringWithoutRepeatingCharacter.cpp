//This question was taken from leet code so it might require few changes before it can run properly however the logic is fully build and is accepted on leetcode

/* Question:
Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

  Description:
Given a string s, find the length of the longest substring without repeating characters.

Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::vector<char> prev;
        int count = 0;
        int i = 0;
        int j = 0;
        for (j = i; j < s.length(); j++) {
            int k = 0;
            for (k = 0; k < prev.size(); k++) {
                if (s[j] == prev[k]) {
                    break;
                }
            }
            if (k == prev.size()) {
                prev.push_back(s[j]);
            }
            else if (k != prev.size()) {
                if (prev.size() > count) {
                    count = prev.size();
                }
                i++;
                j = i - 1;
                prev.clear();
            }
        }

        if (count > prev.size()) {
            return count;
        }
        else {
            return prev.size();
        }
    }
};
