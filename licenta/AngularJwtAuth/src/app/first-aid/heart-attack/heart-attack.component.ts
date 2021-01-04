import { Component, OnInit } from '@angular/core';

@Component({
  selector: 'app-heart-attack',
  templateUrl: './heart-attack.component.html',
  styleUrls: ['./heart-attack.component.css']
})
export class HeartAttackComponent implements OnInit {
  title: string = "Atactul de Cord";

  constructor() { }

  ngOnInit() {
  }

}
