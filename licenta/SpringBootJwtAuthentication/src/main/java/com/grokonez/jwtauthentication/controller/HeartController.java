package com.grokonez.jwtauthentication.controller;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.CrossOrigin;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RestController;

import com.grokonez.jwtauthentication.model.Heart;
import com.grokonez.jwtauthentication.repository.HeartRepository;

@CrossOrigin(origins = "http://localhost:4200")
@RestController
public class HeartController {
	@Autowired
	private HeartRepository br ;
	
	@RequestMapping(value = { "/heart_page" }, method = RequestMethod.GET)
	public List<Heart> listHearts() {
		return br.findAll();
	}

}
