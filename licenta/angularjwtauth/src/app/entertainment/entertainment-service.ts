import { Injectable } from '@angular/core';
import { HttpClient } from '@angular/common/http';

export class Joke {
    constructor(
        public id: any,
        public name: string
    ) { }
}

@Injectable({
    providedIn: 'root'
})
export class HttpClientService {

    constructor(private httpClient: HttpClient) {
    }

    getJokes() {
        console.log("test call");
        return this.httpClient.get<Joke[]>('http://localhost:8080/entertainment');
    }
}