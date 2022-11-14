// PROBLEM LINK
// https://leetcode.com/problems/reverse-words-in-a-string/

/*
    Solution : 
    Time complexity : O(N)
*/

class Solution {
public:
    string reverseWords(string str) {
        for(int i=0; i < str.size(); ++i){
            if(str[i] == ' '){
                size_t pos = str.find_first_not_of(' ', i);
                str.erase(i, pos-(i?1:0)-i);
            }
        }
        string newstr = "";
        string temp="";
        int cnt=0;
        for(int i = 0; i< str.size(); i++){
            if(str[i] != ' '){   
                temp+=str[i];
            }
            if(str[i]==' ' || i==str.size()-1){
                cnt++;
                if(cnt==1){
                newstr.insert(0, temp);
                }else{
                newstr.insert(0, temp+' ');
                }
                temp="";
            }
        }
        return newstr;
    }
};