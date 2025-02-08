#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;


int main() {
    string firstWord;
    string secondWord;
    cout << "Please enter the firstWord string in all lower case \n";
    cin >> firstWord;
    cout << "Please enter the secondWord string in all lower case\n";
    cin >> secondWord;
    cout << "length of the longest substring common in both strings is \n" << endl;
    
    int m = firstWord.length();
    int n = secondWord.length();
    

    // vector to store the matrix for the common char in two strings
    // row will be first string 
    // column will be second string
    vector<vector<int>> tempMatrix(m + 1, vector<int>(n + 1, 0));

    int res = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (firstWord[i - 1] == secondWord[j - 1]) {
                tempMatrix[i][j] = tempMatrix[i - 1][j - 1] + 1;
                res = max(res, tempMatrix[i][j]);
            } else {
                tempMatrix[i][j] = 0;
            }
        }
    }
    
    cout << res << endl;
    return 0;
}