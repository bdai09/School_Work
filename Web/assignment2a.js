/*********************************************************************************
* WEB222 – Assignment 02
* Name: ___Bo Dai_____ Date: _June04, 2018_________
*
********************************************************************************/

/*****************************
* Step 1
*****************************/
var e1,e2, e3, e4, e5, e6, e7, str;

/*****************************
* Step 2
*****************************/
function capFirstLetter(strtype){
    var newstr=(strtype.charAt(0)).toUpperCase();
    newstr+= (strtype.substr(1,(strtype.length-1))).toLowerCase();
    return newstr;
}
e1=prompt("Please enter first name:", "bo");
e1=capFirstLetter(e1);
console.log(e1);

/*****************************
* Step 3
*****************************/
var getAge=function(num) {
    var today=new Date();
    var calage=today.getFullYear()-num;
    return calage;
}
e2=prompt("Please enter the year of your birth day:", 1990);
e2=getAge(e2);
console.log(e2);
/*****************************
* Step 4
*****************************/
e3=prompt("Please enter the college name you are attending:", "seneca college");
var myArray1=e3.split(' ');
var newmyArray=capFirstLetter(myArray1[0]);
for(var i=1; i<myArray1.length; i++){
   newmyArray= newmyArray+" "+ capFirstLetter(myArray1[i]);
}
e3=newmyArray;
console.log(e3);
/*****************************
* Step 5
*****************************/
e4=prompt("Please enter 5 favorite sports(in lower case separated by comma):", 
          "hockey,football,basketball,tennis,golf");
e4=e4.replace(/football/g, "soccer");
e4=e4.split(',');
e5=prompt("Please enter an extra favorite sport:", "formula 1");
e4.push(e5);
console.log(e4);
/*****************************
* Step 6
*****************************/
e4=((e4.join()).toUpperCase()).split(',');
console.log(e4.sort());
/*****************************
* Step 7
*****************************/
function getDateString(Dateobj) {
   var month=Dateobj.getMonth()+1;
   var date=Dateobj.getDate();
   month= (month < 10)? ("0"+month): month; 
   date=(date<10)?("0"+date):date;
   var datestring=Dateobj.getFullYear()+"-"+month+"-"+date;
   return datestring;
}
e6= new Date();
e7=getDateString(e6);
console.log(e7);  
/*****************************
* Step 8
*****************************/
str="User info:\n\n"+"name (e1): "+e1+"\n"+"age (e2): "+e2+"\n"+
    "school (e3): "+e3+"\n"+"favorite sports (e4):\n\t"+ e4[0]+"\n\t"+
    e4[1]+"\n\t"+e4[2]+"\n\t"+e4[3]+"\n\t"+e4[4]+"\n\t"+
    e4[5]+"\n"+"current date (e7): "+e7;
console.log(str);


