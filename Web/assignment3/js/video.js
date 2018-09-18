// Data for the "HTML Video" Page
// BO DAI, 132954173, June22,2018

var video = {
    controls: true, 
    width: 320,
    height: 240,
    source: [
        {src: "https://scs.senecac.on.ca/~patrick.crawford/shared/fall-2016/int222/movie.mp4", type: "video/mp4"},
        {src: "https://scs.senecac.on.ca/~patrick.crawford/shared/fall-2016/int222/movie.ogg", type: "video/ogg"},
        {src: "https://scs.senecac.on.ca/~patrick.crawford/shared/fall-2016/int222/movie.webm", type: "video/webm"}
    ]
};
window.onload=function(){
    var videoContainer=document.querySelector("#outputvideo");
    var videoout='<video width="'+video.width+'" height="'+video.height+'"';
    if(video.controls==true)
       videoout+=" controls>";
    else videoout+=">";
   for (var i=0; i<video.source.length;i++){
       videoout+='<source src="'+video.source[i].src+'" type="'
       +video.source[i].type+'"/>';
   }
   videoContainer.innerHTML+=videoout+"</video>";
};