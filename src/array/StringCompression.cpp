#include <iostream>
#include <vector>

int compress(std::vector<char>& chars) {
    int charCount = 0;
    for(int i = 0; i < chars.size(); i++) {
        
    }
    return chars.size();
}

int main() {
    std::vector<char> chars = {"a","b","b","b","b","b","b","b","b","b","b","b","b"};
    std::cout << compress(chars) << std::endl;
    return 0;
}
