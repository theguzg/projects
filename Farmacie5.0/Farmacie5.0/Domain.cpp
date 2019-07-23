#include "Domain.h"
#include <iostream>
#include <fstream>

using namespace std;

Medicament::Medicament(const string& nume, const double& pret, const string& producator, const string& substActiva)
{
	this->nume = nume;
	this->pret = pret;
	this->producator = producator;
	this->substActiva = substActiva;

}

void Medicament::setNume(const string &nume)
{
	this->nume = nume;
}

void Medicament::setPret(const double &pret)
{
	this->pret = pret;
}

void Medicament::setProducator(const string &producator)
{
	this->producator = producator;
}

void Medicament::setSubst(const string &substActiva)
{
	this->substActiva = substActiva;
}

Medicament & Medicament::operator=(const Medicament &med1)
{
	this->nume = med1.getNume();
	this->pret = med1.getPret();
	this->producator = med1.getProducator();
	this->substActiva = med1.getSubst();
	return *this;
}


bool operator==(const Medicament & med1, const Medicament & med2)
{
	if (med1.getNume() == med2.getNume() &&
		med1.getPret() == med2.getPret() &&
		med1.getProducator() == med2.getProducator() &&
		med1.getSubst() == med2.getSubst())
		return true;
	return false;
}

bool operator==(const Medicament & med, const string & nume)
{
	if (med.getNume() == nume)
		return true;
	return false;
}

ofstream & operator<<(ofstream & fout, const Medicament& med) 
{
	fout <<med.getNume() << ',' << med.getPret() << ',' << med.getProducator() << ',' << med.getSubst() << '\n';
	return fout;
}

ifstream & operator >> (ifstream & fin, Medicament & med)
{
	getline(fin, med.nume, ',');
	fin >> med.pret; fin.get();
	getline(fin, med.producator, ',');
	getline(fin, med.substActiva);
	return fin;
}

void testCreate() {

	Medicament med1 = Medicament("paracetamol", 13.5, "roma", "beladona");
	assert(med1.getNume() == "paracetamol");
	assert(med1.getPret() == 13.5);
	assert(med1.getProducator() == "roma");
	assert(med1.getSubst() == "beladona");
	med1.setNume("aspirina");
	assert(med1.getNume() == "aspirina");
	med1.setPret(19.8);
	med1.setProducator("farmexim");
	med1.setSubst("ibuprofen");
	assert(med1.getPret() == 19.8);
	assert(med1.getProducator() == "farmexim");
	assert(med1.getSubst() == "ibuprofen");
}

void testReteta()
{
	Reteta reteta;
	Medicament med1 = Medicament("paracetamol", 13.5, "roma", "beladona");
	reteta.adauga(med1);
	assert(reteta.length() == 1);
	assert(reteta.checkMedInRet("a") == false);
	assert(reteta.checkMedInRet("paracetamol") == true);
	assert(reteta.getAllReteta().size() == 1);
	reteta.goleste();

	assert(reteta.length() == 0);
}


void Reteta::adauga(const Medicament & med)
{
	reteta.push_back(med);
}

void Reteta::goleste()
{
	reteta.clear();
}

int Reteta::length()
{
	return reteta.size();
}

vector<Medicament>& Reteta::getAllReteta()
{
	return reteta;
}


bool Reteta::checkMedInRet(const string & numeMed)
{
	auto it = find(reteta.begin(), reteta.end(), numeMed);
	if (it == reteta.end())
		return false;
	return true;
	
}




