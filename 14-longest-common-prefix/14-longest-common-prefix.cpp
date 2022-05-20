class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
       string c=strs[0];
        int minim=INT_MAX;
        
        for(int i=1;i<strs.size();i++)
        {
            int j=0,k=0;
            int an=0;
            while(j<c.size() && k<strs[i].size())
            {
                if(c[j]==strs[i][k])
                    an++;
                else
                    break;
                j++;
                k++;
                    
}
            minim=min(minim,an);
            
            
            
            
}
        return c.substr(0,minim);
        
        
    }
};