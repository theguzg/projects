package com.grokonez.jwtauthentication.controller;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.CrossOrigin;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RestController;

import com.grokonez.jwtauthentication.model.Kidneys;
import com.grokonez.jwtauthentication.repository.KidneysRepository;

@CrossOrigin(origins = "http://localhost:4200")
@RestController
public class KidneysController {
	@Autowired
	private KidneysRepository br ;
	
	@RequestMapping(value = { "/kidneys_page" }, method = RequestMethod.GET)
	public List<Kidneys> listKidneys() {
		return br.findAll();
	}

}
