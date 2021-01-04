package com.grokonez.jwtauthentication.controller;

import java.util.List;

import javax.validation.Valid;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.CrossOrigin;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RestController;

import com.grokonez.jwtauthentication.message.response.ResponseMessage;
import com.grokonez.jwtauthentication.model.BloodDonation;
import com.grokonez.jwtauthentication.repository.BloodDonationRepository;

@CrossOrigin(origins = "http://localhost:4200")
@RestController
public class BloodDonationController {
	@Autowired
	private BloodDonationRepository bdr ;
	
	@RequestMapping(value = { "/donation" }, method = RequestMethod.GET)
	public List<BloodDonation> listDonations() {
		return bdr.findAll();
	}
	
	//@RequestMapping(value = { "/add-donation" }, method = RequestMethod.POST)
	@PostMapping("/add-donation")
	public ResponseEntity<?> addDonation(@Valid @RequestBody BloodDonation d) {
		
		// BloodDonation d = new BloodDonation(firstName, lastName, email, phone, date);
		BloodDonation donation = new BloodDonation(d.getFirstname(), d.getLastname(), d.getEmail(), d.getPhone(), d.getDate());
		bdr.save(donation);
		return new ResponseEntity<>(new ResponseMessage("Donation registered successfully!"), HttpStatus.OK);
		
	}
//		ModelAndView model = new ModelAndView();
//		
//		Iterable<Entertainment> jokesList = er.findAll(); 
//		model.addObject("jokes",jokesList);
//		
//		model.setViewName("/entertainment/jokesList");
//		return model;
}
