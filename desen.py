def permute(original, permutation):
    permuted = ''
    for index in permutation:
        permuted += original[index - 1]
    return permuted

def xor(bin1, bin2):
    result = ''
    for i in range(len(bin1)):
        result += str(int(bin1[i]) ^ int(bin2[i]))
    return result

def split_half(bits):
    return bits[:4], bits[4:]

def sbox_lookup(bits, sbox):
    row = int(bits[0] + bits[3], 2)
    col = int(bits[1:3], 2)
    return format(sbox[row][col], '02b')

def f_function(bits, key):
    expansion_permutation = [4, 1, 2, 3, 2, 3, 4, 1]
    sbox1 = [
        [1, 0, 3, 2],
        [3, 2, 1, 0],
        [0, 2, 1, 3],
        [3, 1, 3, 2]
    ]
    sbox2 = [
        [0, 1, 2, 3],
        [2, 0, 1, 3],
        [3, 0, 1, 0],
        [2, 1, 0, 3]
    ]
    
    expanded = permute(bits, expansion_permutation)
    xor_result = xor(expanded, key)
    
    left, right = split_half(xor_result)
    sbox_output1 = sbox_lookup(left, sbox1)
    sbox_output2 = sbox_lookup(right, sbox2)
    
    return permute(sbox_output1 + sbox_output2, [2, 4, 3, 1])

def encrypt(plaintext, k1, k2):
    initial_permutation = [2, 6, 3, 1, 4, 8, 5, 7]
    final_permutation = [4, 1, 3, 5, 7, 2, 8, 6]
    
    permuted_plaintext = permute(plaintext, initial_permutation)
    
    fk1 = f_function(permuted_plaintext[4:], k1)
    xor_result = xor(permuted_plaintext[:4], fk1)
    swapped = permuted_plaintext[4:] + xor_result
    
    fk2 = f_function(swapped[4:], k2)
    fk2_xor = xor(swapped[:4], fk2)
    
    ciphertext = permute(fk2_xor + fk2, final_permutation)
    
    return ciphertext

def main():
    plaintext = "00101000"
    k1 = "11101001"
    k2 = "10100111"

    ciphertext = encrypt(plaintext, k1, k2)
    print("Cipher Text:", ciphertext)

if __name__ == "__main__":
    main()