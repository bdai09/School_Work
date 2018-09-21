// BO DAI, 132954173, June22,2018


var users = [
    {first_name: "Kaitlin", last_name: "Burns", age: 23, email: "kburns99753@usermail.com"},
    {first_name: "Joshua", last_name: "Feir", age: 31, email: "josh319726@usermail.com"},
    {first_name: "Stephen", last_name: "Shaw", age: 28, email: "steve.shaw47628@usermail.com"},
    {first_name: "Timothy", last_name: "McAlpine", age: 37, email: "Timbo72469@usermail.com"},
    {first_name: "Sarah", last_name: "Connor", age: 19, email: "SarahC6320@usermail.com"}
];
window.onload=function(){
    var tbl=document.querySelector("#outputtable");
    var table = '<table border="1" style="border:1px solid black;"><tr><th>First Name</th><th>Last Name</th><th>Age</th><th>Email</th></tr>';
    for (var i=0; i<users.length;i++){
        table+="<tr>";
        table+="<td>"+users[i].first_name+"</td>";
        table+="<td>"+users[i].last_name+"</td>";
        table+="<td>"+users[i].age+"</td>"
        table+="<td>"+"<a href="+'mailto:"'+users[i].email+ '">'+users[i].email+"</a>"+"</td>";     
        table+="</tr>";
    }
    tbl.innerHTML+=table+"</table>";
};