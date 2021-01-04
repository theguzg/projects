package com.grokonez.jwtauthentication.controller;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.CrossOrigin;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RestController;

import com.grokonez.jwtauthentication.model.Bladder;
import com.grokonez.jwtauthentication.repository.BladderRepository;

@CrossOrigin(origins = "http://localhost:4200")
@RestController
public class BladderController {
	@Autowired
	private BladderRepository br ;
	
	@RequestMapping(value = { "/bladder_page" }, method = RequestMethod.GET)
	public List<Bladder> listBladers() {
		return br.findAll();
	}

}
