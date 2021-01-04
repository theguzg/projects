import { Component, OnInit } from '@angular/core';
import { SvgUtils } from '../svgUtils.service';
import { Router } from '@angular/router';
@Component({
  selector: 'app-brain',
  templateUrl: './brain.component.html',
  styleUrls: ['./brain.component.css']
})
export class BrainComponent implements OnInit {

  constructor(private router: Router) { }

  ngOnInit() {
    const margins = {
      left: 410,
      top: 45,
      right: 200,
      bottom: 200
    }
    SvgUtils.scaleAndPositionSVG('.brainSvg', margins, 250, 250);

    SvgUtils.createTooltip('#BrainOverlay', '.brainTooltip', '/assets/human-body/organs/brain.svg');

    
  }

  public goToBrainPage() {
    this.router.navigate(['/brain_page']);
  }

}
