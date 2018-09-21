/********************************************************************************* 
*
* WEB222 – Assignment #4a
*
* I declare that this assignment is my own work in accordance with Seneca 
* Academic Policy. No part of this assignment has been copied manually or 
* electronically from any other source (including web sites) or distributed to 
* other students. 
* 
* Name: ___Bo Dai_________ Student ID: _132954173_____ Date: ___July14, 2018_______ 
* 
********************************************************************************/
var filterType = ""; // sets the filter type to "" (will later be dog, cat or bird)
var filterAgeMin = 0; // sets the filter age min to 0 (for no minimum age filter)
var filterAgeMax = Number.MAX_VALUE; // sets the filter age max to the largest number possible (for no maximum age filter)

window.onload=loadTableWithFilters;
function loadTableWithFilters(){
    var elem=document.querySelector("#main-table-body");
    elem.innerHTML="";
    for(var i=0;i<petData.length;i++){
        if((filterType==""||petData[i].type==filterType)&& petData[i].age<=filterAgeMax
             && petData[i].age>=filterAgeMin){
                 var tabletr=document.createElement("tr");
                 var tabletd=document.createElement("td");
                 var tableimg=document.createElement("img");
                 tableimg.src=petData[i].image.src;
                 tableimg.alt=petData[i].image.alt;
                 tableimg.height=petData[i].image.height;
                 tableimg.width=petData[i].image.width;
                 tabletd.appendChild(tableimg);

                 var tabletd2=document.createElement("td");
                 var tablehead=document.createElement("h4");
                 var content=document.createTextNode(petData[i].name);
                 tablehead.appendChild(content);
                 tabletd2.appendChild(tablehead);
                 var tablepara=document.createElement("p");
                 tablepara.innerHTML=petData[i].description;
                 tabletd2.appendChild(tablepara);
                 var tablespan=document.createElement("span");
                 tablespan.appendChild(document.createTextNode("Age: "+
                 petData[i].age+" years old."));
                 tabletd2.appendChild(tablespan);
                 tabletr.appendChild(tabletd);
                 tabletr.appendChild(tabletd2);
                 elem.appendChild(tabletr);
             }
    }
 
}
/*select all pets*/
function filterAllPets(){
    filterType="";
    filterAgeMin=0;
    filterAgeMax=Number.MAX_VALUE;
    loadTableWithFilters();
}
/*select dogs*/
function filterDog(){
    filterType="dog";
    loadTableWithFilters();
}
/*filter cats*/
function filterCat(){
    filterType="cat";
    loadTableWithFilters();
}
/*select all birds*/
function filterBird(){
    filterType="bird";
    loadTableWithFilters();
}
/*select all pets age 0-1*/
function filter_zero_1(){
    filterType="";
    filterAgeMin=0;
    filterAgeMax=1
    loadTableWithFilters();
}
/*select pets age 1 to 3*/
function filter_1_3(){
    filterType="";
    filterAgeMin=1;
    filterAgeMax=3;
    loadTableWithFilters();
}
/*select pets older than 4*/
function filter_4_plus(){
    filterType="";
    filterAgeMin=4;
    filterAgeMax=Number.MAX_VALUE;
    loadTableWithFilters();
}
