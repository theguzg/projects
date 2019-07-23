#pragma once
#include "Domain.h"
#include "Repository.h"

class UndoAction {
public:
	virtual void doUndo() = 0;
	virtual void doRedo() = 0;
	virtual ~UndoAction() {};
	
};

class UndoAdd : public UndoAction
{
private:
	Medicament medAdaugat;
	Repository& repository;

public:
	UndoAdd(Repository& repo, const Medicament& med) : repository(repo), medAdaugat(med) {};
	inline void doUndo() override { repository.sterge(medAdaugat); }
	inline void doRedo() override { repository.adauga(medAdaugat); }
};

class UndoDelete : public UndoAction
{
private:
	Medicament medSters;
	Repository& repository;
public:
	UndoDelete(Repository& repo, const Medicament& med) : repository(repo), medSters(med) {};
	inline void doUndo() override { repository.adauga(medSters);}
	inline void doRedo() override { repository.sterge(medSters);}
};

class UndoUpdate : public UndoAction
{
private:
	Medicament medBeforeUpdate;
	Repository& repository;
	Medicament medAfterUpdate;
public:
	UndoUpdate(Repository& repo, const Medicament& med1, const Medicament& med2) : repository(repo), medAfterUpdate(med1),medBeforeUpdate(med2) {};
	inline void doUndo() override { repository.update(medAfterUpdate,medBeforeUpdate);}
	inline void doRedo() override { repository.update(medBeforeUpdate, medAfterUpdate); }
};
