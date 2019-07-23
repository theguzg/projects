#include "Repository.h"
#include <assert.h>
#include <iostream>
using namespace std;

void Repository::adauga(const Medicament & med)
{
	listaMed.push_back(med);
}

void Repository::sterge(const Medicament & med)
{
	auto iterator = find(listaMed.begin(), listaMed.end(), med);
	if (iterator != listaMed.end())
		listaMed.erase(iterator);

}

void Repository::update(const Medicament & med, const Medicament & medNou)
{
	auto iterator = find(listaMed.begin(), listaMed.end(), med);
	*iterator = move(medNou);
}

bool Repository::gasit(const Medicament & med) const
{
	auto iterator = find(listaMed.begin(), listaMed.end(), med);
	if (iterator != listaMed.end())
		return true;
	return false;

}

bool Repository::gasitByNume(const string& nume) const
{
	auto iterator = find(listaMed.begin(), listaMed.end(), nume);
	if (iterator != listaMed.end())
		return true;
	return false;
}

const Medicament& Repository::getByName(const string& nume) const
{
	auto iterator = find(listaMed.begin(), listaMed.end(), nume);
	return *iterator;
}

vector<Medicament>& Repository::getAll()
{
	return listaMed;
}

const vector<Medicament>& Repository::getAllconst()
{
	return listaMed;
}

int Repository::length()
{
	return listaMed.size();
}

void testRepository() {

	Repository repo = Repository();
	Medicament med1 = Medicament("paracetamol", 13.7, "terapia", "ibuprofen");
	Medicament med2 = Medicament("aspirina", 23.9, "antibiotice", "beladona");
	Medicament med3 = Medicament("carbocil", 17.0, "terapia", "ginko");

	repo.adauga(med1);
	auto l1 = repo.length();
	assert(l1 == 1);
	repo.adauga(med2);
	assert(repo.length() == 2);
	repo.sterge(med1);
	assert(repo.length() == 1);
	repo.update(med2, med3);
	assert(repo.gasit(med3) == true);
	assert(repo.gasitByNume("carbocil") == true);
	vector<Medicament>v = repo.getAll();
	vector<Medicament>v1 = repo.getAllconst();
	assert(v.size() == 1);
	assert(v1.size() == 1);
	assert(repo.gasit(med1) == false);

}

