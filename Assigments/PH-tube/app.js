const AllData = (global) => {
    const id = 1000;
    fetch(`https://openapi.programming-hero.com/api/videos/category/${id? id: global}`)
    .then(res => res.json())
    .then((responseData) => displayData(responseData.data))
    .catch((error) => console.log(error));
     
};  
    

    const displayData = (responseData) => {
        const category = document.getElementById("Video-Container");
        category.innerHTML = "";
        responseData.forEach((data) => {
        console.log(data);     
        const card1 = document.createElement("div");
        card1.classList.add("box");
        card1.innerHTML =  `
        <img class = "box-img" src="${data.thumbnail}" alt="thumbnail" />
        <div class = "flexing-container">
        <img class = "profilePicture" src="${data.authors[0].profile_picture}" alt="profile-pic" />
        <div class = "blocking-container">
        <h4 class = "text">${data.title}</h4>
        <div class = "profile_name-verify" >
        <p class = "txt1">${data.authors[0].profile_name}</p>
        ${data.authors[0].verified? '<img class = "verify" src="verify.png">': ""}
        </div>
        <div class = "profile_name-verify" >
        <p class = "txt2">${data.others.views} views</p>
        ${data.others.posted_date !==""? `<p class = "txt2 bg-body-secondary pe-2 ps-2">  ${totalSecond(data.others.posted_date)}</p>`: ""}
        </div>
        </div>
        </div>
   
        `;
        category.appendChild(card1);         
        
    });
};

const MusicData = () => {
    fetch("https://openapi.programming-hero.com/api/videos/category/1001")
    .then(res => res.json())
    .then((responseData) => display2Data(responseData.data))
    .catch((error) => console.log(error));
};  
    

    const display2Data = (responseData) => {
        const category = document.getElementById("Video-Container");
        category.innerHTML = "";
    responseData.forEach((data) => {
        console.log(data);
        const card1 = document.createElement("div");
        card1.classList.add("box");
        card1.innerHTML =   `
        <img class = "box-img" src="${data.thumbnail}" alt="thumbnail" />
        <div class = "flexing-container">
        <img class = "profilePicture" src="${data.authors[0].profile_picture}" alt="profile-pic" />
        <div class = "blocking-container">
        <h4 class = "text">${data.title}</h4>
        <div class = "profile_name-verify" >
        <p class = "txt1">${data.authors[0].profile_name}</p>
        ${data.authors[0].verified? '<img class = "verify" src="verify.png">': ""}
        </div>
        <div class = "profile_name-verify" >
        <p class = "txt2">${data.others.views} views</p>
        ${data.others.posted_date !==""? `<p class = "txt2 bg-body-secondary pe-2 ps-2">  ${totalSecond(data.others.posted_date)}</p>`: ""}
        </div>
        </div>
        </div>
   
        `;
        category.appendChild(card1);         
    });
};

const ComedyData = () => {
    fetch("https://openapi.programming-hero.com/api/videos/category/1003")
    .then(res => res.json())
    .then((responseData) => display3Data(responseData.data))
    .catch((error) => console.log(error));
};  
    

    const display3Data = (responseData) => {
        const category = document.getElementById("Video-Container");
        category.innerHTML = "";
        responseData.forEach((data) => {
        console.log(data);
        const card1 = document.createElement("div");
        card1.classList.add("box");
        card1.innerHTML =   `
        <img class = "box-img" src="${data.thumbnail}" alt="thumbnail" />
        <div class = "flexing-container">
        <img class = "profilePicture" src="${data.authors[0].profile_picture}" alt="profile-pic" />
        <div class = "blocking-container">
        <h4 class = "text">${data.title}</h4>
        <div class = "profile_name-verify" >
        <p class = "txt1">${data.authors[0].profile_name}</p>
        ${data.authors[0].verified? '<img class = "verify" src="verify.png">': ""}
        </div>
        <div class = "profile_name-verify" >
        <p class = "txt2">${data.others.views} views</p>
        ${data.others.posted_date !==""? `<p class = "txt2 bg-body-secondary pe-2 ps-2">  ${totalSecond(data.others.posted_date)}</p>`: ""}
        </div>
        </div>
        </div>
   
        `;
        category.appendChild(card1);         
    
    });
};

const DrawingData = () => {
    fetch("https://openapi.programming-hero.com/api/videos/category/1005")
    .then(res => res.json())
    .then((responseData) => display4Data(responseData.data))
    .catch((error) => console.log(error));
};  
    

    const display4Data = (responseData) => {
        const category = document.getElementById("Video-Container");
        category.innerHTML = `
        <div class="blockverify">  
        <img class ="iconImg" src= "icon.png" alt =""></img>
        <h1 class="text5">Oops!!Sorry,There is no content here </h1>
        </div>
        `;
    };

    const SortButton = () => {
        fetch("https://openapi.programming-hero.com/api/videos/category/1000")
        .then(res => res.json())
        .then((responseData) => display5Data(responseData.data))
        .catch((error) => console.log(error));
    };
    const display5Data = (responseData) => {
        const category = document.getElementById("Video-Container");
        category.innerHTML = "";
        responseData.sort((a,b) =>parseInt(b.others.views) - parseInt(a.others.views)); 
        responseData.forEach((data) => {
            console.log(data.others.views);
            const card1 = document.createElement("div");
            card1.classList.add("box");
            card1.innerHTML =  `
            <img class = "box-img" src="${data.thumbnail}" alt="thumbnail" />
            <div class = "flexing-container">
            <img class = "profilePicture" src="${data.authors[0].profile_picture}" alt="profile-pic" />
            <div class = "blocking-container">
            <h4 class = "text">${data.title}</h4>
            <div class = "profile_name-verify" >
            <p class = "txt1">${data.authors[0].profile_name}</p>
            ${data.authors[0].verified? '<img class = "verify" src="verify.png">': ""}
            </div>
            <div class = "profile_name-verify" >
            <p class = "txt2">${data.others.views} views</p>
            ${data.others.posted_date !==""? `<p class = "txt2 bg-body-secondary pe-2 ps-2">  ${totalSecond(data.others.posted_date)}</p>`: ""}
            </div>
            </div>
            </div>
       
            `;
            category.appendChild(card1);
        });

    };
const totalSecond = (x) =>{
    const hour = Math.floor(x/3600);
    const minute = Math.floor((x%3600)/60);
    return `${hour}hr ${minute}min ago`;
}



AllData("1000");