#include <iostream>
#include <string>
using namespace std;

string encrypt(const string &input, int key)
{
	string encrypted = input;
	for (size_t i = 0; i < encrypted.size(); ++i)
	{
		char &ch = encrypted[i];

		if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
		{
			char number;
			if (ch >= 'A' && ch <= 'Z')
			{
				number = 'A';
			}
			else
			{
				number = 'a';
			}

			ch = (ch - number + key) % 26 + number;
		}
		//(0-9) number check
		else if (ch >= '0' && ch <= '9')
		{
			ch = (ch - '0' + key) % 10 + '0';
		}
		//special characters check
		else
		{
			ch = (ch + key) % 128; 
		}
	}

	return encrypted;
}

string decrypt(const string &input, int key)
{
	string decrypted = input;
	for (size_t i = 0; i < decrypted.size(); ++i)
	{
		char &ch = decrypted[i];

		if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
		{
			char number;
			if (ch >= 'A' && ch <= 'Z')
			{
				number = 'A';
			}
			else
			{
				number = 'a';
			}
			ch = (ch - number - key + 26) % 26 + number;
		}
	
		else if (ch >= '0' && ch <= '9')
		{
			ch = (ch - '0' - key + 10) % 10 + '0';
		}
		
		else
		{
			ch = (ch - key + 128) % 128; 
		}
	}

	return decrypted;
}

int main()
{
	string input;
	int key;

	cout << "Enter the string to encrypt: ";
	getline(cin, input);

	cout << "Enter the encryption key (number): ";
	cin >> key;

	string encrypted_String = encrypt(input, key);
	cout << "Encrypted String: " << encrypted_String << endl;

	string decrypted_String = decrypt(encrypted_String, key);
	cout << "Decrypted String: " << decrypted_String << endl;

	return 0;
}