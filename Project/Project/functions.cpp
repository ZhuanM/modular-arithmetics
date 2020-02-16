#include <iostream>
#include "functions.h"

using namespace std;

int menu() {
	cout << "Press 0 for exit" << endl;
	cout << "Press 1 for fill ring" << endl;
	cout << "Press 2 for sum ring" << endl;
	cout << "Press 3 for subtract ring" << endl;
	cout << "Press 4 for multiply ring" << endl;
	cout << "Press 5 for reciprocal matrix" << endl;
	cout << "Press 6 for find reciprocal index" << endl;
	cout << "Press 7 for bezu and euclid algorithm" << endl;
	cout << "Press 8 for divison matrix" << endl;
	cout << "Press 9 for fast power" << endl;
	cout << "Press 14 for prime checker" << endl;

	return 0;
}

int fillRing(int* ring, int modulus) {
	for (int i = 0; i < modulus; i++) {
		ring[i] = i;
	}

	return 0;
}

int sumRing(int* ring, int modulus) {
	int a, b;

	cout << "Enter two numbers.";
	do
	{
		cout << "Enter the first number: ";
		cin >> a;
		if (a <= 0 || a >= modulus) {
			cout << "Enter number from the ring: ";
			cin >> a;
		}
	} while (a <= 0 || a >= modulus);

	cout << "You have entered the first number - " << a;

	do
	{
		cout << "Enter the second number: ";
		cin >> b;
		if (b <= 0 || b >= modulus) {
			cout << "Enter number from the ring: ";
			cin >> b;
		}
	} while (b <= 0 || b >= modulus);

	cout << "You have entered the second number - " << b;

	int result = (a + b) % modulus;
	cout << "The sum of the two numbers is = " << result;

	return 0;
}

int subtractRing(int* ring, int modulus) {
	int a, b;

	cout << "Enter two numbers.";
	do
	{
		cout << "Enter the first number: ";
		cin >> a;
		if (a <= 0 || a >= modulus) {
			cout << "Enter number from the ring: ";
			cin >> a;
		}
	} while (a <= 0 || a >= modulus);

	cout << "You have entered the first number - " << a;

	do
	{
		cout << "Enter the second number: ";
		cin >> b;
		if (b <= 0 || b >= modulus) {
			cout << "Enter number from the ring: ";
			cin >> b;
		}
	} while (b <= 0 || b >= modulus);

	cout << "You have entered the second number - " << b;

	int result = (a - b) % modulus;
	cout << "The sum of the two numbers is = " << result;

	return 0;
}

int multiplyRing(int* ring, int modulus) {
	int a, b;

	cout << "Enter two numbers.";
	do
	{
		cout << "Enter the first number: ";
		cin >> a;
		if (a <= 0 || a >= modulus) {
			cout << "Enter number from the ring: ";
			cin >> a;
		}
	} while (a <= 0 || a >= modulus);

	cout << "You have entered the first number - " << a;

	do
	{
		cout << "Enter the second number: ";
		cin >> b;
		if (b <= 0 || b >= modulus) {
			cout << "Enter number from the ring: ";
			cin >> b;
		}
	} while (b <= 0 || b >= modulus);

	cout << "You have entered the second number - " << b;

	int result = (a * b) % modulus;
	cout << "The sum of the two numbers is = " << result;

	return 0;
}

int reciprocalMatrix(unsigned** matrix, int modulus, unsigned sizeOfMatrix) {
	for (unsigned i = 0; i < sizeOfMatrix; i++) {
		for (int j = 0; j < modulus; j++) {
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}

	return 0;
}

int findReciprocalIndex(unsigned** matrix, int modulus, unsigned sizeOfMatrix) {
	int index;
	do
	{
		cout << "Enter index: ";
		cin >> index;
		if (index < 0 || index >= modulus) {
			cout << "Enter correct index: ";
			cin >> index;
		}
	} while (index < 0 || index >= modulus);

	if (index == 0) {
		cout << "There isn't such a value";
		return 0;
	}

	for (int i = 1; i < modulus; i++) {
		if (i == index) {
			cout << "The reciprocal value is " << matrix[1][index] << endl;
		}
	}

	return 0;
}

int bezuAndEuclidAlgorithm(unsigned** matrix, int modulus) {
	int m;
	
	do
	{
		cout << "Enter index: ";
		cin >> m;
		if (m < 0 || m >= modulus) {
			cout << "Enter correct index: ";
			cin >> m;
		}
	} while (m < 0 || m >= modulus);

	if (m == 0) {
		cout << "There isn't such a value" << endl;
		return 0;
	}
	if (m == 1) {
		cout << "The reciprocal value is 1" << endl;
		return 0;
	}

	int divisionCount = 0;
	int remainder = 0;

	int highBound = modulus;
	int lowBound = m;

	// Purvi red
	while (highBound % lowBound != 0) {
		remainder = highBound % lowBound;
		highBound = lowBound;
		lowBound = remainder;
		divisionCount++;
	}

	int cols = divisionCount + 2;
	const int rows = 4;

	int* euclidArray[rows];
	for (unsigned i = 0; i < rows; i++) {
		euclidArray[i] = new int[cols];
	}

	highBound = modulus;
	lowBound = m;

	// Vtori red
	int count = 1;
	while (highBound % lowBound != 0) {
		remainder = highBound % lowBound;
		euclidArray[1][count] = highBound / lowBound;
		highBound = lowBound;
		lowBound = remainder;
		count++;
	}

	// Posleden col na purvi red zashtoto posledniq put ne vliza
	euclidArray[1][count] = highBound / lowBound;

	euclidArray[0][0] = highBound;
	euclidArray[0][1] = lowBound;
	euclidArray[1][0] = 0;
	euclidArray[2][0] = 1;
	euclidArray[2][1] = 0;
	euclidArray[3][0] = 0;
	euclidArray[3][1] = 1;

	int l = 2;
	for (unsigned i = 0; i < divisionCount; i++) {
		euclidArray[2][l] = (euclidArray[1][l - 1] * euclidArray[2][l - 1]) + euclidArray[2][l - 2];
		euclidArray[3][l] = (euclidArray[1][l - 1] * euclidArray[3][l - 1]) + euclidArray[3][l - 2];
		l++;
	}

	// zashtoto ne posledniq put ne vliza
	int s = (euclidArray[1][l - 1] * euclidArray[2][l - 1]) + euclidArray[2][l - 2];

	// ne moje da se deli na 0
	if (s == 0) {
		cout << "There isn't such a value" << endl;
	}

	for (int i = 1; i < modulus; i++) {
		if (s == i) {
			cout << "The reciprocal value is " << matrix[1][i] << endl;
		}
	}

	for (int i = 0; i < rows; i++) {
		if (euclidArray[i] != nullptr) {
			delete[] euclidArray[i];
			euclidArray[i] == nullptr;
		}
	}

	return 0;
}

int divisionMatrix(unsigned** matrix, int modulus) {
	int a, b;

	cout << "Enter two numbers.";
	do
	{
		cout << "Enter the first number: ";
		cin >> a;
		if (a <= 0 || a >= modulus) {
			cout << "Enter number from the ring: ";
			cin >> a;
		}
	} while (a <= 0 || a >= modulus);

	cout << "You have entered the first number - " << a;

	do
	{
		cout << "Enter the second number: ";
		cin >> b;
		if (b <= 0 || b >= modulus) {
			cout << "Enter number from the ring: ";
			cin >> b;
		}
	} while (b <= 0 || b >= modulus);

	cout << "You have entered the second number - " << b;

	int reciprocalNum = matrix[1][b];
	int result = (a * reciprocalNum) % modulus;

	if (reciprocalNum != 0) {
		cout << "The result is: " << result;
	}
	else {
		cout << "The result is: -1";
	}

	return 0;
}

int fastPower(int modulus) {
	int base, power;

	do
	{
		cout << "Enter the base: ";
		cin >> base;
		if (base <= 0 || base >= modulus) {
			cout << "Enter number from the ring: ";
			cin >> base;
		}
	} while (base <= 0 || base >= modulus);

	cout << "You have entered the base - " << base;

	do
	{
		cout << "Enter the power: ";
		cin >> power;
		if (power < 0) {
			cout << "Enter non-negative power: ";
			cin >> power;
		}
	} while (power < 0);

	cout << "You have entered the power - " << power;

	if (base == 0 && power == 0) {
		cout << "There isn't such a value" << endl;
		return 0;
	}
	if (power == 0) {
		cout << "The result is - 1" << endl;
		return 0;
	}
	if (base == 1) {
		cout << "The result is - 1" << endl;
		return 0;
	}

	int poweredNumber = 0;
	int count = 1;
	int remainder = 0;

	for (int i = 1; i <= power; i++) {
		poweredNumber = pow(base, i);
		remainder = poweredNumber % modulus;

		if (remainder == 1) {
			count = i;
			break;
		}
	}

	if (count == 1) {
		poweredNumber = pow(base, power);
		remainder = poweredNumber % modulus;
		cout << "The result is - " << remainder << endl;
		return 0;
	}

	int smallerPower = power % count; // kogato stepenta e mnogo golqma
	poweredNumber = pow(base, smallerPower);

	remainder = poweredNumber % modulus;
	cout << "The result is - " << remainder << endl;

	return 0;
}

int primeChecker(int modulus) {
	int count = 0;
	for (int i = 1; i <= modulus; i++) {
		if (modulus % i == 0) {
			count++;
		}

		if (count > 2) {
			break;
		}
	}

	if (count == 2) {
		cout << "Ring Z is Field F" << endl;
	}
	else {
		cout << "Ring Z is NOT Field F" << endl;
	}

	return 0;
}