#include <iostream>

using namespace std;

int main() {
    int num[6] = {0, 1, 2, 3, 4, 5};

    
    for (int i = 0; i < 3; ++i) {
        int temp = num[i];
        num[i] = num[5 - i];  
        num[5 - i] = temp;
    }

    std::cout << "Reversed array: ";
    for (int i = 0; i < 6; ++i) {
        std::cout << num[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
