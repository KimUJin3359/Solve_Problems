/* 1�� */
SELECT ANIMAL_ID FROM ANIMAL_INS WHERE NAME IS NULL;

/* 2�� */
SELECT ANIMAL_ID FROM ANIMAL_INS WHERE NAME IS NOT NULL;

/* 3�� */
SELECT ANIMAL_TYPE, IFNULL(NAME, "No name"), SEX_UPON_INTAKE FROM ANIMAL_INS;


