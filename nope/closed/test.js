let spoilButton =  document.querySelector(".spoil-button") 
let mss = document.querySelector(".mss")

spoilButton.addEventListener("click" , () => {
    if(mss.style.display == "none") {
        mss.style.display = "block" 
        return ; 
    }
    mss.style.display = "none" 
})