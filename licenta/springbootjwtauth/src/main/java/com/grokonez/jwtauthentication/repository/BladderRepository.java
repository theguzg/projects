package com.grokonez.jwtauthentication.repository;

import java.util.List;
import java.util.Optional;

import org.springframework.data.repository.CrudRepository;
import org.springframework.stereotype.Repository;

import com.grokonez.jwtauthentication.model.Bladder;

@Repository
public interface BladderRepository extends CrudRepository<Bladder, Long> {
	Optional<Bladder> findById(Long id);

	@Override
	List<Bladder> findAll();
}
