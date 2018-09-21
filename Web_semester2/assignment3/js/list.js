// BO DAI, 132954173, June22,2018

var fruits = [ "Apples","Oranges","Pears","Grapes","Pineapples","Mangos" ];

var directory = [
    {type: "file", name: "file1.txt"},
    {type: "file", name: "file2.txt"},
    {type: "directory", name: "HTML Files", files: [{type: "file", name: "file1.html"},{type: "file", name: "file2.html"}]},
    {type: "file", name: "file3.txt"},
    {type: "directory", name: "JavaScript Files", files: [{type: "file", name: "file1.js"},{type: "file", name: "file2.js"},{type: "file", name: "file3.js"}]}
];

window.onload=function(){
    var myContainer=document.querySelector("#outputcontainer");
    var orderlist="<ol>"
    for (var i=0;i<fruits.length;i++){
        orderlist+="<li>"+fruits[i]+"</li>";
    }
    myContainer.innerHTML+=orderlist+"</ol>";
    var newContainer=document.querySelector("#directcontainer");
    var unorderlist="<ul>";
    for (var i=0;i<directory.length;i++){
        unorderlist+="<li>"+directory[i].name;
        if(directory[i].type=="directory") {
            unorderlist+="<ul>";
            for(var t=0; t<directory[i].files.length; t++)
                {unorderlist +="<li>"+directory[i].files[t].name+"</li>";}
            unorderlist+="</ul>";
        } 
        unorderlist+="</li>";
    }
    newContainer.innerHTML+=unorderlist+"</ul>";
};

    