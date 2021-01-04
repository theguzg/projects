package com.grokonez.jwtauthentication.model;

import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.Table;
import javax.validation.constraints.Size;

@Entity
@Table(name = "pancreas")
public class Pancreas {
	@Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;

    @Size(min=3, max = 4000)
    private String description_disease;
    
    @Size(min=3, max = 4000)
    private String name_disease;
    
    @Size(min=3, max = 4000)
    private String treatment;
    
    @Size(min=3, max = 4000)
    private String prevention;

	public Long getId() {
		return id;
	}

	public void setId(Long id) {
		this.id = id;
	}

	public String getDescription_disease() {
		return description_disease;
	}

	public void setDescription_disease(String description_disease) {
		this.description_disease = description_disease;
	}

	public String getName_disease() {
		return name_disease;
	}

	public void setName_disease(String name_disease) {
		this.name_disease = name_disease;
	}

	public String getTreatment() {
		return treatment;
	}

	public void setTreatment(String treatment) {
		this.treatment = treatment;
	}

	public String getPrevention() {
		return prevention;
	}

	public void setPrevention(String prevention) {
		this.prevention = prevention;
	}

	public Pancreas() {
		
	}
	
	public Pancreas(@Size(min = 3, max = 4000) String description_disease,
			@Size(min = 3, max = 4000) String name_disease, @Size(min = 3, max = 4000) String treatment,
			@Size(min = 3, max = 4000) String prevention) {
		super();
		this.description_disease = description_disease;
		this.name_disease = name_disease;
		this.treatment = treatment;
		this.prevention = prevention;
	}

}
