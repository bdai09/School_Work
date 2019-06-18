import React, { Component } from 'react';
//import MultiSelectBar from './MultiSelectBar';
import Select from 'react-select';
import { getAllEmployees, getProjects,getTeamLead,getTeamProjects,getTeamsEmployees} from "../src/dataService";   
import axios from 'axios';
  
class Panel extends Component {
    constructor(props){
        super(props);
        this.state={
            changeInfo:false,
            TeamLead:[], 
            TeamMembers:[], //members only for this team
            TeamProjects:[], //projects for specific team
            employees:[],  //store all employees
            projects:[] //store all projects
        }
        this.handleLeadChange = this.handleLeadChange.bind(this);
        this.handleMemChange = this.handleMemChange.bind(this);
        this.handleProChange = this.handleProChange.bind(this);
        this.handleSave = this.handleSave.bind(this);
        
      }
    
    componentDidMount(){
        // axios.get("https://agile-river-17555.herokuapp.com/employees")
        // .then((res)=>{
        //     const employees=res.data;
        //     console.log(employees);
        //     //deal with all employees drop down list
        //      const storeEmps=employees.map(employee=>({
        //             value:employee._id,
        //             label:employee.FirstName+" "+employee.LastName,
        //          } ) );
             
        //   this.setState({
        //     employees:storeEmps
        //    });
           
        //    //deal with selected employees for the team
        //    let validEmps=this.props.TeamEmps;   
        //     const members=storeEmps.filter(emp=> validEmps.find(empId=>empId===emp.value));
        //     this.setState({
        //             TeamMembers:members
        //     });
        //     console.log(this.state.TeamMembers);

        //     //deal with team lead
        //     let lead=this.props.TeamLead;
        //     const leadFull=storeEmps.filter(emp=> lead===emp.value);
        //    leadtry=leadFull;
        //     this.setState({
        //         TeamLead:leadFull
            
        //        });
        //        console.log(this.state.TeamLead);
        // }).catch((e)=>console.log("employees error!"));

        

    //    //projects:
    //    axios.get("https://agile-river-17555.herokuapp.com/projects")
    //     .then((res)=>{
    //         const projects=res.data;
    //         console.log(projects);
    //          console.log(this.props.TeamProjects);
    //          let validPros=this.props.TeamProjects;
    //          const allpros=projects.map(project=>({
    //             value:project._id,
    //             label:project.ProjectName,
    //             } )); 
        
    //             this.setState({
    //                 projects:allpros
    //                });
        
    //          const teampro=projects.filter(project=>validPros.find(proId=>proId===project._id)             
    //              ).map(project=>({
    //                 value:project._id,
    //                 label:project.ProjectName,
    //                 } )); 
                 
    //       this.setState({
    //         TeamProjects:teampro
    //        });
    //        console.log(this.state.TeamProjects[0]);
    //     }).catch((e)=>console.log("Projects error!"));

    //   }
      


          this.setState({
            employees:getAllEmployees(),
            TeamMembers: getTeamsEmployees(this.props.TeamEmps),
            TeamLead:getTeamLead(this.props.TeamLead),
            projects:getProjects(),  
            TeamProjects:getTeamProjects(this.props.TeamProjects)
           });
      }
      handleLeadChange(value){
          this.setState({
              TeamLead:value,
              changeInfo:true,
        });
      }

      handleProChange(value){
        this.setState({
            TeamProjects:value,
            changeInfo:true,
      });
    }

    handleMemChange(value){
        this.setState({
            TeamMembers:value,
            changeInfo:true,
      });
    }


      handleSave(event){
          event.preventDefault();

          let url="https://agile-river-17555.herokuapp.com/team/"+ this.props.TeamId;
        axios({
            method:'put',
            url:url,
            data:{ 
                TeamName: this.props.title,
                TeamLead: this.state.TeamLead.value,
                Projects: this.state.TeamProjects.map(project => project.value),
                Employees:this.state.TeamMembers.map(member => member.value)
            },
            config: {headers: {'Content-type' : 'application/json'}}
        })
        .then(res=>{
            if(res.status===200)
            console.log("Update Success");
        })
        .then(alert("Team: "+ this.props.title+" has been updated"))
        .catch((e)=>console.log(e));

      }
            
    render() {          

        return (
            <div className="panel panel-default">
                <div className="panel-heading">
                    <span className="panel-title">{this.props.title}</span>
                    <span ><button className="btn btn-primary pull-right" onClick={this.handleSave}>SAVE</button>
                </span>
                </div>
                <div className="panel-body">

                  <p>Team Lead</p>
                 <Select 
                 onChange={this.handleLeadChange}
                 closeMenuOnSelect={false}
                 defaultValue={this.state.TeamLead}
                 className="SingleSelect"
                 options={this.state.employees}  
                    />

                  <p>Team Members</p>
                  <Select options={this.state.employees}
                  onChange={this.handleMemChange}
                  closeMenuOnSelect={false}
                  isMulti
                  className="MultiSelect"
                   defaultValue={this.state.TeamMembers}/>
                  
                  <p>Projects</p>
                  <Select 
                  onChange={this.handleProChange}
                   options={this.state.projects}
                   closeMenuOnSelect={false}
                   className="MultiSelect"
                   {...console.log(this.state.TeamProjects[0])}
                   defaultValue={this.state.TeamProjects}
                   isMulti  
                      
                  />
                </div>
            </div>
        );
    }
}

export default Panel;
