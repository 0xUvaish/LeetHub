class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
                /* It is guaranteed input would always be 9x9.
           I am choosing to traverse this 2D matrix row-wise.
           We are interested in knowing if a number was seen before in
           1. row
           2. col
           3. box
           
           So, we can just use bool for tracking purpose. 
           At any given index 'i', we still store number = i+1.
                    
           
           So, when I am traversing a row I need to consider the follwing:
           1. row info: how many rows am I looking at? 
           2. col info: how many cols am I looking at?
           3. box info: how many boxes am I looking at?
           
           For #1
           I only need to worry about the current row - so we can live with just a vector of size 9
           
           For #2
           I will end up looking at all 9 cols, but one element each. So, we can imagine that
           it would make sense to have 2D vector = max.cols x max. elements per col i.e., 9x9
           
           For #3
           I will end up looking at 3 different boxes when I reach the end of a particular row.
           So, I need to track 3 (boxes) * 9 (no. of elements per box) i.e., 
           a 2D vector of 3*9. But to avoid resetting the box values and avoid other operations
           we can use 9x9 and make our lives a bit easier!
        */
        
        vector<vector<bool>> col(9, vector<bool> (9, false));
        vector<vector<bool>> box(9, vector<bool> (9, false));
        
        /* start traversing - row */
        for(int i = 0; i < 9; ++i)
        {
            //reset before traversing each row
            vector<bool> row(9, false);
            
			/* look at all columns in this ith row */
            for(int j = 0; j < 9; ++j)
            {
                /* only interested in digits */
                if(!isdigit(board[i][j]))
                    continue;
                
                /* number would be stored at (number - 1) index as per our logic, 
                   so subtract 1 to get the index directly */
                int idx = board[i][j] - '1';
                
                /* check current row if the number was already seen */
                if(row[idx] == true)
                    return false;
                
                row[idx] = true; //mark as seen
                
                //Now check if this number was already seen for the current column
                if(col[j][idx] == true)
                    return false;
                
                
                col[j][idx] = true; //mark as seen
                
                
                /* box indices need to go from 0 to 9,
                   j can be limited from 0 to 2
                   and then i in multiples of 3 can be added
                */
                int boxIdx = ((i/3) * 3) + (j/3);
                
                if(box[boxIdx][idx] == true)
                    return false;
                
                box[boxIdx][idx] = true; //mark as seen
            }
        }
        
        return true;
    }
};