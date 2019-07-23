#pragma once
#include <vector>
#include "Domain.h"
using namespace std;

class Repository
{
protected:
	vector<Medicament>listaMed;

public:
	/*
	Functie de adaugare in repository de tip vector de medicamente.
	-input: referinta la obiect de tip medicament.
	-output: se modifica lista de produse
	*/
	virtual void adauga(const Medicament&);
	/*
	Functie de stergere din repository de tip vector de medicamente
	-input: referinta la obiect de tip medicament.
	-output: modificarea listei cu conditia existentei elementului trimis ca si referinta
	*/
	virtual void sterge(const Medicament&);
	/*
	Functie de update din repository de tip vector de medicamente
	-input: doua referinte la obiecte de tip medicament.
	-->unul de modificat
	-->cel nou
	-output: modificarea listei cu conditia existentei elementului
	de modificat trimis ca si referinta
	*/
	virtual void update(const Medicament&, const Medicament&);
	/*
	Functie care cauta in lista un medicament trimis ca si referinta.
	-input:referinta la obiect de tip medicament
	-output:returneaza True in cazul care elementul se regaseste in lista si
	fals in caz contrar
	*/
	virtual bool gasit(const Medicament &) const;
	/*
	Functie care cauta in lista un medicament dupa nume.
	-input:numele medicamentului de cautat de tip string
	-output:returneaza True in cazul care elementul se regaseste in lista si
	fals in caz contrar
	*/
	virtual bool gasitByNume(const string &) const;
	/*
	Functie care cauta in lista un medicament dupa nume.
	-input:numele medicamentului de cautat de tip string
	-output:returneaza elementul cautat
	*/
	virtual const Medicament& getByName(const string & nume) const;
	/*
	Functie care returneaza toate elementele din lista.
	*/
	virtual vector<Medicament>& getAll();
	virtual const vector<Medicament>& getAllconst();
	/*
	Returneaza numarul de elemente din lista (de tip int).
	*/
	virtual int length();
	/*
	Constructor default pentru repository.
	*/
	Repository() = default;
	/*
	Functie care salveaza in memorie medicamentele din fisier. 
	*/
	//virtual void write() {};

	virtual ~Repository() {};
};

void testRepository();
