package com.grokonez.jwtauthentication.repository;

import java.util.List;
import java.util.Optional;

import org.springframework.data.repository.CrudRepository;
import org.springframework.stereotype.Repository;

import com.grokonez.jwtauthentication.model.Pancreas;

@Repository
public interface PancreasRepository extends CrudRepository<Pancreas, Long> {
	Optional<Pancreas> findById(Long id);

	@Override
	List<Pancreas> findAll();
}
