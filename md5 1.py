def prepare_md5_block(message):
    # Convert the plain text message into bits
    message_bits = ''.join(format(ord(char), '08b') for char in message) 
    
    # Print message length
    print("Message length:", len(message))
    
    
    # Append the bit '1' to the message
    message_bits += '1'  
    
    #Calculate the number of bits appended
    bits_appended = 1
    
    # Pad with '0' bits until the length is 448 mod 512
    padding_length = (448 - len(message_bits) % 512) % 512
    message_bits += '0' * padding_length  
    
    # Print number of padding bits
    print("Number of padding bits:", padding_length)
    
    # Calculate the number of padding bits 
    
    padding_bits = padding_length
    
    # Append the original message length in bits (64-bit big-endian integer)
    original_length = len(message) * 8
    message_bits += format(original_length,'064b') 
    
    # Print number of bits appended
    bits_appended += 64
    print("Number of bits appended:", bits_appended)
    # Calculate the number of blocks
    num_blocks = len(message_bits) // 512
    print("Number of blocks:", num_blocks)
    
    return message_bits

def get_md5_hash(message):
    
    padded_message = prepare_md5_block(message)
    # Update the hash object with the padded message
   
    # Print MD5 block
    print("\nMD5 block:")
    print(padded_message)
    

# Input
message = "VPKBIET_BARAMATI_PUNE_MAHARASHTRA"

# Get MD5 hash
get_md5_hash(message)