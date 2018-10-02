var errors=document.querySelector(".sidepanel");

function formValidation(){
    var errors=document.querySelector(".sidepanel");
    var password1=document.signup.password;
    var password2=document.signup.repassword;
    errors.innerHTML=""
    nodigit=0;
    noUppercase=0;
    var value=password1.value.trim();
    if(value.length!=8){
        errors.innerHTML+="<p>Password must be 8 characters long</p>";
        password1.focus();
        //document.getElementById("password").focus();
        return false;
    }
    if(value.charAt(0).toUpperCase()>"Z"&&value.charAt(0).toUpperCase()<"A"){
        errors.innerHTML+="<p>Password must start with a character</p>";
        password1.focus();
        return false;
    }

    for(var i=0; i<value.length;i++){
         !isNaN(value.charAt(i))? nodigit++ : nodigit;
          value.charAt(i)<='Z'&& value.charAt(i)>='A'?noUppercase++ : noUppercase;
    }
   if(nodigit==0||noUppercase==0){
         errors.innerHTML+="<p>Password must have at least 1 digit and 1 uppercase character</p>";  
         password1.focus();
        return false;
    } 
    var test3=match(password1,password2);
    if(!test3){
        //errors.innerHTML+="<p>Error! Please try again.</p>";
        return false;
    }
    errors.innerHTML+=("Congratulations! You have been registered.");
    return true;
}

function valid(){
    var errors=document.querySelector(".sidepanel");
    var invalid = document.querySelector("input:focus:invalid");
    var current = document.querySelector("input:focus");
    errors.innerHTML="";//reset for every time use
    //var result=true;
    if(current!=null){
        if(current.value.trim()==""){ //when no input
            errors.innerHTML+="<p>The field is required</p>";
        }
        else if(current.value.trim()!=null && invalid==null){
            errors.innerHTML="";
        }
        else {
        //check when input start
        var option=current.name;
        switch (option) {
            case "stname":
                errors.innerHTML+="<p>Street should not contain digits</p>";
                break;
            case "city":
                errors.innerHTML+="<p>City should contain letters only</p>";
                break;
            case "postcode":
                errors.innerHTML+="<p>Postal Code should be (Letter Digit Letter Digit Letter Digit)<p/>";
                break;
            case "phone":
                errors.innerHTML+="<p>Phone Number should be ###-###-####</p>";
                break;
            case "email":
                errors.innerHTML+="<p>Email address is not valid</p>";
                break;
            case "username":
                errors.innerHTML+="<p>Username must start with a letter, must have at least 6 characters</p>";
                break;            
            default:
                break;
            }
        }
    }
}

//check if password match
function match(pass1, pass2){
    var errors=document.querySelector(".sidepanel");
    errors.innerHTML=""
    var result;
    if(pass1.value==pass2.value){
        result=true;
    }else{
        errors.innerHTML+="<p>Confirmation password does not match with password";
        result=false;
        pass1.focus();
        pass2.focus();
    }
    return result;
}

 