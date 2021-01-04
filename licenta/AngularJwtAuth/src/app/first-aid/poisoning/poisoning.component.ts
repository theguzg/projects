import { Component, OnInit } from '@angular/core';

@Component({
  selector: 'app-poisoning',
  templateUrl: './poisoning.component.html',
  styleUrls: ['./poisoning.component.css']
})
export class PoisoningComponent implements OnInit {
  title: string = "Otrăvirea";

  constructor() { }

  ngOnInit() {
  }

}
