// https://leetcode.com/problems/data-stream-as-disjoint-intervals/discuss/3109611/Easy-oror-C%2B%2B-oror-O(n)-oror-Set

class SummaryRanges {
public:
    set<int> st;
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        st.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
       
        vector<vector<int>> ans;
        vector<int> temp;
        int prev=-1;
        for(auto curr:st)
        {
            if(prev==-1)
            {
                prev=curr;
                temp.push_back(prev);
               
                continue;
            }
            else if(curr==prev+1)
            {
                prev=curr;

            }
            else
            {
                temp.push_back(prev);
                ans.push_back(temp);
                temp.clear();
                prev=curr;
                temp.push_back(curr);
            }
        }
        if(temp.size()!=0)
        {
            temp.push_back(prev);
            ans.push_back(temp);
        }
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */