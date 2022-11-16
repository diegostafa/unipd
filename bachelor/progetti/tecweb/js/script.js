var containerCart, hamburgerCart, cart;
function createFunctionContainer(value, index) {
    var node = document.createElement("div");
    node.classList.add("container-function");
    child = document.createElement("button");
    child.classList.add("btn-qnt");
    var img = document.createElement("img");
    img.setAttribute("src", "/srizzato/img/utils/minus.png");
    img.setAttribute("alt", "bottone diminuisci");
    child.appendChild(img);
    child.setAttribute("type", "button");
    child.setAttribute("onclick", "decrease(event," + index + ")");
    node.appendChild(child);
    child = document.createElement("input");
    child.classList.add("quantity");
    child.setAttribute("id", "quantity" + index);
    child.setAttribute("type", "number");
    child.setAttribute("name", "cart_dish_qnt[]");
    child.setAttribute("value", value);
    child.setAttribute("min", "1");
    child.setAttribute("max", "99");
    node.appendChild(child);
    child = document.createElement("button");
    child.classList.add("btn-qnt");
    img = document.createElement("img");
    img.setAttribute("src", "/srizzato/img/utils/plus.png");
    img.setAttribute("alt", "bottone aumenta");
    child.appendChild(img);
    child.setAttribute("type", "button");
    child.setAttribute("onclick", "increase(event," + index + ")");
    node.appendChild(child);
    return node;
}
function increase(evt, i) {
    var value = Number(evt.currentTarget.parentElement.childNodes[1].getAttribute("value"));
    evt.currentTarget.parentElement.childNodes[1].setAttribute("value",
        ++value);
    //showcart
    localStorage.setItem(localStorage.getItem(i), value);
    notSaved();

}
function decrease(evt, i) {
    var value = Number(evt.currentTarget.parentElement.childNodes[1].getAttribute("value"));
    if (value > 1) {
        evt.currentTarget.parentElement.childNodes[1].setAttribute("value", --value);
        localStorage.setItem(localStorage.getItem(i), value);
        notSaved();
    }
}
function addCart(e) {
    containerCart = document.querySelector(".container-cart")
    e.currentTarget.parentElement.classList.add("selected");
    var dato = document.querySelector(".selected .name");
    var name = dato.textContent;
    dato = document.querySelector(".selected .price");
    var price = dato.textContent;
    addLocalStorage(name, 1, price, false);
    notSaved();
    showCart();
    dato = document.querySelector(".dish.selected");
    dato.classList.remove("selected");
    if (!containerCart.classList.contains("open")) {
        cartToggle();
    }
}

function showCart() {
    removeAllChildNodes(cart);
    var dato = document.querySelector(".empty");
    if (localStorage.getItem("length") > 0) {
        if (!dato.classList.contains("hidden"))
            dato.classList.add("hidden");
        dato = document.querySelectorAll(".checkout");
        dato.forEach(element => {
            if (element.classList.contains("hidden"))
                element.classList.remove("hidden");

        });
        for (let i = 0; i < localStorage.getItem("length"); i++) {
            var node = document.createElement("li");
            node.classList.add("cart-item");
            dato = document.createElement("label");
            dato.setAttribute("for", "quantity" + i);
            dato.classList.add("name");
            dato.textContent = localStorage.getItem(i);
            node.appendChild(dato);
            dato = document.createElement("input");
            dato.setAttribute("value", localStorage.getItem(i));
            dato.setAttribute("name", "cart_dish_name[]");
            dato.setAttribute("type", "hidden");
            node.appendChild(dato);
            dato = document.createElement("span");
            dato.classList.add("price");
            dato.textContent = localStorage.getItem(localStorage.getItem(i) + "price");
            node.appendChild(dato);
            dato = createFunctionContainer(localStorage.getItem(localStorage.getItem(i)), i);
            node.appendChild(dato);
            dato = document.createElement("button");
            dato.classList.add("btn-remove");
            dato.textContent = "rimuovi";
            dato.setAttribute("onclick", "removeCart(" + i + ")");
            node.appendChild(dato);
            cart.appendChild(node);
        }
        dato = document.createElement("input");
        dato.setAttribute("value", localStorage.getItem("length"));
        dato.setAttribute("name", "count_cart");
        dato.setAttribute("type", "hidden");
        cart.appendChild(dato);
    }
    else {
        dato = document.createElement("input");
        dato.setAttribute("value", localStorage.getItem("length"));
        dato.setAttribute("name", "count_cart");
        dato.setAttribute("type", "hidden");
        cart.appendChild(dato);
        if (dato.classList.contains("hidden"))
            dato.classList.remove("hidden");
        dato = document.querySelectorAll(".checkout");
        dato.forEach(element => {
            if (!element.classList.contains("hidden"))
                element.classList.add("hidden");
        })

    }
}
function localStorageActive() {
    var test = 'test';
    try {
        localStorage.setItem(test, test);
        localStorage.removeItem(test);
        return true;
    } catch (e) {
        return false;
    }
}

function saved() {
    var selector = document.querySelector('.logged');
    if (selector)
        localStorage.setItem('saved', 1);
}

function start() {
    cart = document.querySelector(".cart-dishes");
    containerCart = document.querySelector(".container-cart");
    hamburgerCart = document.querySelector(".hamburger-cart");
    if (localStorageActive()) {
        if (localStorage.getItem('saved') == 0)
            notSaved();
        if (localStorage.getItem("isCartOpen") == null) {
            localStorage.setItem("isCartOpen", 0);
        }
        else {
            if (localStorage.getItem("isCartOpen") == 1) {
                containerCart.classList.toggle("open");
                hamburgerCart.classList.toggle("open");
            }
        }
        var numCartDb = document.querySelector("#count_cart");
        if (numCartDb) {
            numCartDb = document.querySelector("#count_cart").value;
            for (var i = 0; i < Number(numCartDb); i++) {
                var name, quantity, price;
                name = document.querySelector(".name" + i).textContent;
                quantity = document.querySelector(".quantity" + i).value;
                price = document.querySelector(".price" + i).textContent;
                addLocalStorage(name, quantity, price, true);
            }
        }
        showCart();
    }
    else {
        alert("local storage non e' attivo non e' possibile effettuare ordini");
    }
}
function addLocalStorage(name, quantity, price, db) {
    if (localStorage.getItem("length") > 0) {
        var count = 0;
        for (let i = 0; i < localStorage.getItem("length"); i++) {
            if (localStorage.getItem(i) != name) {
                if (i + 1 == localStorage.getItem("length")) {
                    localStorage.setItem(i + 1, name);
                    localStorage.setItem(localStorage.getItem(i + 1), quantity);
                    localStorage.setItem(localStorage.getItem(i + 1) + "price", price);
                    localStorage.setItem("length", i + 2);
                    count++;
                    break;
                }
            }
            else {
                if (!db) {
                    notSaved();
                    var numQ;
                    numQ = Number(localStorage.getItem(localStorage.getItem(i))) + Number(quantity);
                    if (numQ > 99) numQ = 99;
                    localStorage.setItem(localStorage.getItem(i), numQ);
                }
                else {
                    localStorage.setItem(localStorage.getItem(i), quantity);
                }
                break;
            }
        }
        if (count == localStorage.getItem("length"))
            localStorage.setItem('saved', 1);
    } else {
        localStorage.setItem("length", 1);
        localStorage.setItem(0, name);
        localStorage.setItem(localStorage.getItem(0), quantity);
        localStorage.setItem(localStorage.getItem(0) + "price", price);
    }
}
function removeAllChildNodes(parent) {
    while (parent.firstChild) {
        parent.removeChild(parent.firstChild);
    }
}
function removeAllCart() {
    while (localStorage.getItem("length") > 0)
        removeCart(0);
}

function clearLocalStorage() {
    localStorage.clear();
}

function removeCart(index) {
    localStorage.removeItem(localStorage.getItem(index));
    localStorage.removeItem(localStorage.getItem(index) + "price");
    for (let i = index; i < localStorage.getItem("length"); i++)
        localStorage.setItem(i, localStorage.getItem(i + 1));
    localStorage.removeItem(localStorage.getItem("length") - 1);
    localStorage.setItem("length", localStorage.getItem("length") - 1);
    notSaved();
    showCart();
}
function cartToggle() {
    containerCart = document.querySelector(".container-cart");
    hamburgerCart = document.querySelector(".hamburger-cart");
    localStorage.setItem("isCartOpen", localStorage.getItem("isCartOpen") == 0 ? 1 : 0);
    containerCart.classList.toggle("open");
    hamburgerCart.classList.toggle("open");
}
function notSaved() {
    var noSaved = document.querySelector('.notSaved');
    localStorage.setItem('saved', 0);
    if (noSaved.classList.contains('hidden'))
        noSaved.classList.remove('hidden');
}

/*--- fine menù ---*/
window.onload = function () {
    initializeValidationForm();
};

function showErrorMessage(input, message) {
    var parent = input.parentNode;
    var errorMessage = document.createElement("strong");

    errorMessage.className = "error-message";
    errorMessage.appendChild(document.createTextNode(message));
    parent.appendChild(errorMessage);
}

function validateByRegex(id, regex, errorMessage) {
    var input = document.getElementById(id);

    resetErrorMessage(input);

    var text = input.value;

    if (text.search(regex) != 0) {
        showErrorMessage(input, errorMessage);
        input.select();
        return false;
    }
    return true;
}

function resetErrorMessage(input) {
    var parent = input.parentNode;
    if (parent.children.length == 3) {
        parent.removeChild(parent.children[2]);
    }
}

function checkConfirmPassword(passwordId, confirmPasswordId, errorMessage) {
    var psw = document.getElementById(passwordId);
    var cnfPsw = document.getElementById(confirmPasswordId);
    resetErrorMessage(cnfPsw);

    if (psw.value != cnfPsw.value) {
        showErrorMessage(cnfPsw, errorMessage);
        return false;
    }
    return true;
}

function validateDate() {
    var schedule = document.getElementById("schedule");
    var date = document.getElementById("data");
    if (schedule.value == "" || date.value == "")
        return false;

    resetErrorMessage(schedule);
    var currentDate = new Date();
    var orderDate = new Date(date.value + " " + schedule.value);

    if (currentDate > orderDate) {
        showErrorMessage(schedule, "inserire una data valida");
        date.select();
        return false;
    }
    return true;
}

function deliveryValidation() {
    return ("address", /^[a-zA-Z0-9\s']{2,}$/, "inserire un indirizzo valido") && validateDate();
}
function confirmOrder() {
    if (deliveryValidation()) {
        clearLocalStorage();
        return true;
    }
    else return false;
}

function setOnBlurValidationRegex(id, regex, errorMessage) {
    var input = document.getElementById(id);
    input.onblur = function () {
        validateByRegex(id, regex, errorMessage);
    };
}

function setOnBlurConfirmPassword(passwordId, confirmPasswordId, regex, errorMessage) {
    var input = document.getElementById(confirmPasswordId);
    input.onblur = function () {
        validateByRegex(confirmPasswordId, regex, errorMessage);
        checkConfirmPassword(passwordId, confirmPasswordId, errorMessage);
    };
}

function loadingCart() {
    var date = document.getElementById("data");
    var schedule = document.getElementById("schedule");
    var take = document.getElementById("take");
    var delivery = document.getElementById("domicilio");

    take.checked = true;
    readOnlyAddress(true);
    setOnBlurValidationRegex("address", /^[a-zA-Z0-9\s']{2,}$/, "inserire un indirizzo valido");

    date.onchange = function () {
        validateDate();
    };
    schedule.onchange = function () {
        validateDate();
    };
    delivery.onchange = function () {
        readOnlyAddress(false);
        var addr = document.getElementById("address");
        resetErrorMessage(addr);
    };
    take.onchange = function () {
        readOnlyAddress(true);
        var addr = document.getElementById("address");
        resetErrorMessage(addr);
    };
}

function loadingSignUp() {
    setOnBlurValidationRegex("first_name", /^[A-Za-zàèìòùé\s']{1,50}$/, "siamo spiacenti sono consentite lettere, spazi, apostrofi e massimo 50 caratteri");
    setOnBlurValidationRegex("last_name", /^[A-Za-zàèìòùé\s']{1,50}$/, "siamo spiacenti sono consentite lettere, spazi, apostrofi e massimo 50 caratteri");
    setOnBlurValidationRegex("username", /^[A-Za-zàèìòùé0-9]{1,50}$/, "siamo spiacenti sono consentite lettere, numeri e al massimo 50 caratteri");
    setOnBlurValidationRegex("email", /^[\w\-\+\.\%\_\!\/\#\$\{\}]{1,64}\@[a-zA-Z]([a-zA-Z0-9\-]{0,61}[a-zA-Z0-9])?\.[a-zA-Z]([a-zA-Z0-9\-\.\+]+)$/, "inserire un'email valida");
    setOnBlurValidationRegex("password", /^.{4,20}$/, "inserire una password di almeno 4 caratteri");
    setOnBlurConfirmPassword("password", "confirm_password", /^.{4,20}$/, "confermare la password inserita in precedenza");
}

function loadingUpdateUser() {
    setOnBlurValidationRegex("first_name", /^[A-Za-zàèìòùé\s']{1,50}$/, "siamo spiacenti sono consentite lettere, spazi, apostrofi e massimo 50 caratteri");
    setOnBlurValidationRegex("last_name", /^[A-Za-zàèìòùé\s']{1,50}$/, "siamo spiacenti sono consentite lettere, spazi, apostrofi e massimo 50 caratteri");
    setOnBlurValidationRegex("email", /^[\w\-\+\.\%\_\!\/\#\$\{\}]{1,64}\@[a-zA-Z]([a-zA-Z0-9\-]{0,61}[a-zA-Z0-9])?\.[a-zA-Z]([a-zA-Z0-9\-\.\+]+)$/, "inserire un'email valida");
}

function loadingResetPassword() {
    setOnBlurValidationRegex("password", /^.{4,20}$/, "inserire una password di almeno 4 caratteri");
    setOnBlurValidationRegex("new_password", /^.{4,20}$/, "inserire una password di almeno 4 caratteri");
    setOnBlurConfirmPassword("new_password", "confirm_new_password", /^.{4,20}$/, "confermare la nuova password inserita in precedenza");
}

function loadingAddDish() {
    setOnBlurValidationRegex("dish_name", /^[A-Za-zàèìòùé0-9\s']{1,50}$/, "il nome di un piatto può contenere lettere, numeri e non può superare i 50 caratteri");
    setOnBlurValidationRegex("dish_description", /^[A-Za-zàèìòùé0-9\s'\,\.]{1,255}$/, "la descrizione di un piatto può contenere lettere, numeri, virgole, punti e non può superare i 255 caratteri");
    setOnBlurValidationDishPrice("dish_price", "il prezzo di un piatto non può superare i mille euro");
}

function setOnBlurValidationDishPrice(id, errorMessage) {
    var input = document.getElementById(id);
    input.onblur = function () {
        resetErrorMessage(this);
        if (this.value > 1000 && this.value < 0) {
            showErrorMessage(this, errorMessage);
            this.select();
            return false;
        }
        return true;
    }
}

function validatePrice() {
    input.onblur = function () {
        var input = document.getElementById("dish_price");
        resetErrorMessage(input);
        if (input.value < 1000) {
            showErrorMessage(input, "il prezzo di un piatto non può superare i mille euro");
            return true;
        }
        return false;
    };
}
function loadingAddCategory() {
    setOnBlurValidationRegex("new_category", /^[A-Za-zàèìòùé0-9]{1,100}$/, "il nome di una categoria può contenere lettere, numeri e non può superare i 100 caratteri");
}
function loadingAddNews() {
    setOnBlurValidationRegex("news_title", /^[A-Za-zàèìòùé0-9\s']{1,50}$/, "il titolo di una news può contenere lettere, numeri e non può superare i 50 caratteri");
    setOnBlurValidationRegex("news_desc", /^[A-Za-zàèìòùé0-9\s'\,\.]{1,255}$/, "il contenuto di una news può contenere lettere, numeri, virgole, punti e non può superare i 255 caratteri");
    setOnBlurValidationRegex("img_alt", /^[A-Za-zàèìòùé0-9\s']{1,100}$/, "la descrizione di un'immagine può contenere lettere, numeri e non può superare i 100 caratteri");
}

function initializeValidationForm() {
    if (document.getElementById("form_signup") != null)
        loadingSignUp();
    if (document.getElementById("form_add_order") != null)
        loadingCart();
    if (document.getElementById("form_add_dish") != null)
        loadingAddDish();
    if (document.getElementById("form_add_category") != null)
        loadingAddCategory();
    if (document.getElementById("form_add_news") != null)
        loadingAddNews();
    if (document.getElementById("form_update_user") != null)
        loadingUpdateUser();
    if (document.getElementById("form_reset_password") != null)
        loadingResetPassword();
}

function signUpValidation() {
    return checkConfirmPassword("confermare la password inserita in precedenza");
}

function readOnlyAddress(isReadOnly) {
    var addr = document.getElementById("address");
    addr.value = isReadOnly ? "Via Trieste 63" : "";
    addr.readOnly = isReadOnly;
}

/*--- fine validazione --- */

function openOverlay() {
    document.getElementById("overlay").style.display = "block";
    document.getElementById("overlay").style.width = "100%";
    document.documentElement.style.overflow = 'hidden';
}

function closeOverlay() {
    document.getElementById("overlay").style.width = "0%";
    document.getElementById("overlay").style.display = "none";
    document.documentElement.style.overflow = 'scroll';
}