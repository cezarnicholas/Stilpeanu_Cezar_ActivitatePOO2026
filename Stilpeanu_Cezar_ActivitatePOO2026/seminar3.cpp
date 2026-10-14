#include <iostream>
#include <string>
#include <vector>

class CPrajitura {
public:
	char* denumire;

	float pret;
	float cantitate;

	bool de_post;

	int nr_ingrediente;
	std::string* ingrediente;

	CPrajitura() {
		denumire = new char[9];
		strcpy_s(denumire, 9, "tiramisu");

		pret = 4.20f;
		cantitate = 2.24f;

		de_post = false;
		nr_ingrediente = 3;

		ingrediente = new std::string[nr_ingrediente];

		ingrediente[0] = "mascarpone";
		ingrediente[1] = "oua";
		ingrediente[2] = "zahar";
	}

	CPrajitura(const char* denumire_, float pret_, float cantitate_, bool de_post_, int nr_ingrediente_, std::vector<std::string> ingrediente_) :
		pret{ pret_ },
		cantitate{ cantitate_ },
		de_post{ de_post_ },
		nr_ingrediente{ nr_ingrediente_ }
	{
		denumire = new char[strlen(denumire_) + 1];
		strcpy_s(denumire, strlen(denumire_) + 1, denumire_);

		ingrediente = new std::string[nr_ingrediente];

		for (int ing = 0; ing < nr_ingrediente; ing++)
			ingrediente[ing] = ingrediente_[ing];
	}

	float costMediuGram() {
		if (cantitate == 0)
			return -1;

		return pret / cantitate;
	}

	void modificaDenumire(const char* denumire_) {
		delete denumire;

		denumire = new char[strlen(denumire_) + 1];
		strcpy_s(denumire, strlen(denumire_) + 1, denumire_);
	}
};

std::ostream& operator<<(std::ostream& os, const CPrajitura p) {
	os << p.denumire << ' ' << p.pret << ' ' << p.cantitate << ' ' << (p.de_post ? "DA" : "NU") << ' ' << p.nr_ingrediente << '\n';

	for (int i = 0; i < p.nr_ingrediente; ++i)
		os << p.ingrediente[i] << ' ';

	os << '\n';

	return os;
}

float calculeazaCantitateTotala(CPrajitura* prajituri, int nr_prajituri) {
	float greutate = 0;

	for (int i = 0; i < nr_prajituri; i++)
		greutate += prajituri[i].cantitate;

	return greutate;
}

int main() {
	CPrajitura p;

	CPrajitura* prajituri;
	prajituri = new CPrajitura[3];

	std::cout << prajituri[2];

	prajituri[2].pret = 50;
	prajituri[2].cantitate = 20;

	prajituri[0].modificaDenumire("tort");
	prajituri[1].modificaDenumire("ecler");

	for (int i = 0; i < 3; i++)
		std::cout << prajituri[i].denumire << ' ' << prajituri[i].costMediuGram() << '\n';

	float greutate = calculeazaCantitateTotala(prajituri, 3);
	std::cout << greutate;
}