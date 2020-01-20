import { Component, OnInit, OnDestroy } from '@angular/core';
import { Employee } from '../../data/employees';
import { EmployeeService } from '../../data/employees.service';
import { Router } from '@angular/router';


@Component({
  selector: 'app-employees',
  templateUrl: './employees.component.html',
  styleUrls: ['./employees.component.css']
})
export class EmployeesComponent implements OnInit, OnDestroy {
  private employees: Employee[];
  private getEmployeesSub;
  private loadingError: boolean = false;
  private filteredEmployees: Employee[];

  constructor(private e: EmployeeService, private router: Router) { }

  ngOnInit() {
    this.getEmployeesSub = this.e.getEmployees()
      .subscribe(
        employees => {
          this.employees = employees;
          this.filteredEmployees = employees;
        },
        function (e) { this.loadingError = true; }
      );
  }

  routeEmployee(id: string) {
    this.router.navigate(['/employee/', id]);
  }

  onEmployeeSearchKeyUP(event: any) {
    let substring: string = event.target.value.toLowerCase();
    this.filteredEmployees = this.employees.filter((employee) =>
      ((employee.FirstName.toLowerCase().indexOf(substring) != -1) ||
        (employee.LastName.toLowerCase().indexOf(substring) != -1) ||
        (employee.Position["PositionName"].toLowerCase().indexOf(substring) != -1)))

  }


  ngOnDestroy() {
    if (this.getEmployeesSub != 'undefined') {
      this.getEmployeesSub.unsubscribe();
    }
  }
}
