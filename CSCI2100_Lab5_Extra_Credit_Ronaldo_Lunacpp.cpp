#include <iostream>
#include <vector>

using namespace std;
int search(int a, vector<int> b){
    for (auto it = b.begin(); it != b.end(); it++) {
        if(a == *it){
            return *it;
        }
    }
    return -1;
}


int waysTwoClimb(int n, vector<int> value, vector<int> key){
    if(n == 1){
        return 1;
    }
    if(n ==2){
        return 2;
    }
    if(search(n, key) != -1){
        return value[search(n, key)];
    }
    return waysTwoClimb(n-1, value, key) + waysTwoClimb(n-2, value, key);
}
int main() {
    int input;
    int temp;
    cout << "Input the number of steps: " << endl;
    vector<int> key;
    vector<int> value;
    while(true){    
        cin >> input;
        if(input==0){
            break;
        }
        bool found = false;
        temp = waysTwoClimb(input, value, key);
        for (auto it = value.begin(); it != value.end(); it++) {
            if (waysTwoClimb(input, value, key) == *it){
                found = true;
            }
            if(found == false){
                value.push_back(temp);
                key.push_back(input);
            }
                
            }
        cout << "The number of ways to climb " << input << " steps is " << temp << endl;
    }

}