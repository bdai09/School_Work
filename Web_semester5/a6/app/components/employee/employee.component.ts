import { Component, OnInit, OnDestroy } from '@angular/core';
import { ActivatedRoute } from '@angular/router';
import { EmployeeRaw } from '../../data/employeeRaw';
import { EmployeeService } from '../../data/employees.service';
import { PositionService } from '../../data/position.service';
import { Position } from '../../data/positions';

@Component({
  selector: 'app-employee',
  templateUrl: './employee.component.html',
  styleUrls: ['./employee.component.css']
})
export class EmployeeComponent implements OnInit, OnDestroy {

  paramSubScription: any;
  employeeSubscription: any;
  getPositionsSubcription: any;
  saveEmployeeSubscription: any;
  employee: EmployeeRaw;
  positions: Position[];
  successMessage = false;
  failMessage = false;

  constructor(private employeeService: EmployeeService, private activeRoute: ActivatedRoute, private positionService: PositionService) { }

  ngOnInit() {
    this.paramSubScription = this.activeRoute.params.subscribe((params) => {
      this.employeeSubscription = this.employeeService.getEmployee(params['_id'])
        .subscribe((employee) => { this.employee = employee[0]; });

      this.getPositionsSubcription = this.positionService.getPositions()
        .subscribe(position => { this.positions = position; });
    });
  }

  onSubmit() {
    this.saveEmployeeSubscription = this.employeeService.saveEmployee(this.employee)
      .subscribe(() => {
        this.successMessage = true;
        setTimeout(() => {
          this.successMessage = false;
        }, 2500);
      },
        () => {
          this.failMessage = true;
          setTimeout(() => {
            this.failMessage = false;
          }, 2500);
        });
  }

  ngOnDestroy() {
    if (this.paramSubScription) { this.paramSubScription.unsubscribe(); }
    if (this.employeeSubscription) { this.employeeSubscription.unsubscribe(); }
    if (this.getPositionsSubcription) { this.getPositionsSubcription.unsubscribe(); }
    if (this.saveEmployeeSubscription) { this.saveEmployeeSubscription.unsubscribe(); }
  }
}