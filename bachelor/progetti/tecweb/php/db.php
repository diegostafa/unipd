<?php
class sushiDB
{
    // fields
    private $conn_open;
    private $host;
    private $user;
    private $pw;
    private $db;
    private $conn;


    // CONSTRUCTOR
    function __construct()
    {
        $ini = parse_ini_file("../config/settings.ini") or die("errore interno: non è stato possibile ottenere il file di configurazione.");

        $this->host = $ini["host"];
        $this->user = $ini["user"];
        $this->pw = $ini["pw"];
        $this->db = $ini["db"];
        $this->conn_open = false;
    }


    // CONNECTION
    public function open_connection()
    {
        $this->conn = new mysqli($this->host, $this->user, $this->pw, $this->db);
        $this->conn_open = $this->conn->connect_errno || $this->conn->set_charset('utf8');
        return $this->conn_open;
    }

    public function close_connection()
    {
        $this->conn->close();
        $this->conn_open = false;
    }

    public function is_open()
    {
        return $this->conn_open;
    }


    // DISH
    public function add_dish($name, $desc, $cat, $img, $price)
    {
        $dish = $this->exec_query("
        SELECT *
        FROM dish
        WHERE d_name=?
        ", "s", $name);

        $res = $this->exec_query("
        SELECT p_id
        FROM picture
        WHERE p_path=?
        ", "s", $img);

        $id_img = $res ? $res[0]["p_id"] : false;

        if ($dish) {
            return $this->exec_non_query("
                UPDATE dish
                SET summary=?, category=?,
                    picture=?, price=?,
                    deleted=true
                WHERE d_name=?;
            ", "siids", $desc, $cat, $id_img, $price, $name);
        } else {
            return $this->exec_non_query("
                INSERT INTO dish(d_name, summary, category, picture, price)
                VALUES (?,?,?,?,?)
            ", "ssiid", $name, $desc, $cat, $id_img, $price);
        }
    }

    public function remove_dish($name)
    {
        return $this->exec_non_query("
            UPDATE dish
            SET deleted=true
            WHERE d_name IN (" . str_repeat('?,', count($name) - 1)  .  "?)
        ", str_repeat('s', count($name)), ...$name);
    }

    public function get_all_dish()
    {
        return $this->exec_query("
            SELECT *
            FROM dish INNER JOIN picture
            ON dish.picture = picture.p_id
            WHERE deleted=false
        ");
    }

    public function get_dish_by_category($cat)
    {
        return $this->exec_query("
            SELECT *
            FROM dish INNER JOIN picture
            ON dish.picture = picture.p_id
            WHERE category=? AND deleted=false 
        ", "i", $cat);
    }

    public function get_top_dish($limit)
    {
        return $this->exec_query("
            SELECT *
            FROM dish INNER JOIN
            (
                SELECT dish, sum(quantity) as qnt
                FROM orders
                    INNER JOIN cart ON orders.cart_id = cart.id
                    INNER JOIN listCartDish ON listCartDish.cart_id = cart.id
                    INNER JOIN dish ON listCartDish.dish = dish.d_name
                WHERE dish.deleted=false
                GROUP BY dish
                ORDER BY qnt desc,dish asc
                limit ?
            ) AS D
            ON dish.d_name = D.dish
            INNER JOIN picture
            ON dish.picture = picture.p_id
        ", "i", $limit);
    }

    // CATEGORY
    public function add_category($name)
    {
        $cat = $this->exec_query("
            SELECT *
            FROM category
            WHERE c_name=?
        ", "s", $name);
        if ($cat) {
            return $this->exec_non_query("
                UPDATE category
                SET deleted=false
                WHERE c_name=?;
            ", "s", $name);
        } else {
            return $this->exec_non_query("
                INSERT INTO category(c_name)
                VALUES (?)
        ", "s", $name);
        }
    }


    public function get_deletable_category()
    {
        return $this->exec_query("
            SELECT DISTINCT c_id,c_name
            FROM category LEFT JOIN (select category, d_name from dish where deleted=false) as A
            ON c_id=A.category
            WHERE d_name IS NULL and category.deleted=false
        ");
    }

    public function get_menu_category()
    {
        return $this->exec_query("
            SELECT DISTINCT c_id, c_name
            FROM category LEFT JOIN dish
            ON c_id=dish.category
            WHERE d_name IS NOT NULL and dish.deleted=false and category.deleted=false
        ", "");
    }

    public function remove_category($id)
    {
        return $this->exec_non_query("
            UPDATE category
            SET deleted=true
            WHERE c_id=?
        ", "i", $id);
    }

    public function is_category_present($name)
    {
        return $this->exec_query("
            SELECT *
            FROM category
            WHERE c_name=? and deleted=false
        ", "s", $name) != false;
    }

    public function get_category_by_id($id)
    {
        return $this->exec_query("
            SELECT c_name
            FROM category
            WHERE c_id=? and deleted=false
        ", "i", $id);
    }

    public function get_all_category()
    {
        return $this->exec_query("
            SELECT *
            FROM category
            where deleted=false
        ");
    }


    // NEWS
    public function add_news($title, $content, $date, $img)
    {
        $res = $this->exec_query("
            SELECT p_id
            FROM picture
            WHERE p_path=?
        ", "s", $img);
        $id = $res ? $res[0]["p_id"] : false;
        return $id && $this->exec_non_query("
            INSERT INTO news(title, summary, picture, creation_date)
            VALUES (?,?,?,?)
        ", "ssis", $title, $content, $id, $date);
    }

    public function remove_news($id)
    {
        return $this->exec_non_query("
            DELETE
            FROM news
            WHERE n_id IN(" . str_repeat('?,', count($id) - 1)  .  "?)
        ", str_repeat('i', count($id)), ...$id);
    }

    public function get_last_news($n)
    {
        return $this->exec_query("
            SELECT *
            FROM news INNER JOIN picture
            ON news.picture = picture.p_id
            ORDER BY creation_date
            DESC LIMIT ?
        ", "i", $n);
    }

    public function get_all_news()
    {
        return $this->exec_query("
            SELECT *
            FROM news INNER JOIN picture
            ON news.picture = picture.p_id
            ORDER BY creation_date DESC
        ");
    }


    // USER
    public function add_user($first_name, $last_name, $username, $email, $pw)
    {
        return $this->exec_non_query("
            INSERT INTO users(first_name, last_name, username, email, pw)
            VALUES (?,?,?,?,?)
        ", "sssss", $first_name, $last_name, $username, $email, $pw);
    }

    public function update_user($user, $first_name, $last_name, $email)
    {
        return $this->exec_non_query("
            UPDATE users
            SET
                first_name=?,
                last_name=?,
                email=?
            WHERE username=?
        ", "ssss", $first_name, $last_name, $email, $user);
    }

    public function is_user_present($username)
    {
        return $this->exec_query("
            SELECT *
            FROM users
            WHERE username=?
        ", "s", $username) != false;
    }

    public function validate_user($username, $pw)
    {
        return $this->exec_query("
            SELECT first_name, last_name, username, email, is_admin
            FROM users
            WHERE username=? AND pw=?
        ", "ss", $username, $pw);
    }

    public function reset_user_password($user, $new_password)
    {
        return $this->exec_non_query("
            UPDATE users
            SET
                pw=?
            WHERE username=?
        ", "ss", $new_password, $user);
    }


    // ORDER
    public function add_order($cart, $date, $delivery_date, $addr, $take_away, $tot)
    {
        $take_away = $take_away ? 'true' : 'false';
        return $this->exec_non_query("
            INSERT INTO orders(cart_id, pay_date, delivery_date, delivery_address, take_away, tot_price)
            VALUES (?,?,?,?,?,?)
        ", "isssid", $cart, $date, $delivery_date, $addr, $take_away, $tot);
    }

    public function get_order_by_user($username)
    {
        return $this->exec_query("
            SELECT *
            FROM orders INNER JOIN cart
            ON orders.cart_id = cart.id
            WHERE users=?
        ", "s", $username);
    }

    public function get_order_by_date($date)
    {
        return $this->exec_query("
            SELECT *
            FROM orders
            WHERE pay_date=?
        ", "s", $date);
    }


    // CART
    public function add_cart($username)
    {
        return $this->exec_non_query("
            INSERT INTO cart(users)
            VALUES (?)
        ", "s", $username);
    }

    public function get_active_cart($username)
    {
        return $this->exec_query("
            SELECT C.id
            FROM orders RIGHT JOIN ( SELECT * FROM cart WHERE users=?) as C
            ON orders.cart_id = C.id
            WHERE orders.cart_id IS NULL
        ", "s", $username);
    }

    // LIST CART DISH
    public function get_cart_content($cart)
    {
        return $this->exec_query("
            SELECT *
            FROM listCartDish
            INNER JOIN dish
            ON listCartDish.dish=dish.d_name
            INNER JOIN picture
            ON dish.picture = picture.p_id
            WHERE cart_id=?
        ", "i", $cart);
    }

    public function replace_cart_content($cart, $content) // content --> (dish, quantity)
    {
        $batch = "
            DELETE
            FROM listCartDish
            WHERE cart_id=?";
        $ok = $this->exec_non_query($batch, "i", $cart);
        if ($ok && count($content)) {
            $content_size = count($content);
            for ($i = 0; $i < $content_size && $ok; $i++)
                $ok = $this->exec_non_query("
                        INSERT INTO listCartDish(cart_id, dish, quantity)
                        VALUES(?,?,?);
                    ", "isi", $cart, $content[$i][0], $content[$i][1]) && $ok;
        }

        return $ok;
    }



    // PICTURE
    public function add_picture($src, $alt)
    {
        return $this->exec_non_query("
            INSERT INTO picture(p_path, alt)
            VALUES (?,?)
        ", "ss", $src, $alt);
    }

    // PRIVATE
    private function exec_query($cmd, $paramsType = "", ...$params)
    {
        $stmt = $this->conn->prepare($cmd);
        if ($paramsType != "")
            $stmt->bind_param($paramsType, ...$params);

        $stmt->execute();
        $result = $stmt->get_result();
        $val = $result->fetch_all(MYSQLI_ASSOC);
        $result->free();

        return $val != null ? $val : false;
    }

    private function exec_non_query($cmd, $paramsType = "", ...$params)
    {
        $stmt = $this->conn->prepare($cmd);
        if (count($params) > 0)
            $stmt->bind_param($paramsType, ...$params);

        return $stmt->execute();
    }
};
