#include <iostream>

using namespace std;

int waysTwoClimb(int n){
    if(n == 1){
        return 1;
    }
    if(n ==2){
        return 2;
    }
    return waysTwoClimb(n-1) + waysTwoClimb(n-2);
}
int main() {
    int input;
    cout << "Input the number of steps: " << endl;
    while(true){    
        cin >> input;
        if(input==0){
            break;
        }
        cout << "The number of ways to climb " << input << " steps is " << waysTwoClimb(input) << endl;
    }

}