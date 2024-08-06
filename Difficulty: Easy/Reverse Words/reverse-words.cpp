//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(const string& S) {
    // Use a stringstream to split the string by '.'
    stringstream ss(S);
    string word;
    vector<string> words;
    
    // Split the string by '.'
    while (getline(ss, word, '.')) {
        words.push_back(word);
    }
    
    // Reverse the vector of words
    reverse(words.begin(), words.end());
    
    // Join the reversed words with dots
    std::string result;
    for (size_t i = 0; i < words.size(); ++i) {
        result += words[i];
        if (i < words.size() - 1) {
            result += '.';
        }
    }
    
    return result;
}
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends