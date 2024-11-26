//This question was taken from leet code so it might require few changes before it can run properly however the logic is fully build and is accepted on leetcode

/* Question:
Link: https://leetcode.com/problems/string-to-integer-atoi/description/

Description:
Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.

The algorithm for myAtoi(string s) is as follows:
1) Whitespace: Ignore any leading whitespace (" ").
2) Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity if neither present.
3) Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. If no digits were read, then the result is 0.
4) Rounding: If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then round the integer to remain in the range. Specifically, integers less than -231 should be rounded to -231, and integers greater than 231 - 1 should be rounded to 231 - 1.
5) Return the integer as the final result.

Example 1:
Input: s = "42"
Output: 42
Explanation:
The underlined characters are what is read in and the caret is the current reader position.
Step 1: "42" (no characters read because there is no leading whitespace)
         ^
Step 2: "42" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "42" ("42" is read in)
  
Example 2:
Input: s = " -042"
Output: -42
Explanation:
Step 1: "   -042" (leading whitespace is read and ignored)
            ^
Step 2: "   -042" ('-' is read, so the result should be negative)
             ^
Step 3: "   -042" ("042" is read in, leading zeros ignored in the result)

Example 3:
Input: s = "1337c0d3"
Output: 1337
Explanation:
Step 1: "1337c0d3" (no characters read because there is no leading whitespace)
         ^
Step 2: "1337c0d3" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "1337c0d3" ("1337" is read in; reading stops because the next character is a non-digit)

*/

class Solution {
public:
    int myAtoi(string s) {
        long int answer = 0;
        bool leaders = 0;
        bool leadzeroes = 0;
        bool leadsign = 0;
        bool sign = 0;
        int i = 0;
        for (; i < s.size(); i++) {
        
            if (s[i] == ' ' && leaders == 0) {
                while (s[i + 1] == ' ') {
                    i++;
                }
                leaders = 1;
            }
            else  if ((s[i] == '-' || s[i] == '+') && (leadsign == 0)) {
                leadsign = 1;
                if (s[i] == '-') {
                    sign = 1;
                }
            }
            else if (s[i] == '0' && leadzeroes == 0) {
                while (s[i + 1] == '0') {
                    i++;
                }
                leadzeroes = 1;
                leadsign = 1;
                leaders = 1;
            }
            else if (s[i] >= '0' && s[i] <= '9') {
                answer *= 10;
                answer += (int(s[i]) - 48);
                leadzeroes = 1;
                leadsign = 1;
                leaders = 1;
            }
            else {
                break;
            }


            if (answer < -2147483648 || answer > 2147483648 - 1) {
                break;
            }
        }
        if (sign) {
            answer *= -1;
        }
        if (answer < -2147483648) {
            return -2147483648;
        }
        else if (answer > 2147483648 - 1) {
            return 2147483647;
        }
        return answer;

    }
};
