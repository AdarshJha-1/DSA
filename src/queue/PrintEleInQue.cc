#include "iostream"
#include "queue"
#include <queue>

using namespace std;

void printQueue(queue<int> q) {
    int s = q.size();

    while(s--) {
        cout << q.front() << " ";
        q.push(q.front());
        q.pop();
    }
    cout << endl;
}

int main() {
    queue<int> q;
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    printQueue(q);
    return 0;
}
