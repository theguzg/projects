import { Component, OnInit, Input } from '@angular/core';

@Component({
  selector: 'app-anaphylaxis',
  templateUrl: './anaphylaxis.component.html',
  styleUrls: ['./anaphylaxis.component.css']
})
export class AnaphylaxisComponent implements OnInit {
  title: string = "Șocul Anafilactic";
  constructor() { }

  ngOnInit() {
  }

}
