import { NgModule } from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';
import { HumanBodyPartsComponent } from './human-body-parts.component';
import { MaleBodyComponent } from './male-body/male-body.component';
import { FemaleBodyComponent } from './female-body/female-body.component';


@NgModule({
  declarations: [
      MaleBodyComponent,
      FemaleBodyComponent
    
  ],
  exports: [HumanBodyPartsComponent],

  imports: [
    BrowserModule
  ]
})
export class HumanBodyPartsModule { }