import React, { Component } from 'react';
import Header from './Header.js';
import { getProjects } from "../dataService.js";
import './Projects.css';

class Projects extends Component{
    constructor(props){
        super(props);
        this.state = {
            projects:[]
        };
    }

    componentDidMount(){
        getProjects()
        .then(data => this.setState({projects : data}))
        .catch(err => {console.log(err); })
    }

    render(){
        return (
            <div>
                <Header title="All Projects page"></Header>
                <div className="container-fluid">
                    <div className="row">
                        {this.state.projects.map((project) =>
                            <div key={project._id} className="col-md-4">
                                <div className="panel panel-default fixed-panel" >
                                    <div className="panel-heading">
                                        <h3 className="panel-title">{project.ProjectName}</h3>
                                    </div>
                                    <div className="panel-body">
                                        <p><b>ID:</b> {project._id}</p>
                                        <p><b>Description:</b> {project.ProjectDescription}</p>
                                        <p><b>Start Date:</b> {project.ProjectStartDate ? project.ProjectStartDate : 'NA'}</p>
                                        <p><b>End Date:</b> {project.ProjectEndDate ? project.ProjectEndDate : 'NA'}</p>
                                    </div>
                                </div>
                            </div>)}
                    </div>
                </div> 
            </div>

            
        )
    }
}

export default Projects;