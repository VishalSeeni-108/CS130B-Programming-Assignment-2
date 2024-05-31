#include <iostream>
#include <list>
#include <vector>
#include <algorithm> 

using namespace std; 

main()
{
    int numCars; 
    cin >> numCars; 

    vector<list<int>> dynamicTable; 

    for(int i = 0; i < numCars; i++)
    {
        int newCarWeight; 
        cin >> newCarWeight;

        vector<list<int>> tempTable; 
        for(int i = 0; i < dynamicTable.size(); i++)
        {
            //Don't add new car
            tempTable.push_back(dynamicTable.at(i)); 
            //Add at back, if possible
            if(newCarWeight < dynamicTable.at(i).front())
            {
                list<int> tempOrder= dynamicTable.at(i); 
                tempOrder.push_front(newCarWeight);   
                tempTable.push_back(tempOrder); 
            }
            //Add at front, if possible
            if(newCarWeight > dynamicTable.at(i).back())
            {
                list<int> tempOrder = dynamicTable.at(i); 
                tempOrder.push_back(newCarWeight); 
                tempTable.push_back(tempOrder); 
            }      
        }
        //Add new car as starting point 
        tempTable.push_back({newCarWeight});

        //Replace old dynamic table with temp table
        dynamicTable.clear(); 
        dynamicTable = tempTable; 

        // cout << "After adding " << newCarWeight << ": " << endl; 
        // for(int i = 0; i < dynamicTable.size(); i++)
        // {
        //     for(int n : dynamicTable.at(i))
        //     {
        //         cout << n;
        //     }
        //     cout << endl; 
        // }
    }

    //Output longest list as longest possible train
    // cout << "Final dynamic table: " << endl; 
    // for(int i = 0; i < dynamicTable.size(); i++)
    // {
    //     for(int n : dynamicTable.at(i))
    //     {
    //         cout << n;
    //     }
    //     cout << endl; 
    // }

    cout << (*(max_element(dynamicTable.begin(), dynamicTable.end(), [](list<int> a, list<int> b){return b.size() > a.size();}))).size() << endl; 
}