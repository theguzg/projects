import { NgModule } from '@angular/core';

import { BrowserModule } from '@angular/platform-browser';
import { DonationComponent } from './donation.component';
import { DonationListComponent } from './donation-list/donation-list.component';
import { DonationService } from './services/donation.service';
import { FormsModule, ReactiveFormsModule } from '@angular/forms';
import { MatTableModule } from '@angular/material/table';
import { MatPaginatorModule } from '@angular/material/paginator';
import { MatSelectModule } from '@angular/material/select';
import { MatInputModule } from '@angular/material';
import { MatFormFieldModule } from '@angular/material/form-field';


@NgModule({
    declarations: [
        DonationComponent,
        DonationListComponent
    ],
    exports: [DonationComponent],
    providers: [DonationService],
    imports: [
        BrowserModule,
        FormsModule,
        MatTableModule,
        MatPaginatorModule,
        MatSelectModule,
        MatInputModule,
        MatFormFieldModule,
        ReactiveFormsModule
    ]
})
export class DonationModule { }
