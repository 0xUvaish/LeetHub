class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();
        vector<int> right(26,-1);

        for(int i = n-1; i >=0 ; i--)  //Last occurence index of every character
            if(right[s[i]-'a'] < 0)
                right[s[i]-'a'] = i;
         
		
        vector<int> ans;
        int start = 0, end = right[s[0]-'a'];
        
        for(int i = 1; i < n; i++)
        {
            int ch = s[i]-'a';
           
            if(i <= end){
              end = max(end,right[ch]);  
            }
            else{
                ans.push_back(end-start+1);
                start = i;
                end = right[ch];
            }
        }
        
        ans.push_back(end-start+1);
        
        return ans;
    }
};