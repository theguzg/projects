import { HumanBodyComponent } from "./human-body.component";
import { NgModule } from '@angular/core';
import { BrainComponent } from "./brain/brain.component";
import { HumanShapeComponent } from "./human-shape/human-shape.component";
import { KidneysComponent } from "./kidneys/kidneys.component";
import { HeartComponent } from "./heart/heart.component";
import { LargeIntestinesComponent } from "./large-intestines/large-intestines.component";
import { LiverComponent } from "./liver/liver.component";
import { LungsComponent } from "./lungs/lungs.component";
import { PancreasComponent } from "./pancreas/pancreas.component";
import { SmallIntestinesComponent } from "./small-intestines/small-intestines.component";
import { SplineComponent } from "./spline/spline.component";
import { StomachComponent } from "./stomach/stomach.component";
import { BladderComponent } from "./bladder/bladder.component";
import { SvgUtils } from "./svgUtils.service";
import { BrowserModule } from '@angular/platform-browser';

@NgModule({
  declarations: [
    HumanBodyComponent,
    BrainComponent,
    HumanShapeComponent,
    KidneysComponent,
    HeartComponent,
    LargeIntestinesComponent,
    LiverComponent,
    LungsComponent,
    PancreasComponent,
    SmallIntestinesComponent,
    SplineComponent,
    StomachComponent,
    BladderComponent
  ],
  exports: [HumanBodyComponent],
  providers: [SvgUtils],
  imports: [
    BrowserModule
  ]
})
export class HumanBodyModule { }
