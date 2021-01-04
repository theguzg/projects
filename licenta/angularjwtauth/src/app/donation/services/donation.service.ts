import { Injectable } from "@angular/core";
import { HttpClient, HttpRequest } from "@angular/common/http";
import { Observable } from "rxjs/Rx";
import { Donation } from "../models/donation";
import 'rxjs/add/operator/map';
import 'rxjs/add/operator/catch';


@Injectable()
export class DonationService {
    constructor(private _httpService: HttpClient) { }

    getAllDonations() {
        return this._httpService.get<Donation[]>("http://localhost:8080/donation");
            // .map((response: any) => response.json())
            // .catch(this.handleError);
    }

    getDonationById(donationId: string): Observable<Donation> {
        return this._httpService.get("http://localhost:8080/donation/" + donationId)
            .map((response: any) => response.json())
            .catch(this.handleError);
    }

    addDonation(donation: Donation) {
        let body = JSON.parse(JSON.stringify(donation));
        // let headers = new Headers({ 'Content-Type': 'application/json' });
        // let options = new HttpRequest("OPTIONS","http://localhost:8080/blood-donation",{ headers: headers });
        // if (donation.id) {
        //     return this._httpService.put("http://localhost:8080/donation/" + donation.id, body);
        // } else {
            return this._httpService.post("http://localhost:8080/add-donation", body);
        // }
    }

    deleteDonation(donationId: string) {
        return this._httpService.delete("http://localhost:8080/donation/" + donationId);
    }

    private handleError(error: Response) {
        return Observable.throw(error);
    }
}