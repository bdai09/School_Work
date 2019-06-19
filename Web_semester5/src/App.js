import React, { Component } from 'react';
import { Route, Switch } from 'react-router-dom';
import Home from './components/Home.js';
import Employees from './components/Employees.js';
import Projects from './components/Projects.js';
import Team from './components/Team.js';
import TeamsRaw from './components/TeamsRaw.js';
import './App.css';

class App extends Component {
  render() {
    return (
      <Switch>
        <Route exact path='/' render={() => (
          <Home />
        )} />
        
        <Route exact path='/teams-raw' render={() => (
          <TeamsRaw />
        )} />

        <Route exact path='/employees' render={() => (
          <Employees />
        )} />

        <Route exact path='/projects' render={() => (
          <Projects />
        )} />

      <Route path='/team/:id' render={(props) => (
          <Team id={props.match.params.id}/>
        )} />
        
        <Route render={() => (
          <h1>Not Found</h1>
        )} />
      </Switch>
    );
  }
}

export default App;
