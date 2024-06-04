#include <iostream>
#include <list>
#include <vector>
#include <algorithm> 

using namespace std; 

int main()
{
    int numCars; 
    cin >> numCars; 

    vector<int> cars; 

    for(int i = 0; i < numCars; i++)
    {
        int newCarWeight; 
        cin >> newCarWeight;
        cars.push_back(newCarWeight); 
    }

    //Find longest increasing substring at each index
    vector<int> longestIncreasingSubstring(cars.size(), 1); 
    for(int i = cars.size() - 2; i >= 0; i--)
    {
        for(int j = i; j < cars.size(); j++)
        {
            if(cars.at(j) > cars.at(i))
            {
                int potentialNewLongest = longestIncreasingSubstring.at(j) + 1; 
                if(potentialNewLongest > longestIncreasingSubstring.at(i))
                {
                    longestIncreasingSubstring.at(i) = potentialNewLongest;  
                }
            }
        }
    }

    //Find longest decreasing substring at each index
    vector<int> longestDecreasingSubstring(cars.size(), 1); 
    for(int i = cars.size() - 2; i >= 0; i--)
    {
        for(int j = i; j < cars.size(); j++)
        {
            if(cars.at(j) < cars.at(i))
            {
                int potentialNewLongest = longestDecreasingSubstring.at(j) + 1; 
                if(potentialNewLongest > longestDecreasingSubstring.at(i))
                {
                    longestDecreasingSubstring.at(i) = potentialNewLongest;  
                }
            }
        }
    }

    //Calculate longest possible train at each index and take max
    vector<int> longestTrain(cars.size(), 1); 
    for(int i = 0; i < longestTrain.size(); i++)
    {
        longestTrain.at(i) = longestIncreasingSubstring.at(i) + longestDecreasingSubstring.at(i) - 1; 
    }

    if(longestTrain.size() != 0)
    {
        cout << *max_element(longestTrain.begin(), longestTrain.end()) << endl; 
    }
    else
    {
        cout << 0 << endl; 
    }
    
    // for(int i = 0; i < longestIncreasingSubstring.size(); i++)
    // {
    //     cout << "Longest increasing substring starting at " << cars.at(i) << ": " << longestIncreasingSubstring.at(i) << endl; 
    // }

    // for(int i = 0; i < longestDecreasingSubstring.size(); i++)
    // {
    //     cout << "Longest decreasing substring starting at " << cars.at(i) << ": " << longestDecreasingSubstring.at(i) << endl; 
    // }
}