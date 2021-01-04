package com.grokonez.jwtauthentication.repository;

import java.util.List;
import java.util.Optional;

import org.springframework.data.repository.CrudRepository;
import org.springframework.stereotype.Repository;

import com.grokonez.jwtauthentication.model.Entertainment;

@Repository
public interface EntertainmentRepository extends CrudRepository<Entertainment, Long> {
	Optional<Entertainment> findById(Long id);

	@Override
	List<Entertainment> findAll();
}
