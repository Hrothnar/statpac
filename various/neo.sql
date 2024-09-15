-- CREATE TABLE users (
--     id INTEGER PRIMARY KEY,
--     name VARCHAR(64) NOT NULL,
--     username VARCHAR(64) NOT NULL UNIQUE,
--     email VARCHAR(64) NOT NULL UNIQUE,
--     age INTEGER,
--     created_at DATETIME DEFAULT CURRENT_TIMESTAMP
-- );

-- ALTER TABLE users ADD COLUMN status VARCHAR(16);

-- DROP TABLE users;

-- INSERT INTO users (name, username, email) VALUES ('Tim', 'myAwesomeUsername', 'email@mail.com');

SELECT * FROM users;