#pragma once
#include "Repository.h"
#include "Undo.h"
//#include "Redo.h"
#include <stdexcept>
#include <vector>
#include <memory>


class  Ctrl_error : public GeneralException {
private:
	string message;
public:
	explicit Ctrl_error(const string& output): message{output}{}
	const char* what() const
	{return message.data();}
};


class Controller {

private:
	Repository &ctrl;
	vector<unique_ptr<UndoAction>>undoActions;
	vector<unique_ptr<UndoAction>>redoActions;
public:
	/*
	Constructor pentru controller care primeste ca si parametru o referinta de tip repository.
	*/
	Controller(Repository &repo) : ctrl{ repo} {}
	/*
	Functie care construieste un obiect de tip medicament si il adauga in lista de medicamente.
	-input:nume,producator si substActiva de tip string si pret de tip double
	-output:se adauga un medicament cu atributele date in repository.
	-raises:runtime_error daca medicamentul exista deja.
	*/
	void addMed(const string&, double, const string&, const string&);
	/*
	Functie care sterge un obiect de tip medicament din lista de medicamente.
	-input:numele medicamentului de sters
	-output:se sterge medicamentul cu numele dat
	-raises:runtime_error daca medicamentul nu exista.
	*/
	void deleteMed(const string & nume);
	/*
	Functie care construieste un nou obiect de tip medicament si il adauga in lista de medicamente.
	-input:nume medicament de modificat, nume medicament nou, producator si substActiva de tip string si pret de tip double
	-output:se modifica un medicament cu atributele date in repository.
	-raises:runtime_error daca medicamentul nu exista.
	*/

	void updateMed(const string&, const string&, double, const string&, const string&);
	/*
	Functie care filtreaza o lista de medicamente dupa un criteriu dat.
	*/
	vector<Medicament> filtrareByPrice(double);
	/*
	Functie care filtreaza o lista de medicamente dupa un criteriu dat.
	*/
	vector<Medicament> filtrareBySubst(const string &);
	/*
	Functie care sorteaza o lista de medicamente dupa un criteriu dat.
	*/
	void sortare(bool(*criteriu)(const Medicament &, const Medicament &));
	void sortByNameCrescator();
	void sortByNameDesc();
	void sortByProdCresc();
	void sortByProdDesc();
	void sortBySubstCresc();
	void sortBySubstDesc();
	void sortByPretCresc();
	void sortByPretDesc();

	/*
	Functie care returneaza numarul de elemente din lista de medicamente.
	*/
	int nrElemente() const;
	/*
	Functie care returneaza toate elementele din lista de medicamente.
	*/
	vector<Medicament>& getAllMeds();
	/*
	Realizeaza undo pentru ultima operatie efectuata.
	*/

	void undo();
	void redo();
	};

class ControllerReteta
{
private:
	Reteta &ctrlRet;
	Repository &ctrl;
public:
	/*
	Constructor pentru controller pentru reteta, care primeste ca si parametru o referinta de tip Reteta si una de tip repository.
	*/
	ControllerReteta(Reteta &ret, Repository &repo) : ctrlRet{ ret }, ctrl{repo} {}
	/*
	Adauga un medicament pe reteta, al carui nume este transmis ca si parametru. Daca medicamentul nu exista se afiseaza un mesaj de avertizare.
	*/
	void adaugaInReteta(const string& nume);
	/*
	Goleste reteta, stergand toate elementele existente.
	*/
	void golesteReteta();
	/*
	Returneaza numarul de elemente din reteta.
	*/
	int nrElemReteta();
	/*
	Populeaza reteta cu numarul de medicamente primit ca parametru.
	*/
	void genereazaReteta(int& numar);
	/*
	Functie care returneaza toate elementele din lista de medicamente.
	*/
	vector<Medicament>& getMedsReteta();
	/*
	Exporta reteta intr-un fisier.
	*/
	void exportaReteta();
};
void testController();
