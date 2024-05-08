#include <bits/stdc++.h>

using namespace std;

int main(){

    string my_input_string;

    getline(cin, my_input_string);
    cin.ignore();

    map<char, int> auxiliar_map;

    for(int i = 0; i < my_input_string.size(); i++){

        if(my_input_string[i] != ' '){

            char to_lowercase_char = my_input_string[i] > 96 ? my_input_string[i] : my_input_string[i] + 32;

            if(!auxiliar_map[to_lowercase_char]){
                auxiliar_map[to_lowercase_char] = 1;
            }
            else{
                auxiliar_map[to_lowercase_char]++;
            }
        }

    }

    int total_even_chars = 0;

    for(auto it = auxiliar_map.begin(); it != auxiliar_map.end(); it++) {

        if(it->second % 2 != 0){
            total_even_chars++;
        } 

    }

    if(total_even_chars > 1){
        cout << "False" << endl;
    }
    else{
        cout << "True" << endl;
    }

    return 0;
}