/* 1번 */
SELECT * FROM ANIMAL_INS ORDER BY ANIMAL_ID;

/* 2번 */
SELECT NAME, DATETIME FROM ANIMAL_INS ORDER BY ANIMAL_ID DESC;

/* 3번 */
SELECT ANIMAL_ID, NAME FROM ANIMAL_INS WHERE INTAKE_CONDITION = 'Sick';

/* 4번 */
SELECT ANIMAL_ID, NAME FROM ANIMAL_INS WHERE INTAKE_CONDITION != 'Aged' ORDER BY ANIMAL_ID;

/* 5번 */
SELECT ANIMAL_ID, NAME FROM ANIMAL_INS ORDER BY ANIMAL_ID;

/* 6번 */
SELECT ANIMAL_ID, NAME, DATETIME FROM ANIMAL_INS ORDER BY NAME, DATETIME DESC;

/* 7번 */
SELECT NAME FROM ANIMAL_INS ORDER BY DATETIME LIMIT 1;