#pragma once
#include "Repository.h"
#include "Movie.h"



class Undo
{
public:
	virtual void executeUndo() = 0;
	virtual ~Undo() {};

};

class UndoAdd : public Undo
{
private:
	Movie addedMovie;
	Repository& repo;

public:
	UndoAdd(Repository& _repo, const Movie & m) : repo{ _repo }, addedMovie{ m } {}

	void executeUndo() override
	{
		this->repo.removeMovie(addedMovie);
	}
};

class UndoRemove : public Undo
{
private:
	Movie removedMovie;
	Repository& repo;

public:
	UndoRemove(Repository& _repo, const Movie & m) : repo{ _repo }, removedMovie{ m } {}

	void executeUndo() override
	{
		this->repo.addMovie(removedMovie);
	}
};

class UndoUpdate : public Undo
{
private:
	Movie newMovie;
	Movie updatedMovie;
	Repository& repo;

public:
	UndoUpdate(Repository& _repo, const Movie & m, const Movie & newm) : repo{ _repo }, updatedMovie{ m }, newMovie{ newm } {}

	void executeUndo() override
	{
		this->repo.updateMovie(newMovie, updatedMovie);
	}
};