import { Component, OnInit } from '@angular/core';
import { Bladder } from '../models/bladder.model';
import { HttpOrgansClientService } from '../services/organs.service';

@Component({
  selector: 'app-bladder-page',
  templateUrl: './bladder-page.component.html',
  styleUrls: ['./bladder-page.component.css']
})
export class BladderPageComponent implements OnInit {

  bladders: Bladder[];
  selectedDisease: boolean = false;
  selectedTreatment: boolean = false;
  selectedStatistics: boolean = false;
  selectedPrevention: boolean = false;
   
  constructor(private httpClientService:HttpOrgansClientService) { }

  ngOnInit() {
    this.httpClientService.getAllBladderInformation().subscribe(
     response => this.handleSuccessfulResponse(response),
    );
  }

handleSuccessfulResponse(response)
{
    this.bladders=response;
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
