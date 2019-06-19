import React, { Component } from 'react';
import { getTeams } from '../dataService.js';
import Header from './Header.js';
import './TeamsRaw.css'; 

class TeamsRaw extends Component{
    constructor(props){
        super(props);
        this.state = {
            teams:[],
        }
    }

    componentDidMount(){
        getTeams()
        .then(data => this.setState({teams : data}))
        .catch(err => {console.log(err); })
    }
        

    render(){
        return(
            <div>
                <Header title="Teams Raw Data" />
                <div className="container-fluid">
                    <div className="row">
                        {this.state.teams.map((team) =>  
                            <div key={team._id} className="col-md-4">
                                <div className="panel panel-default fixed-panel" >
                                    <div className="panel-heading">
                                        <h3 className="panel-title">{team.TeamName}</h3>
                                    </div>
                                    <div className="panel-body">
                                        <p><b>Team ID: </b>{team._id}</p>
                                        <p><b>Team Projects ID: </b></p>
                                        {team.Projects.map((proj) => 
                                            <p>{proj._id}</p>)}
                                        <p><b>Team Employees ID: </b></p>
                                        {team.Employees.map((emp) => 
                                            <p>{emp._id}</p>)}
                                    </div>
                                </div>
                            </div>
                        )}
                    </div>
                </div>
            </div>
        )
    }
}

export default TeamsRaw;