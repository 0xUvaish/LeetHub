class Solution {
public:
 string simplifyPath(string path) 
 {
    path=path[path.size()-1]=='/'?path:path+"/";
    string token="";
    stack<string>path_names;
    int index=0;
     
    while(index<path.size())
    {
        char chr=path[index++];
        if(chr!='/')token+=chr;
        else{
            if(token.compare("..")==0)
            {
                if(!path_names.empty()) 
                {
                    path_names.pop();
                }
                token="";
            }
            else{
                if(!token.empty() &&token.compare(".")!=0 )
                path_names.push(token);
                token="";
            }
        }
    }
     
    string result="";
    while(!path_names.empty())
    
    {
        cout<<path_names.top()<<endl;
        result='/'+path_names.top()+result;
        path_names.pop();
    }
     
    if(result.empty())
        result="/";
    return result;
}
    
};