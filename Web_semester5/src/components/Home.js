import React, { Component } from 'react';
import Header from './Header.js';
import Panel from './Panel.js';
import { getTeams, getEmployees, getProjects} from "../dataService.js";

class Home extends Component {
    constructor(props){
        super(props);
        this.state = {
            teams:[],
            employees:[],
            projects:[]
        };
    }

    componentDidMount(){
        getTeams()
        .then(data => this.setState({teams : data}))
        .catch(err => {console.log(err); })

        getEmployees()
        .then(data => this.setState({employees : data}))
        .catch(err => {console.log(err); })

        getProjects()
        .then(data => this.setState({projects : data}))
        .catch(err => {console.log(err); })
    }

    render() {
        const teams = this.state.teams;

        //get the Number value in the value of TeamName of each team
        function getTeamNum(team){
            let regex = /\d+/g;
            let found = team.TeamName.match(regex).map(Number);
            return found[0];
        }

        //a compare function for sorting the teams by the Number value in the TeamName
        function compare(a, b){
            return getTeamNum(a) - getTeamNum(b);
        }

        //sort the teams
        teams.sort(compare);

        
        return (
            <div>
                <Header title="Assignment 3 - Team Details"/>
                <div className="container-fluid">
                    <div className="row">
                        {teams.map((team) => 
                            <div key={team._id} className="col-md-4">
                                <Panel team={team} title={team.TeamName} teamId={team._id} teams={this.state.teams} employees={this.state.employees} projects={this.state.projects}/>
                            </div>)}
                    </div>
                </div>
            </div>
        );
    }
}

export default Home;