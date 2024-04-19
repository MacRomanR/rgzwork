#include "consolOutputInform.h"

//The function of writing the encryption type
void funkTypeName(int cryptoType)
{
	switch (Ciphers(cryptoType))
	{
	case Ciphers::RSA:
		cout << "���� RSA" << endl;
		break;
	case Ciphers::Atbash:
		cout << "���� �����" << endl;
		break;
	case Ciphers::Binary:
		cout << "�������� ����" << endl;
		break;
	}
}

//The function of writing the principle of action
void funkPrinciple(int funkType)
{
	switch (Principle(funkType))
	{
	case Principle::Encription:
		cout << "����������" << endl;
		break;
	case Principle::Decription:
		cout << "�������������" << endl;
		break;
	}
}
