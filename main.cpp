#include <iostream> 
#include <ostream>
#include <stdlib.h>
#include <limits>
#include <cstdint>
#include <vector>
#include <string>
#include <bitset>

#define N (10000)

int minFlips(std::string s) {
    std::bitset<N> a{s.c_str()};
    size_t ans = 10000;
    for(int k{0}; k<s.length(); ++k) {
        // std::cout << a.to_string().c_str() << std::endl;
        size_t cnt = 0;
        std::bitset<N> b(a);
        for(int i{1}; i<s.length(); ++i) {
            if(b[i] == b[i-1]) {
                b[i] = !b[i];
                ++cnt;
            }
        }
        bool x = a[s.length()-1];
        a <<= 1;
        a[0] = x;
        ans = std::min(ans, cnt);
    }
    return ans;
}

int main(int argc, char *argv[]) {
    std::string str = std::string(argv[1]);
    std::cout << minFlips(str) << std::endl;
    return 0;
}