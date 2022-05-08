class Solution {
public:
string countAndSay(int n) 
{
        string prevStr = "1";
        n--;
    
        while(n--)
        {
            string currStr = "";
            int i = 0;
            int k = prevStr.size();
            
            while(i < k)
            {
                int startInd = i;
                char ch = prevStr[i]; 
                
                while(prevStr[i] == prevStr[i+1])
                    i++;
                
                currStr += (i-startInd+1)+'0';
                currStr += ch;
                i++;
            }
            
            prevStr = currStr;
        }
        return prevStr;
    }
};