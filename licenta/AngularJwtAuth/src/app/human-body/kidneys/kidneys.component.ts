import { Component, OnInit } from '@angular/core';
import { SvgUtils } from '../svgUtils.service';
import { Router } from '@angular/router';

@Component({
  selector: 'app-kidneys',
  templateUrl: './kidneys.component.html',
  styleUrls: ['./kidneys.component.css']
})
export class KidneysComponent implements OnInit {

  constructor(private router: Router) { }

  ngOnInit() {
    const margins = {
      left: 290,
      top: 445,
      right: 200,
      bottom: 200
    }
    SvgUtils.scaleAndPositionSVG('.kidneysSvg', margins, 500, 500);
    SvgUtils.createTooltip('#KidneysOverlay', '.kidneysTooltip', '/assets/human-body/organs/kidneys.svg');
  }

  public goToKidneysPage() {
    this.router.navigate(['/kidneys_page']);
  }


}
