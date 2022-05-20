class Solution {
public:
    bool isValid(string s) {
           if(s.length()%2!=0||s.length()==0)
            return false;
        stack<char> st;
     
        for(int i=0;i<s.size();i++)
        {
            char x=s[i];
            if(x=='('||x=='['||x=='{')
                st.push(x);
            else if(x==')'&&st.empty()!=true&&st.top()=='(')
                st.pop();
            else if(x==']'&&st.empty()!=true&&st.top()=='[')
                st.pop();
            else if(x=='}'&&st.empty()!=true&&st.top()=='{')
                st.pop();  
            else
                st.push(x);
}
        return st.empty();
        

        
    }
};