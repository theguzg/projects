#pragma once
#include "Repository.h"


class FileRepository: public Repository
{
private:
	string fileName;
/*
	Functie care incarca din fisier toate inregistrarile.
*/
	void loadFromFile();
/*
	Functie care memoreaza in fisier inregistrarile din repository-ul din memorie. 
*/
	void writeToFile();

public:
	/*
	Constructor pentru repository cu fisiere.
		-input:referinta constanta la un nume de fisier de tip string
		-output:se creeaza repository. 
	*/
	FileRepository(const string& fileName);
	/*
	Functie care imi inchide fisierul de repository.
	*/
	void closeFile() const;
	/*
	Functie de adaugare in repository de tip fisier
	-input: referinta la obiect de tip medicament.
	-output: se modifica lista de produse
	*/
	void adauga(const Medicament&) override;
	/*
	Functie de stergere din repository de tip fisier
	-input: referinta la obiect de tip medicament.
	-output: modificarea listei cu conditia existentei elementului trimis ca si referinta
	*/
	void sterge(const Medicament&) override;
	/*
	Functie de update din repository de tip fisier
	-input: doua referinte la obiecte de tip medicament.
	-->unul de modificat
	-->cel nou
	-output: modificarea listei cu conditia existentei elementului
	de modificat trimis ca si referinta
	*/
	void update(const Medicament&, const Medicament&) override;
	/*
	Functie care scrie in fisier.
	*/
	//void write() override;
	vector<Medicament>& getAll() override;
	~FileRepository() { closeFile();}
};

void testFileRepo();