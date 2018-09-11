/*********************************************************************************
* WEB222 – Assignment 02
* I declare that this assignment is my own work in accordance with Seneca Academic Policy. No part of
* this assignment has been copied manually or electronically from any other source (including web sites)
* or distributed to other students.
*
* Name: ___Bo Dai_____ Student ID: __132954173___ Date: _June04, 2018_________
*
********************************************************************************/
// an array of course objects
var courses = [
    { code: 'APC100', name: 'Applied Professional Communications', hours: 3, url: 'http://www.senecacollege.ca/' },
    { code: 'IPC144', name: 'Introduction to Programming Using C', hours: 4, url: 'https://scs.senecac.on.ca/~ipc144/' },
    { code: 'ULI101', name: 'Introduction to Unix/Linux and the Internet', hours: 4, url: 'https://cs.senecac.on.ca/~fac/uli101/live/' },
    { code: 'IOS110', name: 'Introduction to Operating Systems Using Windows', hours: 4, url: 'https://cs.senecac.on.ca/~fac/ios110' },
    { code: 'EAC150', name: 'College English', hours: 3, url: null }
];

// prototype object for creating student objects
var student = { 
    name: "", 
    dob: new Date(),
    sid: "",
    program: "", 
    gpa: 4.0,
    toString: function () {
        return 'Student info for ' + this.name + ': born on ' + this.dob.toLocaleDateString() +
               ', student id ' + this.sid + ', progrem ' + this.program + ', current GPA ' + this.gpa; 
    }
};

/************************************************************
 * Start your Part B code here. Do not change the code above.
 ************************************************************/
// task 1
var delcourse=courses.pop();
console.log("*** Task 1 ***");
console.log("\n");
console.log("Course "+delcourse.code+" was deleted from the array (courses)");
console.log("Adding new courses objects into the array (courses)\n");
var subject={
    code:"",name:"",hours:0, url:""
};
var ibc233=Object.create(subject);
ibc233.code='IBC233';
ibc233.name= 'iSERIES Business Computing';
ibc233.hours= 4;
ibc233.url= 'https://scs.senecac.on.ca/~ibc233/';
var oop244=Object.create(subject);
oop244.code='OOP244';
oop244.name='Introduction to Object Oriented Programming';
oop244.hours= 4;
oop244.url= 'https://scs.senecac.on.ca/~oop244/';
var web222=Object.create(subject);
web222.code='WEB222';
web222.name='Internet I - Internet Fundamentals';
web222.hours= 4;
web222.url= 'https://scs.senecac.on.ca/~web222/';
var dbs201=Object.create(subject);
dbs201.code='DBS201';
dbs201.name='Introduction to Database Design and SQL';
dbs201.hours= 4;
dbs201.url='https://scs.senecac.on.ca/~dbs201/';
courses.push(ibc233, oop244, web222, dbs201);
console.log("\n");
console.log("Course objects in the array (courses):");
for (var x=0; x<courses.length; x++) {
        console.log('"' +courses[x].code+ ", "+ courses[x].name+", "+courses[x].hours
                    +" hours/week, website: "+courses[x].url+'"');
}

// task 2
var stu1=Object.create(student);
stu1.name= "John Smith"; 
stu1.dob=new Date(1999,8,10);
stu1.sid="010456101";
stu1.program= "CPA"; 
stu1.gpa= 4;
var stu2=Object.create(student);
stu2.name= "Jim Carrey"; 
stu2.dob=new Date(1992,0,17);
stu2.sid="012345678";
stu2.program= "CPD"; 
stu2.gpa= 3.5;
var stu3=Object.create(student);
stu3.name= "Justin Bieber"; 
stu3.dob=new Date(1994,2,1);
stu3.sid="0987654321";
stu3.program= "CAN"; 
stu3.gpa= 3;
var stu4=Object.create(student);
stu4.name= "Justin Trudeau"; 
stu4.dob=new Date(1992,0,12);
stu4.sid="123456789";
stu4.program= "CAN"; 
stu4.gpa= 4;
var students=[stu1, stu2, stu3, stu4];
console.log("\n*** Task 2 ***\n");
console.log("Student objects in the array （students):");
function show(item, index){
    console.log(index+": "+ item.toString());
}
students.forEach(show);

