package com.grokonez.jwtauthentication.repository;

import java.util.List;
import java.util.Optional;

import org.springframework.data.repository.CrudRepository;
import org.springframework.stereotype.Repository;

import com.grokonez.jwtauthentication.model.LargeIntestines;

@Repository
public interface LargeIntestinesRepository extends CrudRepository<LargeIntestines, Long> {
	Optional<LargeIntestines> findById(Long id);

	@Override
	List<LargeIntestines> findAll();
}
