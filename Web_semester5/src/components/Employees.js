import React, { Component } from 'react';
import Header from './Header.js';
import { getEmployees } from "../dataService.js";
import './Employees.css';

class Employees extends Component{
    constructor(props){
        super(props);
        this.state = {
            employees:[]
        };
    }

    componentDidMount(){
        getEmployees()
        .then(data => this.setState({employees : data}))
        .catch(err => {console.log(err); })
    }

    render(){
        return (
            <div>
                <Header title="All Employees page"></Header>
                <div className="container-fluid">
                    <div className="row">
                        {this.state.employees.map((employee) =>
                            <div key={employee._id} className="col-md-4">
                                <div className="panel panel-default fixed-panel" >
                                    <div className="panel-heading">
                                        <h3 className="panel-title">{employee.FirstName + ' ' + employee.LastName}</h3>
                                    </div>
                                    <div className="panel-body">
                                        <p><b>ID:</b> {employee._id}</p>
                                        <p><b>Address:</b> {employee.AddressStreet+', '+employee.AddressCity+', '+employee.AddressState+' '+employee.AddressZip}</p>
                                        <p><b>Phone:</b> {employee.PhoneBun+' '+employee.Extension}</p>
                                        <p><b>Position ID:</b> {employee.Position._id}</p>
                                        <p><b>Position Name:</b> {employee.Position.PositionName}</p>
                                        <p><b>Position Description:</b> {employee.Position.PositionDescription}</p>
                                        <p><b>Salary:</b> {employee.Position.PositionBaseSalary}</p>
                                        <p><b>HireDate:</b> {employee.HireDate}</p>
                                        <p><b>Salary Bonus:</b> {employee.SalaryBonus}</p>
                                    </div>
                                </div>
                            </div>)}
                    </div>
                </div> 
            </div>

            
        )
    }
}

export default Employees;