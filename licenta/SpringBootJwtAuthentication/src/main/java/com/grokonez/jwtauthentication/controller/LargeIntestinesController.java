package com.grokonez.jwtauthentication.controller;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.CrossOrigin;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RestController;

import com.grokonez.jwtauthentication.model.LargeIntestines;
import com.grokonez.jwtauthentication.repository.LargeIntestinesRepository;

@CrossOrigin(origins = "http://localhost:4200")
@RestController
public class LargeIntestinesController {
	@Autowired
	private LargeIntestinesRepository br ;
	
	@RequestMapping(value = { "/large_intestines_page" }, method = RequestMethod.GET)
	public List<LargeIntestines> listLargeIntestines() {
		return br.findAll();
	}

}
