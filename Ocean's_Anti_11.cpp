#include <iostream> 
#include <vector> 

using namespace std;

struct dpData //data passed up from previous cases
{
    long long int numStrings; 
    long long int numStartOne; 
    long long int numEndOne; 
}; 

main()
{
    int numTests; 
    cin >> numTests; 
    vector<dpData> dpTable; 
    dpData dummyCase1; 
    dpData dummyCase2; 
    dpData baseCase; //substring of length 2 
    baseCase.numStrings = 3;
    baseCase.numStartOne = 1; 
    baseCase.numEndOne = 1;
    dpTable.push_back(dummyCase1);
    dpTable.push_back(dummyCase2);   
    dpTable.push_back(baseCase); 
     

    for(int i = 0; i < numTests; i++)
    {
        int length; 
        cin >> length; 
        
        vector<dpData> dpTable; 
        dpData dummyCase1; 
        dpData dummyCase2; 
        dpData baseCase; //substring of length 2 
        baseCase.numStrings = 3;
        baseCase.numStartOne = 1; 
        baseCase.numEndOne = 1;
        dpTable.push_back(dummyCase1);
        dpTable.push_back(dummyCase2);   
        dpTable.push_back(baseCase);
        
        for(int j = 3; j <= length; j++) 
        {      
    
           long long int zeroAddedToEnd = dpTable.at(j-1).numStrings; 
           long long int oneAddedToEnd = (dpTable.at(j-1).numStrings - dpTable.at(j-1).numEndOne); 
           long long int zeroAddedToBeginning = dpTable.at(j-1).numStrings; 
           long long int oneAddedToBeginning = (dpTable.at(j-1).numStrings - dpTable.at(j-1).numStartOne);


           dpData newCase; 
           newCase.numStrings = zeroAddedToEnd + oneAddedToEnd + zeroAddedToBeginning + oneAddedToBeginning; 
           newCase.numStartOne = oneAddedToBeginning; 
           newCase.numEndOne = oneAddedToEnd; 
           dpTable.push_back(newCase);  
        }
        cout << dpTable.at(length).numStrings << endl; 
    }
}