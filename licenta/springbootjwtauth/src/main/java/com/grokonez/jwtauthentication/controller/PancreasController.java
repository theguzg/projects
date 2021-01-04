package com.grokonez.jwtauthentication.controller;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.CrossOrigin;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RestController;

import com.grokonez.jwtauthentication.model.Pancreas;
import com.grokonez.jwtauthentication.repository.PancreasRepository;

@CrossOrigin(origins = "http://localhost:4200")
@RestController
public class PancreasController {
	@Autowired
	private PancreasRepository br ;
	
	@RequestMapping(value = { "/pancreas_page" }, method = RequestMethod.GET)
	public List<Pancreas> listPancreas() {
		return br.findAll();
	}

}
