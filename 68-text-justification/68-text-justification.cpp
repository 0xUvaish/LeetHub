class Solution {
public:
    string get_spaces(int n) {
        string spaces = "";
        for(int i = 0; i < n; i++)
            spaces += " ";
        return spaces;
    }
    
    
    string justify(vector<string> &words, int mxWidth) {
        int len = 0;
        for(string word: words) 
            len += word.length();
        
        int total = mxWidth - len;
        
        if(words.size() == 1) 
            return words[0] + get_spaces(total);
        
        
        int space = total / (words.size()-1);
        int rem = total % (words.size()-1);
        
        string line = words[0];
        for(int i = 1; i < words.size(); i++) {
            // extra spaces give to leftmost rem words
            if(i <= rem)
                line += get_spaces(space+1) + words[i];
            else 
                line += get_spaces(space) + words[i];
        }
        
        return line;
    }
    
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int curr = 0;
        vector<string> tmp;
        vector<string> ans;
        
        for(string word: words) {
            if(curr + word.length() <= maxWidth) {
                tmp.push_back(word);
                curr += word.length() + 1;
            } else {
                curr = 0;
                string line = justify(tmp, maxWidth);
                ans.push_back(line);
                tmp.clear();
                
                tmp.push_back(word);
                curr += word.length() + 1;
            }
        }
        
        string line = tmp[0];
        for(int i = 1; i < tmp.size(); i++)
            line += " " + tmp[i];
        
        // add extra spaces to the end
        line += get_spaces(maxWidth-line.length());
        ans.push_back(line);
        
        return ans;
    }
};