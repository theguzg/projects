package com.grokonez.jwtauthentication.repository;

import java.util.List;
import java.util.Optional;

import org.springframework.data.repository.CrudRepository;
import org.springframework.stereotype.Repository;

import com.grokonez.jwtauthentication.model.Spline;

@Repository
public interface SplineRepository extends CrudRepository<Spline, Long> {
	Optional<Spline> findById(Long id);

	@Override
	List<Spline> findAll();
}
