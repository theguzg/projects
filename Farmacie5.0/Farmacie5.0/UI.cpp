#include "UI.h"
#include <iostream>
#include <algorithm>

using namespace std;

void Console::showOptions() const
{
	while (1) {

		int optiune;
		cout << "_____Farmacie_____" << endl;
		cout << "1.  Adauga medicament" << endl;
		cout << "2.  Modifica medicament" << endl;
		cout << "3.  Sterge medicament" << endl;
		cout << "4.  Filtrare lista medicamente" << endl;
		cout << "5.  Sortare lista medicamente" << endl;
		cout << "6.  Afisare lista medicamente" << endl;
		cout << "7.  Adaugare automata -10 itemi-" << endl;
		cout << "8.  Adaugare pe reteta" << endl;
		cout << "9.  Golire reteta" << endl;
		cout << "10. Generare reteta" << endl;
		cout << "11. Exporta reteta" << endl;
		cout << "12. Undo" << endl;
		cout << "13. Redo" << endl;
		cout << "0.  Exit" << endl;
		cout << "__________________" << endl << endl;
		cout << "Optiunea dumneavoastra este: ";
		cin >> optiune;

		if (optiune == 0)
			break;
		cout << endl;
		switch (optiune)
		{
		case 1:
			showAdd();
			break;
		case 2:
			showUpdate();
			break;
		case 3:
			showDelete();
			break;
		case 4:
			showFiltrare();
			break;
		case 5:
			showSortare();
			break;
		case 6:
			printAll();
			break;
		case 7:
			addAutomat();
			break;
		case 8:
			showAddReteta();
			break;
		case 9:
			showGolireReteta();
			break;
		case 10:
			showGenerareReteta();
			break;
		case 11:
			showExportaLista();
			break;
		case 12:
			showUndo();
			break;
		case 13:
			showRedo();
			break;
		default:
			cout << "Optiune invalida!!";
		}

	}
}

void Console::showAdd() const
{
	string nume, producator, substActiva;
	double pret;
	cout << "___Adaugare___" << endl << endl;
	cout << "Introduceti nume: "; cin >> nume;
	cout << "Introduceti pret: "; cin >> pret;
	cout << "Introduceti producator: "; cin >> producator;
	cout << "Introduceti substanta activa: "; cin >> substActiva; cout << endl;
	try
	{
		csl.addMed(nume, pret, producator, substActiva); cout << "Adaugare efectuata! :)" << endl << endl;
	}
	catch (Ctrl_error& eroare)
	{
		cout << "Eroare la adaugare: " << eroare.what();
	}

}

void Console::showAddReteta() const
{
	string nume;
	cout << "__Adaugare pe reteta__" << endl << endl;
	cout << "Introduceti nume: "; cin >> nume;
	try
	{
		cslRet.adaugaInReteta(nume);
		cout << endl << endl;
		showList(cslRet.getMedsReteta());
		cout << endl<<endl;
		showLenReteta();
		cout << endl;
	}
	catch (Ctrl_error& eroare)
	{
		cout << "Eroare la adaugare: " << eroare.what();
	}
}

void Console::showUpdate() const
{
	string nume, producator, substActiva, numeNou;
	double pret;
	cout << "___Modificare___" << endl << endl;
	cout << "Introduceti numele medicamentului de modificat: "; cin >> nume;
	cout << "Introduceti noul nume: "; cin >> numeNou;
	cout << "Introduceti noul pret: "; cin >> pret;
	cout << "Introduceti noul producator: "; cin >> producator;
	cout << "Introduceti noua substanta activa: "; cin >> substActiva; cout << endl << endl;
	try
	{
		csl.updateMed(nume, numeNou, pret, producator, substActiva);
		cout << "Modificare efectuata! :)" << endl;
	}
	catch (Ctrl_error& eroare)
	{
		cout << "Eroare la modificare: " << eroare.what();
	}
}

void Console::showDelete() const
{
	string nume;
	cout << "___Stergere___" << endl << endl;
	cout << "Introduceti numele medicamentului de sters: "; cin >> nume;

	try
	{
		csl.deleteMed(nume); cout << "Stergere efectuata! :)" << endl << endl;
	}
	catch (Ctrl_error& eroare)
	{
		cout << "Eroare la stergere: " << eroare.what() << endl;
	}


}

void Console::showGolireReteta() const
{

	try
	{
		cslRet.golesteReteta(); cout << "Lista a fost golita!"<<endl;
		showList(cslRet.getMedsReteta());
		cout << endl;
		showLenReteta();
		cout << endl << endl;

	}
	catch (Ctrl_error& eroare)
	{
		cout << "Eroare la golire: " << eroare.what()<<endl;
	}
}

void Console::showFiltrare() const
{
	vector<Medicament>lista;
	int optiune;
	cout << "___Filtrare___" << endl << endl;
	cout << "-->1.)Dupa pret " << endl;
	cout << "-->2.)Dupa substanta activa " << endl << endl;
	cout << "Optiunea dumneavoastra este: "; cin >> optiune;

	if (optiune == 1) {
		double pret;
		cout << endl << "Introduceti pret: "; cin >> pret;
		lista = csl.filtrareByPrice(pret);
		showList(lista);
		cout << endl;
	}

	else if (optiune == 2) {
		string substantaActiva;
		cout << endl << "Introduceti substanta activa: "; cin >> substantaActiva;
		lista = csl.filtrareBySubst(substantaActiva);
		showList(lista);
		cout << endl;
	}

}

void Console::showGenerareReteta() const
{
	cout << "__Generare reteta__"<<endl<<endl;
	int numarMedicamenteReteta;
	cout << "Introduceti numarul de medicamente ce se vor adauga pe reteta: "; cin >> numarMedicamenteReteta;
	cslRet.genereazaReteta(numarMedicamenteReteta);
	showList(cslRet.getMedsReteta());
	cout << endl;
	showLenReteta();
	cout << endl;
}

void Console::showExportaLista() const
{
	cout << "__Exportare reteta__" << endl << endl;
	cslRet.exportaReteta();
}

void Console::showSortare() const
{

	int optiune;
	cout << "___Sortare___" << endl << endl;
	cout << "-->1.)Dupa nume" << endl;
	cout << "-->2.)Dupa producator" << endl;
	cout << "-->3.)Dupa substanta activa si pret" << endl << endl;
	cout << "Optiunea dumneavoastra este: "; cin >> optiune;

	if (optiune == 1) {
		string raspuns;
		cout << endl << "Crescator? Raspuns: "; cin >> raspuns;
		if (raspuns == "da")csl.sortByNameCrescator();
		else if (raspuns == "nu") csl.sortByNameDesc();
		else cout << "Un raspuns dintre 'da' si 'nu' astept.." << endl;
		cout << endl;
	}

	else if (optiune == 2) {
		string raspuns;
		cout << endl << "Crescator? Raspuns: "; cin >> raspuns;
		if (raspuns == "da")csl.sortByProdCresc();
		else if (raspuns == "nu") csl.sortByProdDesc();
		else cout << "Un raspuns dintre 'da' si 'nu' astept.." << endl;
		cout << endl;
	}

	else if (optiune == 3) {
		string raspuns;
		cout << endl << "Crescator? Raspuns: "; cin >> raspuns;
		if (raspuns == "da") {
			csl.sortByPretCresc(); csl.sortBySubstCresc();
		}
		else if (raspuns == "nu") { csl.sortByPretDesc(); csl.sortBySubstDesc(); }
		else cout << "Un raspuns dintre 'da' si 'nu' astept.." << endl;
		cout << endl;
	}
}

void Console::showList(vector<Medicament>& lista) const {

	if (lista.size() == 0)
		cout << "Lista este vida!";
	else {
		cout.width(16); cout << left << "Nume";
		cout.width(16); cout << left << "Pret";
		cout.width(16); cout << left << "Producator";
		cout.width(16); cout << left << "Substanta Activa"<<endl;

		for_each(lista.begin(), lista.end(), [](const Medicament& el) {
			cout.width(16); cout << left << el.getNume();
			cout.width(16); cout << left << el.getPret();
			cout.width(16); cout << left << el.getProducator();
			cout.width(16); cout << left << el.getSubst()<<endl; });
	}
}

void Console::addAutomat() const
{
	csl.addMed("a", 10.7, "a", "a");
	csl.addMed("b", 23.5, "b", "a");
	csl.addMed("c", 34.6, "c", "a");
	csl.addMed("d", 67.9, "d", "d");
	csl.addMed("e", 13.2, "e", "e");
	csl.addMed("f", 56.7, "f", "a");
	csl.addMed("g", 34.8, "g", "g");
	csl.addMed("h", 23.2, "h", "h");
	csl.addMed("i", 11.2, "i", "a");
	csl.addMed("j", 14.3, "j", "j");
	csl.addMed("k", 12.4, "k", "k");
}

void Console::showLenReteta() const
{
	cout << "Numarul de medicamente este: " << cslRet.nrElemReteta();
}

void Console::printAll() const
{
	if (csl.nrElemente() == 0)
		cout << "Lista este vida!" << endl << endl;
	else {
		cout.width(16); cout << left << "Nume";
		cout.width(16); cout << left << "Pret";
		cout.width(16); cout << left << "Producator";
		cout.width(16); cout << left << "Substanta Activa" << endl;
		auto& allMeds = csl.getAllMeds();
		for_each(allMeds.begin(), allMeds.end(), [](const Medicament& el) {
			cout.width(16); cout << left << el.getNume();
			cout.width(16); cout << left << el.getPret();
			cout.width(16); cout << left << el.getProducator();
			cout.width(16); cout << left << el.getSubst() << endl; });

	}

}

void Console::showUndo() const 
{
	try
	{
		csl.undo();
		cout << "Undo realizat!!" << endl;
	}
	catch (Ctrl_error& eroare)	{
		cout << "Eroare la undo: " << eroare.what();
	}
}

void Console::showRedo() const
{
	try
	{
		csl.redo();
		cout << "Redo realizat!!" << endl;
	}
	catch (Ctrl_error& eroare)
	{
		cout << "Eroare la redo: " << eroare.what();
	}
}
