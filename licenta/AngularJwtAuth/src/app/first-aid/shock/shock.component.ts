import { Component, OnInit } from '@angular/core';

@Component({
  selector: 'app-shock',
  templateUrl: './shock.component.html',
  styleUrls: ['./shock.component.css']
})
export class ShockComponent implements OnInit {
  title: string = "Șocul";

  constructor() { }

  ngOnInit() {
  }

}
