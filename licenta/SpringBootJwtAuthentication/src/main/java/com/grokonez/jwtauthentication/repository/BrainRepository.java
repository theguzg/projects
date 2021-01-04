package com.grokonez.jwtauthentication.repository;

import java.util.List;
import java.util.Optional;

import org.springframework.data.repository.CrudRepository;
import org.springframework.stereotype.Repository;

import com.grokonez.jwtauthentication.model.Brain;

@Repository
public interface BrainRepository extends CrudRepository<Brain, Long> {
	Optional<Brain> findById(Long id);

	@Override
	List<Brain> findAll();
}
