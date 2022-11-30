DROP DATABASE assignment;
CREATE DATABASE assignment;
USE assignment;

CREATE TABLE Address (
  Address VARCHAR(45) NOT NULL,
  PostalCode VARCHAR(45),
  Nation VARCHAR(45),
  PRIMARY KEY (Address)
); 

CREATE TABLE Person1 (
  Person_ID INT NOT NULL,
  Name VARCHAR(45),
  Phone VARCHAR(45),
  Email VARCHAR(62),
  Address VARCHAR(95),
  PRIMARY KEY (Person_ID),
  FOREIGN KEY (Address) REFERENCES Address(Address)
);

CREATE TABLE Department (
  Dept_Name VARCHAR(45) NOT NULL,
  DeptNum INT,
  PRIMARY KEY (Dept_Name)
); 

CREATE TABLE Laboratory1 (
  Dept_Name VARCHAR(45) NOT NULL,
  Lab_Name VARCHAR(45) NOT NULL,
  Capacity VARCHAR(45),
  Location VARCHAR(45),
  PRIMARY KEY (Dept_Name, Lab_Name),
  FOREIGN KEY (Dept_Name) REFERENCES Department (Dept_Name)
  ON UPDATE CASCADE
); 

CREATE TABLE Schools (
  School_Name VARCHAR(45) NOT NULL,
  Person_ID INT NOT NULL,
  PRIMARY KEY (School_Name, Person_ID),
  FOREIGN KEY (Person_ID) REFERENCES Person1 (Person_ID)
  ON DELETE CASCADE
  ON UPDATE CASCADE
); 

CREATE TABLE Staff (
  Person_ID INT NOT NULL,
  Staff_ID INT NOT NULL,
  Date_hired DATETIME,
  Position VARCHAR(45),
  PRIMARY KEY (Staff_ID),
  FOREIGN KEY (Person_ID) REFERENCES Person1 (Person_ID)
  ON DELETE CASCADE
  ON UPDATE CASCADE
); 

CREATE TABLE Student (
  Person_ID INT NOT NULL,
  Student_ID INT NOT NULL,
  Year INT,
  PRIMARY KEY (Student_ID),
  FOREIGN KEY (Person_ID) REFERENCES Person1 (Person_ID)
  ON DELETE CASCADE
  ON UPDATE CASCADE
); 

CREATE TABLE Majors (
  Student_ID INT NOT NULL,
  Major VARCHAR(45) NOT NULL,
  PRIMARY KEY (Student_ID, Major),
  FOREIGN KEY (Student_ID) REFERENCES Student (Student_ID)
  ON DELETE CASCADE
  ON UPDATE CASCADE
); 

CREATE TABLE Minors (
  Student_ID INT NOT NULL,
  Minor VARCHAR(45) NOT NULL,
  PRIMARY KEY (Student_ID, Minor),
  FOREIGN KEY (Student_ID) REFERENCES Student (Student_ID)
  ON DELETE CASCADE
  ON UPDATE CASCADE
); 

CREATE TABLE Professor (
  Person_ID INT NOT NULL,
  Professor_ID INT NOT NULL,
  Dept_Name VARCHAR(45),
  Major VARCHAR(45),
  PRIMARY KEY (Professor_ID),
  FOREIGN KEY (Person_ID) REFERENCES Person1 (Person_ID)
  ON DELETE CASCADE
  ON UPDATE CASCADE,
  FOREIGN KEY (Dept_Name) REFERENCES Department (Dept_Name)
  ON UPDATE CASCADE
); 

CREATE TABLE Stakeholder (
  Person_ID INT NOT NULL,
  Domain VARCHAR(45),
  PRIMARY KEY (Person_ID),
  FOREIGN KEY (Person_ID) REFERENCES Person1 (Person_ID)
  ON DELETE CASCADE
  ON UPDATE CASCADE
); 

CREATE TABLE Course (
  Cid INT NOT NULL,
  Credit INT,
  Date_time DATETIME,
  Name VARCHAR(45),
  Professor_ID INT NOT NULL,
  PRIMARY KEY (Cid),
  FOREIGN KEY (Professor_ID) REFERENCES Professor (Professor_ID)
  ON DELETE CASCADE
  ON UPDATE CASCADE
); 

CREATE TABLE Take (
  Student_ID INT NOT NULL,
  Cid INT NOT NULL,
  PRIMARY KEY (Student_ID, Cid),
  FOREIGN KEY (Student_ID) REFERENCES Student (Student_ID)
  ON DELETE CASCADE
  ON UPDATE CASCADE,
  FOREIGN KEY (Cid) REFERENCES Course (Cid)
  ON DELETE CASCADE
  ON UPDATE CASCADE
); 

CREATE TABLE Undergrad (
  Student_ID INT NOT NULL,
  PRIMARY KEY (Student_ID),
  FOREIGN KEY (Student_ID) REFERENCES Student (Student_ID)
  ON DELETE CASCADE
  ON UPDATE CASCADE
); 

CREATE TABLE Graduate (
  Student_ID INT NOT NULL,
  PRIMARY KEY (Student_ID),
  FOREIGN KEY (Student_ID) REFERENCES Student (Student_ID)
  ON DELETE CASCADE
  ON UPDATE CASCADE
); 

CREATE TABLE Supervise (
  Graduate_Student_ID INT NOT NULL,
  Professor_ID INT NOT NULL,
  Topic VARCHAR(45),
  PRIMARY KEY (Graduate_Student_ID, Professor_ID),
  FOREIGN KEY (Graduate_Student_ID) REFERENCES Graduate (Student_ID)
  ON DELETE CASCADE
  ON UPDATE CASCADE,
  FOREIGN KEY (Professor_ID) REFERENCES Professor (Professor_ID)
  ON DELETE CASCADE
  ON UPDATE CASCADE
); 

CREATE TABLE Tech_staff (
  Staff_ID INT NOT NULL,
  Laboratory_Dept_Name VARCHAR(45),
  Laboratory_Lab_Name VARCHAR(45),
  PRIMARY KEY (Staff_ID),
  FOREIGN KEY (Staff_ID) REFERENCES Staff (Staff_ID)
  ON DELETE CASCADE
  ON UPDATE CASCADE,
  FOREIGN KEY (Laboratory_Dept_Name, Laboratory_Lab_Name) REFERENCES Laboratory1 (Dept_Name, Lab_Name)
  ON DELETE SET NULL
  ON UPDATE CASCADE
); 

CREATE TABLE Teaching_Laboratory (
  Dept_Name VARCHAR(45) NOT NULL,
  Lab_Name VARCHAR(45) NOT NULL,
  PRIMARY KEY (Dept_Name, Lab_Name),
  FOREIGN KEY (Dept_Name, Lab_Name) REFERENCES Laboratory1 (Dept_Name, Lab_Name)
  ON DELETE CASCADE
  ON UPDATE CASCADE
); 

CREATE TABLE Experiments (
  Dept_Name VARCHAR(45) NOT NULL,
  Lab_Name VARCHAR(45) NOT NULL,
  Student_ID INT NOT NULL,
  Date DATETIME,
  PRIMARY KEY (Dept_Name, Lab_Name, Student_ID),
  FOREIGN KEY (Dept_Name, Lab_Name) REFERENCES Teaching_Laboratory (Dept_Name, Lab_Name)
  ON DELETE CASCADE
  ON UPDATE CASCADE,
  FOREIGN KEY (Student_ID) REFERENCES Undergrad (Student_ID)
  ON DELETE CASCADE
  ON UPDATE CASCADE
); 

CREATE TABLE Research_Laboratory (
  Dept_Name VARCHAR(45) NOT NULL,
  Lab_Name VARCHAR(45) NOT NULL,
  PRIMARY KEY (Dept_Name, Lab_Name),
  FOREIGN KEY (Dept_Name, Lab_Name) REFERENCES Laboratory1 (Dept_Name, Lab_Name)
  ON DELETE CASCADE
  ON UPDATE CASCADE
); 

CREATE TABLE Assign (
  Dept_Name VARCHAR(45) NOT NULL,
  Lab_Name VARCHAR(45) NOT NULL,
  Student_ID INT NOT NULL,
  PRIMARY KEY (Dept_Name, Lab_Name, Student_ID),
  FOREIGN KEY (Dept_Name, Lab_Name) REFERENCES Research_Laboratory (Dept_Name, Lab_Name)
  ON DELETE CASCADE
  ON UPDATE CASCADE,
  FOREIGN KEY (Student_ID) REFERENCES Graduate (Student_ID)
  ON DELETE CASCADE
  ON UPDATE CASCADE
); 

CREATE TABLE Admin_Staff (
  Staff_ID INT NOT NULL,
  PRIMARY KEY (Staff_ID),
  FOREIGN KEY (Staff_ID) REFERENCES Staff (Staff_ID)
  ON DELETE CASCADE
  ON UPDATE CASCADE
); 

CREATE TABLE Admin_Manager (
  Staff_ID INT NOT NULL,
  Professor_ID INT,
  PRIMARY KEY (Staff_ID),
  FOREIGN KEY (Staff_ID) REFERENCES Admin_Staff (Staff_ID)
  ON DELETE CASCADE
  ON UPDATE CASCADE,
  FOREIGN KEY (Professor_ID) REFERENCES Professor (Professor_ID)
  ON DELETE SET NULL
  ON UPDATE CASCADE
); 

CREATE TABLE Comments (
  Stakeholder_Person_ID INT NOT NULL,
  Topic VARCHAR(45) NOT NULL,
  Date DATETIME NOT NULL,
  PRIMARY KEY (Stakeholder_Person_ID, Topic, Date),
  FOREIGN KEY (Stakeholder_Person_ID) REFERENCES Stakeholder (Person_ID)
  ON DELETE CASCADE
  ON UPDATE CASCADE
); 

CREATE TABLE Model_Name (
  Model_No INT NOT NULL,
  Name VARCHAR(45),
  PRIMARY KEY (Model_No)
); 

CREATE TABLE Equipment1 (
  Dept_Name VARCHAR(45) NOT NULL,
  Lab_Name VARCHAR(45) NOT NULL,
  ID INT NOT NULL,
  Date_purchased DATETIME,
  Model_No INT,
  PRIMARY KEY (Dept_Name, Lab_Name, ID),
  FOREIGN KEY (Dept_Name, Lab_Name) REFERENCES Laboratory1 (Dept_Name, Lab_Name)
  ON DELETE CASCADE
  ON UPDATE CASCADE,
  FOREIGN KEY (Model_No) REFERENCES Model_Name (Model_No)
  ON DELETE CASCADE
  ON UPDATE CASCADE
); 
