#include <iostream>
#include <vector>
using namespace std;

int main() {
    int input;
    cout << "Input the number of steps: " << endl;
    while(true){    
        cin >> input;
        if(input==0){
            break;
        }
        vector<int> set;
        for(int i = 0; i < input; i++){
            if(i == 0){
                set.push_back(1);
            }else if(i == 1){
                set.push_back(2);
            }else{
            set.push_back(set[i-1]+set[i-2]);
            }
        }    
        for (auto it =set.begin(); it != set.end(); it++) {
            cout << *it << " ";
        }
        cout <<endl;
        cout << "The number of ways to climb " << input << " steps is " << set[input-1] << endl;
    }

}