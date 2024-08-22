class Solution {
public:
	int findComplement(int num) 
    {
		int res = 0, count = 0;
		while(num){
			if(!(num & 1)){
				res += pow(2, count);
			}
			count++;
			num >>= 1;
		}
		return res;
	}
};