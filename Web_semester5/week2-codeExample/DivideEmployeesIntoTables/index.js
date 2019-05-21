// Import all the necessary modules we'll use,
// picking only the bits we care about vs. the entire thing.
const {
    map,
    pick,
    forEach,
    filter,
    chunk,
    shuffle
} = require('lodash');
const $ = require('jquery');
const moment = require('moment');

//Or
//import {map,pick, forEach,filter,chunk,shuffle} from 'lodash'


/**
 * Given an Array of Tables (Arrays of 5 Employees per Table), format
 * them into the following HTML and display:
 * 
 * <div>
 *   <h2>Table 1</h2>
 *   <ul>
 *     <li>FirstName LastName</li>
 *     ...
 *   </ul>
 * </div>
 */
const displayTables = tables => {
    forEach(tables, function(table, index) {
        const tableDiv = $(`<div><h2>Table ${index + 1}</h2></div>`);
        const ul = $('<ul></ul>');

        forEach(table, function(employee) {
            const li = $(`<li>${employee.FirstName} ${employee.LastName} (${employee.yearsWorked})</li>`);
            ul.append(li);
        });

        tableDiv.append(ul);
        $('#employee-tables').append(tableDiv);
    });
};

/**
 * Given all employees, calculate how long each has been working for the
 * company, filter the list to find all who have 8 or more years of
 * service, shuffle that array to randomize it, create tables of 5
 * people for a seating plan at a dinner.  Display each table
 * in the web page.
 */
const generateTables = employees => {

    const processedEmployees = map(employees, employee => {
        const modifiedEmployee = pick(employee, ['FirstName', 'LastName', 'HireDate']);

        const years = moment().diff(employee.HireDate, 'years');
        modifiedEmployee.yearsWorked = years;

        return modifiedEmployee;
    });
    const eightOrMore = filter(processedEmployees, employee => employee.yearsWorked >= 8);
    const shuffled = shuffle(eightOrMore);
    const tables = chunk(shuffled, 5);

    return tables;
}

// Get all Employees from our web service using jQuery's ajax() function
$(() => {
    $.ajax({
        // Swap this for your own 
        url: 'https://quiet-wave-16481.herokuapp.com/employees',
        // Define our data type to be JSON, so it will get parsed for us
        //default is GET, so didnt write type: GET
        dataType: 'json'
    })
    .done(employees => {
        const tables = generateTables(employees);
        displayTables(tables);
    })
    .fail(function() {
        console.log('it failed');
    });
});
