package com.grokonez.jwtauthentication.controller;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.CrossOrigin;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RestController;

import com.grokonez.jwtauthentication.model.Stomach;
import com.grokonez.jwtauthentication.repository.StomachRepository;

@CrossOrigin(origins = "http://localhost:4200")
@RestController
public class StomachController {
	@Autowired
	private StomachRepository br ;
	
	@RequestMapping(value = { "/stomach_page" }, method = RequestMethod.GET)
	public List<Stomach> listSplines() {
		return br.findAll();
	}

}
