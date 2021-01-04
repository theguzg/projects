package com.grokonez.jwtauthentication.controller;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.CrossOrigin;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RestController;

import com.grokonez.jwtauthentication.model.SmallIntestines;
import com.grokonez.jwtauthentication.repository.SmallIntestinesRepository;

@CrossOrigin(origins = "http://localhost:4200")
@RestController
public class SmallIntestinesController {
	@Autowired
	private SmallIntestinesRepository br ;
	
	@RequestMapping(value = { "/small_intestines_page" }, method = RequestMethod.GET)
	public List<SmallIntestines> listSmallIntestines() {
		return br.findAll();
	}

}
