#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>

using namespace std;

void RSACode();									//Encryption with RSA cipher

void AtbashCode(int);							//Encryption with Atbash cipher

void BinaryCode();								//Encryption with Binary cipher

bool checkIfNotANumber(string);					//The function of checking whether the entered string is a number

void funkTypeName(int);							//The function of writing the principle of action (print in consol what type of encryption your choose)
void funkPrinciple(int);						//The function of writing the encryption type (print in consol what your do(encryption or decription))
