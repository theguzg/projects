import { Component, OnInit } from '@angular/core';
import { SvgUtils } from '../svgUtils.service';
import { Router } from '@angular/router';

@Component({
  selector: 'app-pancreas',
  templateUrl: './pancreas.component.html',
  styleUrls: ['./pancreas.component.css']
})
export class PancreasComponent implements OnInit {

  constructor(private router: Router) { }

  ngOnInit() {
    const margins = {
      left: 470,
      top: 550,
      right: 200,
      bottom: 200
    }
    SvgUtils.scaleAndPositionSVG('.pancreasSvg', margins, 140, 140);
    SvgUtils.createTooltip('#PancreasOverlay', '.pancreasTooltip', '/assets/human-body/organs/pancreas.svg');
  }

  public goToPancreasPage() {
    this.router.navigate(['/pancreas_page']);
  }

}


