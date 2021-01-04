package com.grokonez.jwtauthentication.repository;

import java.util.List;
import java.util.Optional;

import org.springframework.data.repository.CrudRepository;
import org.springframework.stereotype.Repository;

import com.grokonez.jwtauthentication.model.Kidneys;

@Repository
public interface KidneysRepository extends CrudRepository<Kidneys, Long> {
	Optional<Kidneys> findById(Long id);

	@Override
	List<Kidneys> findAll();
}
