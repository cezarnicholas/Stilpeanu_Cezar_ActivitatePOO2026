#include <iostream>

struct Ghiozdan_t {
	float lungime;
	int nr_buzunare;

	bool laptop;
	char* producator;
};

Ghiozdan_t citire() {
	Ghiozdan_t g;

	std::cout << "lungime= "; 
	std::cin >> g.lungime;

	std::cout << "buzunare = ";
	std::cin >> g.nr_buzunare;

	std::cout << "pt laptop 0/1= "; 
	std::cin >> g.laptop;

	char nume[10];

	std::cout << "producator= "; 
	std::cin >> nume;

	g.producator = new char[strlen(nume) + 1];
	strcpy_s(g.producator, strlen(nume) + 1, nume);

	return g;
}

void afisare(Ghiozdan_t g) {
	std::cout << "lungime:" << g.lungime << '\n';
	std::cout << "buzunare:" << g.nr_buzunare << '\n';

	std::cout << "laptop:" << g.laptop << '\n';
	std::cout << "nume producator:" << g.producator << '\n';
}

void modificare(Ghiozdan_t* g, float lungime1) {
	g->lungime = lungime1;
}

int calculeazaNrBuzunareTotal(Ghiozdan_t* ghiozdane, int nr_ghiozdane) {
	int s = 0;

	for (int i = 0; i < nr_ghiozdane; i++)
		s += ghiozdane[i].nr_buzunare;

	return s;
}
int main() {
	//Ghiozdan_t g=citire();
	//afisare(g);

	//modificare(&g, 12);
	//afisare(g);

	Ghiozdan_t* ghiozdane = new Ghiozdan_t[3];

	for (int i = 0; i < 3; i++)
		ghiozdane[i] = citire();

	//for (int i = 0; i < 3; i++)
	//	afisare(ghiozdane[i]);

	std::cout << "nr total de buzunare:" << calculeazaNrBuzunareTotal(ghiozdane, 3) << '\n';

	return 0;
}