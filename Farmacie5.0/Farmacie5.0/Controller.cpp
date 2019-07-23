#include "Controller.h"
#include <exception>
#include <iostream>
#include <algorithm>
#include <assert.h>
#include <functional>
#include <iterator>
#include <random>
#include <chrono>
#include <fstream>


using namespace std;

void Controller::addMed(const string & nume, double pret, const string & producator, const string & substActiva)
{
	Ctrl_error eroare("Medicament deja existent! \n");
	Medicament med = Medicament(nume, pret, producator, substActiva);
	if (ctrl.gasitByNume(nume))
		throw(eroare);
	ctrl.adauga(med);
	undoActions.push_back(make_unique <UndoAdd>( ctrl,med ));
}

void Controller::deleteMed(const string & nume)
{
	Ctrl_error eroare("Element inexistent! \n");
	if (ctrl.gasitByNume(nume) == false)
		throw(eroare);
	Medicament med = Medicament(nume, ctrl.getByName(nume).getPret(), ctrl.getByName(nume).getProducator(), ctrl.getByName(nume).getSubst());
	ctrl.sterge(med);
	undoActions.push_back(make_unique <UndoDelete>( ctrl,med ));


}

void Controller::updateMed(const string & nume, const string & numeNou, double pret, const string & producator, const string & substActiva)
{
	Ctrl_error eroare("Element inexistent! \n");
	if (ctrl.gasitByNume(nume) == false)
		throw(eroare);
	Medicament medNou = Medicament(numeNou, pret, producator, substActiva);
	Medicament medVechi = ctrl.getByName(nume);
	ctrl.update(medVechi, medNou);
	undoActions.push_back(make_unique <UndoUpdate>( ctrl, medNou, medVechi ));
	}

vector<Medicament> Controller::filtrareByPrice(double pret)
{
	vector<Medicament>& listaMed = ctrl.getAll();
	vector<Medicament>listaFiltrata;

	copy_if(listaMed.begin(), listaMed.end(), back_inserter(listaFiltrata), [&](const Medicament& med) 
	{ return med.getPret() < pret; });
	return listaFiltrata;
}

vector<Medicament> Controller::filtrareBySubst(const string & substActiva)
{
	vector<Medicament>& listaMed = ctrl.getAll();
	vector<Medicament>listaFiltrata;
	
	copy_if(listaMed.begin(), listaMed.end(), back_inserter(listaFiltrata), [&](const Medicament& med)
	{ return med.getSubst() == substActiva; });
	return listaFiltrata;
}

void Controller::sortare(bool(*criteriu)(const Medicament&, const Medicament&))
{
	auto& allMeds = ctrl.getAll();
	sort(allMeds.begin(), allMeds.end(), criteriu);
}

void Controller::sortByNameCrescator()
{
	sortare([](const Medicament& med1, const Medicament& med2) {
		return med1.getNume() < med2.getNume();
	});
}

void Controller::sortByNameDesc()
{
	sortare([](const Medicament& med1, const Medicament& med2) {
		return med1.getNume() > med2.getNume();
	});
}

void Controller::sortByProdCresc()
{
	sortare([](const Medicament& med1, const Medicament& med2) {
		return med1.getProducator() < med2.getProducator();
	});
}

void Controller::sortByProdDesc()
{
	sortare([](const Medicament& med1, const Medicament& med2) {
		return med1.getProducator() > med2.getProducator();
	});
}

void Controller::sortBySubstCresc()
{
	sortare([](const Medicament& med1, const Medicament& med2) {
		return med1.getSubst() < med2.getSubst();
	});
}

void Controller::sortBySubstDesc()
{
	sortare([](const Medicament& med1, const Medicament& med2) {
		return med1.getSubst() > med2.getSubst();
	});
}

void Controller::sortByPretCresc()
{
	sortare([](const Medicament& med1, const Medicament& med2) {
		return med1.getPret() < med2.getPret();
	});
}

void Controller::sortByPretDesc()
{
	sortare([](const Medicament& med1, const Medicament& med2) {
		return med1.getPret() > med2.getPret();
	});
}

int Controller::nrElemente() const
{
	return ctrl.length();
}

vector<Medicament>& Controller::getAllMeds()
{
	return ctrl.getAll();
}

void Controller::undo()
{
	Ctrl_error eroare("Nu mai exista operatii! \n");
	if (undoActions.empty()) {
		throw eroare;
	}
	auto action = move(undoActions.back());
	action->doUndo();
	redoActions.push_back(move(action));
	undoActions.pop_back();

}

void Controller::redo()
{
	Ctrl_error eroare("Nu exista operatie de redo valabila! \n");
	if (redoActions.empty()) {
		throw eroare;
	}
	auto action = move(redoActions.back());
	action->doRedo();
	undoActions.push_back(move(action));
	redoActions.pop_back();
}

void testController()
{
	Repository repo;
	Reteta ret;
	Controller ctrl1{ repo };
	ctrl1.addMed("a", 10.4, "a", "a");
	ctrl1.addMed("c", 10.9, "c", "c");
	ctrl1.addMed("d", 21.3, "d", "d");
	ctrl1.addMed("b", 10.7, "b", "b");
	ctrl1.addMed("f", 22.9, "a", "a");
	assert(ctrl1.nrElemente() == 5);
	vector<Medicament>listaF = ctrl1.filtrareByPrice(15.4);
	assert(listaF.size() == 3);
	vector<Medicament>listaF1 = ctrl1.filtrareBySubst("a");
	assert(listaF1.size() == 2);
	ctrl1.deleteMed("a");
	assert(ctrl1.nrElemente() == 4);
	ctrl1.updateMed("d", "e", 45.6, "e", "e");
	assert(ctrl1.nrElemente() == 4);
	ctrl1.sortByNameCrescator();
	assert(ctrl1.getAllMeds()[0].getNume() == "b");
	ctrl1.sortByNameDesc();
	assert(ctrl1.getAllMeds()[0].getNume() == "f");
	ctrl1.sortByProdCresc();
	assert(ctrl1.getAllMeds()[0].getProducator() == "a");
	ctrl1.sortByProdDesc();
	assert(ctrl1.getAllMeds()[0].getProducator() == "e");
	ctrl1.sortByPretDesc(); ctrl1.sortBySubstCresc();
	assert(ctrl1.getAllMeds()[0].getPret() == 22.9);
	ctrl1.sortByPretCresc(); ctrl1.sortBySubstDesc();
	assert(ctrl1.getAllMeds()[0].getSubst() == "e");
	ctrl1.sortByNameCrescator();
	assert(ctrl1.getAllMeds()[0].getNume() == "b");
	ctrl1.sortByNameDesc();
	assert(ctrl1.getAllMeds()[0].getNume() == "f");
	ctrl1.addMed("z", 12, "z", "z");
	ctrl1.undo();
	ctrl1.addMed("z", 12, "z", "z");
	ctrl1.updateMed("z", "yy", 34, "h", "p");
	ctrl1.undo();
	ctrl1.redo();
	ctrl1.deleteMed("yy");
	ctrl1.undo();
	ctrl1.redo();
	ctrl1.undo();
	ctrl1.redo();
	ctrl1.addMed("a", 4, "a", "a");
	ctrl1.undo();
	ctrl1.redo();
	ControllerReteta ctrlRet{ ret,repo };
	ctrlRet.adaugaInReteta("c");
	assert(ctrlRet.nrElemReteta() == 1);
	assert(ctrlRet.getMedsReteta().size() == 1);
	ctrlRet.exportaReteta();
	ctrlRet.golesteReteta();
	assert(ctrlRet.nrElemReteta() == 0);
	int nr = 3;
	ctrlRet.genereazaReteta(nr);
	assert(ctrlRet.nrElemReteta() == 3);

	bool exception = false;
	bool exception1 = false;
	bool exception2 = false;
	bool exception3 = false;
	bool exception4 = false;

	try
	{
		ctrlRet.adaugaInReteta("a");}
	catch (Ctrl_error& eroare)
	{
		exception3 = true;
		assert(exception3 == true);
	}

	ctrlRet.golesteReteta();

	try
	{
		ctrlRet.golesteReteta();}
	catch (Ctrl_error& eroare)
	{
		exception4 = true;
		assert(exception4 == true);
	}

	try
	{
		ctrl1.addMed("f", 34.5, "sdf", "jjj");}
	catch (Ctrl_error& eroare)
	{
		exception = true;
		assert(exception == true);
	}

	try
	{
		ctrl1.updateMed("g", "s", 23.4, "sdf", "jjj");}
	catch (Ctrl_error& eroare)
	{
		exception1 = true;
		assert(exception1 == true);
	}

	try
	{
		ctrl1.deleteMed("g");}
	catch (Ctrl_error& eroare)
	{
		exception2 = true;
		assert(exception == true);
	}
	
}


void ControllerReteta::adaugaInReteta(const string & nume)
{
	Ctrl_error eroare("Element inexistent in lista de medicamente sau element deja existent in reteta! \n");
	if (ctrl.gasitByNume(nume) == false || ctrlRet.checkMedInRet(nume) == true)
		throw(eroare);
	Medicament med = ctrl.getByName(nume);
	ctrlRet.adauga(med);
	
}

void ControllerReteta::golesteReteta()
{
	Ctrl_error eroare("Reteta este deja goala! \n");
	if (ctrlRet.length() == 0)
		throw(eroare);
	ctrlRet.goleste();
}

int ControllerReteta::nrElemReteta()
{
	return ctrlRet.length();
}

void ControllerReteta::genereazaReteta(int & numar)
{	
	vector<Medicament>listaMed = ctrl.getAll();
	ctrlRet.goleste();
	auto seed = chrono::system_clock::now().time_since_epoch().count();
	shuffle(listaMed.begin(), listaMed.end(), default_random_engine(seed));
	for (auto elem : listaMed)
	{
		if (numar == 0)break;
		ctrlRet.adauga(elem);
		numar--;
	}
}


vector<Medicament>& ControllerReteta::getMedsReteta()
{
	return ctrlRet.getAllReteta();
}

void ControllerReteta::exportaReteta()
{		
	ofstream fout("Reteta.CVS",ios::trunc);
	auto& allMeds = ctrlRet.getAllReteta();
	//for_each(allMeds.begin(), allMeds.end(), [&](const Medicament& el) {
		//fout << el; });
	for (auto& el : allMeds) {
		fout << el;
	}
}
