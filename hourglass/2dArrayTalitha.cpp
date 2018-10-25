#include <bits/stdc++.h>

using namespace std;

// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr) 
{
  //BRUTE FORCE
    int maxHourglassSum = INT_MIN, currentSum =0;

    //doesn't loop through last two rows/colums since those can't make complete hourglasses       
    for(int i=0; i < (arr.size() - 2); i++)
    {
        for(int j=0; j < (arr[0].size() - 2); j++)
        {
            /*
                [i][j]    [i][j+1]    [i][j+2]
                          [i+1][j+1]
                [i+2][j]  [i+2][j+1]  [i+2][j+2]
            */            
            
            //top row (3)
            currentSum = arr[i][j] + arr[i][j+1] + arr[i][j+2];
            // middle glass part (1)
            currentSum += arr[i+1][j+1];
            //bottom row (3)
            currentSum += arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2];
    
            //check if we've found a bigger hourglass
            if(currentSum > maxHourglassSum)
            {
                cout << i << " " << j << endl;
                maxHourglassSum = currentSum;
            }            
        }
    }

    return maxHourglassSum;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = hourglassSum(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
