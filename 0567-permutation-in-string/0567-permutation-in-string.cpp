class Solution {
public:
    bool checkInclusion(string s1, string s2) 
    {                
        string m1(26,0), m2(26,0);
        int l1 = s1.size(),l2=s2.size();
        
        for( auto ch : s1) 
            m1[ch-'a']++; 
        
        for( int r = 0 ; r < l2 ; r++)
        {
            m2[s2[r]-'a']++;
            
            if(r>=l1)
                m2[s2[r-l1] - 'a']--;
            
            if(m2==m1)
                return true;
        }   
        
        return false;
    }
};