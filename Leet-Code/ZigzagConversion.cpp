//This question was taken from leet code so it might require few changes before it can run properly however the logic is fully build and is accepted on leetcode

/* Question:
Link: https://leetcode.com/problems/zigzag-conversion/description/

Description:

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:
string convert(string s, int numRows);

Example 1:
Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"

Example 3:
Input: s = "A", numRows = 1
Output: "A"

*/

class Solution {
public:
    string convert(string s, int numRows) {
        string* converter = new string[numRows];
        string answer;
        int j = 0;
        int direction = 0;
        for (int i = 0; i < s.size(); i++) {

            converter[j].push_back(s[i]);

            if (j == 0) {
                direction = 0;
            }
            else if (j == numRows - 1) {
                direction = 1;
            }
            if (direction == 0&&numRows!=1) {
                j++;
            }
            else if(direction == 1 && numRows != 1) {
                j--;
            }
        }

        for (int i = 0; i < numRows; i++) {
            answer += converter[i];
        }
        delete[] converter;
        converter=nullptr;
        return answer;


    }
};
