use assignment;

INSERT INTO Address VALUE ("50, UNIST-gil, Eonyang-eup, Ulju-gun, Ulsan", "44919", "Korea");
INSERT INTO Address VALUE ("242, Cheomdan-ro, Jeju-si, Jeju-do", "63309", "Korea");

INSERT INTO Person1 VALUE (1, "staff1", "010-7777-7777", "staff1@unist.ac.kr", "50, UNIST-gil, Eonyang-eup, Ulju-gun, Ulsan");
INSERT INTO Person1 VALUE (2, "staff2", "010-3333-3333", "staff2@unist.ac.kr", "50, UNIST-gil, Eonyang-eup, Ulju-gun, Ulsan");
INSERT INTO Person1 VALUE (3, "student1", "010-1234-1234", "student1@unist.ac.kr", "50, UNIST-gil, Eonyang-eup, Ulju-gun, Ulsan");
INSERT INTO Person1 VALUE (4, "student2", "010-4321-4321", "student2@unist.ac.kr", "50, UNIST-gil, Eonyang-eup, Ulju-gun, Ulsan");
INSERT INTO Person1 VALUE (5, "student3", "010-1234-5678", "student3@unist.ac.kr", "50, UNIST-gil, Eonyang-eup, Ulju-gun, Ulsan");
INSERT INTO Person1 VALUE (6, "student4", "010-1234-4321", "student4@unist.ac.kr", "50, UNIST-gil, Eonyang-eup, Ulju-gun, Ulsan");
INSERT INTO Person1 VALUE (7, "student5", "010-1234-0987", "student5@unist.ac.kr", "50, UNIST-gil, Eonyang-eup, Ulju-gun, Ulsan");
INSERT INTO Person1 VALUE (8, "student6", "010-1234-2231", "student5@unist.ac.kr", "50, UNIST-gil, Eonyang-eup, Ulju-gun, Ulsan");
INSERT INTO Person1 VALUE (9, "student7", "010-1234-3342", "student5@unist.ac.kr", "50, UNIST-gil, Eonyang-eup, Ulju-gun, Ulsan");
INSERT INTO Person1 VALUE (10, "student8", "010-1234-4451", "student5@unist.ac.kr", "50, UNIST-gil, Eonyang-eup, Ulju-gun, Ulsan");
INSERT INTO Person1 VALUE (11, "student9", "010-1234-5567", "student5@unist.ac.kr", "50, UNIST-gil, Eonyang-eup, Ulju-gun, Ulsan");
INSERT INTO Person1 VALUE (12, "student10", "010-1234-6675", "student5@unist.ac.kr", "50, UNIST-gil, Eonyang-eup, Ulju-gun, Ulsan");
INSERT INTO Person1 VALUE (13, "professor1", "010-0000-0000", "professor1@unist.ac.kr", "50, UNIST-gil, Eonyang-eup, Ulju-gun, Ulsan");
INSERT INTO Person1 VALUE (14, "professor2", "010-1111-1111", "professor2@unist.ac.kr", "50, UNIST-gil, Eonyang-eup, Ulju-gun, Ulsan");
INSERT INTO Person1 VALUE (15, "professor3", "010-1111-0000", "professor3@unist.ac.kr", "50, UNIST-gil, Eonyang-eup, Ulju-gun, Ulsan");
INSERT INTO Person1 VALUE (16, "professor4", "010-0000-1111", "professor4@unist.ac.kr", "50, UNIST-gil, Eonyang-eup, Ulju-gun, Ulsan");
INSERT INTO Person1 VALUE (17, "stakeholder1", "010-9999-1111", "stakeholder1@unist.ac.kr", "50, UNIST-gil, Eonyang-eup, Ulju-gun, Ulsan");
INSERT INTO Person1 VALUE (18, "stakeholder2", "010-8777-1111", "stakeholder2@unist.ac.kr", "50, UNIST-gil, Eonyang-eup, Ulju-gun, Ulsan");

INSERT INTO Department VALUE ("Computer Science Engineering", 1);
INSERT INTO Department VALUE ("Business Administration", 2);

-- Not sure why capacity is varchar
INSERT INTO Laboratory1 VALUE ("Computer Science Engineering", "System Lab", "20", "50, UNIST-gil, Eonyang-eup, Ulju-gun, Ulsan");
INSERT INTO Laboratory1 VALUE ("Computer Science Engineering", "Network Lab", "30", "50, UNIST-gil, Eonyang-eup, Ulju-gun, Ulsan");
INSERT INTO Laboratory1 VALUE ("Computer Science Engineering", "Algorithm Lab", "40", "50, UNIST-gil, Eonyang-eup, Ulju-gun, Ulsan");
INSERT INTO Laboratory1 VALUE ("Business Administration", "Management Information System Lab", "10", "50, UNIST-gil, Eonyang-eup, Ulju-gun, Ulsan");
INSERT INTO Laboratory1 VALUE ("Business Administration", "Marketing Lab", "10", "50, UNIST-gil, Eonyang-eup, Ulju-gun, Ulsan");

INSERT INTO Schools VALUE ("UNIST", 1);
INSERT INTO Schools VALUE ("UNIST", 2);
INSERT INTO Schools VALUE ("UNIST", 3);
INSERT INTO Schools VALUE ("UNIST", 4);
INSERT INTO Schools VALUE ("UNIST", 5);

INSERT INTO Staff VALUE (1, 1, "2020-01-01 00:00:00", "Administrative Officer");
INSERT INTO Staff VALUE (2, 2, "2021-01-01 00:00:00", "Administrative Officer");
INSERT INTO Staff VALUE (3, 3, "2021-01-01 00:00:00", "Administrative Officer");

INSERT INTO Student VALUE (3, 1, 2016);
INSERT INTO Student VALUE (4, 2, 2017);
INSERT INTO Student VALUE (5, 3, 2018);
INSERT INTO Student VALUE (6, 4, 2019);
INSERT INTO Student VALUE (7, 5, 2020);
INSERT INTO Student VALUE (8, 6, 2020);
INSERT INTO Student VALUE (9, 7, 2020);
INSERT INTO Student VALUE (10, 8, 2020);
INSERT INTO Student VALUE (11, 9, 2020);
INSERT INTO Student VALUE (12, 10, 2020);

INSERT INTO Majors VALUE (1, "Computer Science Engineering");
INSERT INTO Majors VALUE (2, "Computer Science Engineering");
INSERT INTO Majors VALUE (3, "Computer Science Engineering");
INSERT INTO Majors VALUE (4, "Computer Science Engineering");
INSERT INTO Majors VALUE (5, "Computer Science Engineering");
INSERT INTO Majors VALUE (6, "Computer Science Engineering");
INSERT INTO Majors VALUE (7, "Computer Science Engineering");
INSERT INTO Majors VALUE (8, "Computer Science Engineering");
INSERT INTO Majors VALUE (9, "Computer Science Engineering");
INSERT INTO Majors VALUE (10, "Business Administration");

INSERT INTO Minors VALUE (1, "Business Administration");
INSERT INTO Minors VALUE (2, "Business Administration");
INSERT INTO Minors VALUE (3, "Business Administration");
INSERT INTO Minors VALUE (4, "Business Administration");
INSERT INTO Minors VALUE (5, "Business Administration");
INSERT INTO Minors VALUE (6, "Business Administration");
INSERT INTO Minors VALUE (7, "Business Administration");
INSERT INTO Minors VALUE (8, "Business Administration");
INSERT INTO Minors VALUE (9, "Business Administration");
INSERT INTO Minors VALUE (10, "Computer Science Engineering");

INSERT INTO Professor VALUE (11, 1, "Computer Science Engineering", "Computer Science Engineering");
INSERT INTO Professor VALUE (12, 2, "Computer Science Engineering", "Computer Science Engineering");
INSERT INTO Professor VALUE (13, 3, "Computer Science Engineering", "Computer Science Engineering");
INSERT INTO Professor VALUE (14, 4, "Business Administration", "Business Administration");

INSERT INTO Stakeholder VALUE (15, "Individual");
INSERT INTO Stakeholder VALUE (16, "Government");
INSERT INTO Stakeholder VALUE (17, "Individual");
INSERT INTO Stakeholder VALUE (18, "Overseas");



INSERT INTO Course VALUE (1, 3, "2022-09-01 00:00:00", "Database", 1);
INSERT INTO Course VALUE (2, 3, "2022-09-01 00:00:00", "Network", 2);
INSERT INTO Course VALUE (3, 3, "2022-09-01 00:00:00", "Algorithm", 3);
INSERT INTO Course VALUE (4, 3, "2022-09-01 00:00:00", "Marketing", 4);
INSERT INTO Course VALUE (5, 3, "2022-09-01 00:00:00", "Principles of Economics", 4);
INSERT INTO Course VALUE (6, 3, "2022-09-01 00:00:00", "Computer Vision", 3);

-- (Student ID - CID)
INSERT INTO Take VALUE (1, 1);
INSERT INTO Take VALUE (2, 1);
INSERT INTO Take VALUE (3, 1);
INSERT INTO Take VALUE (4, 1);
INSERT INTO Take VALUE (5, 1);

INSERT INTO Take VALUE (1, 2);
INSERT INTO Take VALUE (2, 2);
INSERT INTO Take VALUE (3, 2);
INSERT INTO Take VALUE (4, 2);
INSERT INTO Take VALUE (5, 2);


INSERT INTO Take VALUE (1, 3);
INSERT INTO Take VALUE (2, 3);
INSERT INTO Take VALUE (3, 3);

INSERT INTO Take VALUE (1, 4);
INSERT INTO Take VALUE (2, 4);

INSERT INTO Take VALUE (1, 5);
INSERT INTO Take VALUE (2, 5);

INSERT INTO Take VALUE (1, 6);
INSERT INTO Take VALUE (2, 6);


INSERT INTO Undergrad VALUE (1);
INSERT INTO Undergrad VALUE (2);
INSERT INTO Undergrad VALUE (3);
INSERT INTO Undergrad VALUE (4);

INSERT INTO Graduate VALUE (5);
INSERT INTO Graduate VALUE (6);
INSERT INTO Graduate VALUE (7);
INSERT INTO Graduate VALUE (8);
INSERT INTO Graduate VALUE (9);
INSERT INTO Graduate VALUE (10);

INSERT INTO Supervise VALUE (5, 1, "Algorithm Optimization1");
INSERT INTO Supervise VALUE (6, 1, "Algorithm Optimization2");
INSERT INTO Supervise VALUE (7, 1, "Algorithm Optimization3");
INSERT INTO Supervise VALUE (8, 1, "Algorithm Optimization4");
INSERT INTO Supervise VALUE (9, 1, "Algorithm Optimization5");
INSERT INTO Supervise VALUE (10, 4, "Business Skill");

INSERT INTO Tech_staff VALUE (1, "Computer Science Engineering", "System Lab");
INSERT INTO Tech_staff VALUE (2, "Business Administration", "Management Information System Lab");
INSERT INTO Tech_staff VALUE (3, "Business Administration", "Marketing Lab");

INSERT INTO Teaching_Laboratory VALUE ("Computer Science Engineering", "System Lab");
INSERT INTO Teaching_Laboratory VALUE ("Business Administration", "Management Information System Lab");
INSERT INTO Teaching_Laboratory VALUE ("Business Administration", "Marketing Lab");

INSERT INTO Experiments VALUE ("Computer Science Engineering", "System Lab", 1, "2022-10-01 00:00:00");
INSERT INTO Experiments VALUE ("Business Administration", "Management Information System Lab", 1, "2022-10-01 00:00:00");
INSERT INTO Experiments VALUE ("Computer Science Engineering", "System Lab", 2, "2022-10-01 00:00:00");
INSERT INTO Experiments VALUE ("Business Administration", "Management Information System Lab", 2, "2022-10-01 00:00:00");
INSERT INTO Experiments VALUE ("Business Administration", "Marketing Lab", 2, "2022-10-01 00:00:00");
INSERT INTO Experiments VALUE ("Computer Science Engineering", "System Lab", 3, "2022-10-01 00:00:00");

INSERT INTO Research_Laboratory VALUE ("Computer Science Engineering", "Algorithm Lab");
INSERT INTO Research_Laboratory VALUE ("Computer Science Engineering", "Network Lab");

INSERT INTO Assign VALUE ("Computer Science Engineering", "Algorithm Lab", 5);

INSERT INTO Admin_Staff VALUE (1);

INSERT INTO Admin_Manager VALUE (1, 1);
INSERT INTO Admin_Manager VALUE (2, 3);
INSERT INTO Admin_Manager VALUE (3, 2);
INSERT INTO Admin_Manager VALUE (4, 2);
INSERT INTO Admin_Manager VALUE (5, 2);
INSERT INTO Admin_Manager VALUE (6, 4);
INSERT INTO Admin_Manager VALUE (7, 1);
INSERT INTO Admin_Manager VALUE (8, 3);
INSERT INTO Admin_Manager VALUE (9, 2);

INSERT INTO Comments VALUE (15, "Regarding CSE Curriculum", "2022-11-01 00:00:00");
INSERT INTO Comments VALUE (16, "CSE Events", "2022-12-01 00:00:00");
INSERT INTO Comments VALUE (17, "Regarding scholarship", "2022-12-02 00:00:00");
INSERT INTO Comments VALUE (18, "Academic Calendar", "2022-12-02 00:00:00");
INSERT INTO Comments VALUE (17, "More scholarships for students", "2022-12-02 00:00:00");
INSERT INTO Comments VALUE (16, "Regarding CSE Gatherings", "2022-12-02 00:00:00");
INSERT INTO Comments VALUE (15, "Scholarship issues", "2022-12-02 00:00:00");

-- Not sure what should be Model Name
INSERT INTO Model_Name VALUE (1, "Model1");
INSERT INTO Model_Name VALUE (2, "Model2");

INSERT INTO Equipment1 VALUE ("Computer Science Engineering", "System Lab", 1, "2022-10-01 00:00:00", 1);
INSERT INTO Equipment1 VALUE ("Computer Science Engineering", "System Lab", 2, "2022-10-01 00:00:00", 2);
INSERT INTO Equipment1 VALUE ("Computer Science Engineering", "Network Lab", 3, "2022-10-01 00:00:00", 2);
