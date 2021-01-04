import { Component, OnInit } from '@angular/core';
import { SvgUtils } from '../svgUtils.service';
import { Router } from '@angular/router';

@Component({
  selector: 'app-spline',
  templateUrl: './spline.component.html',
  styleUrls: ['./spline.component.css']
})
export class SplineComponent implements OnInit {

  constructor(private router: Router) { }

  ngOnInit() {
    const margins = {
      left: 540,
      top: 492,
      right: 200,
      bottom: 200
    }
    SvgUtils.scaleAndPositionSVG('.splineSvg', margins, 150, 150);
    SvgUtils.createTooltip('#SplineOverlay', '.splineTooltip', '/assets/human-body/organs/spline.svg');
  }

  public goToSplinePage() {
    this.router.navigate(['/spline_page']);
  }

}
