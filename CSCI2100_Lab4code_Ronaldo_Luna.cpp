#include <iostream>
#include <vector>

#define DEBUG

using namespace std;

bool search(vector<int> set, int key){
    for (auto it = set.begin(); it != set.end(); it++) {
        if(*it == key){
            return true;
        }
    }
    return false;
}

int main() {
    int input;
    vector<int> valueSet;
    vector<int> temp;
    int answer = 0;

    while(true){
        cout << "Enter value:" << endl;
        cin >> input;
        if (input == -1){
            break;
        }
        valueSet.push_back(input);
    }

    #ifdef DEBUG
    cout << "Your input: ";
    for (auto it = valueSet.begin(); it != valueSet.end(); it++) {
        cout << *it << ", ";
    }
    cout <<endl;
    cout << "Evens: ";
    #endif

    for (auto it = valueSet.begin(); it != valueSet.end(); it++) {
        if(*it%2 == 0){
            temp.push_back(*it);
            #ifdef DEBUG
            cout << *it << ", ";
            #endif
        }
    }
    #ifdef DEBUG
    cout << endl;
    #endif
    for (auto it = temp.begin(); it != temp.end(); it++) {
        if(search(temp, (*it/2)) || (*it/2 == 1)){
            answer++;
        }
    }

    cout << "There are " << answer << " doubles in the list";
}