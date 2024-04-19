#pragma once
#include <iostream>
#include <cstdint>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

void RSAKeyGeneration(int);										//Key generation function for RSA encryption
void randPrimeSearch(uint64_t&, uint64_t&, int&);				//Random prime number generation function (Erastophene sieve)
uint64_t publicExponSearch(uint64_t, int);						//Public exponentiation calculation function
uint64_t privateExponSearch(uint64_t, uint64_t, uint64_t&);		//Private exponentiation calculation function (privateExpon * publicExpon = 1 + k * eiler) => (privateExpon = (1 + k * eiler)/publicExpon) must be in integer!!!
