#include <iostream>
#include <cmath>
using namespace std;
 
int main() {
 
    float number;
    cout << "Enter a number: "<<endl;
    
    cin >> number;
      if (fmod(number, 2) == 0) {
        cout << number << " is even" << endl;
    } else {
        cout << number << " is odd" << endl;
    }
    
    // cin >> number;
//   getline use garda nii hunxa
//     cout << "the number you enter is  = " << number << endl;
 
    return 0;
}
