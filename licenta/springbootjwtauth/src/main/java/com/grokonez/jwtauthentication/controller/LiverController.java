package com.grokonez.jwtauthentication.controller;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.CrossOrigin;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RestController;

import com.grokonez.jwtauthentication.model.Liver;
import com.grokonez.jwtauthentication.repository.LiverRepository;

@CrossOrigin(origins = "http://localhost:4200")
@RestController
public class LiverController {
	@Autowired
	private LiverRepository br ;
	
	@RequestMapping(value = { "/liver_page" }, method = RequestMethod.GET)
	public List<Liver> listLivers() {
		return br.findAll();
	}

}
