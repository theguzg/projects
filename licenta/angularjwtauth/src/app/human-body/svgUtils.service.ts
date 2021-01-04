import * as d3 from 'd3';

export class SvgUtils {
  static scaleAndPositionSVG(svgElement: string, margin: { top: number, right: number, bottom: number, left: number }, width: number, height: number): any {
    let svgWidth = width - margin.left - margin.right;
    let svgHeight = height - margin.top - margin.bottom;
    return d3.select(svgElement).attr("width", svgWidth + margin.left + margin.right)
      .attr("height", svgHeight + margin.top + margin.bottom).attr("transform",
        "translate(" + margin.left + "," + margin.top + ")");
  }

  static createTooltip(svgElement: string, svgTooltip: string, svgImgSrc: string) {

    let tooltip = d3
      .select(svgTooltip)
      .style("position", "absolute")
      .style("display", "none")
      .style("background-color", "white")
      .style("border", "solid")
      .style("border-width", "1px")
      .style("border-radius", "5px")
      .style("padding", "10px")
      // .text("this is the fking brain");
      .html("<p>I'm a tooltip written in HTML</p><img src=" + svgImgSrc + " height='150' width='150'></img><br>Fancy<br><span style='font-size: 40px;'>Isn't it?</span>");

    d3.select(svgElement)
      .on("mouseover", () => tooltip.style("display", "block"))
      // .on("mousemove", function () { tooltip.style("top", d3.select(svgElement).attr("cy") + "px").style("left", d3.select(svgElement).attr("cx") + "px"); })
      .on("mousemove", () => tooltip.style("top", ((<any>d3.event).pageY - 100) + "px").style("left", ((<any>d3.event).pageX - 650) + "px"))
      .on("mouseout", () => tooltip.style("display", "none"));
  }

  static hideSvg(svgElement: string) {
    d3.select(svgElement).style("display", "none");
  }

  static showSvg(svgElement: string) {
    d3.select(svgElement).style("display", "block");
  }

  static createTooltipBodyParts(svgElement: string, svgTooltip: string) {

    let tooltip = d3
      .select(svgTooltip)
      .style("position", "absolute")
      .style("display", "none")
      .style("background-color", "white")
      .style("border", "solid")
      .style("border-width", "1px")
      .style("border-radius", "5px")
      .style("padding", "10px")
      // .text("this is the fking brain");
      .html("<p>I'm a tooltip written in HTML</p><br>Fancy<br><span style='font-size: 40px;'>Isn't it?</span>");

    // d3.select(svgElement)
    //   .on("mouseover", () => tooltip.style("display", "block"))
      // .on("mousemove", function () { tooltip.style("top", d3.select(svgElement).attr("cy") + "px").style("left", d3.select(svgElement).attr("cx") + "px"); })
      // .on("mousemove", () => tooltip.style("top", ((<any>d3.event).pageY - 100) + "px").style("left", ((<any>d3.event).pageX - 650) + "px"))
      // .on("mouseout", () => tooltip.style("display", "none"));

    d3.select(svgElement)
      .on("mouseover", () => d3.select(svgElement).style("fill", "rgba(248, 148, 6,1 )"))
      .on("mouseout", () => d3.select(svgElement).style("fill", "rgba(255, 255, 255,0 )"));
  }

  // static showTooltip(event) {
  //   console.log("event");
  // }
}



