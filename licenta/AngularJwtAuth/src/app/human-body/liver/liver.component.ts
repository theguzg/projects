import { Component, OnInit } from '@angular/core';
import { SvgUtils } from '../svgUtils.service';
import { Router } from '@angular/router';

@Component({
  selector: 'app-liver',
  templateUrl: './liver.component.html',
  styleUrls: ['./liver.component.css']
})
export class LiverComponent implements OnInit {

  constructor(private router: Router) { }

  ngOnInit() {
    const margins = {
      left: 375,
      top: 460,
      right: 200,
      bottom: 200
    }
    SvgUtils.scaleAndPositionSVG('.liverSvg', margins, 280, 280);
    SvgUtils.createTooltip('#LiverOverlay', '.liverTooltip', '/assets/human-body/organs/liver.svg');
  }

  public goToLiverPage() {
    this.router.navigate(['/liver_page']);
  }

}
