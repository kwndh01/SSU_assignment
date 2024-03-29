-- MySQL dump 10.13  Distrib 8.0.35, for Win64 (x86_64)
--
-- Host: localhost    DataBase: db20212211
-- ------------------------------------------------------
-- Server version	8.0.35

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `account`
--

DROP TABLE IF EXISTS `account`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `account` (
  `account_number` varchar(20) NOT NULL,
  `balance` int DEFAULT NULL,
  PRIMARY KEY (`account_number`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `account`
--

LOCK TABLES `account` WRITE;
/*!40000 ALTER TABLE `account` DISABLE KEYS */;
INSERT INTO `account` VALUES ('1234-012-345678',60),('1234-123-456789',50),('1234-234-567890',40),('1234-345-678901',30),('1234-456-789012',20),('1234-567-890123',100),('1234-901-234567',70);
/*!40000 ALTER TABLE `account` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `borrower`
--

DROP TABLE IF EXISTS `borrower`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `borrower` (
  `customer_id` varchar(3) DEFAULT NULL,
  `loan_number` varchar(20) DEFAULT NULL,
  KEY `customer_id` (`customer_id`),
  KEY `loan_number` (`loan_number`),
  CONSTRAINT `borrower_ibfk_1` FOREIGN KEY (`customer_id`) REFERENCES `customer` (`customer_id`),
  CONSTRAINT `borrower_ibfk_2` FOREIGN KEY (`loan_number`) REFERENCES `loan` (`loan_number`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `borrower`
--

LOCK TABLES `borrower` WRITE;
/*!40000 ALTER TABLE `borrower` DISABLE KEYS */;
INSERT INTO `borrower` VALUES ('cu1','7894-123-456789'),('cu1','7894-234-567890'),('cu1','7894-345-678901'),('cu2','7894-456-789012'),('cu2','7894-567-890123'),('cu2','7894-678-901234'),('cu3','7894-678-901234'),('cu5','7894-345-678901'),('cu5','7894-789-012345');
/*!40000 ALTER TABLE `borrower` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `branch`
--

DROP TABLE IF EXISTS `branch`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `branch` (
  `branch_name` varchar(100) NOT NULL,
  `branch_city` varchar(100) DEFAULT NULL,
  `assets` int DEFAULT NULL,
  PRIMARY KEY (`branch_name`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `branch`
--

LOCK TABLES `branch` WRITE;
/*!40000 ALTER TABLE `branch` DISABLE KEYS */;
INSERT INTO `branch` VALUES ('媛泥쒕?吏??,'?깅궓',300),('?④뎅?吏??,'?⑹씤',400),('?섏썝?吏??,'?섏썝',300),('??떎?吏??,'?쒖슱',500),('?쒖＜?吏??,'?쒖＜',200),('以묒븰?吏??,'?쒖슱',200),('移댁씠?ㅽ듃吏??,'???,100);
/*!40000 ALTER TABLE `branch` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `customer`
--

DROP TABLE IF EXISTS `customer`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `customer` (
  `customer_id` varchar(3) NOT NULL,
  `customer_name` varchar(100) DEFAULT NULL,
  `customer_street` varchar(100) DEFAULT NULL,
  `customer_city` varchar(100) DEFAULT NULL,
  PRIMARY KEY (`customer_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `customer`
--

LOCK TABLES `customer` WRITE;
/*!40000 ALTER TABLE `customer` DISABLE KEYS */;
INSERT INTO `customer` VALUES ('cu1','源??떎','?숈옉援??곷룄濡?369','?쒖슱'),('cu2','?댁쨷??,'?숈옉援??묒꽍濡?84','?쒖슱'),('cu3','諛뺢?泥?,'?섏젙援??깅궓?濡?1342','?깅궓'),('cu4','理쒕떒援?,'?섏?援?二쎌쟾濡?152','?⑹씤'),('cu5','?댁뭅?댁뒪??,'?좎꽦援?臾몄?濡?139','???),('cu6','?대???,'遺?곕??숇줈 49','?묒궛'),('cu7','沅뚭컯??,'?⑹“湲?346','?쇱쿃');
/*!40000 ALTER TABLE `customer` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `customer_banker`
--

DROP TABLE IF EXISTS `customer_banker`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `customer_banker` (
  `customer_id` varchar(3) DEFAULT NULL,
  `employee_id` varchar(3) DEFAULT NULL,
  KEY `customer_id` (`customer_id`),
  KEY `employee_id` (`employee_id`),
  CONSTRAINT `customer_banker_ibfk_1` FOREIGN KEY (`customer_id`) REFERENCES `customer` (`customer_id`),
  CONSTRAINT `customer_banker_ibfk_2` FOREIGN KEY (`employee_id`) REFERENCES `employee` (`employee_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `customer_banker`
--

LOCK TABLES `customer_banker` WRITE;
/*!40000 ALTER TABLE `customer_banker` DISABLE KEYS */;
INSERT INTO `customer_banker` VALUES ('cu1','em1'),('cu2','em2'),('cu3','em3'),('cu4','em3'),('cu5','em4'),('cu7','em1');
/*!40000 ALTER TABLE `customer_banker` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `depositor`
--

DROP TABLE IF EXISTS `depositor`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `depositor` (
  `customer_id` varchar(3) DEFAULT NULL,
  `account_number` varchar(20) DEFAULT NULL,
  KEY `customer_id` (`customer_id`),
  KEY `account_number` (`account_number`),
  CONSTRAINT `depositor_ibfk_1` FOREIGN KEY (`customer_id`) REFERENCES `customer` (`customer_id`),
  CONSTRAINT `depositor_ibfk_2` FOREIGN KEY (`account_number`) REFERENCES `account` (`account_number`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `depositor`
--

LOCK TABLES `depositor` WRITE;
/*!40000 ALTER TABLE `depositor` DISABLE KEYS */;
INSERT INTO `depositor` VALUES ('cu1','1234-567-890123'),('cu2','1234-456-789012'),('cu4','1234-234-567890'),('cu4','1234-123-456789'),('cu6','1234-012-345678'),('cu7','1234-901-234567');
/*!40000 ALTER TABLE `depositor` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `employee`
--

DROP TABLE IF EXISTS `employee`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `employee` (
  `employee_id` varchar(3) NOT NULL,
  `employee_name` varchar(100) DEFAULT NULL,
  `telephone_number` varchar(11) DEFAULT NULL,
  `employee_length` int DEFAULT NULL,
  `start_date` date DEFAULT NULL,
  PRIMARY KEY (`employee_id`),
  KEY `idx_employee_name` (`employee_name`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `employee`
--

LOCK TABLES `employee` WRITE;
/*!40000 ALTER TABLE `employee` DISABLE KEYS */;
INSERT INTO `employee` VALUES ('em1','源?곕━','820-1234',23,'2000-01-01'),('em2','?닿뎅誘?,'881-5678',10,'2012-12-31'),('em3','諛뺥븯??,'713-5678',8,'2015-02-12'),('em4','議곗궛??,'8005-1234',5,'2018-04-12'),('em5','理쒖떊??,'861-4567',3,'2020-10-04'),('em6','?쒕냽??,'515-5467',2,'2021-05-05'),('em7','沅뚮???,'257-1234',1,'2022-07-14');
/*!40000 ALTER TABLE `employee` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `employee_dependent`
--

DROP TABLE IF EXISTS `employee_dependent`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `employee_dependent` (
  `employee_id` varchar(3) DEFAULT NULL,
  `dependent_name` varchar(100) DEFAULT NULL,
  KEY `employee_id` (`employee_id`),
  CONSTRAINT `employee_dependent_ibfk_1` FOREIGN KEY (`employee_id`) REFERENCES `employee` (`employee_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `employee_dependent`
--

LOCK TABLES `employee_dependent` WRITE;
/*!40000 ALTER TABLE `employee_dependent` DISABLE KEYS */;
INSERT INTO `employee_dependent` VALUES ('em5','理쒕???),('em5','理쒕?援?),('em5','理쒗븳誘?),('em5','源?援?);
/*!40000 ALTER TABLE `employee_dependent` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `loan`
--

DROP TABLE IF EXISTS `loan`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `loan` (
  `loan_number` varchar(20) NOT NULL,
  `amount` int DEFAULT NULL,
  PRIMARY KEY (`loan_number`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `loan`
--

LOCK TABLES `loan` WRITE;
/*!40000 ALTER TABLE `loan` DISABLE KEYS */;
INSERT INTO `loan` VALUES ('7894-123-456789',1),('7894-234-567890',2),('7894-345-678901',3),('7894-456-789012',4),('7894-567-890123',5),('7894-678-901234',6),('7894-789-012345',7);
/*!40000 ALTER TABLE `loan` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `loan_branch`
--

DROP TABLE IF EXISTS `loan_branch`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `loan_branch` (
  `loan_number` varchar(20) DEFAULT NULL,
  `branch_name` varchar(100) DEFAULT NULL,
  KEY `loan_number` (`loan_number`),
  KEY `branch_name` (`branch_name`),
  CONSTRAINT `loan_branch_ibfk_1` FOREIGN KEY (`loan_number`) REFERENCES `loan` (`loan_number`),
  CONSTRAINT `loan_branch_ibfk_2` FOREIGN KEY (`branch_name`) REFERENCES `branch` (`branch_name`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `loan_branch`
--

LOCK TABLES `loan_branch` WRITE;
/*!40000 ALTER TABLE `loan_branch` DISABLE KEYS */;
INSERT INTO `loan_branch` VALUES ('7894-123-456789','??떎?吏??),('7894-234-567890','??떎?吏??),('7894-345-678901','??떎?吏??),('7894-456-789012','媛泥쒕?吏??),('7894-567-890123','?쒖＜?吏??),('7894-678-901234','?섏썝?吏??),('7894-789-012345','以묒븰?吏??);
/*!40000 ALTER TABLE `loan_branch` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `manager_worker`
--

DROP TABLE IF EXISTS `manager_worker`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `manager_worker` (
  `employee_manager` varchar(20) DEFAULT NULL,
  `employee_worker` varchar(20) DEFAULT NULL,
  KEY `employee_manager` (`employee_manager`),
  KEY `employee_worker` (`employee_worker`),
  CONSTRAINT `manager_worker_ibfk_1` FOREIGN KEY (`employee_manager`) REFERENCES `employee` (`employee_id`),
  CONSTRAINT `manager_worker_ibfk_2` FOREIGN KEY (`employee_worker`) REFERENCES `employee` (`employee_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `manager_worker`
--

LOCK TABLES `manager_worker` WRITE;
/*!40000 ALTER TABLE `manager_worker` DISABLE KEYS */;
INSERT INTO `manager_worker` VALUES ('em6','em1'),('em6','em2'),('em7','em3'),('em7','em4');
/*!40000 ALTER TABLE `manager_worker` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `payment`
--

DROP TABLE IF EXISTS `payment`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `payment` (
  `loan_number` varchar(20) NOT NULL,
  `payment_number` int NOT NULL,
  `payment_amount` int DEFAULT NULL,
  `payment_date` date DEFAULT NULL,
  PRIMARY KEY (`loan_number`,`payment_number`),
  CONSTRAINT `payment_ibfk_1` FOREIGN KEY (`loan_number`) REFERENCES `loan` (`loan_number`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `payment`
--

LOCK TABLES `payment` WRITE;
/*!40000 ALTER TABLE `payment` DISABLE KEYS */;
INSERT INTO `payment` VALUES ('7894-123-456789',1,1,'2020-01-03'),('7894-234-567890',1,1,'2020-10-01'),('7894-234-567890',2,1,'2023-11-04'),('7894-345-678901',1,1,'2021-11-01'),('7894-345-678901',2,1,'2023-11-02'),('7894-345-678901',3,1,'2023-11-04'),('7894-456-789012',1,4,'2020-10-01');
/*!40000 ALTER TABLE `payment` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2023-11-16 19:31:59
