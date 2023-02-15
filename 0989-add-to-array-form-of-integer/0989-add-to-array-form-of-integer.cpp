class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);

        reverse(num.begin() , num.end());
        int carry = 0;
        int i=0;
        while(k>0 || i<num.size())
        {
            int dig = k%10;
            k=k/10;

            int sum = dig;
            if(i<num.size())   sum+=num[i];

            sum+=carry;

            carry = sum/10;
            if(i<num.size())    num[i] = sum%10;
            else num.push_back(sum%10);
            i++;
        }
        while(carry != 0 )
        {
            num.push_back(carry%10);
            carry = carry/10;
        }
        reverse(num.begin() , num.end());
        return num;
    }
};