#include <bits/stdc++.h>

using namespace std;

int sumHourglass(const vector<vector<int>> & arr, int i, int j)
{
    int sum = arr.at(i).at(j)  +  arr.at(i).at(j + 1) +   arr.at(i).at(j + 2);
    sum +=                        arr.at(i + 1).at(j + 1);
    sum +=    arr.at(i + 2).at(j) + arr.at(i + 2).at(j + 1) + arr.at(i + 2).at(j + 2);
    return sum;
}


// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr) {
    int largestHourglass = INT_MIN; 
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            largestHourglass = max(largestHourglass, sumHourglass(arr,i,j));
    return largestHourglass;
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

    cout << "Hourglass sum at 3 2 " << sumHourglass(arr,3,2) << "\n";

    int result = hourglassSum(arr);

    cout << result << "\n";

    fout.close();

    return 0;
}
