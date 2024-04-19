#include "RSAKeyGeneration.h"
#include "helpFunc.h"

//Key generation function for RSA encryption
void RSAKeyGeneration(int mayDecode)
{
	uint64_t first_prime = 0, señond_prime = 0, modul = 0, eiler = 0, publicExpon = 0, privateExpon = 0;
	string publicExponStr = "", privateExponStr = "", modulStr = "";
	int memoryBit = 0;
	if (mayDecode != 1)
	{
		randPrimeSearch(first_prime, señond_prime, memoryBit);

		modul = first_prime * señond_prime;
		eiler = (first_prime - 1) * (señond_prime - 1);
#ifdef DEBUGRSA
		cout << "First prime number: " << first_prime << endl << "Second prime number: " << señond_prime << endl;
		cout << "Module (p*q): " << modul << endl;
		cout << "Eiler funktion: " << eiler << endl;
#endif
		publicExpon = publicExponSearch(eiler, memoryBit);
		cout << "PUBLIC KEY: {" << publicExpon << "," << modul << "}" << endl;

		uint64_t k = 1;
		while ((privateExpon * publicExpon) % eiler != 1)
		{
			privateExpon = privateExponSearch(publicExpon, eiler, k);
		}
		cout << "PRIVATE KEY: {" << privateExpon << "," << modul << "}" << endl;
	}
	else if (mayDecode == 1)
	{
		bool isGood = false;
		do
		{
			publicExponStr = "", privateExponStr = "", modulStr = "";
			try
			{
				cout << "Enter public expon" << endl << ": ";
				getline(cin, publicExponStr);
				if (publicExponStr == "")
				{
					throw runtime_error("An empty string has been entered.\nTry again.\n");
				}
				if (!checkIfNotANumber(publicExponStr))
				{
					throw runtime_error("You entered \"" + publicExponStr + "\", when a number was expected.\nTry again.\n");
				}

				cout << "Enter private expon" << endl << ": ";
				getline(cin, privateExponStr);
				if (privateExponStr == "")
				{
					throw runtime_error("An empty string has been entered.\nTry again.\n");
				}
				if (!checkIfNotANumber(privateExponStr))
				{
					throw runtime_error("You entered \"" + privateExponStr + "\", when a number was expected.\nTry again.\n");
				}

				cout << "Enter module" << endl << ": ";
				getline(cin, modulStr);
				if (modulStr == "")
				{
					throw runtime_error("An empty string has been entered.\nTry again.\n");
				}
				if (!checkIfNotANumber(modulStr))
				{
					throw runtime_error("You entered \"" + modulStr + "\", when a number was expected.\nTry again.\n");
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
		cout << "PUBLIC KEY: {" << publicExponStr << "," << modulStr << "}" << endl;
		cout << "PRIVATE KEY: {" << privateExponStr << "," << modulStr << "}" << endl;
	}
	//[PUBLIC KEY: {publicExpon , modul}
	//[PRIVATE KEY: {privateExpon , modul}

	ofstream fin("keys.txt");	 //î÷èùàåò ôàéë Some_text.txt êóäà ñíà÷àëà çàïèñûâàåòñÿ êëþ÷, à çàòåì èñõîäíûé òåêñò
	if (mayDecode != 1)
	{
		fin << publicExpon << " " << privateExpon << " " << modul << endl;
	}
	else if (mayDecode == 1)
	{
		fin << publicExponStr << " " << privateExponStr << " " << modulStr << endl;
	}
	fin.close();

	cout << endl;
	system("PAUSE");
	system("CLS");
}

//Random prime number generation function (Erastophene sieve)
void randPrimeSearch(uint64_t& first_prime, uint64_t& second_prime, int& memoryBit)
{
	srand(time(0));
	bool isNumber = false;
	string memoryBitStr = "";
	do
	{
		try
		{
			cout << "Enter bit memory for prime numbers in range from 3 to 14 (recommended no more than 12(in 14 slow))" << endl << ": ";	//may 30 for prime but in encrypt don't work
			getline(cin, memoryBitStr);																										//max - 32
			if (memoryBitStr == "")
			{
				throw runtime_error("An empty string has been entered.\nTry again.\n");
			}
			isNumber = checkIfNotANumber(memoryBitStr);
			if (isNumber == false)
			{
				string err;
				err = "Invalid input.\nYou have entered \"" + memoryBitStr + "\", when a number between 3 and 14 was expected.\nTry again.\n";
				throw runtime_error(err);
			}
			for (int i = 0; memoryBitStr[i] != '\0'; i++)  //convert from string to uint64_t
			{
				char askii = '0';
				for (int j = 48; j < 58; j++)
				{
					askii = (char)j;
					if (memoryBitStr[i] == askii)
					{
						memoryBit = (memoryBit * 10) + ((int)memoryBitStr[i] - 48);
						break;
					}
				}
			}
			if (memoryBit < 3 || memoryBit > 14)
			{
				string err;
				err = "Invalid input.\nYou have entered \"" + to_string(memoryBit) + "\", when a number between 3 and 14 was expected.\nTry again.\n";
				throw runtime_error(err);
			}
		}
		catch (const exception& error)
		{
			memoryBit = 0;
			isNumber = false;
			system("CLS");
			cerr << error.what();
		}
	} while (isNumber == false);

	system("CLS");
	cout << "Wait, there are complex calculations going on..." << endl;

	uint64_t mayPrimeMin = stepen(2, memoryBit - 1) + 1;  //Calculating the maximum and minimum numbers in a given size value
	uint64_t mayPrimeMax = stepen(2, memoryBit);

	vector <int16_t> primeNumErast(mayPrimeMax, 0);
	vector <uint64_t> primeNum;

	for (uint64_t i = 2; i < mayPrimeMax; i++)
	{
		if (primeNumErast[i] == 0)
		{
			for (uint64_t j = i * i; ((i * i) < mayPrimeMax) && (j < mayPrimeMax); j = j + i)
			{
				primeNumErast[j] = 1;
			}
			if (i >= mayPrimeMin)
			{
				primeNum.push_back(i);
			}
		}
	}
	system("CLS");

	//Returning a random prime number from a range
	first_prime = primeNum[rand() % primeNum.size()];
	second_prime = primeNum[rand() % primeNum.size()];
	while (first_prime == second_prime)
	{
		second_prime = primeNum[rand() % primeNum.size()];
	}
}

//Public exponentiation calculation function
uint64_t publicExponSearch(uint64_t eiler, int memoryBit)
{
	uint64_t expon = 0;

	for (expon = (eiler / stepen(2, memoryBit + 5)) + 2; expon < eiler; expon++)
	{
		if (greatestCommonDivisor(expon, eiler) == 1)
		{
			return expon;
		}
	}
	return -1;
}

//Private exponentiation calculation function (privateExpon * publicExpon = 1 + k * eiler) => (privateExpon = (1 + k * eiler)/publicExpon) must be in integer!!!
uint64_t privateExponSearch(uint64_t publicExpon, uint64_t eiler, uint64_t& k)
{
	while (true)
	{
		k = k + eiler;   //k - is a number initially equal to 1, to which we add the Euler function, i.e. we add it (k) times until, when dividing by a public exponent, we get a division without remainder.
		if (k % publicExpon == 0)
		{
			return (k / publicExpon);
		}
	}
}
