package com.grokonez.jwtauthentication.controller;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.CrossOrigin;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RestController;

import com.grokonez.jwtauthentication.model.Brain;
import com.grokonez.jwtauthentication.repository.BrainRepository;

@CrossOrigin(origins = "http://localhost:4200")
@RestController
public class BrainController {
	@Autowired
	private BrainRepository br ;
	
	@RequestMapping(value = { "/brain_page" }, method = RequestMethod.GET)
	public List<Brain> listBrains() {
		return br.findAll();
	}
//		ModelAndView model = new ModelAndView();
//		
//		Iterable<Entertainment> jokesList = er.findAll(); 
//		model.addObject("jokes",jokesList);
//		
//		model.setViewName("/entertainment/jokesList");
//		return model;
}
