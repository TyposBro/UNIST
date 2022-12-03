USE assignment;
DELIMITER $$ CREATE TRIGGER AFTER_INSERT_Person1
AFTER
INSERT ON Person1 BEGIN PRINT("Successfully inserted records into Person1")
END $$ DELIMITER;
DELIMITER $$ CREATE TRIGGER AFTER_INSERT_Department
AFTER
INSERT ON Department BEGIN PRINT("Successfully inserted records into Department")
END $$ DELIMITER;
DELIMITER $$ CREATE TRIGGER AFTER_INSERT_Laboratory
AFTER
INSERT ON Laboratory BEGIN PRINT("Successfully inserted records into Laboratory")
END $$ DELIMITER;
DELIMITER $$ CREATE TRIGGER AFTER_INSERT_Schools
AFTER
INSERT ON Schools BEGIN PRINT("Successfully inserted records into Schools")
END $$ DELIMITER;
DELIMITER $$ CREATE TRIGGER AFTER_INSERT_Staff
AFTER
INSERT ON Staff BEGIN PRINT("Successfully inserted records into Staff")
END $$ DELIMITER;
DELIMITER $$ CREATE TRIGGER AFTER_INSERT_Student
AFTER
INSERT ON Student BEGIN PRINT("Successfully inserted records into Student")
END $$ DELIMITER;
DELIMITER $$ CREATE TRIGGER AFTER_INSERT_Majors
AFTER
INSERT ON Majors BEGIN PRINT("Successfully inserted records into Majors")
END $$ DELIMITER;
DELIMITER $$ CREATE TRIGGER AFTER_INSERT_Minors
AFTER
INSERT ON Minors BEGIN PRINT("Successfully inserted records into Minors")
END $$ DELIMITER;
DELIMITER $$ CREATE TRIGGER AFTER_INSERT_Professor
AFTER
INSERT ON Professor BEGIN PRINT("Successfully inserted records into Professor")
END $$ DELIMITER;
DELIMITER $$ CREATE TRIGGER AFTER_INSERT_Stakeholder
AFTER
INSERT ON Stakeholder BEGIN PRINT("Successfully inserted records into Stakeholder")
END $$ DELIMITER;
DELIMITER $$ CREATE TRIGGER AFTER_INSERT_Course
AFTER
INSERT ON Course BEGIN PRINT("Successfully inserted records into Course")
END $$ DELIMITER;
DELIMITER $$ CREATE TRIGGER AFTER_INSERT_Take
AFTER
INSERT ON Take BEGIN PRINT("Successfully inserted records into Take")
END $$ DELIMITER;
DELIMITER $$ CREATE TRIGGER AFTER_INSERT_Undergrad
AFTER
INSERT ON Undergrad BEGIN PRINT("Successfully inserted records into Undergrad")
END $$ DELIMITER;
DELIMITER $$ CREATE TRIGGER AFTER_INSERT_Graduate
AFTER
INSERT ON Graduate BEGIN PRINT("Successfully inserted records into Graduate")
END $$ DELIMITER;
DELIMITER $$ CREATE TRIGGER AFTER_INSERT_Supervise
AFTER
INSERT ON Supervise BEGIN PRINT("Successfully inserted records into Supervise")
END $$ DELIMITER;
DELIMITER $$ CREATE TRIGGER AFTER_INSERT_Tech_staff
AFTER
INSERT ON Tech_staff BEGIN PRINT("Successfully inserted records into Tech_staff")
END $$ DELIMITER;
DELIMITER $$ CREATE TRIGGER AFTER_INSERT_Teaching_Laboratory
AFTER
INSERT ON Teaching_Laboratory BEGIN PRINT(
        "Successfully inserted records into Teaching_Laboratory"
    )
END $$ DELIMITER;
DELIMITER $$ CREATE TRIGGER AFTER_INSERT_Experiments
AFTER
INSERT ON Experiments BEGIN PRINT("Successfully inserted records into Experiments")
END $$ DELIMITER;
DELIMITER $$ CREATE TRIGGER AFTER_INSERT_Research_Laboratory
AFTER
INSERT ON Research_Laboratory BEGIN PRINT(
        "Successfully inserted records into Research_Laboratory"
    )
END $$ DELIMITER;
DELIMITER $$ CREATE TRIGGER AFTER_INSERT_Assign
AFTER
INSERT ON Assign BEGIN PRINT("Successfully inserted records into Assign")
END $$ DELIMITER;
DELIMITER $$ CREATE TRIGGER AFTER_INSERT_Admin_Staff
AFTER
INSERT ON Admin_Staff BEGIN PRINT("Successfully inserted records into Admin_Staff")
END $$ DELIMITER;
DELIMITER $$ CREATE TRIGGER AFTER_INSERT_Admin_Manager
AFTER
INSERT ON Admin_Manager BEGIN PRINT(
        "Successfully inserted records into Admin_Manager"
    )
END $$ DELIMITER;
DELIMITER $$ CREATE TRIGGER AFTER_INSERT_Comments
AFTER
INSERT ON Comments BEGIN PRINT("Successfully inserted records into Comments")
END $$ DELIMITER;
DELIMITER $$ CREATE TRIGGER AFTER_INSERT_Model_Name
AFTER
INSERT ON Model_Name BEGIN PRINT("Successfully inserted records into Model_Name")
END $$ DELIMITER;
DELIMITER $$ CREATE TRIGGER AFTER_INSERT_Equipment1
AFTER
INSERT ON Equipment1 BEGIN PRINT("Successfully inserted records into Equipment1")
END $$ DELIMITER;