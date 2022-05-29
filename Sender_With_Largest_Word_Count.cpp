PROBLEM STATEMENT :- You have a chat log of n messages. You are given two string arrays messages and senders where messages[i] is a message sent by senders[i].

A message is list of words that are separated by a single space with no leading or trailing spaces. The word count of a sender is the total number 
of words sent by the sender. Note that a sender may send more than one message. Return the sender with the largest word count. 
 If there is more than one sender with the largest word count, return the one with the lexicographically largest name.

Note: Uppercase letters come before lowercase letters in lexicographical order.
"Alice" and "alice" are distinct.
 

Example 1:
Input: messages = ["Hello userTwooo","Hi userThree","Wonderful day Alice","Nice day userThree"], senders = ["Alice","userTwo","userThree","Alice"]
Output: "Alice"
Explanation: Alice sends a total of 2 + 3 = 5 words.
userTwo sends a total of 2 words.
userThree sends a total of 3 words.
  
  SOLUTION :- class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders)
    {
        map<string, int> mp;
        for(int i=0; i<messages.size(); i++)
        {
            int cnt = 0;
            string s = messages[i];
            int j = 0;
            while(j<s.size())
            {
                while(j<s.size() && s[j]!=' ')
                    j++;
                cnt++;
                j++;
            }
            if(mp.find(senders[i])!=mp.end())
                mp[senders[i]] += cnt;
            else
                mp[senders[i]] = cnt;
        }
        int mx = INT_MIN;
        string p ;
        for(auto it = mp.begin(); it!=mp.end(); it++)
        {
            if(it->second == mx )
            {
                vector<string> vc;
                vc.push_back(it->first);
                vc.push_back(p);
                sort(vc.begin(), vc.end());
                
                p = vc[1];
            }
            if(it->second>mx)
            {
                mx = it->second;
                p = it->first;
            }
            
        }
        return p;
    }
};
