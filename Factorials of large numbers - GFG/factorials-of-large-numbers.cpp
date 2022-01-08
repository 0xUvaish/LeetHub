// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
public:
    vector<int> factorial(int N)
    {
        vector<int> v;
        v.push_back(1);
        int x = 0, num = 0;
        for (int j = 2; j <= N; j++)
        {
            num=0;
            
            for (int i = v.size()-1; i >= 0; i--)
            {
                int x = (v[i] * j) + num;
                num = x / 10;
                v[i] = x % 10;
            }
            
            if (num == 0)
                continue;
                
            while (num != 0)
            {
                v.insert(v.begin(),num%10);
                num=num/10;
            }
        }
        return v;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends