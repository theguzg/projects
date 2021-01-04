import { Component, OnInit } from '@angular/core';
import { Router } from '@angular/router';

@Component({
  selector: 'app-human-body-parts',
  templateUrl: './human-body-parts.component.html',
  styleUrls: ['./human-body-parts.component.css']
})
export class HumanBodyPartsComponent implements OnInit {

  constructor(private router: Router) { }

  ngOnInit() {
  }

  goToOrgansPage() {
    this.router.navigate(['/home']);
  }

}
