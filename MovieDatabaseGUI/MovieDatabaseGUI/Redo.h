#pragma once
#include "Repository.h"
#include "Movie.h"

class Redo
{
public:
	virtual void executeRedo() = 0;
	virtual ~Redo() {};

};

class RedoAdd : public Redo
{
private:
	Movie addedMovie;
	Repository& repo;

public:
	RedoAdd(Repository& _repo, const Movie & m) : repo{ _repo }, addedMovie{ m } {}

	void executeRedo() override
	{
		this->repo.addMovie(addedMovie);
	}
};

class RedoRemove : public Redo
{
private:
	Movie removedMovie;
	Repository& repo;

public:
	RedoRemove(Repository& _repo, const Movie & m) : repo{ _repo }, removedMovie{ m } {}

	void executeRedo() override
	{
		this->repo.removeMovie(removedMovie);
	}
};

// NU POTI FACE REDO LA UPDATE, NU-I LOGIC