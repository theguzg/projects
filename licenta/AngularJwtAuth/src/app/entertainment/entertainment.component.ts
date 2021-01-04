import { Component, OnInit } from '@angular/core';
import { HttpClientService } from './entertainment-service';

@Component({
  selector: 'app-entertainment',
  templateUrl: './entertainment.component.html',
  styleUrls: ['./entertainment.component.css']
})
export class EntertainmentComponent implements OnInit {

  jokes:string[];
   
  constructor(private httpClientService:HttpClientService) { }

  ngOnInit() {
    this.httpClientService.getJokes().subscribe(
     response => this.handleSuccessfulResponse(response),
    );
  }

handleSuccessfulResponse(response)
{
    this.jokes=response;
}

}
