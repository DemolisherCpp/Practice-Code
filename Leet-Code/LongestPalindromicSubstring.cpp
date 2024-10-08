//This question was taken from leet code so it might require few changes before it can run properly however the logic is fully build and is accepted on leetcode

/* Question:
Link: https://leetcode.com/problems/longest-palindromic-substring/description/

Description:
Given a string s, return the longest palindromic substring in s.

Example 1:
Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
  
Example 2:
Input: s = "cbbd"
Output: "bb"

*/

class Solution {
public:
    string longestPalindrome(string s) {
        string chook;
        int total = 0;
        for (int j = 0; j <= s.size(); j++) {

            {
                int count=0;
                int k = j;
                int i = j;
                for (; i < s.size() && k >= 0; i++, k--) {
                    if (s[i] != s[k]) {
                        break;
                    }
                    else if(k==i) {
                        count += 1;
                    }
                    else {
                        count += 2;
                    }
                }
                if (count > total) {
                    total = count;
                    chook.erase();
                    for (int z = k + 1; z <= i - 1; z++) {
                        chook.push_back(s[z]);
                    }

                }
            }


            if (j > 0) {
                if (s[j] == s[j - 1]) {
                    int count=0;
                    int k = j-1;
                    int i = j;
                    for (; i < s.size() && k >= 0; i++, k--) {
                        if (s[i] != s[k]) {
                            break;
                        }
                        else {
                            count += 2;
                        }
                    }
                    if (count > total) {
                        total = count;
                        chook.erase();
                        for (int z = k + 1; z <= i - 1; z++) {
                            chook.push_back(s[z]);
                        }

                    }

                }
            }
           

            }
        
        return chook;

    }
};
