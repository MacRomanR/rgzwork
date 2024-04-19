#include "consolOutputInform.h"

//The function of writing the encryption type
void funkTypeName(int cryptoType)
{
	switch (Ciphers(cryptoType))
	{
	case Ciphers::RSA:
		cout << "RSA Cipher" << endl;
		break;
	case Ciphers::Atbash:
		cout << "Atbash Cipher" << endl;
		break;
	case Ciphers::Binary:
		cout << "Binary Cipher" << endl;
		break;
	}
}

//The function of writing the principle of action
void funkPrinciple(int funkType)
{
	switch (Principle(funkType))
	{
	case Principle::Encription:
		cout << "Encryption" << endl;
		break;
	case Principle::Decription:
		cout << "Decryption" << endl;
		break;
	}
}
