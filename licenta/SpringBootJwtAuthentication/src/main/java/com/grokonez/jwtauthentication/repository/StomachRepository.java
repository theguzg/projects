package com.grokonez.jwtauthentication.repository;

import java.util.List;
import java.util.Optional;

import org.springframework.data.repository.CrudRepository;
import org.springframework.stereotype.Repository;

import com.grokonez.jwtauthentication.model.Stomach;

@Repository
public interface StomachRepository extends CrudRepository<Stomach, Long> {
	Optional<Stomach> findById(Long id);

	@Override
	List<Stomach> findAll();
}
