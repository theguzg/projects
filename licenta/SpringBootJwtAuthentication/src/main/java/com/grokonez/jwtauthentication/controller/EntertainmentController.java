package com.grokonez.jwtauthentication.controller;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.CrossOrigin;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RestController;

import com.grokonez.jwtauthentication.model.Entertainment;
import com.grokonez.jwtauthentication.repository.EntertainmentRepository;

@CrossOrigin(origins = "http://localhost:4200")
@RestController
public class EntertainmentController {
	@Autowired
	private EntertainmentRepository er ;
	
	@RequestMapping(value = { "/entertainment" }, method = RequestMethod.GET)
	public List<Entertainment> listJokes() {
		return er.findAll();
	}
//		ModelAndView model = new ModelAndView();
//		
//		Iterable<Entertainment> jokesList = er.findAll(); 
//		model.addObject("jokes",jokesList);
//		
//		model.setViewName("/entertainment/jokesList");
//		return model;
}
