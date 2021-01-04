import { Component, OnInit } from '@angular/core';
import { Pancreas } from '../models/pancreas.model';
import { HttpOrgansClientService } from '../services/organs.service';

@Component({
  selector: 'app-pancreas-page',
  templateUrl: './pancreas-page.component.html',
  styleUrls: ['./pancreas-page.component.css']
})
export class PancreasPageComponent implements OnInit {

  pancreas: Pancreas[];
  selectedDisease: boolean = false;
  selectedTreatment: boolean = false;
  selectedStatistics: boolean = false;
  selectedPrevention: boolean = false;
   
  constructor(private httpClientService:HttpOrgansClientService) { }

  ngOnInit() {
    this.httpClientService.getAllPancreasInformation().subscribe(
     response => this.handleSuccessfulResponse(response),
    );
  }

handleSuccessfulResponse(response)
{
    this.pancreas=response;
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
