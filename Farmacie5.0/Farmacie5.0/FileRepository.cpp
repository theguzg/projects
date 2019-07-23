#include "FileRepository.h"
#include <fstream>
#include <assert.h>

void FileRepository::loadFromFile()
{
	listaMed.clear();
	ifstream fin(fileName);
	Medicament med;
	while (fin >> med)listaMed.push_back(med);
	fin.close();
	
}

void FileRepository::writeToFile()
{
	ofstream fout(fileName);
	for (auto &med : listaMed)
		fout << med;
	fout.close();
}

FileRepository::FileRepository(const string & fileName) : fileName(fileName)
{
	ifstream fin(fileName);
	if (!fin.is_open()) {
		ofstream auxiliar(fileName);
		auxiliar.close();
		return;
	}
	fin.close();
}

void FileRepository::closeFile() const 
{
	ofstream fout(fileName);
	fout.close();
}


void FileRepository::adauga(const Medicament & med)
{
	loadFromFile();
	Repository::adauga(med);
	ofstream fout(fileName,ios::app);
	fout << med;
	fout.close();
	
}

void FileRepository::sterge(const Medicament & med)
{
	loadFromFile();
	Repository::sterge(med);
	writeToFile();
}

void FileRepository::update(const Medicament & med, const Medicament & medNou)
{
	loadFromFile();
	Repository::update(med, medNou);
	writeToFile();
}

/*void FileRepository::write() 
{
	writeToFile();

}
*/
vector<Medicament>& FileRepository::getAll()
{
	loadFromFile();
	return listaMed;
}

void testFileRepo()
{
	FileRepository fileRepo = FileRepository("Test.txt");
	fileRepo.closeFile();
	Medicament med1 = Medicament("a", 13.4, "a", "a");
	fileRepo.adauga(med1);
	vector<Medicament>lista = fileRepo.getAll();
	assert(lista.size() == 1);
	Medicament med2 = Medicament("a", 14.5, "b", "c");
	fileRepo.update(med1, med2);
	fileRepo.sterge(med2);
	assert(fileRepo.length() == 0);
}
