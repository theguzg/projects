package com.grokonez.jwtauthentication.repository;

import java.util.List;
import java.util.Optional;

import org.springframework.data.repository.CrudRepository;
import org.springframework.stereotype.Repository;

import com.grokonez.jwtauthentication.model.Lungs;

@Repository
public interface LungsRepository extends CrudRepository<Lungs, Long> {
	Optional<Lungs> findById(Long id);

	@Override
	List<Lungs> findAll();
}
