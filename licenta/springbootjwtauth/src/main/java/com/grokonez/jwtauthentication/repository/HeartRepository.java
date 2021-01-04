package com.grokonez.jwtauthentication.repository;

import java.util.List;
import java.util.Optional;

import org.springframework.data.repository.CrudRepository;
import org.springframework.stereotype.Repository;

import com.grokonez.jwtauthentication.model.Heart;

@Repository
public interface HeartRepository extends CrudRepository<Heart, Long> {
	Optional<Heart> findById(Long id);

	@Override
	List<Heart> findAll();
}
