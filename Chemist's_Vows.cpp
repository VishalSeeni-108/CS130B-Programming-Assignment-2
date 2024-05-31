#include <iostream>
#include <algorithm> 
#include <vector> 

using namespace std; 
 
main()
{
    vector<string> oneLetterElements{"h", "b", "c", "n", "o", "f", "p", "s", "k", "v", "y", "i", "w", "u"};
    vector<string> twoLetterElements{"he"};  

    int numWords; 
    cin >> numWords; 

    for(int i = 0; i < numWords; i++)
    {
        string target; 
        bool substringValidity[target.length()];

        //Base cases
        if(find(oneLetterElements.begin(), oneLetterElements.end(), "o") != oneLetterElements.end())
        {
            cout << "Element found" << endl; 
        }
        else
        {
            cout << "Element not found" << endl; 
        }              
    }
}