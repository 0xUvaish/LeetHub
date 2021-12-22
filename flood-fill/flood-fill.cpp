class Solution {
    
public:
      void floodFill(vector<vector<int>>& image, int sr, int sc, int newColor, int oldColor) 
  {  
         if(sr<0 || sc<0 || sc>=image[0].size() || sr>=image.size())
             return;
         if(image[sr][sc] != oldColor || newColor == oldColor)
             return;
      
         image[sr][sc] = newColor;
      
         floodFill(image, sr, sc-1, newColor, oldColor);
         floodFill(image, sr, sc+1, newColor, oldColor);
         floodFill(image, sr-1, sc, newColor, oldColor);
         floodFill(image, sr+1, sc, newColor, oldColor);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        floodFill(image, sr, sc, newColor, image[sr][sc]);       
        return image;
    }
};