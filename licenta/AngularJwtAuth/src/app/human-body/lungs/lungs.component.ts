import { Component, OnInit } from '@angular/core';
import { SvgUtils } from '../svgUtils.service';
import { Router } from '@angular/router';

@Component({
  selector: 'app-lungs',
  templateUrl: './lungs.component.html',
  styleUrls: ['./lungs.component.css']
})
export class LungsComponent implements OnInit {

  constructor(private router: Router) { }

  ngOnInit() {
    const margins = {
      left: 302,
      top: 205,
      right: 200,
      bottom: 200
    }
    SvgUtils.scaleAndPositionSVG('.lungsSvg', margins, 460, 460);
    SvgUtils.createTooltip('#LungsOverlay', '.lungsTooltip', '/assets/human-body/organs/lungs.svg');
  }

  public goToLungsPage() {
    this.router.navigate(['/lungs_page']);
  }

}
