//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

class LRUCache {
  private:
    int capacity;
    list<pair<int, int>> cache; // Doubly linked list to store keys and values in LRU order.
    unordered_map<int, list<pair<int, int>>::iterator> map; // Hashmap for O(1) access to cache items.
    
  public:
    // Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap) {
        capacity = cap;    
        
    }

    // Function to return value corresponding to the key.
    int get(int key) {
        // If the key is not in the cache, return -1.
        if (map.find(key) == map.end()) {
            return -1;
        }
        
        // Move the accessed key-value pair to the front of the cache (most recently used).
        auto it = map[key];
        cache.splice(cache.begin(), cache, it);

        // Return the value.
        return it->second;
    }

    // Function for storing key-value pair.
    void put(int key, int value) {
       if (map.find(key) != map.end()) {
            auto it = map[key];
            it->second = value;
            cache.splice(cache.begin(), cache, it);
            return;
        }

        // If the cache is full, remove the least recently used item (back of the list).
        if (cache.size() == capacity) {
            auto lru = cache.back();
            map.erase(lru.first);
            cache.pop_back();
        }

        // Insert the new key-value pair at the front of the list.
        cache.emplace_front(key, value);
        map[key] = cache.begin();
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);

        int queries;
        cin >> queries;
        while (queries--) {
            string q;
            cin >> q;
            if (q == "PUT") {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->put(key, value);
            } else {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends