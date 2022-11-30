use assignment;

-- Identify all Stakeholders who have provided at least two comments or suggestions.
SELECT *
FROM Person1
WHERE Person_ID IN (
    SELECT Stakeholder_Person_ID
    FROM Comments 
    GROUP BY Stakeholder_Person_ID 
    HAVING COUNT(Stakeholder_Person_ID) >= 2);


-- Identify Undergraduate students who take over 15 credits and conduct experiments in three different labs.
SELECT *
FROM Person1
WHERE Person_ID IN (
    SELECT T1.Person_ID
    FROM Student AS T1
    INNER JOIN (
        SELECT Student_ID
        FROM Take, Course
        WHERE Take.Cid = Course.Cid
        GROUP BY Student_ID
        HAVING SUM(Credit) > 15) AS T2
    ON T1.Student_ID = T2.Student_ID
    INNER JOIN (
        SELECT Student_ID
        FROM Experiments
        GROUP BY Student_ID
        HAVING COUNT(*) = 3) AS T3
    ON T1.Student_ID = T3.Student_ID);


-- Find all the graduate students who take research labs of the CS department.
SELECT *
FROM Person1
WHERE Person_ID IN (
    SELECT DISTINCT Person_ID
    FROM Student AS T1, Assign AS T2
    WHERE T1.Student_ID = T2.Student_ID AND T2.Dept_Name = 'Computer Science Engineering'
);


-- List all the Equipment belonging to a particular Lab.
SELECT *
FROM Equipment1
WHERE Lab_Name = 'Network Lab' AND Dept_Name = 'Computer Science Engineering';


-- Find all Professors who address at least 5 different research topics.
SELECT *
FROM Person1
WHERE Person_ID IN (
    SELECT DISTINCT Person_ID
    FROM Professor AS T1, Supervise AS T2
    WHERE T1.Professor_ID = T2.Professor_ID
    GROUP By T1.Professor_ID
    HAVING COUNT(Topic) >= 5
);


-- Count the number of Technical staff members that are assigned to Teaching Laboratories in any --
-- department, where at least two students are conducting an experiment    --
SELECT COUNT(*)
FROM Tech_staff AS S 
WHERE S.Laboratory_Lab_Name IN (
	SELECT Lab_Name
    FROM Experiments
    GROUP By Lab_Name
	HAVING COUNT(Student_ID) > 1
);


-- Identify the Professor that hired more than one Administrative managers --
SELECT Professor_ID, COUNT(Staff_ID) AS AmountHired
FROM Admin_Manager
GROUP BY Professor_ID
HAVING COUNT(Staff_ID) > 1;


-- List all comments regarding scholarship and whose stakeholders are Individuals --

SELECT *
FROM Comments
WHERE Topic LIKE '%cholarship%' AND Stakeholder_Person_ID IN (
	SELECT Person_ID
	FROM Comments as C, Stakeholder as S
	WHERE C.Stakeholder_Person_ID = S.Person_ID AND S.Domain = 'Individual');



