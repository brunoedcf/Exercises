#include <bits/stdc++.h>

using namespace std;

int main(){

    string a;
    string b;

    cin >> a >> b;

    map<char, int> first_string_map;
    map<char, int> second_string_map;

    for(int i = 0; i < a.size(); i++){
        if(!first_string_map[a[i]]) first_string_map[a[i]] = 1;
        else first_string_map[a[i]]++;
    }

    for(int i = 0; i < b.size(); i++){
        if(!second_string_map[b[i]]) second_string_map[b[i]] = 1;
        else second_string_map[b[i]]++;
    }

    if(first_string_map == second_string_map) cout << "Is permutation" << endl;
    else cout << "Is NOT permutation" << endl;

    return 0;
}