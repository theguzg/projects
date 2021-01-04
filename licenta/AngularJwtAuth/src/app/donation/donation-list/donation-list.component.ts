import { Component, OnInit } from '@angular/core';
import { Donation } from '../models/donation';
import { Router } from '@angular/router';
import { DonationService } from '../services/donation.service';

@Component({
  selector: 'app-donation-list',
  templateUrl: './donation-list.component.html',
  styleUrls: ['./donation-list.component.css']
})
export class DonationListComponent implements OnInit {
  donation = new Donation();
  statusMessage: string;
  donations: Donation[];
  constructor(private _donationService: DonationService,
    private _router: Router) { }

  ngOnInit(): void {
    console.log("calling ngOnInit()::::");
    this.getDonations();
  }

  getDonations(): void {
    console.log("Inside getDonations():::::")
    this._donationService.getAllDonations()
      .subscribe((donationData) => this.donations = donationData,
        (error) => {
          console.log(error);
          this.statusMessage = "Problem with service. Please try again later!";
        }
      );
    console.log("end of getDonations():::::");
  }

}
