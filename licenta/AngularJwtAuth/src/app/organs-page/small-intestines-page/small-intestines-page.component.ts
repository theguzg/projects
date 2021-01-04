import { Component, OnInit } from '@angular/core';
import { SmallIntestines } from '../models/small-intestines.model';
import { HttpOrgansClientService } from '../services/organs.service';

@Component({
  selector: 'app-small-intestines-page',
  templateUrl: './small-intestines-page.component.html',
  styleUrls: ['./small-intestines-page.component.css']
})
export class SmallIntestinesPageComponent implements OnInit {

  smallIntestines: SmallIntestines[];
  selectedDisease: boolean = false;
  selectedTreatment: boolean = false;
  selectedStatistics: boolean = false;
  selectedPrevention: boolean = false;
   
  constructor(private httpClientService:HttpOrgansClientService) { }

  ngOnInit() {
    this.httpClientService.getAllSmallIntestinesInformation().subscribe(
     response => this.handleSuccessfulResponse(response),
    );
  }

handleSuccessfulResponse(response)
{
    this.smallIntestines=response;
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
