//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    class Meeting {
    public:
        int start;
        int end;
        int pos;

        Meeting(int start, int end, int pos) : start(start), end(end), pos(pos) {}
    };
    static bool meetingComparator(Meeting m1, Meeting m2) {
        return (m1.end < m2.end);
    }

    
    int maxMeetings(int n, int start[], int end[]) {
        vector<Meeting> meet;
        for (int i = 0; i < n; i++) {
            meet.push_back(Meeting(start[i], end[i], i + 1));
        }

        sort(meet.begin(), meet.end(), meetingComparator);

        int count = 1;
        int limit = meet[0].end;

        for (int i = 1; i < n; i++) {
            if (meet[i].start > limit) {
                limit = meet[i].end;
                count++;
            }
        }

        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++)
            cin >> start[i];

        for (int i = 0; i < n; i++)
            cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(n, start, end);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends