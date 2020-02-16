#include <iostream>
#include "functions.h"

using namespace std;

int main() {
	menu();
	int modulus;

	cout << "Enter your modulus number: ";

	do
	{
		cin >> modulus;
		if (modulus <= 0) {
			cout << "Enter a positive number!";
			cin >> modulus;
		}
	} while (modulus <= 0);

	int* ring = new int[modulus];

	const unsigned sizeOfMatrix = 2;
	unsigned* matrix[sizeOfMatrix];

	for (unsigned i = 0; i < sizeOfMatrix; i++) {
		matrix[i] = new unsigned[modulus];
	}

	for (unsigned i = 0; i < modulus; i++) {
		matrix[0][i] = i;
	}
	matrix[1][0] = 0;

	for (unsigned i = 1; i < modulus; i++) {
		for (unsigned j = 0; j < modulus; j++) {
			if ((i * j) % modulus == 1) {
				matrix[1][i] = j;
			}
		}
	}
	
	bool endProgram = false;
	unsigned exercise;
	while (true) {
		cout << "Enter exercise number: ";
		cin >> exercise;
		switch (exercise) {
			case 0:
				endProgram = true;
				break;
			case 1:
				fillRing(ring, modulus);
				break;
			case 2:
				sumRing(ring, modulus);
				break;
			case 3:
				subtractRing(ring, modulus);
				break;
			case 4:
				multiplyRing(ring, modulus);
				break;
			case 5:
				reciprocalMatrix(matrix, modulus, sizeOfMatrix);
				break;
			case 6:
				findReciprocalIndex(matrix, modulus, sizeOfMatrix);
				break;
			case 7:
				bezuAndEuclidAlgorithm(matrix, modulus);
				break;
			case 8:
				divisionMatrix(matrix, modulus);
				break;
			case 9:
				fastPower(modulus);
				break;
			case 14:
				primeChecker(modulus);
				break;
		}

		if (endProgram) {
			cout << "Thank you for using my program. My name is Zhuan Mustafa." << endl;
			break;
		}
		else {
			menu();
		}
	}

	for (int i = 0; i < sizeOfMatrix; i++) {
		if (matrix[i] != nullptr) {
			delete[] matrix[i];
			matrix[i] == nullptr;
		}
	}

	if (ring != nullptr) {
		delete[] ring;
		ring = nullptr;
	}

	return 0;
}