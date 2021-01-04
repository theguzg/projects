import { Component, OnInit } from '@angular/core';
import { Lungs } from '../models/lungs.model';
import { HttpOrgansClientService } from '../services/organs.service';

@Component({
  selector: 'app-lungs-page',
  templateUrl: './lungs-page.component.html',
  styleUrls: ['./lungs-page.component.css']
})
export class LungsPageComponent implements OnInit {

  lungs: Lungs[];
  selectedDisease: boolean = false;
  selectedTreatment: boolean = false;
  selectedStatistics: boolean = false;
  selectedPrevention: boolean = false;
   
  constructor(private httpClientService:HttpOrgansClientService) { }

  ngOnInit() {
    this.httpClientService.getAllLungsInformation().subscribe(
     response => this.handleSuccessfulResponse(response),
    );
  }

handleSuccessfulResponse(response)
{
    this.lungs=response;
}

onDiseaseClick() {
  this.selectedDisease = true;
  this.selectedTreatment = false;
  this.selectedStatistics = false;
  this.selectedPrevention = false;
  console.log(this.selectedDisease);
}

onTreatmentClick() {
  this.selectedDisease = false;
  this.selectedTreatment = true;
  this.selectedStatistics = false;
  this.selectedPrevention = false;

}

onStatisticsClick() {
  this.selectedDisease = false;
  this.selectedTreatment = false;
  this.selectedStatistics = true;
  this.selectedPrevention = false;

}

onPreventionClick() {
  this.selectedDisease = false;
  this.selectedTreatment = false;
  this.selectedStatistics = false;
  this.selectedPrevention = true;

}

}
