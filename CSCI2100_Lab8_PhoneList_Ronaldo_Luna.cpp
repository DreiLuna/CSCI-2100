#include <iostream>
#include <string>
#include <algorithm> 

using namespace std;


bool runCase(int numPhoneNumbers){
  cout << "Please input " << numPhoneNumbers << " phone numbers: " << endl;
  string phoneNumbers[numPhoneNumbers];
  for(int i = 0; i < numPhoneNumbers; i++){
    cin >> phoneNumbers[i];
  }
  sort(phoneNumbers, phoneNumbers+numPhoneNumbers);
  for(int i = 0; i < numPhoneNumbers; i++){
    if(sizeof(phoneNumbers[i+1]) > sizeof(phoneNumbers) || sizeof(phoneNumbers) >sizeof(phoneNumbers[i-1])){
      if(phoneNumbers[i+1].substr(0, phoneNumbers[i].length()) == phoneNumbers[i] || phoneNumbers[i-1].substr(0, phoneNumbers[i].length()) == phoneNumbers[i]){
        return true;
      }
    }
  }
  return false;
}
  
  


int main() { 
  int input;
  int numCases;
  cout << "Please enter the amount of cases: ";
  cin >> numCases;
  cout << endl;
  for(int i = 0; i < numCases; i++){
    cout << "Please input how many phone numbers you want to enter: " << endl;
    cin >> input;
    if(runCase(input)){
      cout << "NO" << endl;
    }else{
      cout << "YES" << endl;
    }
  }

}