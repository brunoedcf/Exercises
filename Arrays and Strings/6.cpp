#include <bits/stdc++.h>

using namespace std;

int main(){

    string my_string;
    cin >> my_string;

    int index = 0;
    string compressed;

    while(index < my_string.size()){
        int ocurrences = 1;
        char current = my_string[index];
        index++;
        while(index < my_string.size() && my_string[index] == current){
            ocurrences++;
            index++;
        }
        compressed.push_back(current);
        compressed += to_string(ocurrences);
    }
    cout << compressed << endl;

    return 0;
}