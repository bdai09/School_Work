import React, { Component } from 'react';
import { getTeams } from '../dataService.js';
import Header from './Header.js';
import './Team.css'; 

class Team extends Component{
    constructor(props){
        super(props);
        this.state = {
            teams:[],
            teamId : this.props.id.substr(1)
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
                <Header title={'You just updated: Team ' + this.state.teamId} />
                <div className="container-fluid">
                    <div className="row">
                        {this.state.teams.map((team) =>  team._id===this.state.teamId &&
                            <div key={team._id} className="col-md-4">
                                <div className="panel panel-default fixed-panel" >
                                    <div className="panel-heading">
                                        <h3 className="panel-title">{team.TeamName}</h3>
                                    </div>
                                    <div className="panel-body">
                                        <p><b>Team Lead: </b>{team.TeamLead._id}</p>
                                        <p><b>Team Projects: </b></p>
                                        {team.Projects ? team.Projects.map((proj) => 
                                            <p key={proj._id}>{proj._id}</p>) : null}
                                        <p><b>Team Employees: </b></p>
                                        {team.Employees ? team.Employees.map((emp) => 
                                            <p key={emp._id}>{emp._id}</p>) : null}
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

export default Team;