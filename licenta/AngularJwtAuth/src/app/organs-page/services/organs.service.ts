import { Injectable } from '@angular/core';
import { HttpClient } from '@angular/common/http';
import { Brain } from '../models/brain.model';
import { Bladder } from '../models/bladder.model';
import { Heart } from '../models/heart.model';
import { Kidneys } from '../models/kidneys.model';
import { LargeIntestines } from '../models/large-intestines.model';
import { Liver } from '../models/liver.model';
import { Lungs } from '../models/lungs.model';
import { Pancreas } from '../models/pancreas.model';
import { SmallIntestines } from '../models/small-intestines.model';
import { Spline } from '../models/spline.model';
import { Stomach } from '../models/stomach.model';

@Injectable({
    providedIn: 'root'
})
export class HttpOrgansClientService {

    constructor(private httpClient: HttpClient) {
    }

    getAllBrainInformation() {
        console.log("test call");
        return this.httpClient.get<Brain[]>('http://localhost:8080/brain_page');
    }

    getAllBladderInformation() {
        console.log("test call");
        return this.httpClient.get<Bladder[]>('http://localhost:8080/bladder_page');
    }

    getAllHeartInformation() {
        console.log("test call");
        return this.httpClient.get<Heart[]>('http://localhost:8080/heart_page');
    }

    getAllKidneysInformation() {
        console.log("test call");
        return this.httpClient.get<Kidneys[]>('http://localhost:8080/kidneys_page');
    }

    getAllLargeIntestinesInformation() {
        console.log("test call");
        return this.httpClient.get<LargeIntestines[]>('http://localhost:8080/large_intestines_page');
    }

    getAllLiverInformation() {
        console.log("test call");
        return this.httpClient.get<Liver[]>('http://localhost:8080/liver_page');
    }

    getAllLungsInformation() {
        console.log("test call");
        return this.httpClient.get<Lungs[]>('http://localhost:8080/lungs_page');
    }

    getAllPancreasInformation() {
        console.log("test call");
        return this.httpClient.get<Pancreas[]>('http://localhost:8080/pancreas_page');
    }

    getAllSmallIntestinesInformation() {
        console.log("test call");
        return this.httpClient.get<SmallIntestines[]>('http://localhost:8080/small_intestines_page');
    }

    getAllSplineInformation() {
        console.log("test call");
        return this.httpClient.get<Spline[]>('http://localhost:8080/spline_page');
    }

    getAllStomachInformation() {
        console.log("test call");
        return this.httpClient.get<Stomach[]>('http://localhost:8080/stomach_page');
    }
}