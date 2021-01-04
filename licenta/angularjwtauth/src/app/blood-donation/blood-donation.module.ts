import { NgModule } from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';
import { BloodDonationComponent } from './blood-donation.component'
import { DonationComponent } from '../donation/donation.component';


@NgModule({
    declarations: [
        DonationComponent

    ],
    exports: [BloodDonationComponent],

    imports: [
        BrowserModule
    ]
})
export class BloodDonationModule { }