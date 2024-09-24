class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string>st;
        // Iterate each string in the arr1
        for(int i=0;i<arr1.size();i++)
        {
            string val=to_string(arr1[i]);
            string prefix;
            // iterate each character, append it to prefix and add the prefix to the set
            // e.g. if val is 100, for 1st iteration, prefix="1", 2nd: prefix="10", 3rd: prefix="100" etc
            // after first outer loop, set = Set("1", "10", "100")
            for(auto ch:val)
            {
                prefix+=ch;
                st.insert(prefix);
            }
        }
        int ans=0;
        // Check every prefix combination in arr2, to see if it exists in the set we created above
        for(int i=0;i<arr2.size();i++)
        {
            string val=to_string(arr2[i]);
            string prefix;
            for(auto ch:val)
            {
                prefix+=ch;
                if(st.count(prefix))ans=max(ans,(int)prefix.size());
            }
        }
        return ans;
        
    }
};