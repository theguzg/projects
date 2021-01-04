import { Component, OnInit } from '@angular/core';
import { SvgUtils } from '../svgUtils.service';
import { Router } from '@angular/router';

@Component({
  selector: 'app-stomach',
  templateUrl: './stomach.component.html',
  styleUrls: ['./stomach.component.css']
})
export class StomachComponent implements OnInit {

  constructor(private router: Router) { }

  ngOnInit() {
    const margins = {
      left: 420,
      top: 440,
      right: 200,
      bottom: 200
    }
    SvgUtils.scaleAndPositionSVG('.stomachSvg', margins, 280, 280);
    SvgUtils.createTooltip('#StomachOverlay', '.stomachTooltip', '/assets/human-body/organs/stomach.svg');
  }

  public goToStomachPage() {
    this.router.navigate(['/stomach_page']);
  }

}
