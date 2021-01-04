import { Component, OnInit } from '@angular/core';
import { SvgUtils } from 'src/app/human-body/svgUtils.service';

@Component({
  selector: 'app-female-body',
  templateUrl: './female-body.component.html',
  styleUrls: ['./female-body.component.css']
})
export class FemaleBodyComponent implements OnInit {

  constructor() { }

  ngOnInit() {

    const margins = {
      left: -200,
      top: -300,
      right: 200,
      bottom: 200
    }

    SvgUtils.scaleAndPositionSVG('.femaleBody', margins, 2000, 2000);

    SvgUtils.createTooltipBodyParts('#Head_Female', '.femaleHeadTooltip');
    SvgUtils.createTooltipBodyParts('#Breasts_Female', '.femaleHeadTooltip');
    SvgUtils.createTooltipBodyParts('#Chest_Female', '.femaleHeadTooltip');
    SvgUtils.createTooltipBodyParts('#Neck_Female', '.femaleHeadTooltip');
    SvgUtils.createTooltipBodyParts('#Left_Shoulder_Female', '.femaleHeadTooltip');
    SvgUtils.createTooltipBodyParts('#Right_Shoulder_Female', '.femaleHeadTooltip');
    SvgUtils.createTooltipBodyParts('#Left_Arm_Female', '.femaleHeadTooltip');
    SvgUtils.createTooltipBodyParts('#Left_Forearm_Female', '.femaleHeadTooltip');
    SvgUtils.createTooltipBodyParts('#Left_Hand_Female', '.femaleHeadTooltip');
    SvgUtils.createTooltipBodyParts('#Right_Arm_Female', '.femaleHeadTooltip');
    SvgUtils.createTooltipBodyParts('#Right_Forearm_Female', '.femaleHeadTooltip');
    SvgUtils.createTooltipBodyParts('#Right_Hand_Female', '.femaleHeadTooltip');
    SvgUtils.createTooltipBodyParts('#Abdomen_Female', '.femaleHeadTooltip');
    SvgUtils.createTooltipBodyParts('#Vagina_Female', '.femaleHeadTooltip');
    SvgUtils.createTooltipBodyParts('#Left_Lower_Limb_Female', '.femaleHeadTooltip');
    SvgUtils.createTooltipBodyParts('#Left_Leg_Female', '.femaleHeadTooltip');
    SvgUtils.createTooltipBodyParts('#Left_Foot_Female', '.femaleHeadTooltip');
    SvgUtils.createTooltipBodyParts('#Right_Lower_Limb_Female', '.femaleHeadTooltip');
    SvgUtils.createTooltipBodyParts('#Right_Leg_Female', '.femaleHeadTooltip');
    SvgUtils.createTooltipBodyParts('#Right_Foot_Female', '.femaleHeadTooltip');
  }

}
