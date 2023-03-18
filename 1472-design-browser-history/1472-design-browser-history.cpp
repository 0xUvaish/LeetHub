// https://leetcode.com/problems/design-browser-history/discuss/3311362/No-stack-no-resize-O(1)-solution-using-array-and-pointers-beats-99!!

class BrowserHistory {
public:
    vector<string>v;
    int cur=0;
    int forwardlim=0;
    BrowserHistory(string homepage) {
        v.push_back(homepage);
    }
    
    void visit(string url) {
        if(cur<v.size()-1)
        v[++cur]=url;
        else
        {
            v.push_back(url);
            cur++;
        }
        forwardlim=cur;

    }
    
    string back(int steps) {
        cur=max(0,cur-steps);
        return v[cur];
    }
    
    string forward(int steps) {
        cur=min(forwardlim,cur+steps);
        return v[cur];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */