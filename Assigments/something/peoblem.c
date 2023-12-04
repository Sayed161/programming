#include<bits/stdc++.h>
using namespace std;

int main() {
        int N;
        cin>>N;

    for (int i = 0; i < N; i++) {
        // Print spaces before the left side of the pattern
        for (int j = 0; j < i; j++) {
            cout << " ";
        }
        
        // Print left side of the pattern
       cout << "\\";

        // Print spaces between the characters
        for (int j = 0; j < 2 * (N - i - 2); j++) {
           cout << " ";
        }
        
        // Print right side of the pattern
      cout << "/";

        // Move to the next line
        cout << std::endl;
    }

    // Print the center line with 'X'
    cout << "  X" << std::endl;

    for (int i = N - 1; i >= 0; i--) {
        // Print spaces before the left side of the pattern
        for (int j = 0; j < i; j++) {
            std::cout << " ";
        }
        
        // Print left side of the pattern
        std::cout << "/";
        
        // Print spaces between the characters
        for (int j = 0; j < 2 * (N - i - 2); j++) {
            std::cout << " ";
        }
        
        // Print right side of the pattern
        std::cout << "\\";

        // Move to the next line
        std::cout << std::endl;
    }

    return 0;
}
