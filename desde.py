ip = [2,6,3,1,4,8,5,7]
ip1 = [4,1,3,5,7,2,8,6]

s0 = [
    [1,0,3,2],
    [3,2,1,0],
    [0,2,1,3],
    [3,1,3,2]
]

s1 = [
    [0,1,2,3],
    [2,0,1,3],
    [3,0,1,0],
    [2,1,0,3]
]

EP = [4,1,2,3,2,3,4,1]
p4 = [2,4,3,1]

def permutatioins(key,permutation):
    temp = ''
    for i in range(len(permutation)):
        temp = temp+key[permutation[i]-1]
    return temp

def xor(first,second):
    n = len(first)
    temp =''
    for i in range(n):
        temp = temp + str(int(first[i]) ^ int(second[i]))
    return temp
        
def Decrypt(leftPart,rightPart,key):
    
    epRight1 = permutatioins(rightPart,EP) 
    xorEpRightKey = xor(epRight1,key)
    
    left = xorEpRightKey[:4]
    right = xorEpRightKey[4:]
    
    leftRow = left[0] + left[3]
    leftRow = int(leftRow,2)
    
    leftCol = left[1:3]
    leftCol = int(leftCol,2)
    
    rightRow = right[0]+ right[3]
    rightRow = int(rightRow,2)

    rightCol =right[1:3]
    rightCol = int(rightCol,2)
    
    s01 = format(s0[leftRow][leftCol],'02b')
    s11 = format(s1[rightRow][rightCol],'02b')
 
    combine = s01 + s11
    combineP4 = permutatioins(combine,p4)
    combineP4Xor = xor(leftPart,combineP4)
    encr1 = combineP4Xor + rightPart
    return encr1
        
def Decryption(plain,key1,key2):
    plainText = plain
    initPerPT = permutatioins(plainText,ip)

    leftPart = initPerPT[:int(len(initPerPT)/2)]
    rightPart = initPerPT[int(len(initPerPT)/2):]

    decr1=Decrypt(leftPart,rightPart,key2)
    print("decr1 = ",decr1)
    leftPart = decr1[4:]
    rightPart = decr1[:4]
    decr2=Decrypt(leftPart,rightPart,key1)
    print("decr2 = ",decr2)
    cipherText = permutatioins(decr2,ip1)
    print("Cipher Text = ",cipherText)
    
def main():
    CipherText = '10001010'
    key1 = '11101001'
    key2 = '10100111'
    Decryption(CipherText,key1,key2)

if __name__ == "__main__":
    main()
    