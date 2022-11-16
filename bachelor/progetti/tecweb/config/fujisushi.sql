DROP TABLE IF EXISTS listCartDish;
DROP TABLE IF EXISTS orders;
DROP TABLE IF EXISTS cart;
DROP TABLE IF EXISTS dish;
DROP TABLE IF EXISTS news;
DROP TABLE IF EXISTS category;
DROP TABLE IF EXISTS picture;
DROP TABLE IF EXISTS users;

CREATE TABLE category
(
    c_id int PRIMARY KEY AUTO_INCREMENT,
    c_name VARCHAR(100) NOT NULL UNIQUE,
    deleted bool NOT NULL DEFAULT FALSE
);

CREATE TABLE picture
(
    p_id int PRIMARY KEY AUTO_INCREMENT,
    p_path VARCHAR(255) NOT NULL,
    alt VARCHAR(100)
);

CREATE TABLE dish
(
    d_name VARCHAR(100) primary KEY,
    summary VARCHAR(255) NOT NULL,
    price DECIMAL(5,2) CHECK(price > 0),
    deleted bool NOT NULL DEFAULT FALSE,
    category INT NOT NULL,
    picture INT NOT NULL,
    FOREIGN KEY (category) REFERENCES category(c_id),
    FOREIGN KEY (picture) REFERENCES picture(p_id)
);

CREATE TABLE users
(
    username VARCHAR(50) PRIMARY KEY,
    email VARCHAR(140) NOT NULL,
    first_name VARCHAR(50) NOT NULL,
    last_name VARCHAR(50) NOT NULL,
    pw VARCHAR(20) NOT NULL,
    is_admin BOOLEAN NOT NULL DEFAULT FALSE
);

CREATE TABLE news
(
    n_id int PRIMARY KEY AUTO_INCREMENT,
    title VARCHAR(50) NOT NULL,
    summary VARCHAR(255),
    creation_date TIMESTAMP NOT NULL,
    picture INT NOT NULL,
    FOREIGN KEY (picture) REFERENCES picture(p_id)
);

CREATE TABLE cart
(
    id INT PRIMARY KEY AUTO_INCREMENT,
    users VARCHAR(50) NOT NULL,
    FOREIGN KEY (users) REFERENCES users(username)
);

CREATE TABLE orders
(
    cart_id int PRIMARY KEY,
    pay_date TIMESTAMP NOT NULL,
    delivery_date TIMESTAMP NOT NULL,
    tot_price DECIMAL(12,2) NOT NULL CHECK(tot_price > 0),
    take_away bool NOT NULL,
    delivery_address VARCHAR(100) NOT NULL,
    FOREIGN KEY (cart_id) REFERENCES cart(id)
);


CREATE TABLE listCartDish
(
    cart_id int NOT NULL,
    dish VARCHAR(50)  NOT NULL,
    quantity int CHECK(quantity>0),
    FOREIGN KEY (dish) REFERENCES dish(d_name),
    FOREIGN KEY (cart_id) REFERENCES cart(id),
    PRIMARY KEY (cart_id, dish)
);