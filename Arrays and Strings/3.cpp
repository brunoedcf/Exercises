#include <bits/stdc++.h>

using namespace std;

string strip_string(string str){

    string auxiliar_string = str;

    for(int i = str.size() - 1; i >= 0; i--){
        if(str[i] == ' ') auxiliar_string.pop_back();
        else break;
    }

    return auxiliar_string;
}

string replace_spaces(string str){

    string auxiliar_string;
    
    for(int i = 0; i < str.size(); i++){

        if(str[i] == ' '){
            auxiliar_string += "%20";
            for(int j = i+1; j < str.size(); j++){
                if(str[j] != ' '){
                    i = j-1;
                    break;
                }
            }
        }
        else{
            auxiliar_string.push_back(str[i]);
        }

    }

    return auxiliar_string;
}

int main(){

    string a;
    string b;

    getline(cin, a);
    getline(cin, b);
    cin.ignore();

    cout << replace_spaces(strip_string(a)) << endl;
    cout << replace_spaces(strip_string(b)) << endl;

    return 0;
}