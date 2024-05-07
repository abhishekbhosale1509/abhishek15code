
#include<iostream>
using namespace std;
int main()
{

    int col, rail;
    // columns and rails
    int top = 0, temp = 0; // top for indicating whether we should go diagonallyup or down
                           // temp for storing the row number as it keeps on increasing and decreasing
    int abc = 0;
    // for traversing through array
    cout << "Enter the number of rails: ";
    cin >> rail;
    cout << "Enter the number of columns: ";
    cin >> col;

    char array[col];

    cout << "Enter the text: "; // this section takes input the plaintext and stores in character array
    cin >> array;
    cout << "PlainText: ";
    for (int i = 0; i < col; i++)
    {

        cout << array[i];
    }

    cout << endl;
    // Intilaize the matrix with blank

    char matrix[rail][col];
    for (int i = 0; i < rail; i++)
    {
        for (int j = 0; j < col; j++)
        {
            matrix[i][j] = ' ';
        }
    }

    // zigzag logic

    for (int j = 0; j < col; j++)
    {
        matrix[temp][j] = array[abc];
        abc++;
        if (top == 0)
        {
            temp++;
            if (temp == rail - 1)
            {
                top = 1;
            }
        }
        else if (top == 1)
        {
            temp--;
            if (temp == 0)
            {
                top = 0;
            }
        }
    }
    // Display the encrypted text
    cout << "Encrypted text: ";
    for (int i = 0; i < rail; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] != ' ')
            {
                cout << matrix[i][j];
            }
        }
    }

    // Decryption
    char dec[col];
    dec[col] = '\0'; // Null-terminate the decrypted array
    abc = 0;
    top = 0;
    temp = 0;
    for (int j = 0; j < col; j++)
    {
        dec[j] = matrix[temp][j];
        if (top == 0)
        {
            temp++;
            if (temp == rail - 1)
            {
                top = 1;
            }
        }
        else if (top == 1)
        {
            temp--;
            if (temp == 0)
            {
                top = 0;
            }
        }
    }
    cout << "\nDecrypted text: " << dec << endl;
     return 0;
}