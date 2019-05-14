$(function(){
 //Handler for .ready() called.
console.log("jQuery working"); 

$("#teams-menu").on("click",function(event){
    event.preventDefault();
    $.get("https://agile-river-17555.herokuapp.com/teams")
    .done(function(data){
        $("#data").empty()
        .append("<h3>Teams</h3>")
        .append(JSON.stringify(data));
    });
});

$("#employees-menu").on("click",function(event){
    event.preventDefault();
    $.get("https://agile-river-17555.herokuapp.com/employees")
    .done(function(data){
        $("#data").empty()
        .append("<h3>Employees</h3>")
        .append(JSON.stringify(data));
    });
});
$("#projects-menu").on("click",function(event){
    event.preventDefault();
    $.get("https://agile-river-17555.herokuapp.com/projects")
    .done(function(data){
        $("#data").empty()
        .append("<h3>Projects</h3>")
        .append(JSON.stringify(data));
    });
});
$("#positions-menu").on("click",function(event){
    event.preventDefault();
    $.get("https://agile-river-17555.herokuapp.com/positions")
    .done(function(data){
        $("#data").empty()
        .append("<h3>Positions</h3>")
        .append(JSON.stringify(data));
    });
});
});
