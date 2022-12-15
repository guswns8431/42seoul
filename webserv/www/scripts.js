window.onload = init();

if (window.location.href.match('admin.html') != null) {
	window.onload = create_user_list();
}

function init() {
	console.log("yo");

	if (!sessionStorage.alreadyClicked) {
    		sessionStorage.alreadyClicked = 1;
	}
	else {
		return;
	}

	let normal_creds = [];
	let admin_creds = [];

	let login1 = ["Jose", "1234"];
	let login2 = ["Mahirah", "1234"];
	let login3 = ["Owen", "1234"];

	normal_creds.push(login1);
	normal_creds.push(login2);
	admin_creds.push(login3);

	sessionStorage.setItem('normal_creds',  JSON.stringify(normal_creds));
	sessionStorage.setItem('admin_creds',  JSON.stringify(admin_creds));
}

function login() {
	let normal_creds = JSON.parse(sessionStorage.getItem('normal_creds'));
	let admin_creds = JSON.parse(sessionStorage.getItem('admin_creds'));

	let user = get_login_username();
	let pass = get_login_password();

	for(let i=0; i<normal_creds.length; i++){
		if((normal_creds[i][0] == user) && (normal_creds[i][1] == pass)) {
			window.open("blank.html","_self");
			return;
		}
	}

	for(let i=0; i<admin_creds.length; i++){
		if((admin_creds[i][0] == user) && (admin_creds[i][1] == pass)) {
			window.open("admin.html","_self");
			return;
		}
	}

	alert("Incorrect Login. Please enter again.");
	return;
}

function sign_up() {
	let normal_creds = JSON.parse(sessionStorage.getItem('normal_creds'));

	console.log("yo1");

	let user = get_signup_username();
	let pass = get_signup_password();
	let pass1 = get_signup_password1();

	console.log("yo2");

	if(user == ""){
		alert("Please enter a username.");
		return;
	}

	if(pass == ""){
		alert("Please enter a password");
		return;
	}

	if(pass != pass1){
		alert("Passwords do not match. Please reenter.");
		return;
	}

	for(let i=0; i<normal_creds.length; i++){
		if(normal_creds[i][0] == user) {
			alert("Username is taken. Please choose a new one.");
			return;
		}
	}

	let login = [user, pass];
	normal_creds.push(login);
	sessionStorage.setItem('normal_creds', JSON.stringify(normal_creds));

	window.open("mainpage.html","_self");
	return;
}

function cancel() {
	window.open("login.html","_self");
}

function logout() {
	<!-- add reassurance prompt here -->
	window.open("login.html","_self");
}

function delete_user(user) {
	console.log("hello");
	let normal_creds = JSON.parse(sessionStorage.getItem('normal_creds'));

	for(let j=0;j<normal_creds.length;j++) {
		if(normal_creds[j][0] == user.id) {
			normal_creds.splice(j,1);
		}
	}
	sessionStorage.setItem('normal_creds', JSON.stringify(normal_creds));

	document.getElementById("user_list").removeChild(user);
	return;
}
function create_delete_button(user) {
	let btn = document.createElement("button");
	btn.innerHTML = "Delete User";
	btn.setAttribute("onclick","delete_user(" + user + ")");
	return btn;
}
function create_user_list() {
	let normal_creds = JSON.parse(sessionStorage.getItem('normal_creds'));

	for(let i=0;i<normal_creds.length;i++) {
		create_user_element(normal_creds[i][0]);
	}
}
function create_user_element(user){
	var ul = document.getElementById("user_list");
	var li = document.createElement("li");
	li.setAttribute("id",user);
	li.innerHTML = li.innerHTML + user + "  ";
	li.appendChild(create_delete_button(user));
	ul.appendChild(li);
	return false;
}

function get_login_username() {
	return document.getElementById("username").value;
}
function get_login_password() {
	return document.getElementById("password").value;
}

function get_signup_username() {
	return document.getElementById("username").value;
}
function get_signup_password() {
	return document.getElementById("password").value;
}
function get_signup_password1() {
	return document.getElementById("password1").value;
}
