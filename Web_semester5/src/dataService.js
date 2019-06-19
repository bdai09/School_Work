export function getTeams() {
    const teamsUrl = "https://mighty-wildwood-35586.herokuapp.com/teams";
    return fetch(teamsUrl)
      .then(res => {
        if (!res.ok) {
          throw new Error(res.statusText);
        }
        return res.json();
      })
      .then(function(data) {
          return data;
      });
  }

  export function getEmployees() {
    const employeesUrl = "https://mighty-wildwood-35586.herokuapp.com/employees";
    return fetch(employeesUrl)
      .then(res => {
        if (!res.ok) {
          throw new Error(res.statusText);
        }
        return res.json();
      })
      .then(function(data) {
        return data;
      });
  }
  
  export function getProjects() {
    const projectsUrl = "https://mighty-wildwood-35586.herokuapp.com/projects";
    return fetch(projectsUrl)
      .then(res => {
        if (!res.ok) {
          throw new Error(res.statusText);
        }
        return res.json();
      })
      .then(function(data) {
        return data;
    });
  }
  
  export default { getTeams, getEmployees, getProjects };
  