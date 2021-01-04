import { Component, OnInit } from '@angular/core';
import { SvgUtils } from '../svgUtils.service';
import { Router } from '@angular/router';

@Component({
  selector: 'app-heart',
  templateUrl: './heart.component.html',
  styleUrls: ['./heart.component.css']
})
export class HeartComponent implements OnInit {

  constructor(private router: Router) { }

  ngOnInit() {
    const margins = {
      left: 415,
      top: 350,
      right: 200,
      bottom: 200
    }
    SvgUtils.scaleAndPositionSVG('.heartSvg', margins, 245, 245);
    SvgUtils.createTooltip('#HeartOverlay', '.heartTooltip', '/assets/human-body/organs/heart.svg');
  }

  public goToHeartPage() {
    this.router.navigate(['/heart_page']);
  }

}
