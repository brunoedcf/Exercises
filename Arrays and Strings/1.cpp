#include <bits/stdc++.h>

using namespace std;

int main(){

    string my_string;
    cin >> my_string;

    // Using additional data structure

    map<char, int> char_map;
    bool is_unique = true;

    for(int i = 0; i < my_string.size(); i++){
        if( char_map.find(my_string[i]) != char_map.end() ){
            is_unique = false;
            break;
        }
        char_map[my_string[i]] = 1;
    }

    if(is_unique) cout << "Is Unique" << endl;
    else cout << "Is Not Unique" << endl;

    // Not using an additional data structure

    string sorted_my_string = my_string;
    sort(sorted_my_string.begin(), sorted_my_string.end());

    is_unique = true;

    for(int i = 1; i < sorted_my_string.size(); i++){
        if(sorted_my_string[i] == sorted_my_string[i-1]){
            is_unique = false;
            break;
        }
    }

    if(is_unique) cout << "Is Unique" << endl;
    else cout << "Is Not Unique" << endl;

    return 0;
}