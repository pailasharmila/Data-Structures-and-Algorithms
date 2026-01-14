/* Question:  5.Longest Palindromic Substring 
Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
 

Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters.
*/


// Possible best post for this quesion is :https://leetcode.com/problems/longest-palindromic-substring/solutions/4212564/beats-9649-5-different-approaches-brute-u46gf

class Solution {
public:
  
    string expand_from_center(int left, int right,string s){

        while(left>=0&&right<s.size()&&s[left]==s[right]){
            left--;right++;

        }
        return s.substr(left+1, right-left-1);
    }



    string longestPalindrome(string s) {
        
      
       if(s.size()<=1)  return s;
       string max_str=s.substr(0,1);

       for(int i=0;i<s.size()-1;i++){

        string odd=expand_from_center(i,i,s);
        string even=expand_from_center(i,i+1,s);

        if(odd.size()>max_str.size()){  max_str=odd;}
        if(even.size()>max_str.size()){   max_str=even;}
       }


     return max_str;

    }
};

