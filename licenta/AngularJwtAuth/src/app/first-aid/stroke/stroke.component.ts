import { Component, OnInit } from '@angular/core';

@Component({
  selector: 'app-stroke',
  templateUrl: './stroke.component.html',
  styleUrls: ['./stroke.component.css']
})
export class StrokeComponent implements OnInit {
  title: string = "AVC( Accident Vascular Cerebral)";

  constructor() { }

  ngOnInit() {
  }

}
