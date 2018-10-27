#include <bits/stdc++.h>

using namespace std;

// Complete the makeAnagram function below.
int makeAnagram(string a, string b)
{
    //my inital thought was of course a nested-loop brute force
    //I also thought some sort of hash could useful
        //but could not thing of an efficent way to implement it
    
    //this is a slight modifcation of the code found in the problem discusson
        //posted by cool_shark
    
    //hold the amount of times each character is seen 
    vector<int> characterCount (26, 0);
    int charcIndex = 0, deletionsCount = 0;


    //using the ascii value of characters find the index for the characterCount
    //increment for a and decrment at the corresponding index in the array
    //characters that occur in both strings will negate each other 
    //leaving the total absoulte value of the count in the array as the total deletions necessary
    for(int i=0; i < a.length(); i++)
    {
        charcIndex = a[i] - 'a';
        characterCount[charcIndex]++;
    }
    for(int i=0; i < b.length(); i++)
    {
        charcIndex = b[i] - 'a';
        characterCount[charcIndex]--;            
    }
    
    for(int i=0; i < 26; i++)
    {
        deletionsCount += abs(characterCount[i]);
            //absoulte value needed in case stirng b has more instances of a given character
                //resulting in a negative value, don't wanna subtract from the count
    }

    return deletionsCount;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int res = makeAnagram(a, b);

    fout << res << "\n";

    fout.close();

    return 0;
}
