import { Component, OnInit } from '@angular/core';
import * as L from 'leaflet';
import { FormControl, Validators } from '@angular/forms';

@Component({
  selector: 'app-blood-donation',
  templateUrl: './blood-donation.component.html',
  styleUrls: ['./blood-donation.component.css']
})
export class BloodDonationComponent implements OnInit {
  private map;

  constructor() { }

  ngOnInit() {

    this.map = L.map('map', {
      center: [45.657248, 25.608759],
      zoom: 15
    });

    const tiles = L.tileLayer('https://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png', {
      maxZoom: 19,
      attribution: '&copy; <a href="http://www.openstreetmap.org/copyright">OpenStreetMap</a>'
    });

    tiles.addTo(this.map);

    L.tileLayer('https://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png', {
      attribution: '&copy; <a href="https://www.openstreetmap.org/copyright">OpenStreetMap</a> contributors'
    }).addTo(this.map);

    L.marker([45.651735, 25.599079]).addTo(this.map)
      .bindPopup('Centrul de transfuzie Brasov')
      .openPopup();

  }

}
