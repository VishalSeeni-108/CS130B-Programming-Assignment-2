#include <iostream>
#include <algorithm> 
#include <vector> 
#include <map>

using namespace std; 
 
main()
{
    vector<string> oneLetterElements{"h", "b", "c", "n", "o", "f", "p", "s", "k", "v", "y", "i", "w", "u"};
    vector<string> twoLetterElements{"he", "li", "be", "ne", "na", "mg", "al", "si", "cl", "ar", "ca", "sc", 
    "ti", "cr", "mn", "fe", "co", "ni", "cu", "zn", "ga", "ge", "as", "se", "br", "kr", "rb", "sr", "zr", "nb", 
    "mo", "tc", "ru", "rh", "pd", "ag", "cd", "in", "sn", "sb", "te", "xe", "cd", "ba", "hf", "ta", "re", "os", 
    "ir", "pt", "au", "hg", "tl", "pb", "bi", "po", "at", "rn", "fr", "ra", "rf", "db", "sg", "bh", "hs", "mt", 
    "ds", "rg", "cn", "fl", "lv", "la", "ce", "pr", "nd", "pm", "sm", "eu", "gd", "tb", "dy", "ho", "er", "tm", 
    "yb", "lu", "ac", "th", "pa", "np", "pu", "am", "cm", "bk", "cf", "es", "fm", "md", "no", "lr"};  

    int numWords; 
    cin >> numWords; 

    for(int i = 0; i < numWords; i++)
    {
        string target; 
        map<string, bool> substringValidity; //TODO: Getting memory limit exceeded error - only ever use last 2 calculations, so modify this to only store the last 2

        cin >> target; 

        //Base cases
        substringValidity[target.substr(0,1)] = find(oneLetterElements.begin(), oneLetterElements.end(), target.substr(0,1)) != oneLetterElements.end();  
        substringValidity[target.substr(0, 2)] = (find(twoLetterElements.begin(), twoLetterElements.end(), target.substr(0,2)) != twoLetterElements.end()) || ((substringValidity[target.substr(0,1)] == true) && (find(oneLetterElements.begin(), oneLetterElements.end(), target.substr(1,1)) != oneLetterElements.end())); 
        // cout << substringValidity[target.substr(0,1)] << endl;      
        // cout << substringValidity[target.substr(0,2)] << endl; 

        //Inductive case
        for(int n = 3; n <= target.length(); n++)
        {
            substringValidity[target.substr(0, n)] = ((substringValidity[target.substr(0,n-1)] == true) && (find(oneLetterElements.begin(), oneLetterElements.end(), target.substr(n-1,1)) != oneLetterElements.end())) || ((substringValidity[target.substr(0,n-2)] == true) && (find(twoLetterElements.begin(), twoLetterElements.end(), target.substr(n-2,2)) != twoLetterElements.end())); 
            //cout << target.substr(0,n) << ": " << substringValidity[target.substr(0,n)] << endl;
        } 

        if(substringValidity[target])
        {
            cout << "YES" << endl; 
        }
        else
        {
            cout << "NO" << endl; 
        }
    }
}
