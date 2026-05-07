#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        char c;
         if(s.size()%2 != 0) return false;
         for(int i=0;i<s.size();i++)
         {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                st.push(s[i]);
            }else
            {
                if(st.empty()) return false;
            }

            
            if(s[i]==')')
            {
                c = st.top();
                st.pop();
                if(c!='(')
                {
                    return false;
                }
            } 
            if(s[i]==']')
            {
                c = st.top();
                st.pop();
                if(c!='[')
                {
                    return false;
                }
            } 
            if(s[i]=='}')
            {
                c = st.top();
                st.pop();
                if(c!='{')
                {
                    return false;
                }
            } 
         }
         return st.empty();
    }
};