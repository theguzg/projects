package com.grokonez.jwtauthentication.controller;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.CrossOrigin;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RestController;

import com.grokonez.jwtauthentication.model.Spline;
import com.grokonez.jwtauthentication.repository.SplineRepository;

@CrossOrigin(origins = "http://localhost:4200")
@RestController
public class SplineController {
	@Autowired
	private SplineRepository br ;
	
	@RequestMapping(value = { "/spline_page" }, method = RequestMethod.GET)
	public List<Spline> listSplines() {
		return br.findAll();
	}

}
