PROBLEM STATEMENT :-
  A string is called happy if it does not have any of the strings 'aaa', 'bbb' or 'ccc' as a substring.
Given three integers a, b and c, return any string s, which satisfies following conditions:-
  1. s is happy and longest possible.
  2. s contains at most a occurrences of the letter 'a', at most b occurrences of the letter 'b' and at most c occurrences of the letter 'c'.
  3. s will only contain 'a', 'b' and 'c' letters.
  
If there is no such string s return the empty string "".
  
 Example 1:
Input: a = 1, b = 1, c = 7
Output: "ccaccbcc"
Explanation: "ccbccacc" would also be a correct answer.
  
Example 2:
Input: a = 2, b = 2, c = 1
Output: "aabbc"
  
 Example 3:
Input: a = 7, b = 1, c = 0
Output: "aabaa"
Explanation: It's the only correct answer in this case.
  
  SOLUTION:-
  
  class Solution 
  {
public:
    string longestDiverseString(int a, int b, int c) 
    {
        string ans="";
    vector<pair< int , char >> vec;
    vec.push_back(make_pair(a,'a'));
    vec.push_back(make_pair(b,'b'));
    vec.push_back(make_pair(c,'c'));
    char last;
    sort(vec.begin(),vec.end());
    last='w';
    while(true)
    {
       
            if(last != vec[2].second)        
            {
                for(int i=0 ; i<2 && vec[2].first>0 ; i++)
                {
                    vec[2].first--;
                    ans.push_back(vec[2].second);
                    last = vec[2].second;
                }
            }
            else if( vec[1].first > 0 )        
            {
                vec[1].first--;
                ans.push_back(vec[1].second);
                last = vec[1].second;
            }
            if(last == vec[2].second && vec[0].first+vec[1].first == 0)
                break;
        
            sort(vec.begin(), vec.end());  
    }
        return ans;
    }
};


