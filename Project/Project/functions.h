#ifndef _H_FUNCTIONS_H_
#define	_H_FUNCTIONS_H_

int menu();

int fillRing(int* ring, int modulus);

int sumRing(int* ring, int modulus);

int subtractRing(int* ring, int modulus);

int multiplyRing(int* ring, int modulus);

int reciprocalMatrix(unsigned** matrix, int modulus, unsigned sizeOfMatrix);

int findReciprocalIndex(unsigned** matrix, int modulus, unsigned sizeOfMatrix);

int bezuAndEuclidAlgorithm(unsigned** matrix, int modulus);

int divisionMatrix(unsigned** matrix, int modulus);

int fastPower(int modulus);

int primeChecker(int modulus);

#endif _H_FUNCTIONS_H_