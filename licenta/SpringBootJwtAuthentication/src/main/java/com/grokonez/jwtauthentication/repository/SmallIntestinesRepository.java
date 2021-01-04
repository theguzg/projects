package com.grokonez.jwtauthentication.repository;

import java.util.List;
import java.util.Optional;

import org.springframework.data.repository.CrudRepository;
import org.springframework.stereotype.Repository;

import com.grokonez.jwtauthentication.model.SmallIntestines;

@Repository
public interface SmallIntestinesRepository extends CrudRepository<SmallIntestines, Long> {
	Optional<SmallIntestines> findById(Long id);

	@Override
	List<SmallIntestines> findAll();
}
