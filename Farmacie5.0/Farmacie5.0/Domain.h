#pragma once

#include <string>
#include <vector>
using namespace std;

class Medicament {
private:

	string nume;
	double pret;
	string producator;
	string substActiva;

public:
	Medicament(const Medicament &med) :nume{ med.getNume() }, pret{ med.getPret() }, producator{ med.getProducator() }, substActiva{ med.getSubst() } {}
	Medicament(const string&, const double&, const string&, const string&);
	const string& getNume() const { return nume; }
	const double& getPret() const { return pret; }
	const string& getProducator() const { return producator; }
	const string& getSubst() const { return substActiva; }
	void setNume(const string&);
	void setPret(const double&);
	void setProducator(const string&);
	void setSubst(const string&);
	friend bool operator==(const Medicament&, const Medicament&);
	friend bool operator==(const Medicament&, const string&);
	friend ofstream & operator<<(ofstream &fout, const Medicament& med);
	friend ifstream & operator>>(ifstream &fin, Medicament& med);
	Medicament& operator=(const Medicament&);
	Medicament() = default;
};

class  GeneralException {
private:
	string message;
public:
	GeneralException(const string& output) : message{ output } {}
	const char* what() const
	{
		return message.data();
	}
	GeneralException() = default;
};


class Reteta
{
private:
	vector<Medicament> reteta;
public:
	void adauga(const Medicament& med);
	void goleste();
	int length();
	vector<Medicament>& getAllReteta();
	Reteta() = default;
	bool checkMedInRet(const string& numeMed);
};


void testCreate();
void testReteta();