#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the maxSubsetSum function below.
int maxSubsetSum(vector<int> arr) {
  vector<long long int> recursiveSum(arr.size()); 
  long long int maxSum = -INFINITY;
  
  for(int i=0; i < arr.size(); i++)
  {
      if(i==0)
      {
          recursiveSum[i] = arr[i];          
      }
      else if(i==1)
      {
          if(arr[1] > arr[0])
          {
              recursiveSum[i] = arr[i];
          }
          else
          {
              recursiveSum[i] = arr[0];
          }
      }
      else
      {
          long long int newSum = arr[i] + recursiveSum[i-2];
          if(arr[i] > newSum && arr[i] > maxSum)
          {
              recursiveSum[i] = arr[i];
          }         
          else if(newSum > maxSum)
          {
              recursiveSum[i] = newSum;
          }
          else
          {
              recursiveSum[i] = maxSum;
          }
      }

      if(recursiveSum[i] > maxSum)
      {
          maxSum = recursiveSum[i];
      }
  }

  return maxSum;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int res = maxSubsetSum(arr);

    fout << res << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}


/*
vector<long long int> recursiveSum(arr.size()); 
int lastIndex = arr.size() - 1;
long long int maxSum = -INFINITY;

for (int i = lastIndex; i >= 0; i--) 
  {      
    if((i == lastIndex) || (i == lastIndex - 1))
    {
        recursiveSum[i] = arr[i];       
    }
    else if(i == lastIndex - 2)
    {
        //third to last index
        if(arr[i] > arr[i] + recursiveSum[lastIndex])
        {
            recursiveSum[i] = arr[i];
        }
        else
        {
            recursiveSum[i] = arr[i] + recursiveSum[lastIndex];
        }
    }
    else
    {
        if ((arr[i] > (arr[i]+recursiveSum[i+2])) && (arr[i] > (arr[i]+recursiveSum[i+3])))
        {
            recursiveSum[i] = arr[i];
        }
        else if(recursiveSum[i+2] > recursiveSum[i+3])
        {
            recursiveSum[i] = arr[i] + recursiveSum[i+2];
        }
        else
        {
          recursiveSum[i] = arr[i] + recursiveSum[i+3];
        }
    }

    if (recursiveSum[i] > maxSum)
      maxSum = recursiveSum[i];
  }
*/