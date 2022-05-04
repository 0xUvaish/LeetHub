class Solution
{
  string convertToString(vector<string> &sol)
  {
    return sol[0] + '.' + sol[1] + '.' + sol[2] + '.' + sol[3];
  }
    
  void restore(string &ip, vector<string> &res, vector<string> &sol, int begin)
  {
      
    // If is 4th part
    if (sol.size() == 4) 
    {
      // If we use every character, we find a solution
      if (begin == ip.length())
        res.push_back(convertToString(sol));
      return;
    }
      
    // If is not 4th part
    string str;
    for (int i = 1; i <= 3 && begin + i <= ip.size(); i++) 
    {
      str = ip.substr(begin, i);
      // leading zero or > 255 are invalid
      if ((str[0] == '0' && str.size() > 1) || stoi(str) > 255)
        return;

      sol.push_back(str);
      restore(ip, res, sol, begin + i);
      sol.pop_back();
    }
  }

public:
  vector<string> restoreIpAddresses(string s) 
  {
    vector<string> res, sol;
    if (s.length() > 12)
      return res;
      
    restore(s, res, sol, 0);
    return res;
  }
    
};