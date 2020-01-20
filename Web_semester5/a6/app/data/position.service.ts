import { Injectable } from '@angular/core';
import { Observable } from "rxjs";
import { HttpClient } from "@angular/common/http"
import { Position } from './positions';

@Injectable()
export class PositionService {

  private url = "https://agile-river-17555.herokuapp.com";

  constructor(private http: HttpClient) { }

  getPositions(): Observable<Position[]> {
    return this.http.get<Position[]>(this.url + "/positions")
  }

  savePosition(position: Position): Observable<any> {
    return this.http.put<any>(this.url + '/position/' + position._id, position);
  }

  getPosition(id: string): Observable<Position[]> {
    return this.http.get<Position[]>(this.url + '/position/' + id);
  }
}
