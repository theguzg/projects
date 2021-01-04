import { Component, OnInit } from '@angular/core';
import { SvgUtils } from '../svgUtils.service';
import { Router } from '@angular/router';

@Component({
  selector: 'app-small-intestines',
  templateUrl: './small-intestines.component.html',
  styleUrls: ['./small-intestines.component.css']
})
export class SmallIntestinesComponent implements OnInit {

  constructor(private router: Router) { }

  ngOnInit() {
    const margins = {
      left: 355,
      top: 520,
      right: 200,
      bottom: 200
    }
    SvgUtils.scaleAndPositionSVG('.smallIntestinesSvg', margins, 380, 380);
    SvgUtils.createTooltip('#SmallIntestinesOverlay', '.smallIntestinesTooltip', '/assets/human-body/organs/small_intestines.svg');
  }

  public goToSmallIntestinesPage() {
    this.router.navigate(['/small_intestines_page']);
  }

}
