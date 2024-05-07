#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

// AES S-box
const unsigned char s_box[256] = {
     0x63, 0x7C, 0x77, 0x7B, 0xF2, 0x6B, 0x6F, 0xC5, 0x30, 0x01, 0x67, 0x2B, 0xFE, 0xD7, 0xAB, 0x76,
    
};

// Rcon values for key schedule
const unsigned char rcon[10] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1B, 0x36};

// Number of words in the key
const int key_words = 4;

// Number of rounds for AES-128
const int num_rounds = 10;

// Key expansion function
void keyExpansion(const vector<unsigned char>& key, vector<unsigned char>& roundKeys) {
    roundKeys = key;

    for (int i = key_words; i < (key_words * (num_rounds + 1)); ++i) {
        unsigned char temp[4];
        for (int j = 0; j < 4; ++j) {
            temp[j] = roundKeys[(i - 1) * 4 + j];
        }

        if (i % key_words == 0) {
            // Rotate word
            unsigned char temp_byte = temp[0];
            temp[0] = temp[1];
            temp[1] = temp[2];
            temp[2] = temp[3];
            temp[3] = temp_byte;

            // Substitute word using S-box
            for (int j = 0; j < 4; ++j) {
                temp[j] = s_box[temp[j]];
            }
            // XOR with Rcon
            temp[0] ^= rcon[i / key_words - 1];
        }
        // XOR with the previous word
        for (int j = 0; j < 4; ++j) {
            roundKeys.push_back(roundKeys[(i - key_words) * 4 + j] ^ temp[j]);
        }
    }
}

int main() {
// Input matrix
    int rows, columns;
    rows=4;
    cout << "No. of rows: " <<rows<< endl;
    columns=4;
    cout << "No. of columns: " <<columns<<endl;

    char plain[rows][columns];
    cout << "Enter plain text:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cin >> plain[i][j];
        }
    }

    for (int j = 0; j < columns; j++) {
        cout << "[";
        for (int i = 0; i < rows; i++) {
            cout << plain[i][j] << "   ";
        }
        cout << "]";
        cout << endl;
    }

    // Convert into ASCII
    cout << "Ascii=" << endl;
    for (int j = 0; j < columns; j++) {
        cout << "[";
        for (int i = 0; i < rows; i++) {
            cout << int(plain[i][j]) << "   ";
        }
        cout << "]";
        cout << endl;
    }

    // Convert into hexadecimal
    cout << "Hexadecimal=" << endl;
    for (int j = 0; j < columns; j++) {
        cout << "[";
        for (int i = 0; i < rows; i++) {
            cout << hex << int(plain[i][j]) << "   ";
        }
        cout << "]";
        cout << endl;
    }

    // Example key (128 bits)
    vector<unsigned char> key;
     for (int i = 0; i < rows; i++) 
     {
        for (int j = 0; j < columns; j++) 
        {
            key.push_back(static_cast<unsigned char>(plain[i][j]));
        }
     }

    // Vector to store round keys
    vector<unsigned char> roundKeys;
    // Generate round keys
    keyExpansion(key, roundKeys);
    // Display the round keys
    for (int i = 0; i < num_rounds + 1; ++i) {
        cout << "Round Key " << i << ": ";
        for (int j = 0; j < 16; ++j) {
            cout << hex << setw(2) << setfill('0') << (int)roundKeys[i * 16 + j] << " ";
        }
        cout << endl;
    }
    return 0;
}
/*
No. of rows: 4
No. of columns: 4
Enter plain text:
VPKBIETBARAMATII
[V   I   A   A   ]
[P   E   R   T   ]
[K   T   A   I   ]
[B   B   M   I   ]
Ascii=
[86   73   65   65   ]
[80   69   82   84   ]
[75   84   65   73   ]
[66   66   77   73   ]
Hexadecimal=
[56   49   41   41   ]
[50   45   52   54   ]
[4b   54   41   49   ]
[42   42   4d   49   ]
Round Key 0: 56 50 4b 42 49 45 54 42 41 52 41 4d 41 54 49 49 
Round Key 1: 57 50 4b 42 1e 15 1f 00 5f 47 5e 4d 1e 13 17 04 
Round Key 2: 55 50 b9 42 4b 45 a6 42 14 02 f8 0f 0a 11 ef 0b 
Round Key 3: 51 50 92 25 1a 15 34 67 0e 17 cc 68 04 06 23 63 
Round Key 4: 36 50 92 d7 2c 45 a6 b0 22 52 6a d8 26 54 49 bb 
Round Key 5: 26 50 92 d7 0a 15 34 67 28 47 5e bf 0e 13 17 04 
Round Key 6: 06 50 60 7c 0c 45 54 1b 24 02 0a a4 2a 11 1d a0 
Round Key 7: 46 50 60 7c 4a 15 34 67 6e 17 3e c3 44 06 23 63 
Round Key 8: a9 50 60 7c e3 45 54 1b 8d 52 6a d8 c9 54 49 bb 
Round Key 9: b2 50 60 7c 51 15 34 67 dc 47 5e bf 15 13 17 04 
Round Key a: 84 50 92 7c d5 45 a6 1b 09 02 f8 a4 1c 11 ef a0 
*/