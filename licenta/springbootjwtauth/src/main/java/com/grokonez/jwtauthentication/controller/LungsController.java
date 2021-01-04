package com.grokonez.jwtauthentication.controller;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.CrossOrigin;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RestController;

import com.grokonez.jwtauthentication.model.Lungs;
import com.grokonez.jwtauthentication.repository.LungsRepository;

@CrossOrigin(origins = "http://localhost:4200")
@RestController
public class LungsController {
	@Autowired
	private LungsRepository br ;
	
	@RequestMapping(value = { "/lungs_page" }, method = RequestMethod.GET)
	public List<Lungs> listLungs() {
		return br.findAll();
	}

}
