#include <iostream>
using namespace std;

void rowMajorMapping(int rows, int cols, int arr[][10], int oneD[]) {
    int k = 0;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            oneD[k++] = arr[i][j];
}
void reverseRowMajor(int rows, int cols, int oneD[], int arr[][10]) {
    int k = 0;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            arr[i][j] = oneD[k++];
}
 
void colMajorMapping(int rows, int cols, int arr[][10], int oneD[]) {
    int k = 0;
    for (int j = 0; j < cols; j++)
        for (int i = 0; i < rows; i++)
            oneD[k++] = arr[i][j];
}
void reverseColMajor(int rows, int cols, int oneD[], int arr[][10]) {
    int k = 0;
    for (int j = 0; j < cols; j++)
        for (int i = 0; i < rows; i++)
            arr[i][j] = oneD[k++];
}
 
void diagonalMapping(int n, int arr[ ][10], int oneD[]) {
    for (int i = 0; i < n; i++){
        oneD[i] = arr[i][i];
}
void reverseDiagonal(int n, int oneD[], int arr[][10]) {
    for (int i = 0; i < n; i++)
        arr[i][i] = oneD[i];
}

void triDiagonalMapping(int n, int arr[][10], int oneD[]) {
    int k = 0;
    
    for (int i = 0; i < n; i++) {
          
    }
   
    for (int i = 0; i < n - 1; i++){ 
        oneD[k++] = arr[i][i + 1];
    }
    
    for (int i = 1; i < n; i++){
        oneD[k++] = arr[i][i - 1];
    }

}
void reverseTriDiagonal(int n, int oneD[], int arr[][10]) {
    int k = 0;
    for (int i = 0; i < n; i++) {
        arr[i][i] = oneD[k++];
    }
    for (int i = 0; i < n - 1; i++) {
        arr[i][i + 1] = oneD[k++];
    }
    for (int i = 1; i < n; i++){ 
        arr[i][i - 1] = oneD[k++];
    }
}

void lowerTriangularMapping(int n, int arr[][10], int oneD[]) {
    int k = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++)
            oneD[k++] = arr[i][j];
}
void reverseLowerTriangular(int n, int oneD[], int arr[][10]) {
    int k = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++)
            arr[i][j] = oneD[k++];
}

void symmetricMapping(int n, int arr[][10], int oneD[]) {
    lowerTriangularMapping(n, arr, oneD);
}
void reverseSymmetric(int n, int oneD[], int arr[][10]) {
    reverseLowerTriangular(n, oneD, arr);
    
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            arr[i][j] = arr[j][i];
}
int main() {
    int n, m;
    cout << "Enter rows and columns: ";
    cin >> n >> m;
    int arr[10][10]; 
    int oneD[100];   
    cout << "Enter elements of 2D array:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    
    rowMajorMapping(n, m, arr, oneD);
    cout << "Row-major mapped 1D array: ";
    for (int i = 0; i < n*m; i++) cout << oneD[i] << " ";
    cout << endl;
    reverseRowMajor(n, m, oneD, arr); 
    cout << "After reverse row-major mapping 2D array:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cout << arr[i][j] << " ";
        cout << endl;
diagonalMapping(n, arr, oneD);
            cout << "1D Diagonal array: ";
            display1D(n, oneD);
            reverseDiagonal(n, oneD, arr);
            cout << "Reverse mapped 2D array:\n";
            display2D(n, n, arr);
 triDiagonalMapping(n, arr, oneD);
            cout << "1D Tri-diagonal array: ";
            display1D(3*n-2, oneD);
    reverseTriDiagonal(n, oneD, arr);
            cout << "Reverse mapped 2D array:\n";
            display2D(n, n, arr);
 lowerTriangularMapping(n, arr, oneD);
            cout << "1D Lower Triangular array: ";
            display1D(n*(n+1)/2, oneD);
    reverseLowerTriangular(n, oneD, arr);
            cout << "Reverse mapped 2D array:\n";
            display2D(n, n, arr);
upperTriangularMapping(n, arr, oneD);
            cout << "1D Upper Triangular array: ";
            display1D(n*(n+1)/2, oneD);
            reverseUpperTriangular(n, oneD, arr);
            cout << "Reverse mapped 2D array:\n";
            display2D(n, n, arr);
symmetricMapping(n, arr, oneD);
            cout << "1D Symmetric array: ";
            display1D(n*(n+1)/2, oneD);
            reverseSymmetric(n, oneD, arr);
            cout << "Reverse mapped 2D array:\n";
            display2D(n, n, arr);
    }
