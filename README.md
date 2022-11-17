# EncryptionDecryption


# INTRODUCTION


Problem Statement : Sometimes, our program or the information passes through a group of people but we don’t want to make our confidential message (or something like password or code) visible to everyone. The challenge is to hide the message in the form of code i.e. to convert the message in a password language that can be opened by one who has the access to it, no one else or vice versa.

Encryption: Encryption is a process by which a plain text or a piece of information is converted into a text which can only be decoded by the receiver for whom the information was intended? The algorithm that is used for the process of encryption is known as a cipher. It helps protect consumer information, emails, and other sensitive data from unauthorized access to it and secures communication networks. Presently there are many options to choose from and find the most secure algorithm which meets our requirements.

Decryption: Decryption is the process of converting a meaningless message into its original form (Plaintext). It works by applying the conversion algorithm opposite of the one that is used to encrypt the data. The same key is required to decrypt the information back to its normal form.

# Caesar Cipher Cryptography :

The Caesar Cipher technique is one of the earliest and simplest methods of encryption technique. It’s simply a type of substitution cipher, i.e., each letter of a given text is replaced by a letter with a fixed number of positions down the alphabet. For example with a shift of 1, A would be replaced by B, B would become C, and so on

# Rail Fence Cipher: 

Encryption: 
In the rail fence cipher, the plain-text is written downwards and diagonally on successive rails of an imaginary fence. When we reach the bottom rail, we traverse upwards moving diagonally, after reaching the top rail, the direction is changed again. Thus the alphabets of the message are written in a zig-zag manner. After each alphabet has been written, the individual rows are combined to obtain the cipher-text.

Decryption:
The number of columns in the rail fence cipher remains equal to the length of the plain-text message. And the key corresponds to the number of rails. Hence, the rail matrix can be constructed accordingly. Once we’ve got the matrix we can figure-out the spots where texts should be placed (using the same way of moving diagonally up and down alternatively ). Then, we fill the cipher-text row wise. After filling it, we traverse the matrix in a zig-zag manner to obtain the original text.


# Vigenere Cipher :

Encryption:
The first letter of the plaintext, G is paired with A, the first letter of the key. So use row G and column A of the Vigenère square, namely G. Similarly, for the second letter of the plaintext, the second letter of the key is used, the letter at row E, and column Y is C. The rest of the plaintext is enciphered in a similar fashion. 
Decryption:
Decryption is performed by going to the row in the table corresponding to the key, finding the position of the ciphertext letter in this row, and then using the column’s label as the plaintext. For example, in row A (from AYUSH), the ciphertext G appears in column G, which is the first plaintext letter. Next, we go to row Y (from AYUSH), locate the ciphertext C which is found in column E, thus E is the second plaintext letter.
 
    
 
# OBJECTIVE

The main objective of this project is to hide confidential information from    unnecessary people. The information will be passed in the form of code that needs to be decoded for fetching the data. Also this project can
also be used by the fetchers who want to access the details by decoding the code.
Features:-
The problem will be solved using the concept of file handling and data structures like linked list and stack. We have also use cipher technique called Rail Fence Cipher.

Why is linked list and stack the best data structure for the implementation of this concept?

Linked list will be used to uniquely store the key value for each pointer along with the first in last out operation using the properties of stack. The combination of both these data structures will be most suited as it takes less time and space complexity as well in terms of the non-linear data structure like trees.

What are the basic functions that will be used?

message_decrypt() function is used to read the encrypted file and decrypt the data and generate a new file decrypt.txt. To decrypt a file, a key is requested from the user. If the correct key is entered, then the file is successfully decrypted.

message_encrypt() function is used to handle the encryption of the input                 file. The file handling code is included in the encrypt() function to read the file and write to the file. A new encrypted file called encrypt.txt is generated with all the encrypted data in it. The encrypted file is encrypted using a key that is being inputted by the user.

# CONCLUSION

As we move toward a society where automated information resources are increased,cryptography will continue to increase in importance as a security mechanism.
Electronic networks for banking, shopping, inventory control, benefit and   service delivery, information storage and retrieval, distributed processing, and government applications will need improved methods for access control and data security. Information security can be easily achieved by using Cryptography (encryption and decryption) techniques.


