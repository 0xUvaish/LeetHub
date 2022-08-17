class Solution {
public:
  int uniqueMorseRepresentations(vector<string>& words) 
  {
  	vector<string> mp = 
    {".-","-...","-.-.","-..",".","..-.","--.","....",
    "..",".---","-.-",".-..","--","-.","---",".--.",
    "--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

  	unordered_set<string> ss;

  	for(auto word : words) 
    {
  		string t;
  		for (auto c : word) 
            t += mp[c - 'a'];
        
  		ss.insert(t);
  	 }

  return ss.size();
  }
};