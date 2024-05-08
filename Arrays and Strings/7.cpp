#include <bits/stdc++.h>

using namespace std;

int main(){

    cout << "Input the matrix dimension:" << endl;
    int dim;
    cin >> dim;

    cout << "Input the matrix:" << endl;
    int matrix[dim][dim];
    for(int i = 0; i < dim; i++){
        for(int j = 0; j < dim; j++){
            cin >> matrix[i][j];
        }
    }

    cout << "Original Matrix: " << endl;
    for(int i = 0; i < dim; i++){
        for(int j = 0; j < dim; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    for(int layer = 0; layer < (dim/2); layer++){
        for(int i = 0; i < dim-1-(layer*2); i++){
            int aux = matrix[0+layer][dim-1-i-layer];
            matrix[0+layer][dim-1-i-layer] = matrix[i+layer][0+layer];
            matrix[i+layer][0+layer] = matrix[dim-1-layer][i+layer];
            matrix[dim-1-layer][i+layer] = matrix[dim-1-i-layer][dim-1-layer];
            matrix[dim-1-i-layer][dim-1-layer] = aux;
        }   
    }

    cout << "Rotated Matrix: " << endl;
    for(int i = 0; i < dim; i++){
        for(int j = 0; j < dim; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}