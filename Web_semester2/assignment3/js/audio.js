// Data for the "HTML Audio" Page
// BO DAI, 132954173, June22,2018

var audio = {
    controls: true, 
    source: [
        {src: "https://scs.senecac.on.ca/~patrick.crawford/shared/fall-2016/int222/Track03.mp3", type: "audio/mpeg"},
        {src: "https://scs.senecac.on.ca/~patrick.crawford/shared/fall-2016/int222/Track03.ogg", type: "audio/ogg"}
    ]
};
window.onload=function(){
    var audioContainer=document.querySelector("#outputaudio");
   var audioout="<audio";
   if(audio.controls==true)
       audioout+=" controls>";
    else audioout+=">";
   for (var i=0; i<audio.source.length;i++){
       audioout+='<source src="'+audio.source[i].src+'" type="'
       +audio.source[i].type+'"/>';
   }
   audioContainer.innerHTML+=audioout+"</audio>";
};