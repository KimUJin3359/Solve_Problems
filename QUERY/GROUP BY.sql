/* 1�� */
SELECT ANIMAL_TYPE, COUNT(*) 
FROM ANIMAL_INS 
GROUP BY ANIMAL_TYPE 
ORDER BY ANIMAL_TYPE;

/* 2�� */
SELECT NAME, COUNT(*)
FROM ANIMAL_INS
WHERE NAME IS NOT NULL
GROUP BY NAME
HAVING COUNT(*) > 1
ORDER BY NAME;

/* 3�� */
SELECT HOUR(DATETIME), COUNT(*)
FROM ANIMAL_OUTS
WHERE HOUR(DATETIME) >= 9 AND HOUR(DATETIME) < 20
GROUP BY HOUR(DATETIME)
ORDER BY HOUR(DATETIME);

/* 4�� */
WITH RECURSIVE TIME AS
(
SELECT 0 AS HOURS
UNION ALL
SELECT HOURS + 1 FROM TIME WHERE HOURS < 23
)
SELECT T.HOURS, COUNT(A.ANIMAL_ID)
FROM ANIMAL_OUTS A RIGHT OUTER JOIN TIME T
ON HOUR(A.DATETIME) = T.HOURS
GROUP BY T.HOURS;

/* 5 */
SELECT M.ID as '가맹점 아이디', M.NAME, IFNULL(SUM(U.AMOUNT), 0) as '사용 금액'
FROM MERCHANTS M LEFT OUTER JOIN CARD_USAGES U
ON M.ID = U.MERCHANT_ID
GROUP BY M.ID
ORDER BY IFNULL(SUM(U.AMOUNT), 0) DESC, M.ID ASC;