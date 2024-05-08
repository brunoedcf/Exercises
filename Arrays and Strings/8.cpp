#include <bits/stdc++.h>

using namespace std;

int main(){

    // Read matrix dimensions
    int n, m;
    cout << "Input matix dimensions:" << endl;
    cin >> n >> m;

    int input_matrix[n][m];

    for(int i = 0; i < n; i++){
        cout << "Input line " << i+1 << endl;
        for(int j = 0; j < m; j++){
            cin >> input_matrix[i][j];
        }
    }

    // Print the original matrix 
    cout << "Original Matrix: " << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << input_matrix[i][j] << " ";
        }
        cout << endl;
    }

    int zero_rows[n];
    int zero_columns[m];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(input_matrix[i][j] == 0){
                zero_rows[i] = 1;
                zero_columns[j] = 1;
            }
        }
    }

    // Print the Zero matrix 
    cout << "Zero Row Matrix: " << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(zero_rows[i] == 1 || zero_columns[j] == 1){
                cout << 0 << " ";
            }
            else{
                cout << input_matrix[i][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}