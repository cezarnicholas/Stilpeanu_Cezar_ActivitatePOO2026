#include <iostream>

// https://stackoverflow.com/a/13018191 - din obisnuinta pt atribute private

class CPrajitura {
private:
	const int m_id;
	static int contor;

	char* m_denumire;
	float m_pret;

	int m_cantitate;
	bool m_de_post;

	int m_nr_ingrediente;
	std::string* m_ingrediente;

public:
	// ==============constructors & destructor==============
	CPrajitura() : m_id(contor++) {
		m_denumire = new char[strlen("Tiramisu") + 1];
		strcpy_s(m_denumire, 9, "Tiramisu");

		m_pret = 15.f;
		m_cantitate = 250;

		m_de_post = true;

		m_nr_ingrediente = 3;
		m_ingrediente = new std::string[m_nr_ingrediente];

		m_ingrediente[0] = "piscoturi";
		m_ingrediente[1] = "vanilie";
		m_ingrediente[2] = "cafea";
	}

	CPrajitura(const char* denumire, float pret) : m_id(contor++) {
		m_denumire = new char[strlen(denumire) + 1];
		strcpy_s(m_denumire, strlen(denumire) + 1, denumire);

		m_pret = pret;
		m_cantitate = 250;

		m_de_post = true;
		
		m_nr_ingrediente = 3;
		m_ingrediente = new std::string[m_nr_ingrediente];

		m_ingrediente[0] = "piscoturi";
		m_ingrediente[1] = "vanilie";
		m_ingrediente[2] = "cafea";
	}

	CPrajitura(const CPrajitura& p) : m_id(contor++) {
		this->m_denumire = new char[strlen(p.m_denumire) + 1];
		strcpy_s(this->m_denumire, strlen(p.m_denumire) + 1, p.m_denumire);

		this->m_pret = p.m_pret;
		this->m_cantitate = p.m_cantitate;

		this->m_de_post = p.m_de_post;

		this->m_nr_ingrediente = p.m_nr_ingrediente;
		this->m_ingrediente = new std::string[m_nr_ingrediente];

		for (int i = 0; i < this->m_nr_ingrediente; i++)
			this->m_ingrediente[i] = p.m_ingrediente[i];
	}

	~CPrajitura();
	// ==============constructors & destructor==============

	// ==============methods==============
	float costMediuGram() {
		if (m_cantitate == 0)
			return 0;

		return m_pret / (m_cantitate * 1.0f);
	}

	void modificaDenumire(const char* denumire) {
		if (m_denumire != NULL)
			delete[] m_denumire;

		m_denumire = new char[strlen(denumire) + 1];
		strcpy_s(m_denumire, strlen(denumire) + 1, denumire);
	}
	// ==============methods==============

	// ==============getters==============
	int getID() const {
		return m_id;
	}

	int getCantitate() const {
		return m_cantitate;
	}

	int getNrIngrediente() const {
		return m_nr_ingrediente;
	}

	float getPret() const {
		return m_pret;
	}
	// ==============getters==============

	// ==============setters==============
	void setCantitate(int cantitate) {
		m_cantitate = cantitate;
	}
	// ==============setters==============

	friend std::ostream& operator<<(std::ostream& os, const CPrajitura p); // "friend" ca sa putem accesa membri privati
};

CPrajitura::~CPrajitura() {
	if (this->m_denumire != NULL)
		delete[] this->m_denumire;

	if (this->m_ingrediente != NULL)
		delete[] this->m_ingrediente;
}

int calculeazaCantitateTotala(CPrajitura* prajituri, int nr_prajituri) {
	int cantitate = 0;

	for (int p = 0; p < nr_prajituri; p++)
		cantitate += prajituri[p].getCantitate();

	return cantitate;
}

float calculeazaPretPerIngrediente(CPrajitura p) {
	if (p.getNrIngrediente() != 0)
		return p.getPret() / p.getNrIngrediente();

	return 0;
}

int CPrajitura::contor = 1;

std::ostream& operator<<(std::ostream& os, const CPrajitura p) {
	os << p.m_id << ' ' << 
		p.m_denumire << ' ' <<
		p.m_pret << ' ' <<
		p.m_cantitate << ' ' <<
		(p.m_de_post ? "DA" : "NU") << ' ' << 
		p.m_nr_ingrediente << '\n';

	for (int i = 0; i < p.m_nr_ingrediente; ++i)
		os << p.m_ingrediente[i] << ' ';

	os << '\n';

	return os;
}

int main() {
	CPrajitura p1;

	{
		CPrajitura p2;
	}

	CPrajitura p3;

	CPrajitura* pp = new CPrajitura();

	std::cout << p1.getID() << ' ' << p3.getID() << ' ';

	if (pp != NULL) {
		std::cout << pp->getID() << '\n';
		
		std::cout << (*pp);
	}
}