package com.grokonez.jwtauthentication.repository;

import java.util.List;
import java.util.Optional;

import org.springframework.data.repository.CrudRepository;
import org.springframework.stereotype.Repository;

import com.grokonez.jwtauthentication.model.Liver;

@Repository
public interface LiverRepository extends CrudRepository<Liver, Long> {
	Optional<Liver> findById(Long id);

	@Override
	List<Liver> findAll();
}
