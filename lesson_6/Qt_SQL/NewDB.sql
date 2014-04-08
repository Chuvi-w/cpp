BEGIN TRANSACTION;
CREATE TABLE Student (id INTEGER PRIMARY KEY, name TEXT, surname TEXT);
INSERT INTO Student VALUES(1,'Иван','Иванов');
INSERT INTO Student VALUES(2,'Пётр','Петров');
INSERT INTO Student VALUES(3,NULL,NULL);
CREATE TABLE Subject (name TEXT, id INTEGER PRIMARY KEY);
INSERT INTO Subject VALUES('История',1);
INSERT INTO Subject VALUES('География',2);
INSERT INTO Subject VALUES('Музыка',3);
INSERT INTO Subject VALUES('Информатика',4);
COMMIT;