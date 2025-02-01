//This question was taken from leet code so it might require few changes before it can run properly however the logic is fully build and is accepted on leetcode

/* Question:
Link: https://leetcode.com/problems/container-with-most-water/

Description:
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the container contains the most water.
Return the maximum amount of water a container can store.

Example 1:
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
  
Example 2:
Input: height = [1,1]
Output: 1

*/

class Solution {
    int heighter(vector<int>& height, int& a, int& b) {
        if (height[a] > height[b]) {
            return height[b] * (b-a);
        }
        else {
            return height[a] * (b-a);
        }

    }

public:
    int maxArea(vector<int>& height) {
        int area=0;
        int i = 0;
        int j = height.size() - 1;
        area = heighter(height, i, j);
        while(i!=j){
            if (height[i] < height[j]) {
                    i++;
            }
            else {
                    j--;
            }
            if (heighter(height, i, j) > area) {
                area = heighter(height, i, j);
            }

        }

        return area;


    }
};
