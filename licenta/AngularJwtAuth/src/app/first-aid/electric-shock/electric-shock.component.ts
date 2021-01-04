import { Component, OnInit } from '@angular/core';

@Component({
  selector: 'app-electric-shock',
  templateUrl: './electric-shock.component.html',
  styleUrls: ['./electric-shock.component.css']
})
export class ElectricShockComponent implements OnInit {
  title: string = "Șocul Electric";

  constructor() { }

  ngOnInit() {
  }

}
