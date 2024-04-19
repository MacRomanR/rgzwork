#include "Decryption.h"

//Decryption with RSA cipher
void RSADecode()
{
	string publicExponStr = "";
	string privateExponStr = "";
	string modulStr = "";
	string inputString = "";

	ifstream fout1("keys.txt");
	getline(fout1, publicExponStr, ' ');
	getline(fout1, privateExponStr, ' ');
	getline(fout1, modulStr);
	fout1.close();

	ifstream fout("Some_text.txt");
	uint64_t publicExpon = 0;
	uint64_t privateExpon = 0;
	uint64_t modul = 0;
	for (int i = 0; publicExponStr[i] != '\0'; i++)
	{
		publicExpon = publicExpon * 10 + (publicExponStr[i] - 48);
	}
	for (int i = 0; privateExponStr[i] != '\0'; i++)
	{
		privateExpon = privateExpon * 10 + (privateExponStr[i] - 48);
	}
	for (int i = 0; modulStr[i] != '\0'; i++)
	{
		modul = modul * 10 + (modulStr[i] - 48);
	}

	ofstream fin("Str_aft_proc.txt");

	funkPrinciple(2);
	funkTypeName(1);
	cout << "Расшифрованная строка: " << endl;
	uint64_t buferInt = 0;
	while (!fout.eof())
	{
		getline(fout, inputString);
		for (uint64_t i = 0; inputString[i] != '\0'; i++)
		{
			buferInt = 0;
			for (; inputString[i] != 'O'; i++)
			{
				buferInt = buferInt * 10 + (inputString[i] - 48);
			}
			uint64_t smenaASKII = 1;
			for (uint64_t j = 0; j < privateExpon; j++)
			{
				smenaASKII = (smenaASKII * buferInt) % modul;
			}
			char ASKIICod = smenaASKII;
			fin << ASKIICod;
			cout << ASKIICod;
		}
		if (!fout.eof())
		{
			cout << '\n';
			fin << '\n';
		}
	}
	fout.close();
	fin.close();
	cout << endl << endl;
	system("PAUSE");
	system("CLS");
}

//Decryption with Atbash cipher
void AtbashDecode(int code) {
	string inputString = "";
	string outputString = "";
	bool isEnd = false;                                                   //cheсk-flag for continue

	ifstream fout1("Some_text.txt"); //читает файл с ключом и нашим текстом
	ofstream fin2("Str_aft_proc.txt");

	funkPrinciple(2);
	funkTypeName(2);
	cout << "Расшифрованная строка: " << endl;
	while (!fout1.eof()) {
		vector<char> seng = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
		vector<char> beng = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
		inputString = "";
		outputString = "";
		getline(fout1, inputString);
		char c;
		bool flag;
		for (int i = 0; inputString[i] != '\0'; i++) {
			flag = false;
			for (int j = 0; j < beng.size(); j++) {
				if (inputString[i] == beng[j]) {
					c = beng[25 - j];
					flag = true;
					outputString += c;
				}
				if (inputString[i] == seng[j]) {
					c = seng[25 - j];
					flag = true;
					outputString += c;
				}
			}
			if (flag == false) {
				outputString += inputString[i];
			}
		}
		fin2 << outputString;
		cout << outputString << endl;
		if (!fout1.eof())
		{
			fin2 << endl;
		}
	}
	fout1.close();
	fin2.close();
	cout << endl;
	system("PAUSE");
	system("CLS");
}

//Decryption with Binary cipher
void BinaryDecode()
{
	ifstream fout("Some_text.txt");
	ofstream fin("Str_aft_proc.txt");
	string inputString = "";
	string outputString = "";

	funkPrinciple(2);
	funkTypeName(3);

	cout << "Расшифрованная строка:" << endl;
	while (!fout.eof())
	{
		inputString = "";
		outputString = "";
		getline(fout, inputString);
		for (int i = 0; i < inputString.length(); i++)
		{
			string binCod = "";
			for (int j = i; inputString[j] != ' '; j++)
			{
				binCod += inputString[j];
				i = j;
			}
			i++;
			int decCod = 0;
			for (int j = 0; j < binCod.length(); j++)
			{
				if (binCod[j] == '1')
				{
					decCod += pow(2, (binCod.length() - 1) - j);
				}
			}
			char simb = (char)decCod;
			outputString += simb;
		}
		fin << outputString;											//output of encrypted string
		cout << outputString << endl;
		if (!fout.eof())
		{
			fin << endl;
		}
	}
	fout.close();
	fin.close();
	cout << endl;
#ifndef Clear
	system("PAUSE");
	system("CLS");
#endif
}

