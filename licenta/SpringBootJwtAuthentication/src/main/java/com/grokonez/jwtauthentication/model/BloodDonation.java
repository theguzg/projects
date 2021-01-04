package com.grokonez.jwtauthentication.model;

import java.util.Date;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.Table;
import javax.validation.constraints.Future;
import javax.validation.constraints.NotBlank;
import javax.validation.constraints.NotEmpty;
import javax.validation.constraints.NotNull;
import javax.validation.constraints.Size;

import com.fasterxml.jackson.annotation.JsonFormat;

@Entity
@Table(name = "blood_donation")
public class BloodDonation {

		@Id
	    @GeneratedValue(strategy = GenerationType.IDENTITY)
	    private Long id;

		@NotBlank
	    @Size(min=3, max = 45)
	    private String firstname;
	    
		@NotBlank
	    @Size(min=3, max = 45)
	    private String lastname;
	    
		@NotBlank
	    @Size(min=3, max = 45)
	    private String email;
	    
		@NotBlank
	    @Size(min=3, max = 45)
	    private String phone;
	    
//	    @Size(min=3, max = 45)
		@JsonFormat(pattern = "yyyy-MM-dd")
	    private Date date;
	    
	    public BloodDonation() {}

		public BloodDonation(@NotBlank @Size(min = 3, max = 45) String firstname,
				@NotBlank @Size(min = 3, max = 45) String lastname, @NotBlank @Size(min = 3, max = 45) String email,
				@NotBlank @Size(min = 3, max = 45) String phone, @NotBlank @JsonFormat(pattern = "yyyy-MM-dd") Date date) {
			super();
			this.firstname = firstname;
			this.lastname = lastname;
			this.email = email;
			this.phone = phone;
			this.date = date;
		}

		public Long getId() {
			return id;
		}

		public void setId(Long id) {
			this.id = id;
		}

		public String getFirstname() {
			return firstname;
		}

		public void setFirstname(String firstname) {
			this.firstname = firstname;
		}

		public String getLastname() {
			return lastname;
		}

		public void setLastname(String lastname) {
			this.lastname = lastname;
		}

		public String getEmail() {
			return email;
		}

		public void setEmail(String email) {
			this.email = email;
		}

		public String getPhone() {
			return phone;
		}

		public void setPhone(String phone) {
			this.phone = phone;
		}

		public Date getDate() {
			return date;
		}

		public void setDate(Date date) {
			this.date = date;
		}

		@Override
		public String toString() {
			return "BloodDonation [id=" + id + ", firstname=" + firstname + ", lastname=" + lastname + ", email="
					+ email + ", phone=" + phone + ", date=" + date + "]";
		}

}
