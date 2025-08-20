#include <iostream>
#include <queue>
#include <vector>

void printWK(std::vector<int> arr, int k) {
    std::queue<int> q;
    
    // O(n);
    for(int i = 0; i < arr.size(); i++) {
        q.push(i);
    }

    // O(n);
    while(q.size() != k - 1) {
        int i = 0;
        int si = q.front();
        q.pop();
        
        // O(nk);
        while(i != k) {
            std::cout << arr[si] << " ";
            si++;
            i++;
        }
    }
}

void printV2(std::vector<int> arr, int k) {
    std::queue<int> q;
    int i = 0;

    // O(k);
    while(i != k - 1) {
        q.push(arr[i]);
        i++;
    }

    // O(n);
    while(i < arr.size()) {
        q.push(arr[i]);
        int j = k;

        // O(nk);
        while(j--) {
            std::cout << q.front() << " ";
            int t = q.front();
            q.pop();
            q.push(t);
        }
        q.pop();
        i++;
    }
}

int main() {
    std::vector<int> arr = {3, 6, 2, 7, 8, 11};
    int k = 3; 
    printV2(arr, k);
    return 0;
}
