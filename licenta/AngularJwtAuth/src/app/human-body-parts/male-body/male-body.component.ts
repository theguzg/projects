import { Component, OnInit } from '@angular/core';
import { SvgUtils } from 'src/app/human-body/svgUtils.service';

@Component({
  selector: 'app-male-body',
  templateUrl: './male-body.component.html',
  styleUrls: ['./male-body.component.css']
})
export class MaleBodyComponent implements OnInit {

  constructor() { }

  ngOnInit() {

    const margins = {
      left: -790,
      top: -320,
      right: 200,
      bottom: 200
    }
    
    SvgUtils.scaleAndPositionSVG('.maleBody', margins, 2150, 2150);

    SvgUtils.createTooltipBodyParts('#Head_Male', '.maleHeadTooltip');
    SvgUtils.createTooltipBodyParts('#Chest_Male', '.maleHeadTooltip');
    SvgUtils.createTooltipBodyParts('#Neck_Male', '.maleHeadTooltip');
    SvgUtils.createTooltipBodyParts('#Left_Shoulder_Male', '.maleHeadTooltip');
    SvgUtils.createTooltipBodyParts('#Right_Shoulder_Male', '.maleHeadTooltip');
    SvgUtils.createTooltipBodyParts('#Left_Arm_Male', '.maleHeadTooltip');
    SvgUtils.createTooltipBodyParts('#Left_Forearm_Male', '.maleHeadTooltip');
    SvgUtils.createTooltipBodyParts('#Left_Hand_Male', '.maleHeadTooltip');
    SvgUtils.createTooltipBodyParts('#Right_Arm_Male', '.maleHeadTooltip');
    SvgUtils.createTooltipBodyParts('#Right_Forearm_Male', '.maleHeadTooltip');
    SvgUtils.createTooltipBodyParts('#Right_Hand_Male', '.maleHeadTooltip');
    SvgUtils.createTooltipBodyParts('#Abdomen_Male', '.maleHeadTooltip');
    SvgUtils.createTooltipBodyParts('#Penis_Male', '.maleHeadTooltip');
    SvgUtils.createTooltipBodyParts('#Left_Lower_Limb_Male', '.maleHeadTooltip');
    SvgUtils.createTooltipBodyParts('#Left_Leg_Male', '.maleHeadTooltip');
    SvgUtils.createTooltipBodyParts('#Left_Foot_Male', '.maleHeadTooltip');
    SvgUtils.createTooltipBodyParts('#Right_Lower_Limb_Male', '.maleHeadTooltip');
    SvgUtils.createTooltipBodyParts('#Right_Leg_Male', '.maleHeadTooltip');
    SvgUtils.createTooltipBodyParts('#Right_Foot_Male', '.maleHeadTooltip');
  }

}
