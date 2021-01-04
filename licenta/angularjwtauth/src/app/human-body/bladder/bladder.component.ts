import { Component, OnInit } from '@angular/core';
import { SvgUtils } from '../svgUtils.service';
import { Router } from '@angular/router';

@Component({
  selector: 'app-bladder',
  templateUrl: './bladder.component.html',
  styleUrls: ['./bladder.component.css']
})
export class BladderComponent implements OnInit {

  constructor(private router: Router) { }

  ngOnInit() {
    const margins = {
      left: 442,
      top: 698,
      right: 200,
      bottom: 200
    }
    SvgUtils.scaleAndPositionSVG('.bladderSvg', margins, 212, 212);

    SvgUtils.createTooltip('#BladderOverlay', '.bladderTooltip', '/assets/human-body/organs/bladder.svg');
  }

  public goToBladderPage() {
    this.router.navigate(['/bladder_page']);
  }
}
