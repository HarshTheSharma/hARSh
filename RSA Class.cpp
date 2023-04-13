#include "RSA Class.h"
#include <cmath>
#include <string>
#include <iostream>
#include "InfInt.h"
#include <cstdlib>
#include <time.h>

//Private
InfInt RSAClass::GCD(InfInt firstNumber, InfInt secondNumber) {
	if (firstNumber == 0)
		return secondNumber;

	if (secondNumber == 0)
		return firstNumber;

	// Make sure firstNumber is the larger of the two numbers
	if (firstNumber < secondNumber) {
		InfInt temp = firstNumber;
		firstNumber = secondNumber;
		secondNumber = temp;
	}


	// Use Euclidean algorithm to find gcd
	InfInt remainder = firstNumber % secondNumber;

	while (remainder != 0) {
		firstNumber = secondNumber;
		secondNumber = remainder;
		remainder = firstNumber % secondNumber;

		// If remainder is zero, return the current value of secondNumber
		if (remainder == 0)
			return secondNumber;
	}

	return secondNumber;
}


InfInt RSAClass::inverseMod(InfInt a, InfInt m)
{
	InfInt m0 = m, t, q;
	InfInt x0 = 0, x1 = 1;

	if (m == 1)
		return 0;
	while (a > 1) {
		if (m == 0) return -1;
		q = a / m;

		t = m;

		m = a % m, a = t;

		t = x0;

		x0 = x1 - q * x0;

		x1 = t;
	}
	if (x1 < 0)
		x1 += m0;

	return x1;
}



InfInt RSAClass::fastModularExponentiation(InfInt base, InfInt exponent, InfInt modulus) { //rewrite this
	InfInt result = 1;
	base = base % modulus;
	while (exponent > 0) {
		if (exponent % 2 == 1) {
			result = (result * base) % modulus;
		}
		exponent /= 2;
		base = (base * base) % modulus;
	}
	return result;
}


bool RSAClass::isPrime(InfInt num) {
	InfInt sqrtIndex = num.intSqrt(); //Short circuit to only sqrt of num
	if (num < 2) return false;  //Check simple solutionCheck for 1 and negative

	for (InfInt index = 2; index <= sqrtIndex; index++)
		if (num % index == 0)
			return false;
	return true;
}


//Public
RSAClass::RSAClass() {

}

std::string RSAClass::encrypt(std::string message, InfInt key[]) {
	//Add filler
	InfInt n = key[0];
	InfInt e = key[1];
	while (0 != message.length() % 2) message.append(" ");
	InfInt length = message.length();
	//Translate all letters in the message to a two digit number | A-Z = 10-36 | SPACE = 36
	for (InfInt i = 0; i < message.length(); i++) { //convert all letters to lowercase
		message[i.toInt()] = tolower(message[i.toInt()]);
	}
	std::string translated;
	for (InfInt i = 0; i < length; i++) { //Translate all letters to numeric values
		if (message[i.toInt()] == ' ') translated.append("36");
		else if (message[i.toInt()] == '.') translated.append("37");
		else if (message[i.toInt()] == '!') translated.append("38");
		else if (message[i.toInt()] == '?') translated.append("39");
		else if (message[i.toInt()] == '\'') translated.append("40");
		else if (message[i.toInt()] == '"') translated.append("41");
		else if (message[i.toInt()] == '1') translated.append("42");
		else if (message[i.toInt()] == '2') translated.append("43");
		else if (message[i.toInt()] == '3') translated.append("44");
		else if (message[i.toInt()] == '4') translated.append("45");
		else if (message[i.toInt()] == '5') translated.append("46");
		else if (message[i.toInt()] == '6') translated.append("47");
		else if (message[i.toInt()] == '7') translated.append("48");
		else if (message[i.toInt()] == '8') translated.append("49");
		else if (message[i.toInt()] == '9') translated.append("50");
		else if (message[i.toInt()] == '0') translated.append("51");
		else if (message[i.toInt()] == '+') translated.append("52");
		else if (message[i.toInt()] == '-') translated.append("53");
		else if (message[i.toInt()] == '*') translated.append("54");
		else if (message[i.toInt()] == '/') translated.append("55");
		else if (message[i.toInt()] == '$') translated.append("56");
		else if (message[i.toInt()] == '%') translated.append("57");
		else if (message[i.toInt()] == '^') translated.append("58");
		else if (message[i.toInt()] == '(') translated.append("59");
		else if (message[i.toInt()] == ')') translated.append("60");
		else if (message[i.toInt()] - 87 > 35 || message[i.toInt()] - 87 < 10) translated.append("61");
		else {
			translated.append(std::to_string(message[i.toInt()] - 87));
		}
	}
	//group into blocks of four and encrypt
	std::string encrypted;
	for (int i = 0; i < translated.length(); i = i + 4) {
		std::string str = "";
		str = str + (translated[i]) + (translated[i + 1]) + (translated[i + 2]) + (translated[i + 3]);
		InfInt temp = str;
		//std::cout << "                   " << str << std::endl;
		encrypted = encrypted + fastModularExponentiation(temp, e, n).toString();
		encrypted = encrypted + " ";
	}
	encrypted.pop_back();
	//std::cout << encrypted << std::endl;
	return encrypted;
}

std::string RSAClass::decrypt(std::string message, InfInt key[]) {
	InfInt n = key[0];
	InfInt d = key[1];
	message += " ";
	std::string plaintext = "";
	std::string unencrypted = "";
	std::string block = "";
	for (int i = 0; i < message.length(); i++) {
		if (isspace(message[i])) {
			unencrypted.append(fastModularExponentiation(block, d, n).toString());
			block = "";
		}
		else {
			block = block + message[i];

		}
	}
	//std::cout << "\n" << unencrypted.length() << std::endl;
	//std::cout << unencrypted << ".l" << std::endl;
	//InfInt plaintext = fastModularExponentiation(ciphertext, d, n);
	for (int i = 0; i < unencrypted.length(); i += 2) {
		int temp = (unencrypted[i] - '0');
		temp = temp * 10 + (unencrypted[i + 1] - '0');
		//std::cout << i << "    " << temp << std::endl;
		if (temp == 36) plaintext += ' ';
		else if (temp == 37) plaintext += '.';
		else if (temp == 38) plaintext += '!';
		else if (temp == 39) plaintext += '?';
		else if (temp == 40) plaintext += '\'';
		else if (temp == 41) plaintext += '"';
		else if (temp == 42) plaintext += '1';
		else if (temp == 43) plaintext += '2';
		else if (temp == 44) plaintext += '3';
		else if (temp == 45) plaintext += '4';
		else if (temp == 46) plaintext += '5';
		else if (temp == 47) plaintext += '6';
		else if (temp == 48) plaintext += '7';
		else if (temp == 49) plaintext += '8';
		else if (temp == 50) plaintext += '9';
		else if (temp == 51) plaintext += '0';
		else if (temp == 52) plaintext += '+';
		else if (temp == 53) plaintext += '-';
		else if (temp == 54) plaintext += '*';
		else if (temp == 55) plaintext += '/';
		else if (temp == 56) plaintext += '$';
		else if (temp == 57) plaintext += '%';
		else if (temp == 58) plaintext += '^';
		else if (temp == 59) plaintext += '(';
		else if (temp == 60) plaintext += ')';
		else if (temp > 61 || temp < 10);
		else {
			char c = temp + 87;
			plaintext += c;
		}
	}

	return plaintext;
}


KeyPair RSAClass::generateKeys(PrimePair primePair) {
	KeyPair keys;
	keys.privateKey[0] = primePair.p * primePair.q;
	keys.publicKey[0] = keys.privateKey[0];
	srand(time(0));
	InfInt temp = (rand() % 200) + 13;
	InfInt x = (primePair.p - 1) * (primePair.q - 1);
	while (GCD(temp, x) != 1) {
		if (temp > 97) temp--;
		else temp++;
		std::cout << "    " << temp << std::endl;
	}
	keys.privateKey[1] = temp;
	if (keys.privateKey[1] <= 1) keys = generateKeys(primePair); //ensure the value returned is usable
	keys.publicKey[1] = inverseMod(temp, (primePair.p - 1) * (primePair.q - 1));
	return keys;
}