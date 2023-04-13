#ifndef RSAClass_H
#define RSAClass_H

#include "InfInt.h"
#include <string>
struct PrimePair {
	InfInt p;
	InfInt q;
};
struct KeyPair {
	InfInt publicKey[2];
	InfInt privateKey[2];
};

class RSAClass {
private:
	InfInt GCD(InfInt firstNumber, InfInt secondNumber);
	InfInt fastModularExponentiation(InfInt base, InfInt exponent, InfInt modulus);
	InfInt inverseMod(InfInt a, InfInt m);
public:
	RSAClass();
	bool isPrime(InfInt num);
	std::string encrypt(std::string message, InfInt key[]);
	std::string decrypt(std::string encrypted, InfInt key[]);
	KeyPair generateKeys(PrimePair pair);
	
};
#endif