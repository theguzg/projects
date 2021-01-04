import { Component, OnInit, ViewChild } from '@angular/core';
import { Donation } from './models/donation';
import { Router } from '@angular/router';
import { DonationService } from './services/donation.service';
import { MatPaginator } from '@angular/material/paginator';
import { MatTableDataSource } from '@angular/material/table';
import { FormControl, Validators } from '@angular/forms';
import { TokenStorageService } from '../auth/token-storage.service';

@Component({
    selector: 'app-donation',
    templateUrl: './donation.component.html',
    styleUrls: ['./donation.component.css']
})
export class DonationComponent implements OnInit {
    donations: Donation[];
    statusMessage: string;
    donation = new Donation();
    // isLoggedIn = false;
    // userName : string;

    displayedColumns: string[] = ['id', 'firstname', 'lastname', 'email', 'phone', 'date'];
    displayedColumns2: string[] = ['id', 'firstname', 'lastname', 'date'];
    dataSource = new MatTableDataSource<Donation>(this.donations);
    @ViewChild(MatPaginator) paginator: MatPaginator;

    constructor(private _donationService: DonationService,
        private _router: Router,
        private tokenStorage: TokenStorageService) { }

    ngOnInit(): void {
        this.getDonations();
        this.dataSource = new MatTableDataSource<Donation>(this.donations);
        this.dataSource.paginator = this.paginator;
        console.log(this.tokenStorage.getUsername());

        // if (this.tokenStorage.getToken()) {
        //     this.isLoggedIn = true;
        //     this.userName = this.tokenStorage.getUsername();
        //   }
    }

    getDonations(): void {
        this._donationService.getAllDonations()
            .subscribe((donationData) => {
                this.donations = donationData;
            },
                (error) => {
                    console.log(error);
                    this.statusMessage = "Problem with service. Please try again later!";
                }
            );

    }

    addDonation(): void {
        this._donationService.addDonation(this.donation)
            .subscribe((response) => { console.log(response); this.getDonations(); this.reset(); },
                (error) => {
                    console.log(error);
                    this.statusMessage = "Problem with service. Please try again later!";
                }
            );
    }

    private reset() {
        this.donation.id = null;
        this.donation.firstName = null;
        this.donation.lastName = null;
        this.donation.email = null;
        this.donation.phone = null;
        this.donation.date = null;
    }

    deleteDonation(donationId: string) {
        console.log("Inside the deleteDonation()::::Donation id::::" + donationId);
        this._donationService.deleteDonation(donationId)
            .subscribe((response) => { console.log(response); this.getDonations(); },
                (error) => {
                    console.log(error);
                    this.statusMessage = "Problem with service. Please try again later!";
                });
        this.reset();
        console.log("end of deleteDonations():::::::");
    }


    getDonation(donationId: string) {
        this._donationService.getDonationById(donationId)
            .subscribe((donationData) => { this.donation = donationData; this.getDonations(); }),
            (error) => {
                console.log(error);
                this.statusMessage = "Problem with service. Please try again later!";
            }
        this.reset();
    }

}

