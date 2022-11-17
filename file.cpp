#include <bits/stdc++.h>
using namespace std;

struct node // creating node
{
	char data;
	node *next;
};
string getcurrenttime() {
	time_t curr_time;
	tm *curr_tm;
	char currenttime[100];
	time(&curr_time);
	curr_tm = localtime(&curr_time);
	strftime(currenttime, 100, "<%Y-%m-%d , %T>: ", curr_tm);
	return currenttime;
}
void log(string input) {
	fstream logfile;
	logfile.open("log.txt", ios::in | ios::out);
	logfile.seekg(0, ios::end);
	logfile << input;
	logfile.close();
}
node *linking(node *main, int data) // creating a linked list
{
	node *temp = new node;
	temp->data = data;
	temp->next = NULL;
	if (main == NULL) {
		main = temp;
	} else {
		node *temp1 = main;
		while (temp1->next != NULL) {
			temp1 = temp1->next;
		}
		temp1->next = temp;
	}
	return main;
}
void encrypt_caesar_cipher(node *main, int key) // encrypting using file handling and key
{
	cout << "File has been Encrypted!" << endl;
	fstream fin, fout;
	fout.open("encrypt.txt", fstream::out); // opening empty encrypted file
	char dec;
	while (main != NULL) // encrypting the data of the linked list
	{
		node *temp = main;
		dec = temp->data + key;
		main = main->next;
		fout << dec; // storing the encrypted word in encrypt.txt
	}
	fout.close(); // closing the file
	cout << endl;
	string logtext =
		getcurrenttime() + "File successfully Encrypted Free." + "\n";
	log(logtext);
}
void decrypt_caesar_cipher(node *main, int key) {
	cout << "File has been Decrypted!" << endl;
	node *declist = NULL;
	string line;
	ifstream fin;
	fstream fout;
	fin.open("encrypt.txt", ios::in | ios::out);
	fout.open("decrypt.txt", fstream::out);
	while (fin.good()) // reding the encrypt.txt file
	{
		getline(fin, line, '\n');
		for (int i = 0; i < line.length(); i++) {
			declist = linking(
				declist,
				line[i]); // storing the encrypted text in a linked list
		}
	}
	while (declist != NULL) {
		char enc;
		enc = declist->data - key;
		declist = declist->next;
		if (enc == '$') {
			fout << (char)10;
		} else {
			fout << enc;
		}
	}
	fout.close();
	cout << endl;
	string logtext =
		getcurrenttime() + "File successfully Decrypted Free." + "\n";
	log(logtext);
}
void encrypt_made(node *main) {
	cout << "File has been Encrypted!" << endl;
	fstream fin, fout;
	fout.open("encrypt.txt", fstream::out); // opening empty encrypted file
	char dec;
	while (main != NULL) // encrypting the data of the linked list
	{
		node *temp = main;
		if ((122 >= temp->data && temp->data >= 97) || temp->data == 32 ||
			temp->data == 36) {
			if (temp->data == 'a' || temp->data == 'e' || temp->data == 'i' ||
				temp->data == 'o' || temp->data == 'u' || temp->data == ' ' ||
				temp->data == '$') {
				if (temp->data == 'a') {
					dec = '@';
				} else if (temp->data == 'e') {
					dec = '#';
				} else if (temp->data == 'i') {
					dec = '/';
				} else if (temp->data == 'o') {
					dec = '?';
				} else if (temp->data == 'u') {
					dec = '>';
				} else if (temp->data == ' ') {
					dec = '_';
				} else if (temp->data == '$') {
					dec = '*';
				}
			} else {
				dec = temp->data + 2;
				if (dec > 122)
				{
					dec = dec - 26;
				}
			}
		} else if (90 >= temp->data && temp->data >= 65) {
			if (temp->data == 'A' || temp->data == 'E' || temp->data == 'I' ||
				temp->data == 'O' || temp->data == 'U') {
				if (temp->data == 'A') {
					dec = '!';
				} else if (temp->data == 'E') {
					dec = '%';
				} else if (temp->data == 'I') {
					dec = '&';
				} else if (temp->data == 'O') {
					dec = '+';
				} else if (temp->data == 'U') {
					dec = '-';
				}
			} else {
				dec = temp->data + 2;
				if (dec > 90) {
					dec = dec - 26;
				}
			}
		} else if (temp->data >= 48 && temp->data <= 57) {
			if (temp->data >= 54) {
				dec = (temp->data + 4) - 10;
			} else {
				dec = temp->data + 4;
			}
		}
		main = main->next;
		fout << dec; // storing the encrypted word in encrypt.txt
	}
	fout.close(); // closing the file
	cout << endl;
	string logtext =
		getcurrenttime() + "File successfully Encrypted Paid." + "\n";
	log(logtext);
}
void decrypt_made() {
	cout << "File has been Decrypted!" << endl;
	node *declist = NULL;
	string line;
	ifstream fin;
	fstream fout;
	fin.open("encrypt.txt", ios::in | ios::out);
	fout.open("decrypt.txt", fstream::out);
	while (fin.good()) // reding the encrypt.txt file
	{
		getline(fin, line, '\n');
		for (int i = 0; i < line.length(); i++) {
			declist = linking(
				declist,
				line[i]); // storing the encrypted text in a linked list
		}
	}
	while (declist != NULL) {
		char enc;
		if (declist->data == '*') {
			enc = 10;
		} else if (
			(122 >= declist->data && declist->data >= 97) ||
			declist->data == 95 || declist->data == 42 || declist->data == 64 ||
			declist->data == 35 || declist->data == 47 || declist->data == 63 ||
			declist->data == 62) {
			if (declist->data == '@' || declist->data == '#' ||
				declist->data == '/' || declist->data == '?' ||
				declist->data == '>' || declist->data == '_' ||
				declist->data == '*') {
				if (declist->data == '@') {
					enc = 'a';
				} else if (declist->data == '#') {
					enc = 'e';
				} else if (declist->data == '/') {
					enc = 'i';
				} else if (declist->data == '?') {
					enc = 'o';
				} else if (declist->data == '>') {
					enc = 'u';
				} else if (declist->data == '_') {
					enc = ' ';
				}
			} else {
				enc = declist->data - 2;
				if (enc < 97) {
					enc = enc + 26;
				}
			}
		} else if (
			(90 >= declist->data && declist->data >= 65) ||
			declist->data == 33 || declist->data == 37 || declist->data == 38 ||
			declist->data == 43 || declist->data == 45) {
			if (declist->data == '!' || declist->data == '%' ||
				declist->data == '&' || declist->data == '+' ||
				declist->data == '-') {
				if (declist->data == '!') {
					enc = 'A';
				} else if (declist->data == '%') {
					enc = 'E';
				} else if (declist->data == '&') {
					enc = 'I';
				} else if (declist->data == '+') {
					enc = 'O';
				} else if (declist->data == '-') {
					enc = 'U';
				}
			} else {
				enc = declist->data - 2;
				if (enc < 65) {
					enc = enc + 26;
				}
			}
		} else if (declist->data >= 48 && declist->data <= 57) {
			if (declist->data <= 51) {
				enc = (declist->data - 4) + 10;
			} else {
				enc = declist->data - 4;
			}
		}
		declist = declist->next;
		fout << enc;
	}
	fout.close();
	cout << endl;
	string logtext =
		getcurrenttime() + "File successfully Decrypted Paid." + "\n";
	log(logtext);
}

// ENCRYPTION
void encryptRailFence(int key) {
  	cout << "File has been Encrypted!" << endl;
    string text;
    ifstream t("sample.txt");
    stringstream buffer;
    buffer << t.rdbuf();
    text=buffer.str();

    char rail[key][(text.length())];

    for (int i=0; i < key; i++)
        for (int j = 0; j < text.length(); j++)
            rail[i][j] = '\n';

    bool dir_down = false;
    int row = 0, col = 0;

    for (int i=0; i < text.length(); i++) {
        if (row == 0 || row == key-1)
            dir_down = !dir_down;
        rail[row][col++] = text[i];
        dir_down ? row++ : row--;
    }

    string result;
    for (int i=0; i < key; i++)
        for (int j=0; j < text.length(); j++)
            if (rail[i][j]!='\n')
                result.push_back(rail[i][j]);
    

    ofstream out("encrypt.txt");
    out << result;
    out.close();

    string logtext =
		getcurrenttime() + "File successfully Encrypted using Rail Fence." + "\n";
	log(logtext);
}

// DECRYPTION
void decryptRailFence(int key) {
  	cout << "File has been Decrypted!" << endl;
    string cipher;
    ifstream t("encrypt.txt");
    stringstream buffer;
    buffer << t.rdbuf();
    cipher=buffer.str();

    char rail[key][cipher.length()];

    for (int i=0; i < key; i++)
        for (int j=0; j < cipher.length(); j++)
            rail[i][j] = '\n';

    bool dir_down;
    int row = 0, col = 0;
    for (int i=0; i < cipher.length(); i++) {
        if (row == 0)
            dir_down = true;
        if (row == key-1)
            dir_down = false;

        rail[row][col++] = '*';

        dir_down ? row++ : row--;
    }

    int index = 0;
    for (int i=0; i<key; i++)
        for (int j=0; j<cipher.length(); j++)
            if (rail[i][j] == '*' && index<cipher.length())
                rail[i][j] = cipher[index++];

    string result;
    row = 0, col = 0;
    for (int i=0; i< cipher.length(); i++) {
        if (row == 0)
            dir_down = true;
        if (row == key-1)
            dir_down = false;

        if (rail[row][col] != '*')
            result.push_back(rail[row][col++]);

        dir_down?row++: row--;
    }

    ofstream out("decrypt.txt");
    out << result;
    out.close();

    string logtext =
		getcurrenttime() + "File successfully Decrypted Rail Fence Encryption." + "\n";
	log(logtext);
}

string VigeneregenerateKey(string key) {
    string str;
    ifstream t("sample.txt");
    stringstream buffer;
    buffer << t.rdbuf();
    str=buffer.str();

    int x = str.size();
 
    for (int i = 0; ; i++) {
        if (x == i)
            i = 0;
        if (key.size() == str.size())
            break;
        key.push_back(key[i]);
    }
    return key;
}

void VigenerecipherText(string key) {
  	cout << "File has been Encrypted!" << endl;
    string str;
    ifstream t("sample.txt");
    stringstream buffer;
    buffer << t.rdbuf();
    str=buffer.str();

    string cipher_text;
 
    for (int i = 0; i < str.size(); i++) {
        char x = (str[i] + key[i]) %26;
        x += 'A';
 
        cipher_text.push_back(x);
    }
    
    ofstream out("encrypt.txt");
    out << cipher_text;
    out.close();

    string logtext =
		getcurrenttime() + "File successfully Encrypted using Vigenere Cipher." + "\n";
	log(logtext);
}

void VigenereoriginalText(string key) {
  	cout << "File has been Decrypted!" << endl;
    string cipher_text;
    ifstream t("encrypt.txt");
    stringstream buffer;
    buffer << t.rdbuf();
    cipher_text=buffer.str();

    string orig_text;
 
    for (int i = 0 ; i < cipher_text.size(); i++) {
        char x = (cipher_text[i] - key[i] + 26) %26;
        x += 'A';
        orig_text.push_back(x);
    }
    
    ofstream out("decrypt.txt");
    out << orig_text;
    out.close();

    string logtext =
		getcurrenttime() + "File successfully Decrypted Vigenere Encryption." + "\n";
	log(logtext);
}

int main() {
	string logtext = getcurrenttime() + "Program Started." + "\n";
	log(logtext);
	cout << "Enter your text in the Sample text file given" << endl
		 << endl
		 << endl;
	int choice, key;
	node *main = NULL;
	string line;
	ifstream fin;
	fin.open("sample.txt", ios::in | ios::out);
	while (fin.good()) {
		getline(fin, line, '\n');
		main = linking(main, '$');
		for (int i = 0; i < line.length(); i++) {
			main = linking(
				main,
				line[i]); // storing the text from sample.txt to a linked list
		}
	}
	fin.close();
	do // using do while because we have to execute the statement atleast once
	{
		cout << "TYPES OF ENCRYPTIONS\n1.Caesar Cipher Encrypt\n2.Caesar Cipher Decrypt\n3.Selfmade Encryption\n4.Selfmade Decryption\n5.Rail Fence Encryption\n6.Rail Fence Decryption\n7.Vigenere Encryption\n8.Vigenere Decryption\n0.Exit\n\n";
		
        cout << "Enter your choice: ";
        cin >> choice; // Input choice from user
		cout << endl;
		switch (choice) {
            case 1: {
                cout << "Enter your Unique Key between 1 to 9" << endl;
                cin >> key;
                encrypt_caesar_cipher(main, key);
                cout << endl;
                break;
            }
            case 2: {
                cout << "Enter your Unique Key between 1 to 9" << endl;
                cin >> key;
                decrypt_caesar_cipher(main, key);
                cout << endl;
                break;
            }
            case 3: {
                cout << "Enter Key" << endl;
                cin >> key;
                if (key == 3456) // If the key inputted from the user matches then
                                // call the function
                {
                    encrypt_made(main);
                    cout << endl;
                } else
                    cout << "Please enter a valid PIN" << endl;
                break;
            }
            case 4: {
                cout << "Enter Key" << endl;
                cin >> key;
                if (key == 3456) // If the key inputted from the user matches then
                                // call the function
                {
                    // encrypt_made(main);
                    decrypt_made();
                    cout << endl;
                } else
                    cout << "Please enter a valid PIN" << endl;
                break;
            }
            case 5: {
                cout << "Enter key" << endl;
                cin >> key;
                
                encryptRailFence(key);
                break;
            }
            case 6: {
                cout << "Enter key" << endl;
                cin >> key;
                
                decryptRailFence(key);
                break;
            }
            case 7: {
                string key; //VIG
                cout << "Enter key (string): ";
                cin >> key;
                key = VigeneregenerateKey(key);
                VigenerecipherText(key);
                break;
            }
            case 8: {
                string key;//VIG
                cout << "Enter same key (string): ";
                cin >> key;
                key = VigeneregenerateKey(key);
                VigenereoriginalText(key);
                break;
            }
            default: {
                choice = 0;
                string logtext =
                    getcurrenttime() + "Program successfully Ended." + "\n";
                log(logtext);
                break;
            }
		}
	} while (choice != 0);
	return 0;
}