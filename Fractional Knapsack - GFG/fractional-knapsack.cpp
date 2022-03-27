// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    
    
    static bool cmp(struct Item i1, struct Item i2)
    {
    double vw1 = (double) i1.value/i1.weight;
    double vw2 = (double) i2.value/i2.weight;
    return vw1 > vw2;
    }
    
    double fractionalKnapsack(int W, Item arr[], int n)
    {
       sort(arr, arr+n, cmp);
        double fVal = 0;
    
        for(int i = 0; i < n; i++)
        {
            if(arr[i].weight <= W)
            {
                fVal += arr[i].value;
                W -= arr[i].weight; 
            }
            
            else
            {
                double priceperWt = (double) arr[i].value/arr[i].weight;
                fVal += priceperWt * W;
                break;
            }
        }
    
    return fVal;
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends