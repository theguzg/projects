import { Component, OnInit } from '@angular/core';
import { Spline } from '../models/spline.model';
import { HttpOrgansClientService } from '../services/organs.service';

@Component({
  selector: 'app-spline-page',
  templateUrl: './spline-page.component.html',
  styleUrls: ['./spline-page.component.css']
})
export class SplinePageComponent implements OnInit {

  splines: Spline[];
  selectedDisease: boolean = false;
  selectedTreatment: boolean = false;
  selectedStatistics: boolean = false;
  selectedPrevention: boolean = false;
   
  constructor(private httpClientService:HttpOrgansClientService) { }

  ngOnInit() {
    this.httpClientService.getAllSplineInformation().subscribe(
     response => this.handleSuccessfulResponse(response),
    );
  }

handleSuccessfulResponse(response)
{
    this.splines=response;
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
