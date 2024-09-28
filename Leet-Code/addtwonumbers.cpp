//This question was taken from leet code so it might require few changes before it can run properly however the logic is fully build and is accepted on leetcode

/* Question:
Link: https://leetcode.com/problems/add-two-numbers/description/

Description:
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example 2:
Input: l1 = [0], l2 = [0]
Output: [0]

Example 3:
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]

*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* answer=new ListNode;
        ListNode* current = answer;
        int carry=0;
        int sum=0;
        bool first=0;

        while(l1!=nullptr&&l2!=nullptr){
        if(first==0){
          ListNode* answer=new ListNode;
          ListNode* current = answer;
        }
        else{
         ListNode* dummy=new ListNode;
         current->next=dummy;
         current=current->next;
        }

        sum=l1->val+l2->val+carry;
        if(sum<10){
            carry=0;
        }
        else{
            sum=sum-10;
            carry=1;
        }


        l1=l1->next;
        l2=l2->next;
        current->val=sum;
        first=1;
        }

        if(l1!=nullptr){
          while(l1!=nullptr){
            ListNode* dummy=new ListNode;
            current->next=dummy;
            current=current->next;

            sum=l1->val+carry;
            if(sum<10){
               carry=0;
            }
            else{
               sum=sum-10;
               carry=1;
            }


            l1=l1->next;
        
            current->val=sum;
          }
        }

        else if(l2!=nullptr){
          while(l2!=nullptr){
            ListNode* dummy=new ListNode;
            current->next=dummy;
            current=current->next;

            sum=l2->val+carry;
            if(sum<10){
               carry=0;
            }
            else{
               sum=sum-10;
               carry=1;
            }


            l2=l2->next;
        
            current->val=sum;
            }
        }

        if(carry>0){
            ListNode* dummy=new ListNode;
            current->next=dummy;
            current=current->next;
            current->val=carry;
        }
        return answer;
    }
};
