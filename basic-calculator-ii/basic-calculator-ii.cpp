class Solution {
public:
    
    string evalute(vector<string> v)
    {
        int num=stoi(v[0]);
        for(int i=1;i<v.size();i+=2)
        {
            if(v[i]=="+")
                num+=stoi(v[i+1]);
            else if(v[i]=="-")
               num-=stoi(v[i+1]); 
            else if(v[i]=="*")
                num*=stoi(v[i+1]);
            else
                num/=stoi(v[i+1]);
        }
        return to_string(num);
    }
    
    
    int calculate(string s) {
       string ss;
        
        for(auto ch:s)
            if(ch!=' ')
                ss.push_back(ch);  //non-space string (digits + operators)
        
        vector<string> st;
        int l=0;
        int len=ss.length();
        while(l<len)
        {
            string num;
            while(l<len and isdigit(ss[l]))
                num.push_back(ss[l++]); //digits only consecutive string
            if(l==len)
                st.push_back(num);
            else if(ss[l]=='+' or ss[l]=='-')
            {
                st.push_back(num);
                st.push_back(string(1,ss[l]));
                l++;
            }
            else
            {
                vector<string> v;
                v.push_back(num);
                
                v.push_back(string(1,ss[l++]));
                while(l<len)
                {
                    string nma;
                    while(l<len and isdigit(ss[l]))
                        nma.push_back(ss[l++]);
                    v.push_back(nma);
                    if(l==len)
                    {
                        st.push_back(evalute(v));
                        break;
                    }
                    else if(ss[l]=='+' or ss[l]=='-')
                    {
                        st.push_back(evalute(v));
                        st.push_back(string(1,ss[l++]));
                        break;
                    }
                    else
                    {
                        v.push_back(string(1,ss[l]));
                        l++;
                    }
                }
            }
        }
        return stoi(evalute(st));
    }
};