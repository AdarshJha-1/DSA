#include <iostream>
#include <string>
#include <queue>

std::string ans(std::string A) {
    std:: queue<char> q;
    std::string B = "";
    for(int i = 0; i < A.size(); i++) {
        if(q.empty()) {
            q.push(A[i]);
            B += q.front();
        } else {
            if(q.front() == A[i]) {
                q.pop();
            } else {
                q.push(A[i]);
            }
            if(q.empty()) {
                B += '#';
            } else {
                B += q.front();
            }
        }
    }
    
    return B;
} 

int main() {
    std::string A = "jyhrcwuengcbnuchctluxjgtxqtfvrebveewgasluuwooupcyxwgl";
    std::string B = ans(A);
    std::cout << B << std::endl; 
    return 0;
}
