import { initializeApp } from "https://www.gstatic.com/firebasejs/10.10.0/firebase-app.js";
import { getDatabase, ref, onValue } from "https://www.gstatic.com/firebasejs/10.10.0/firebase-database.js";
const firebaseConfig = {
    apiKey: "AIzaSyBvrlEtTbtfMINYar4lizglSg8n-jHgHyA",
    authDomain: "swiss-33a45.firebaseapp.com",
    databaseURL: "https://swiss-33a45-default-rtdb.firebaseio.com",
    projectId: "swiss-33a45",
    storageBucket: "swiss-33a45.appspot.com",
    messagingSenderId: "281601069011",
    appId: "1:281601069011:web:09fa5a838a73fc6bcb6926"
};
const app = initializeApp(firebaseConfig);
const firebase = getDatabase(app);

function insertTop() {
    let top = document.querySelector('.top');
    top.style = ('background: #222;');
}

// Receive Firebase Function
const db = getDatabase();
const starCountRef = ref(db, 'swiss/system');
onValue(starCountRef, (snapshot) => {
    const dataReceived = snapshot.val();

    let angle_servo_value = dataReceived.angle_servo;
    console.log(angle_servo_value);

    if (angle_servo_value == 160)
    {
        console.log("NÃO METAL");
        let top = document.querySelector('.top');
        top.style = ('background: 0;');
        let divider = document.querySelector('.divider');
        divider.style = ('background: #FFB81C;');
        let cube = document.querySelector('.cube');
        cube.style = ('animation: animateRight 3s linear forwards;');
        document.querySelector('.sidef').style.background = 'linear-gradient(#151515, #FFB81C)';
        document.querySelector('.sidel').style.background = 'linear-gradient(#151515, #FFB81C)';
        document.querySelector('.sider').style.background = 'linear-gradient(#151515, #FFB81C)';
        document.querySelector('.sideb').style.background = 'linear-gradient(#151515, #FFB81C)';
        let material_ball = document.querySelector('.material_ball');
        material_ball.textContent = "Não metal";
        let cor_ball = document.querySelector('.cor_ball');
        cor_ball.textContent = "Laranja";
        setTimeout(insertTop, 4000);
    }
    if (angle_servo_value == 0)
    {
        console.log("METAL");
        let top = document.querySelector('.top');
        top.style = ('background: 0;');
        let divider = document.querySelector('.divider');
        divider.style = ('background: #FFD43B;');
        let cube = document.querySelector('.cube');
        cube.style = ('animation: animateLeft 3s linear forwards;');
        document.querySelector('.sidef').style.background = 'linear-gradient(#151515, #FFD43B)';
        document.querySelector('.sidel').style.background = 'linear-gradient(#151515, #FFD43B)';
        document.querySelector('.sider').style.background = 'linear-gradient(#151515, #FFD43B)';
        document.querySelector('.sideb').style.background = 'linear-gradient(#151515, #FFD43B)';
        let material_ball = document.querySelector('.material_ball');
        material_ball.textContent = "Metal";
        let cor_ball = document.querySelector('.cor_ball');
        cor_ball.textContent = "Amarelo";
        setTimeout(insertTop, 4000);
    }
});
