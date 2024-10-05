//This question was taken from leet code so it might require few changes before it can run properly however the logic is fully build and is accepted on leetcode

/* Question:
Link: https://leetcode.com/problems/median-of-two-sorted-arrays/description/

 Description:
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
The overall run time complexity should be O(log (m+n)).

Example 1:
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

Example 2:
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

*/

class Solution {
public:
    
    void merger(vector<int>& nums1,vector<int>& nums2,vector<int>& temp){
       int i=0;
       int j=0;
       while(i<nums1.size()&&j<nums2.size()){
        if (nums1[i]<nums2[j]){
            temp.push_back(nums1[i]);
            i++;
        }
        else if(nums1[i]>nums2[j]){
            temp.push_back(nums2[j]);
            j++;
        }
        else{
            temp.push_back(nums1[i]);
            i++;
        }
       }
       if(i==nums1.size()&&j!=nums2.size()){
        for(;j<nums2.size();j++){
            temp.push_back(nums2[j]);
        }
       }
       else if(j==nums2.size()&&i!=nums1.size()){
         for(;i<nums1.size();i++){
            temp.push_back(nums1[i]);
        }
       }
        
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> arr;
        double secondary;
        merger(nums1,nums2,arr);
        if(arr.size()%2!=0){
           return arr[((arr.size()+1)/2)-1];
        } 
        else{
           secondary = arr[(arr.size()/2)-1] +  arr[(arr.size()/2)];
           return secondary/2;
        }
    }
};
