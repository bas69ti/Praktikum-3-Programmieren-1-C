#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <string.h>
#include <stdio.h>
using namespace std;

#pragma warning(disable:4996)
typedef enum {FALSE, TRUE} BOOL; 

#define A1
//#define A2
//#define A3
//#define A4


//Aufgabe 1 a)
int fakultaetrekursiv(int v, const int& limit = 2) {
	if (v < limit)
		return 1;

	return v * fakultaetrekursiv(v - 1, limit);
}

int binomial(const int& n, const int& k) {
	long a{ fakultaetrekursiv(n, n-k+1) };
	
	return a / fakultaetrekursiv(k);
}

//Aufgabe 1 b)
int binomialdirekt(int n, int k) {
	if (n == k || k == 0)
		return 1;

	return binomialdirekt(n - 1, k - 1) + binomialdirekt(n - 1, k);
}

//Aufgabe 2
int fakultaetiterativ(int v) {
	int r{ 1 };

	while (v > 0)
		r *= v--;

	return r;
}

//Aufgabe 3 a)
bool ist_anagramm(const char* ca, const char* cb) {
	const int* cnt[255];

	for (int i = 0; i < sizeof(cnt) / sizeof(*cnt); i++)
		cnt[i] = 0;
	
	const char* c[2]{ ca, cb };
	int t{ 1 };

	for (int i = 0; i < 2; i++, t -= 2) {

		int pos{ 0 };

		while (pos < strlen(c[i])) {
			c[i][pos] <= 'Z' ? cnt[tolower(c[i][pos])]+= t : cnt[c[i][pos]]+= t;
			++pos;
		}
	}

	for (int i = 0; i < sizeof(cnt) / sizeof(*cnt); i++)
		if (cnt[i] != 0)
			return false;

	return true;
}

//Aufgabe 4
template<typename fld, int lines>
bool is_in(int tofind, const fld (&feld)[lines], int* idx) {

	for (int i = 0; i < lines; ++i) {
		if (*(feld + i) == tofind) {
			*idx = i;
			return true;
		}
	}
	return false;
	
}


int main() {

	int x{ 5 }, y{ 2 };
#ifdef A1

	//a)
	
	cout << "a) Binomialkoeffizient " << x << " ueber " << y << ":\t" << binomial(x, y) << '\n';
	
	//b)
	cout << "b) Binomialkoeffizient " << x << " ueber " << y << ":\t" << binomialdirekt(x, y) << '\n';
	
#endif //A1

#ifdef A2
	x = 10;

	cout << "Fakultaet von " << x << ": " << fakultaetiterativ(x) << '\n';

#endif //A2

#ifdef A3

	//a)
	const char* stra{ "hello" }; const char* strb{ "hLelO" };
	cout << "a) Die Strings	" << stra << " & " << strb << (ist_anagramm(stra, strb) ? " sind ein Anagramm\n\n" : "sind kein Anagramm\n\n");

	//b)
	const char* c[]{ " erstes ", " zweites " };
	char t1[101];
	char t2[101];

	
	for (int i = 0; i < 2; i++) {

		printf("%sBitte%sWort eingeben: ",(i < 1 ? "b) " : "   "), c[i]);
		fgets(i < 1 ? t1 : t2, 100, stdin);
	}

	int r{ ist_anagramm(t1, t2) };
	printf("\n%s", (r ? "-> Anagramm" : "-> kein Anagramm."));

#endif //A3

#ifdef A4
	
	int fld[]{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int tofind{ 7 };
	int* ptr = new int{ 0 };

	
	cout << "Array: ";
	for (int el : fld)
		cout << el << ' ';
	cout << "\n\n";

	is_in(tofind, fld, ptr) ? cout << "Zahl " << tofind << " gefunden an Position " << *ptr << ".\n" : cout << "Zahl nicht gefunden.\n";

#endif //A4

}