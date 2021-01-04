import { Component, OnInit } from '@angular/core';
import { SvgUtils } from '../svgUtils.service';
import { Router } from '@angular/router';

@Component({
  selector: 'app-large-intestines',
  templateUrl: './large-intestines.component.html',
  styleUrls: ['./large-intestines.component.css']
})
export class LargeIntestinesComponent implements OnInit {

  constructor(private router: Router) { }

  ngOnInit() {
    const margins = {
      left: 260,
      top: 432,
      right: 200,
      bottom: 200
    }
    SvgUtils.scaleAndPositionSVG('.largeIntestinesSvg', margins, 550, 550);
    SvgUtils.createTooltip('#LargeIntestinesOverlay', '.largeIntestinesTooltip', '/assets/human-body/organs/large_intestines.svg');
  }
 
  public goToLargeIntestinesPage() {
    this.router.navigate(['/large_intestines_page']);
  }

}
