class Solution {
public:
    //M1: Brute Force
    // int maximumSwap(int num) 
    // {
    //     string s=to_string(num);
    //     int n=stoi(s);
    //     for(int i=0;i<s.size();i++)
    //     {
    //         for(int j=i+1;j<s.size();j++)
    //         {
    //             swap(s[i],s[j]);
    //             n=max(n,stoi(s));
    //             swap(s[i],s[j]);
    //         }
    //     }
    //     return n;
    // }
    
    //M2: Optimised
    int maximumSwap(int num) {
        if (num >= 0 && num < 9) { return num; }
        
        // convert to string
        string n = to_string(num);
        string max_n = to_string(num);
        
        sort(max_n.begin(), max_n.end()); // sort
        reverse(max_n.begin(), max_n.end()); // reverse
        
        for (auto jj = 0; jj < n.length(); jj++) {
            if (n[jj] == max_n[jj]) { continue; }
            int index = n.find_last_of(max_n[jj]);
            swap(n[jj], n[index]);
            break;
        }
        stringstream ss(n);
        int value = 0;
        ss >> value;
        return value;
    }
};