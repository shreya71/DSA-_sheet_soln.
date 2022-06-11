/***********************************************************************************************************************************************
QUESTION: Given a string path, which is an absolute path (starting with a slash '/') to a file or directory in a Unix-style file system, convert it to the
          simplified canonical path. In a Unix-style file system, a period '.' refers to the current directory, a double period '..' refers to the directory
          up a level, and any multiple consecutive slashes (i.e. '//') are treated as a single slash '/'. For this problem, any other format of periods such 
          as '...' are treated as file/directory names.
          The canonical path should have the following format:
          The path starts with a single slash '/'.
          Any two directories are separated by a single slash '/'.
          The path does not end with a trailing '/'.
          The path only contains the directories on the path from the root directory to the target file or directory (i.e., no period '.' or double period '..')
          Return the simplified canonical path.
          
 APPROACH: We used the split property of strings to find all substrings lying between two strings then stacked the strings according to the conditions given
           and printed the result string at last. 
           
                              ************************ Splitting of strings *******************************************
************************************************************************************************************************************************/

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> v;
        //to split the strings between two '/'
        istringstream ss(path) ;
        string p, r;
        while(getline(ss, p, '/'))
        {
            if(p == "" || p == ".")
                continue;
            if( p != "..")
                v.push_back(p);
            else if(!v.empty())    // if ".." is present we have to back to previous and it wont be counted in string    
                v.pop_back();
        }
        for(auto i : v)
            r += "/"+i ;
        if(v.empty())
            return "/";
        else
            return r ;
    }
};
