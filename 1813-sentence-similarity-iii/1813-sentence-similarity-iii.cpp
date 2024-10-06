class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        //store all the words in a vector of string 
        vector<string> arr1;
        vector<string> arr2;
        
        //i want to keep a track of which sentence is longer and which sentence  is smaller
        //Because it would help me when i use two pointer approach
        
        string longest=sentence1;
        string shortest=sentence2;
        
        if(sentence1.length()<sentence2.length())
        {
            longest=sentence2;
            shortest=sentence1;
        }
        string currWord="";
        for(int i=0;i<longest.length();i++)
        {
            if(longest[i]==' ')
            {
                arr1.push_back(currWord);
                currWord="";
                continue;
            }
            currWord.push_back(longest[i]);
        }
        //add the last word too
        arr1.push_back(currWord);
        
        //store the strings in sentence 2
        currWord="";
        for(int i=0;i<shortest.length();i++)
        {
            if(shortest[i]==' ')
            {
                arr2.push_back(currWord);
                currWord="";
                continue;
            }
            currWord.push_back(shortest[i]);
        }
        arr2.push_back(currWord);
        
        //use two pointer approach 
        // i always to the arr1 (longest) 
        //j points to the arr2  (shortest)
        int start1=0;
        int start2=0;
        int end1=arr1.size()-1;
        int end2=arr2.size()-1;
         while(start1<=end1 && start2<=end2){
            if(arr1[start1]==arr2[start2]) //if crrent both starting words are same
                start1++,start2++;
            else if(arr1[end1]==arr2[end2]) //if the  current both ending words are same
                end1--,end2--;
            else
                return false;
        }
        return true;
    }
};