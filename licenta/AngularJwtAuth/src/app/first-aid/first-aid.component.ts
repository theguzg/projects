import { Component, OnInit } from '@angular/core';
import { MatDialog } from '@angular/material';

@Component({
  selector: 'app-first-aid',
  templateUrl: './first-aid.component.html',
  styleUrls: ['./first-aid.component.css']
})
export class FirstAidComponent implements OnInit {
  IMAGES: any[] = [
    { id: 1, imgPath: '../../assets/images/anaphylaxis.png', name: 'anaphylaxis', title: 'Șoc anafilactic' },
    { id: 2, imgPath: '../../assets/images/bleeding.png', name: 'bleeding', title: 'Sângerări' },
    { id: 3, imgPath: '../../assets/images/burns.png', name: 'burns', title: 'Arsuri' },
    { id: 4, imgPath: '../../assets/images/choking.png', name: 'choking', title: 'Sugrumare' },
    { id: 5, imgPath: '../../assets/images/drowning.png', name: 'drowning', title: 'Înecare' },
    { id: 6, imgPath: '../../assets/images/electric.png', name: 'electric_shock', title: 'Electrocutare' },
    { id: 7, imgPath: '../../assets/images/fracture.png', name: 'fracture', title: 'Fracturi' },
    { id: 8, imgPath: '../../assets/images/heart.png', name: 'heart_attack', title: 'Atac de cord' },
    { id: 9, imgPath: '../../assets/images/poisoning.png', name: 'poisoning', title: 'Otrăvire' },
    { id: 10, imgPath: '../../assets/images/shock.png', name: 'shock', title: 'Șoc' },
    { id: 11, imgPath: '../../assets/images/stroke.png', name: 'stroke', title: 'Accident Vascular Cerebral' }
  ];
  constructor() { }

  ngOnInit() {
  }

}


