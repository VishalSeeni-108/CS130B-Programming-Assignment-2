#include <iostream> 
#include <vector> 
#include <math.h>

using namespace std;

struct dpData //data passed up from previous cases
{
    long long int numStrings; 
    long long int numEndOne;
}; 

main()
{
    int numTests; 
    cin >> numTests;      

    for(int i = 0; i < numTests; i++)
    {
        int length; 
        cin >> length; 
        
        vector<dpData> dpTable; 
        dpData dummyCase1; 
        dpData oneCase; //substring of length 1
        dpData twoCase; //substring of length 2 
        oneCase.numStrings = 2; 
        oneCase.numEndOne = 1; 
        twoCase.numStrings = 3;
        twoCase.numEndOne = 1;
        dpTable.push_back(dummyCase1);
        dpTable.push_back(oneCase);   
        dpTable.push_back(twoCase);
        
        for(int j = 3; j <= length; j++) 
        {      
           long long int addZero = dpTable.at(j-1).numStrings % (long long int)(pow(10,9) + 7); 
           long long int addOne = ((dpTable.at(j-1).numStrings % (long long int)(pow(10,9) + 7)) - (dpTable.at(j-1).numEndOne % (long long int)(pow(10,9) + 7))) % (long long int)(pow(10,9) + 7); 

           dpData newCase; 
           newCase.numStrings = ((addZero  % (long long int)(pow(10,9) + 7)) + (addOne % (long long int)(pow(10,9) + 7))) % (long long int)(pow(10,9) + 7); 
           newCase.numEndOne = (addOne % (long long int)(pow(10,9) + 7)); 
           dpTable.push_back(newCase); 
        }
        cout << (dpTable.at(length).numStrings) << endl;
    }
}