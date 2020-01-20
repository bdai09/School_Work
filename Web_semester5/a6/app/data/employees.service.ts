import { Injectable } from '@angular/core';
import { Observable } from "rxjs";
import { HttpClient } from "@angular/common/http"
import { Employee } from './employees';
import { EmployeeRaw } from './employeeRaw';

@Injectable()
export class EmployeeService {

  private url = "https://agile-river-17555.herokuapp.com";

  constructor(private http: HttpClient) { }

  getEmployees(): Observable<Employee[]> {
    return this.http.get<Employee[]>(this.url + '/employees')
  }

  saveEmployee(employee: EmployeeRaw): Observable<any> {
    return this.http.put<any>(this.url + '/employee/' + employee._id, employee);
  }

  getEmployee(id): Observable<EmployeeRaw[]> {
    return this.http.get<EmployeeRaw[]>(this.url + '/employee-raw/' + id);
  }
}