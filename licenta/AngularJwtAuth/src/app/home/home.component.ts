import { Component, OnInit } from '@angular/core';

import { TokenStorageService } from '../auth/token-storage.service';
import { SvgUtils } from '../human-body/svgUtils.service';
import { Router } from '@angular/router';

@Component({
  selector: 'app-home',
  templateUrl: './home.component.html',
  styleUrls: ['./home.component.css']
})
export class HomeComponent implements OnInit {
  info: any;
  organsHidden = true;

  constructor(private token: TokenStorageService, private router: Router) { }

  ngOnInit() {
    this.info = {
      token: this.token.getToken(),
      username: this.token.getUsername(),
      authorities: this.token.getAuthorities()
      
    };
  }

  toggleDisplay() {
    this.organsHidden = !this.organsHidden;

    if(this.organsHidden === false) {
      SvgUtils.hideSvg('.largeIntestinesSvg');
      SvgUtils.hideSvg('.liverSvg');
      SvgUtils.hideSvg('.bladderSvg');
      SvgUtils.hideSvg('.smallIntestinesSvg');
      SvgUtils.hideSvg('.liverSvg');
      SvgUtils.hideSvg('.pancreasSvg');
      SvgUtils.hideSvg('.stomachSvg');
    }
    else
    {
      SvgUtils.showSvg('.largeIntestinesSvg');
      SvgUtils.showSvg('.liverSvg');
      SvgUtils.showSvg('.bladderSvg');
      SvgUtils.showSvg('.smallIntestinesSvg');
      SvgUtils.showSvg('.liverSvg');
      SvgUtils.showSvg('.pancreasSvg');
      SvgUtils.showSvg('.stomachSvg');
    }
  }

  public goToHumanBodyPartsPage() {
    this.router.navigate(['/human_body_parts']);
  }

  // logout() {
  //   this.token.signOut();
  //   window.location.reload();
  // }
}
