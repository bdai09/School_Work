
// set a global httpRequest object

var httpRequest;
		
// TODO: when the page (window) has loaded, make a
// request for page 1

window.onload=function() {
	//remove no data
	document.getElementById('nodata').remove();
	makeRequest(1);
}


function makeRequest(pageNum) {
	
    // TODO: create a variable "url" to store the request to 
	// the current pageNum, ie:
	// 		"https://reqres.in/api/users?page=1" // for page 1
	// 		"https://reqres.in/api/users?page=2" // for page 2
	// 		etc...
	
	var url="";
	switch(pageNum){
		case 1:
		   url="https://reqres.in/api/users?page=1";
		   break;
		case 2:
		   url="https://reqres.in/api/users?page=2";
		   break;
		case 3:
		   url="https://reqres.in/api/users?page=3";
		   break;
		case 4:
		   url="https://reqres.in/api/users?page=4";
		   break;
	}
 
	// make an HTTP request object
	
	httpRequest = new XMLHttpRequest();

	// execute the "showContents" function when
	// the httprequest.onreadystatechange event is fired
	
	httpRequest.onreadystatechange = showContents;
	
	// open a asynchronous HTTP (GET) request with the specified url
	
	httpRequest.open('GET', url, true);
	
	// send the request
	
	httpRequest.send();
}

// the function that handles the server response

function showContents() {

//  check for response state
//  0      The request is not initialized
//  1      The request has been set up
//  2      The request has been sent
//  3      The request is in process
//  4      The request is complete

	if (httpRequest.readyState === 4) {
		// check the response code
		if (httpRequest.status === 200) { // The request has succeeded
		    // Just for debugging. 
			console.log(httpRequest.responseText);
			
			// Javascript function JSON.parse to parse JSON data
			var jsData = JSON.parse(httpRequest.responseText);
			
			// TODO: use the jsData object to populate the correct
			// table cells, ie <tr><td>...</td></tr>
			// in the <tbody> element with id="data"
			
			var tbl=document.querySelector("#data");
			//while(tbl.firstChild){tbl.removeChild(tbl.firstChild);}
			tbl.innerHTML="";
			var usedata=jsData.data;
			for (var i = 0; i < usedata.length; i++) {
			   // creates a table row
			   var row = document.createElement("tr");
			   row.appendChild(getTdElement(usedata[i].id));
			   row.appendChild(getTdElement(usedata[i].first_name));
			   row.appendChild(getTdElement(usedata[i].last_name));
			   row.appendChild(getTdImgElement(usedata[i].avatar));
			   // add the row to the end of the table body
			   tbl.appendChild(row);
			} 

		} else {
			console.log('There was a problem with the request.');
		}
	}
}	

// Create a <td> element and a text
function getTdElement(text) {
	var cell = document.createElement("td");
	var cellText = document.createTextNode(text);
	cell.appendChild(cellText);
	return cell;
 }
 
 // Create a <td> element with a hyperlink
 function getTdImgElement(src) {
	var image = document.createElement("img");
	image.setAttribute("src", src);   
	var cell = document.createElement("td");
	cell.appendChild(image);
	return cell;
 }