PROBLEM STATEMENT :- Given a list of folders folder, return the folders after removing all sub-folders in those folders. You may return the answer in any order.
If a folder[i] is located within another folder[j], it is called a sub-folder of it.
The format of a path is one or more concatenated strings of the form: '/' followed by one or more lowercase English letters.
For example, "/leetcode" and "/leetcode/problems" are valid paths while an empty string and "/" are not.
 

Example 1:
Input: folder = ["/a","/a/b","/c/d","/c/d/e","/c/f"]
Output: ["/a","/c/d","/c/f"]
Explanation: Folders "/a/b" is a subfolder of "/a" and "/c/d/e" is inside of folder "/c/d" in our filesystem.
  
Example 2:
Input: folder = ["/a","/a/b/c","/a/b/d"]
Output: ["/a"]
Explanation: Folders "/a/b/c" and "/a/b/d" will be removed because they are subfolders of "/a".
  
Example 3:
Input: folder = ["/a/b/c","/a/b/ca","/a/b/d"]
Output: ["/a/b/c","/a/b/ca","/a/b/d"]

SOLUTION :-
  class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) 
    {
        vector<string> ans;
        map<string,int> mp;
        sort(folder.begin(),folder.end());
        
      for(int i=0; i<folder.size(); i++)
      {
        string s1 = folder[i];
        string samp="";
        for(int i=0; i<s1.size(); i++)
        {
            if(s1[i]=='/' && i==0)
                samp+=s1[i];
            else if(s1[i]=='/')
            {
                if(mp.find(samp) != mp.end())
                {
                    break;
                }
                samp+=s1[i];
            }
            else if(s1[i]!='/')
            {
                samp+=s1[i];
                if(mp.find(samp) != mp.end() && s1[i+1]=='/')
                {
                    break;
                }
                else if(mp.find(samp) == mp.end() && i==s1.size()-1)
                {
                    ans.push_back(samp);
                    mp[samp]++;
                }
            }
        }
    }
    return ans;
    }
};
