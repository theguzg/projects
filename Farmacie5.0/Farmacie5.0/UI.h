#pragma once
#include "Controller.h"

class Console
{
private:
	Controller &csl;
	ControllerReteta &cslRet;

public:
	Console(Controller &ctrl, ControllerReteta &ctrlRet) : csl{ ctrl }, cslRet{ctrlRet} {};
	void showOptions() const;
	void showAdd() const;
	void showAddReteta() const;
	void showUpdate() const;
	void showDelete() const;
	void showGolireReteta() const;
	void showFiltrare() const;
	void showGenerareReteta() const;
	void showExportaLista() const;
	void showSortare() const;
	void showList(vector<Medicament>& lista) const;
	void printAll() const;
	void addAutomat() const;
	void showLenReteta() const;
	void showUndo() const;
	void showRedo() const;

};
