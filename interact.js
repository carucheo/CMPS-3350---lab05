function init()
{
const input = document.querySelector(".english-input");
const paragraph = document.querySelector(".spanish-output");

input.addEventListener("keyup", function () {
    const reverse = input.value.split(" ").reverse().join(" ");
    paragraph.innerText = reverse;
});

}
document.addEventListener('DOMContentLoaded', (event) => {
    initReverseWords();
});


init();
