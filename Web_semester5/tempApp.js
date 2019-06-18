import React, { Component } from 'react';
import './App.css';
import Navbar from './Navbar';
import Panel from './Panel';
import axios from 'axios';

class App extends Component {
  constructor(){
    super();
    this.state={
        Teams:[],     
    }
  }
  componentDidMount(){
    axios.get("https://agile-river-17555.herokuapp.com/teams-raw")
        .then((res)=>{
            const teams=res.data;
         this.setState({
           Teams:teams,
         });
         console.log(this.state.Teams);
        }).catch((e)=>console.log("teams error!"));

  }
  render() {
    return (
      <div>
        <Navbar title="Assignment3 - Team Details"/>   
        <div className="container">
          <div className="row">            
             {this.state.Teams.map(team=>
              <div className="col-md-4">
              <Panel title={team.TeamName} TeamLead={team.TeamLead} TeamId={team._id}
              TeamEmps={team.Employees} TeamProjects={team.Projects}  button="Save"> 
            </Panel>
            </div>
             )}     
                         
          </div>
        </div>
        
      </div>
    );
  }
}

export default App;
