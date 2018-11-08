#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

//Returnes number of swaps
int bubbleSort(vector<int> & numbers)
{
    int swaps = 0;
    for(int pass = 0; pass < numbers.size(); pass++)
    {
        bool noSwaps = true;
        for(int number = 0; number < numbers.size() - 1; number++)
        {
            if(numbers[number] > numbers[number + 1])
            {
                swap(numbers[number], numbers[number + 1]);
                noSwaps = false;
                swaps++;
            }
        }
        if(noSwaps)
        {
            break;
        }
    }
    return swaps;
}

void printSwaps(vector<int> numbers)
{
    int swaps = bubbleSort(numbers);
    cout << "Array is sorted in "<< swaps << " swaps." << "\n";
    cout << "First Element: " << numbers.at(0) << "\n";
    cout << "Last Element: "<< numbers.at(numbers.size() - 1) << "\n";
}


int main()
{
    vector<int> numbers = {4,1,23,5};
    printSwaps(numbers);


    return 0;
}
