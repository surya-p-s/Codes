#include <sstream>
#include <vector>
#include <iostream>
#include <cstring>
using namespace std;

vector<int> parseInts(string str) {
	// Complete this function

     // get length of string str
    int str_length = str.length();
 
    // create an array with size as string
    // length and initialize with 0
    int arr[str_length] = { 0 };
 
    int j = 0, i;
 
    // Traverse the string
    for (i = 0; str[i] != '\0'; i++) {
 
        // if str[i] is ', ' then split
        if (str[i] == ',')
            continue;
         if (str[i] == ' '){
            // Increment j to point to next
            // array location
            j++;
        }
        else {
 
            // subtract str[i] by 48 to convert it to int
            // Generate number by multiplying 10 and adding
            // (int)(str[i])
            arr[j] = arr[j] * 10 + (str[i] - 48);
        }
    }
   return;
    
    
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}