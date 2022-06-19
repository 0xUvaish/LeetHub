class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>>output(searchWord.size());
        
        sort(products.begin(), products.end());
        
        auto it = products.begin();
        for(int i = 1; i <= searchWord.size(); i++){
            auto w = searchWord.substr(0,i);
            
            it = lower_bound(it, products.end(), w);
            
            for(int j = 0; j<3 && (it+j)!=products.end(); j++){
                
                if((*(it+j)).compare(0, w.size(), w) == 0){
                    output[i-1].push_back(*(it+j));
                }
                
            }
        }
        return output;
        
    }
};