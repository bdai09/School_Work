/*********************
* Task1
**********************/
var stuname="Bo", numcourse=5, program="CPA", partjob=true;
var answer="";
console.log("My name is "+ stuname + " and I'm in " + program + 
            " program. I'm taking " + numcourse+ " course in this semester.");
if (partjob==true)
  answer = "have";
else
  answer = "don't have";
console.log("My name is "+ stuname + " and I'm in " + program + 
            " program. I'm taking " + numcourse+ " course in this semester and I "
           +answer + " a part-time job now." );
/*********************
* Task2
**********************/
var curryear=2018;
var age = prompt("Please enter your age:");
console.log("You were born in the year of "+ (curryear-age)+".");
var collegeyear = prompt("Enter the number of years you expect to study in the college:");
console.log("You will graduate from Seneca college in the year of "+ (curryear+ parseInt(collegeyear))+".");
/*********************
* Task3
**********************/
var Celtem= prompt("Celsius temperature:"); //store Celsius temperature in Celtem
console.log(Celtem + "°C is "+(Celtem * 9/5 + 32)+"°F.");
var Fahtem= prompt("Fahrenheit temperature:");
console.log(Fahtem +"°F is "+ ((Fahtem -32) * 5/9)+ "°C.");
/*********************
* Task4
**********************/
for(var i=0; i<=10; i++) {
  if (i%2==0)
    console.log(i+" is odd.");
  else
    console.log(i+" is even.");
}
/*********************
* Task5
**********************/
function largerNum(num1, num2) {
  var larger=( num1>=num2)? num1: num2;
  return "The larger number of "+num1+" and "+num2+" is "+ larger+".";
}
var greaterNum= function(num1, num2){
  var greater=( num1>=num2)? num1: num2;
  return "The larger number of "+num1+" and "+num2+" is "+ greater+".";
};
console.log(largerNum(5, 12));
console.log(largerNum(10, 12));
console.log(greaterNum(3, 7));
console.log(greaterNum(2, 18));
/*********************
* Task6
**********************/
function Evaluator(){
  var sum=0;
  for(var i=0; i<arguments.length; i++){
    sum=sum+arguments[i];
  }
  var average= sum/(i-1);
  if (average>= 50)
    return "Average greater than or equal to 50:"+true;
  else
    return "Average greater than or equal to 50:"+false;
}
console.log(Evaluator(1,2,3,4,5));
console.log(Evaluator(13,12,44));
console.log(Evaluator(100,23,322,400));

/*********************
* Task7
**********************/
var Grader= function(score){
  var grade;
  if (score >= 90)
    grade='A+';
  else if (score >= 80)
    grade='A';
  else if (score >= 70)
    grade='B';
  else if (score >= 60)
    grade='C';
  else if (score >= 50)
    grade='D';
  else
    grade="F";
  return "Your grade: " + grade;
};
console.log(Grader(47));
console.log(Grader(87));
console.log(Grader(97));

/*********************
* Task8
**********************/
function showMultiples(num, numMultiples){
  for(var i=1; i<=numMultiples; i++){
    console.log(num +" x "+i+" = "+ num*i );
  }  
}
console.log(showMultiples(2,4));
console.log(showMultiples(5,4));
console.log(showMultiples(10,3));

