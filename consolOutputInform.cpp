#include "consolOutputInform.h"

//The function of writing the encryption type
void funkTypeName(int cryptoType)
{
	switch (Ciphers(cryptoType))
	{
	case Ciphers::RSA:
		cout << "Шифр RSA" << endl;
		break;
	case Ciphers::Atbash:
		cout << "Шифр Атбаш" << endl;
		break;
	case Ciphers::Binary:
		cout << "Бинарный шифр" << endl;
		break;
	}
}

//The function of writing the principle of action
void funkPrinciple(int funkType)
{
	switch (Principle(funkType))
	{
	case Principle::Encription:
		cout << "Шифрование" << endl;
		break;
	case Principle::Decription:
		cout << "Расшифрование" << endl;
		break;
	}
}
