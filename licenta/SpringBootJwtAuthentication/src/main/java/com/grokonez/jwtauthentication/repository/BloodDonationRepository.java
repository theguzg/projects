package com.grokonez.jwtauthentication.repository;

import java.util.List;
import java.util.Optional;

import org.springframework.data.repository.CrudRepository;
import org.springframework.stereotype.Repository;

import com.grokonez.jwtauthentication.model.BloodDonation;

@Repository
public interface BloodDonationRepository extends CrudRepository<BloodDonation, Long> {
	Optional<BloodDonation> findById(Long id);

	@Override
	List<BloodDonation> findAll();
}
