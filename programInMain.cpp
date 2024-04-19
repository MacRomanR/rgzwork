#include "programInMain.h"
#include "Encryption.h"
#include "Decryption.h"

//Password verification function
void passwordCheck()
{
	string password = "";
	cout << "Enter password" << endl << ": ";
	getline(cin, password);
	while (password != PASSWORD)
	{
		system("CLS");
		cout << "Wrong password!" << endl << "Try again." << endl << ": ";
		getline(cin, password);
	}
	system("CLS");
	cout << "Authorization success!" << endl;;
	Sleep(500);
	system("CLS");
}

//Entering a string and saving it to a file or copying and encrypting your file
void inputStrToTxt()
{
	string fileCreate = "";
	bool isGood = false;
	do
	{
		try
		{
			cout << "Do you want to encrypt your file, create a new one, or take a random prepared one?" << endl << "<1>Your file" << endl << "<2>Create a new one" << endl << "<3>Take a random prepared one" << endl << ": ";
			getline(cin, fileCreate);
			if (fileCreate == "")
			{
				throw runtime_error("An empty string has been entered.\nTry again.\n");
			}
			if (fileCreate != "1" && fileCreate != "2" && fileCreate != "3")
			{
				string err;
				err = "Invalid input.\nYou have entered \"" + fileCreate + "\", when \"1\" or \"2\" or \"3\" was expected.\nTry again.\n";
				throw runtime_error(err);
			}
			isGood = true;
		}
		catch (const std::exception& error)
		{
			system("CLS");
			cerr << error.what();
		}
	} while (isGood == false);
	system("CLS");
	if (fileCreate == "1")
	{
		ofstream fin("Some_text.txt");
		ifstream fout;
		isGood = false;
		string path = "";
		do
		{
			cout << "Enter the path to the file (remember, the file must be ANSI or Windows-1251 encoded)" << endl << ": ";
			getline(cin, path);
			try
			{
				fout.open(path);
				if (!fout.is_open())
				{
					throw runtime_error("Unknown file path.\nTry again.\n");
				}
				string bufer = "";
				while (!fout.eof())
				{
					getline(fout, bufer);
					if (bufer == "")
					{
						throw runtime_error("The file is empty.\nTry again.\n");
					}
					for (int i = 0; i < bufer.length(); i++)
					{
						if ((int)bufer[i] < 32 || (int)bufer[i] > 126)
						{
							throw runtime_error("There are excluded characters in the text.\nLatin alphabet characters punctuation marks and special characters are expected.\nTry again.\n");
						}
					}
					fin << bufer;
					if (!fout.eof())
					{
						fin << endl;
					}
				}
				isGood = true;
			}
			catch (const exception& error)
			{
				system("CLS");
				cerr << error.what();
			}
		} while (isGood == false);
		fin.close();
		fout.close();
		system("CLS");
	}
	else if (fileCreate == "2")
	{
		isGood = false;
		string inputStr = "";
		do
		{
			cout << "Enter a line for encryption" << endl << ": ";
			try
			{
				getline(cin, inputStr);
				if (inputStr == "")
				{
					throw runtime_error("An empty text has been entered.\nTry again.\n");
				}
				for (int i = 0; i < inputStr.length(); i++)
				{
					if ((int)inputStr[i] < 32 || (int)inputStr[i] > 126)
					{
						throw runtime_error("There are excluded characters in the text.\nLatin alphabet characters punctuation marks and special characters are expected.\nTry again.\n");
					}
				}
				isGood = true;
			}
			catch (const exception& error)
			{
				system("CLS");
				cerr << error.what();
			}
		} while (isGood == false);
		ofstream fin("Some_text.txt");
		fin << inputStr;
		fin.close();
		system("CLS");
	}
	else if (fileCreate == "3")
	{
		srand(time(NULL));
		ifstream fin("RandStr.txt");
		string randStr;
		string fileContent;
		while (getline(fin, randStr))
		{
			fileContent += randStr + "\n";
		}
		fin.close();

		ofstream fout("Some_text.txt");
		fout << fileContent;
		fout.close();
	}
	system("notepad Some_text.txt");
}

//Choosing the principle of operation
int principleOfOperation()
{
	string strNumPrinciple = "";
	bool isGood = false;
	do
	{
		//Protection against incorrectly entered operating principle
		cout << "Choose the principle of operation: " << endl << "<1>Encryption" << endl << "<2>Decryption" << endl << ": ";
		try
		{
			getline(cin, strNumPrinciple);
			if (strNumPrinciple == "")
			{
				throw runtime_error("An empty string has been entered.\nTry again.\n");
			}
			if (strNumPrinciple != "1" && strNumPrinciple != "2")
			{
				string err;
				err = "Invalid input.\nYou have entered \"" + strNumPrinciple + "\", when \"1\" or \"2\" was expected.\nTry again.\n";
				throw runtime_error(err);
			}
			isGood = true;
		}
		catch (const exception& error)
		{
			system("CLS");
			cerr << error.what();
		}
	} while (isGood == false);

	int intNumPrinciple = strNumPrinciple[0] - 48;

	system("CLS");
	return intNumPrinciple;
}

//Encryption type select
int cryptoTypeSelect(int funkType)
{
	funkPrinciple(funkType);
	string strNumType = "";
	bool isGood = false;
	do
	{
		try //Protection against an incorrectly entered encryption type
		{
			cout << "Select the encryption/decryption type: " << endl << "<1>RSA Cipher" << endl << "<2>Atbash Cipher"
				<< endl << "<3>Binary Cipher"
				<< endl << ": ";
			getline(cin, strNumType);
			if (strNumType == "")
			{
				throw runtime_error("An empty string has been entered.\nTry again.\n");
			}
			if (strNumType != "1" && strNumType != "2" && strNumType != "3")
			{
				string err;
				err = "Invalid input.\nYou have entered \"" + strNumType + "\", when \"1\" or \"2\" or \"3\" was expected.\nTry again.\n";
				throw runtime_error(err);
			}
			isGood = true;
		}
		catch (const exception& error)
		{
			system("CLS");
			cerr << error.what();
		}
	} while (isGood == false);

	int intNumType = 0;
	for (int i = 0; strNumType[i] != '\0'; i++)
	{
		intNumType = (intNumType * 10) + (strNumType[i] - 48);
	}

	system("CLS");
	return intNumType;
}

//Conditions for performing encryption for the selected type and principle of operation
void encryptionStart(int cryptoType, int funkType)
{
	switch (Ciphers(cryptoType))
	{
	case Ciphers::RSA:
		switch (Principle(funkType))
		{
		case Principle::Encription:
			RSAKeyGeneration(0);
			RSACode();
			break;
		case Principle::Decription:
			RSAKeyGeneration(1);
			RSADecode();
			break;
		}
		break;
	case Ciphers::Atbash:
		switch (Principle(funkType))
		{
		case Principle::Encription:
			AtbashCode(0);
			break;
		case Principle::Decription:
			AtbashDecode(0);
			break;
		}
		break;
	case Ciphers::Binary:
		switch (Principle(funkType))
		{
		case Principle::Encription:
			BinaryCode();
			break;
		case Principle::Decription:
			BinaryDecode();
			break;
		}
		break;
	}
	system("notepad Str_aft_proc.txt");
}

//The function of starting the encryption check
void encryptionCheck(int cryptoType, int funkType)
{
	string codeCheck = "";
	bool isGood = false;
	do
	{
		try
		{
			cout << "Do you want to check the encryption?" << endl << "<1>Yes" << endl << "<2>No" << endl << ":";
			getline(cin, codeCheck);
			if (codeCheck == "")
			{
				throw runtime_error("An empty string has been entered.\nTry again.\n");
			}
			if (codeCheck != "1" && codeCheck != "2")
			{
				string err;
				err = "Invalid input.\nYou have entered \"" + codeCheck + "\", when \"1\" or \"2\" was expected.\nTry again.\n";
				throw runtime_error(err);
			}
			isGood = true;
		}
		catch (const exception& error)
		{
			system("CLS");
			cerr << error.what();
		}
	} while (isGood == false);
	system("CLS");
	if (codeCheck == "1")
	{
		string bufer = "";
		ofstream fin("Some_text.txt");   //if - ÷òåíèå, of - çàïèñü
		ifstream fout("Str_aft_proc.txt");
		while (!fout.eof())
		{
			getline(fout, bufer);
			fin << bufer;
			if (!fout.eof())
			{
				fin << '\n';
			}
		}
		fin.close();
		fout.close();

		passwordCheck();
		//Conditions for performing encryption for the selected type and principle of operation
		switch (Ciphers(cryptoType))
		{
		case Ciphers::RSA:
			switch (Principle(funkType))
			{
			case Principle::Encription:
				RSADecode();
				break;
			case Principle::Decription:
				RSACode();
				break;
			}
			break;
		case Ciphers::Atbash:
			switch (Principle(funkType))
			{
			case Principle::Encription:
				AtbashDecode(1);
				break;
			case Principle::Decription:
				AtbashCode(1);
				break;
			}
			break;
		case Ciphers::Binary:
			switch (Principle(funkType))
			{
			case Principle::Encription:
				BinaryDecode();
				break;
			case Principle::Decription:
				BinaryCode();
				break;
			}
			break;
		}
	}
	system("notepad Str_aft_proc.txt");
	system("CLS");
}
