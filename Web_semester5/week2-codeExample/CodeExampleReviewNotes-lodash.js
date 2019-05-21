$(function(){

    // simple data for testing

let users = [
    { 'user': 'fred',    'active': false, 'age': 40 },
    { 'user': 'pebbles', 'active': false, 'age': 1  },
    { 'user': 'barney',  'active': true,  'age': 36 }
];
    // Lodash "Array" methods

        // chunk: https://lodash.com/docs/4.17.4#chunk
        let chunk1 = _.chunk(['a', 'b', 'c', 'd'], 2); // => [['a', 'b'], ['c', 'd']] 
        let chunk3 = _.chunk(users, 2); // objects for [['fred', 'pebbles'], 'barney']

        // findIndex: https://lodash.com/docs/4.17.4#findIndex / see also: https://lodash.com/docs/4.17.4#findLastIndex and https://lodash.com/docs/4.17.4#find
        let findIndex1 = _.findIndex(users, function(user) { 
            return user.user == 'fred'; 
        }); // => 0

        // take: https://lodash.com/docs/4.17.4#take
        let take1 = _.take(users,2) // => objects for ['fred, pebbles']

    // Lodash "Collection" methods

        let filter1 = _.filter(users, function(user) {
            return user.active == true;
        }); // => objects for ['barney']

        // sortby
        let sortBy1 = _.sortBy(users, [
            function(user) { 
                return user.user; 
            }
        ]); // => objects for ['barney', 'fred', 'pebbles']

        // forEachRight
        let forEachRight1 = [];
        _.forEachRight(users, function(user) {
            forEachRight1.push(user);
        }); // iterates as ['barney', 'pebbles', 'fred']
        
    // Lodash "Number" methods

        // random
        let random1 = _.random(0, 5); // => an integer between 0 and 5
        let random2 = _.random(5); // => also an integer between 0 and 5
        let random3 = _.random(5, true); // => a floating-point number between 0 and 5
        let random4 = _.random(1.2, 5.2);// => a floating-point number between 1.2 and 5.2

    // Lodash "Object" methods
        // cloneDeep
        let cloneDeep1 = _.cloneDeep(users); // cloneDeep1[0] !== users[0]
        
        // pick
        let pick1 = _.pick(users[0], ['user', 'age']); // => { 'user': 'fred', 'age': 40 } // note: pick !== users[0]

    // Lodash "String" methods

        // escape
        let escape1 = _.escape('fred, barney, & pebbles'); // => 'fred, barney, &amp; pebbles'

        // template      
        // Use the "interpolate" delimiter to create a compiled template.
        let template1 = _.template('hello <%= user %>!');
        let template1Result = template1({ 'user': users[0].user });  // => 'hello fred!'
        
        // Use the HTML "escape" delimiter to escape data property values.
        let template2 = _.template('<b><%- value %></b>');
        let template22Result = template2({ 'value': '<script>' }); // => '<b>&lt;script&gt;</b>'

        // Use the "evaluate" delimiter to execute JavaScript and generate HTML.
        let template3 = _.template('<ul>' + 
                                        '<% _.forEach(users, function(user) { %>' +
                                            '<li><%- user %></li>' + 
                                        '<% }); %>' +
                                    '</ul>');

        let template3Result = template3({ 'users': ['fred', 'barney'] }); // => '<ul><li>fred</li><li>barney</li></ul>'

        // Use the "evaluate" delimiter to execute JavaScript and generate HTML from our "users" collection.
        let template4 = _.template('<ul>' + 
                                        '<% _.forEach(users, function(user) { %>' + 
                                            '<li><%- user.user %></li>' + 
                                        '<% }); %>' + 
                                    '</ul>');

        let template4Result = template4({ 'users': users }); // => '<ul><li>fred</li><li>pebbles</li><li>barney</li></ul>'

});

//file2

// define the "row" template
let rowTemplate = _.template('<% _.forEach(employees, function(employee) { %>' +
                                '<tr>' + 
                                    '<td><%- employee.FirstName %></td>' + 
                                    '<td><%- employee.LastName %></td>' + 
                                    '<td><%- employee.Position.PositionName %></td>' + 
                                '</tr>' +
                            '<% }); %>');

let allEmployees; // define "allEmployees" as global to this file
let tbody; // define "tbody" as global to this file


// utility function to add rows to tbody
function addRows(pgNum){
    let rows = rowTemplate({ 'employees': _.chunk(allEmployees,5)[pgNum]});  //!!!!!page number, options
    tbody.empty();
    tbody.append(rows);
}

$(function() { 

    // store a reference to $("#employees-table body")
    tbody = $("#employees-table tbody");

    $.ajax({
        url: "your teams api url/employees", // change "your teams api url" to your Teams API url on Heroku
        type: "GET",
        //data: JSON.stringify({ some: "data" }), // we can also send data using the "data" option
        contentType: "application/json"
    })
    .done(function (employees) {
        // only grab the first 15 employees
        allEmployees = _.take(employees,15);
        addRows(0); // show rows from page 0
    })
    .fail(function (err) {
        console.log("error: " + err.statusText);
    });

    // wire up the 3 preset "paging" buttons
    
    $("#pg1").on("click", function () {
        addRows(0); // show rows from page 0
    });

    $("#pg2").on("click", function () {
        addRows(1);  // show rows from page 1
    });

    $("#pg3").on("click", function () {
        addRows(2); // show rows from page 0
    });

    // wire up the filter headings

    $("#first-name-heading").on("click", function(){
        allEmployees = _.sortBy(allEmployees, [
            function(employee) { 
                return employee.FirstName; 
            }
        ]);
        addRows(0); // show rows from page 0
    });

    $("#last-name-heading").on("click", function(){
        allEmployees = _.sortBy(allEmployees, [
            function(employee) { 
                return employee.LastName; 
            }
        ]);
        addRows(0); // show rows from page 0
    });

    $("#position-heading").on("click", function(){
        allEmployees = _.sortBy(allEmployees, [
            function(employee) { 
                return employee.Position.PositionName; 
            }
        ]);
        addRows(0); // show rows from page 0
    });

});