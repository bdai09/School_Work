/*********************************************************************************
* WEB422 – Assignment 1
* I declare that this assignment is my own work in accordance with Seneca Academic
Policy.
* No part of this assignment has been copied manually or electronically from any
other source
* (including web sites) or distributed to other students.
*
* Name: ____Bo Dai_____ Student ID: ___132954173_____ Date: _May14,2019______
*
*
********************************************************************************/

$(function(){
 //Handler for .ready() called.
console.log("jQuery working"); 

$("#teams-menu").on("click",function(event){
    event.preventDefault();
    $.get("https://agile-river-17555.herokuapp.com/teams")
    .done(function(data){
        $("#data").empty()
        .append("<h3>Teams</h3>")
        .append(JSON.stringify(prettyPrintJson.toHtml(data)));
    });
});

$("#employees-menu").on("click",function(event){
    event.preventDefault();
    $.get("https://agile-river-17555.herokuapp.com/employees")
    .done(function(data){
        $("#data").empty()
        .append("<h3>Employees</h3>")
        .append(JSON.stringify(prettyPrintJson.toHtml(data)));
    });
});
$("#projects-menu").on("click",function(event){
    event.preventDefault();
    $.get("https://agile-river-17555.herokuapp.com/projects")
    .done(function(data){
        $("#data").empty()
        .append("<h3>Projects</h3>")
        .append(JSON.stringify(prettyPrintJson.toHtml(data)));
    });
});
$("#positions-menu").on("click",function(event){
    event.preventDefault();
    $.get("https://agile-river-17555.herokuapp.com/positions")
    .done(function(data){
        $("#data").empty()
        .append("<h3>Positions</h3>")
        .append(prettyPrintJson.toHtml(JSON.stringify(data)));
    });
});
});
