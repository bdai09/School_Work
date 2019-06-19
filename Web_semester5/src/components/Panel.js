import React, { Component } from 'react';
import Select from 'react-select';
import './Panel.css';


class Panel extends Component {
    constructor(props){
        super(props);

        this.state = {
            ifChange : false,
            leadValue: this.props.team.TeamLead._id,
            teamMembers: this.props.team.Employees ? (this.props.team.Employees.map((emp) => emp._id)) : null,
            teamProjects: this.props.team.Projects ? (this.props.team.Projects.map((proj) => proj._id)) : null,
            team:this.props.team,
            title : this.props.title,
            teamId : this.props.teamId,
            teams : this.props.teams,
            employees : this.props.employees,
            projects : this.props.projects
        };

        this.handleTLeadChange = this.handleTLeadChange.bind(this);
        this.handleTMemChange = this.handleTMemChange.bind(this);
        this.handleTProjChange = this.handleTProjChange.bind(this);
        this.handleSubmit = this.handleSubmit.bind(this);
    }

    handleTLeadChange (selectedOption){
        this.setState({leadValue : selectedOption});
        this.setState({ifChange : true});
    }

    handleTMemChange (selectedOption) {
        this.setState({teamMembers : selectedOption});
        this.setState({ifChange : true});
    }

    handleTProjChange (selectedOption) {
        this.setState({teamProjects : selectedOption});
        this.setState({ifChange : true})
    }

    
    handleSubmit(event){
        event.preventDefault();
        var updateUrl = "https://mighty-wildwood-35586.herokuapp.com/team/"+ this.state.teamId;
        //var targetUrl = '/team/:' + this.state.teamId;
        fetch(updateUrl, {
            method: 'PUT',
            body: JSON.stringify({
                TeamName: this.state.title,
                TeamLead: this.state.leadValue.value,
                Projects: this.state.teamProjects ? this.state.teamProjects.map((teamProject) => teamProject.value) : null,
                Employees: this.state.teamMembers ? this.state.teamMembers.map((teamMember) => teamMember.value) : null
            }),
            headers: {'Content-type' : 'application/json'}
        })
        .then(res => res.json())
        .then(function(data) {
            alert(data.message);
        })
        .catch(err => {console.log(err);})
    }

    render() {
        function extractSingleSelect(team){
            var obj = {value:"", label:""};
            obj.value = team.TeamLead._id;
            obj.label = team.TeamLead.FirstName +' '+ team.TeamLead.LastName;
            return obj;
        }
        //for extracting Employee Options and finding the initially selected team members
        function getEmpOptions(employees) {
            if(employees){
                return employees.map(emp => {
                    var obj = {value:"", label:""};
                    obj.value=emp._id;
                    obj.label=emp.FirstName+' '+emp.LastName;
                    return obj;
                })
            }
            
        }

        //compare employees by name
        function compareEmp(a, b){
            if(a.FirstName < b.FirstName){
                return -1;
            }
            if(a.FirstName > b.FirstName){
                return 1;
            }
            return 0;
        }

        //for extracting Projects Options and finding the initially selected team members
        function getProjOptions(projects) {
            let objs = projects.map(proj => {
                var obj = {value:"", label:""};
                obj.value=proj._id;
                obj.label=proj.ProjectName;
                return obj;
            })
            return objs.sort(compareP);
        }
        
        //get the number value in the label(ProjectName) of each project
        function getProjNum(project){
            let regex = /\d+/g;
            let found = project.label.match(regex).map(Number);
            return found[0];
        }

        //a compare function for sorting the teams by the Number value in the label(ProjectName) of each project
        function compareP(a, b){
            return getProjNum(a) - getProjNum(b);
        }

        return (
            <div className="panel panel-default" >
                    <div className="panel-heading">
                        <h3 className="panel-title">{this.state.title}</h3>
                    </div>
                    <form onSubmit={this.handleSubmit} >
                    
                    <div className="panel-body fixed-panel">
                        <label>Team Lead</label>
                        <br/>
                        <Select
                            onChange = {this.handleTLeadChange}
                            className="basic-single"
                            classNamePrefix="select"
                            defaultValue={extractSingleSelect(this.state.team)}
                            name="leader"
                            options={getEmpOptions(this.state.employees.sort(compareEmp))}
                        />
                        <br/>
                        <label>Team Members</label>
                        <br/>
                        <Select
                            onChange = {this.handleTMemChange}
                            defaultValue={getEmpOptions(this.state.team.Employees ? (this.state.team.Employees.sort(compareEmp)) : null)}
                            isMulti
                            name="members"
                            options={getEmpOptions(this.state.employees ? (this.state.employees.sort(compareEmp)) : null)}
                            className="basic-multi-select"
                            classNamePrefix="select"
                        />
                        <br/>
                        <label>Team Projects</label>
                        <br/>
                        <Select
                            onChange = {this.handleTProjChange}
                            defaultValue={getProjOptions(this.state.team.Projects)}
                            isMulti
                            name="projects"
                            options={getProjOptions(this.state.projects)}
                            className="basic-multi-select"
                            classNamePrefix="select"
                        />
                        <br/>
                        {this.state.ifChange ? (<button type="submit" id="submit_btn" className="btn btn-info">Submit</button>) : 
                                <button type="submit" id="submit_btn" className="btn btn-info" disabled>Submit</button>}
                        
                    </div>
                </form>
            </div>
        );
    }
}

export default Panel;