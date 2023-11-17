CREATE DATABASE  IF NOT EXISTS `BankSimul_R9` /*!40100 DEFAULT CHARACTER SET utf8mb3 */ /*!80016 DEFAULT ENCRYPTION='N' */;
USE `BankSimul_R9`;

-- MySQL dump 10.13  Distrib 8.1.0, for macos13.3 (arm64)
--
-- Host: localhost    Database: BankSimul_R9
-- ------------------------------------------------------
-- Server version	8.1.0

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
-- Table structure for table `Asiakas`
--

DROP TABLE IF EXISTS `Asiakas`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Asiakas` (
  `idAsiakas` varchar(15) NOT NULL,
  `Etunimet` varchar(45) NOT NULL,
  `Sukunimi` varchar(25) NOT NULL,
  PRIMARY KEY (`idAsiakas`),
  UNIQUE KEY `idAsiakas_UNIQUE` (`idAsiakas`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Asiakas`
--

LOCK TABLES `Asiakas` WRITE;
/*!40000 ALTER TABLE `Asiakas` DISABLE KEYS */;
/*!40000 ALTER TABLE `Asiakas` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Kortti`
--

DROP TABLE IF EXISTS `Kortti`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Kortti` (
  `idKortti` char(16) NOT NULL,
  `Pinkoodi` varchar(255) DEFAULT NULL,
  `Voimassa` date NOT NULL,
  PRIMARY KEY (`idKortti`),
  UNIQUE KEY `idKortti_UNIQUE` (`idKortti`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Kortti`
--

LOCK TABLES `Kortti` WRITE;
/*!40000 ALTER TABLE `Kortti` DISABLE KEYS */;
INSERT INTO `Kortti` VALUES ('0000000011111111','$2a$10$liuk4Wmtf9YKwP9gRv.UIeeTlinMm2mcYheSPJRjEIqkaKdyjIiV6','2024-11-15'),('1234123423452345','$2a$10$g05d/W5n9z4hwFAAPeqaE..IheEH9BnbZ5N6FVnroy7PYfoJMGMQO','2024-11-15'),('1234234534564567','$2a$10$hjBAzx5.aMpwOSGJiWeNTOXSIV6M6WjHNKPBfnZ4x3HMzaqH7fg7e','2024-11-15'),('2345234534563456','$2a$10$2ipv0eHcd00QzO3FIfUyvuhr97RuqXDsVOpirUPJD3jMjJ.6iDM3u','2024-11-16'),('3456345645674567','$2a$10$PHxQSjT4MoXIcUDEjkRqHuafTGAtQLnAthTK5KOlj1Gpl3pFZJRUi','2024-10-20'),('4567456756785678','$2a$10$5SYuBz6oXaVfNl19dL6Fe.J/difRG4n1d/M3RTgMlJPWNIRcPoxhS','2024-09-06'),('5678567867896789','$2a$10$8VhESNiJhZKJ.Dzqe2j93ObfyCB72uZZ7P6QrEtcVidM/fWJRY3pC','2024-11-15'),('6789678978907890','$2a$10$NVoZw.Sj.pHTTr/RqS/DVO69l4zF0i8L0WIMjzcAfzYhDB1HKLk8u','2024-11-15'),('7890789012341234','$2a$10$Z0ttvE97VDZlktwe2UkoMu9obKi5Jqy6x0zlAC.nQPNrV9njeA2/i','2024-11-15');
/*!40000 ALTER TABLE `Kortti` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Oikeus`
--

DROP TABLE IF EXISTS `Oikeus`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Oikeus` (
  `idOikeus` int NOT NULL AUTO_INCREMENT,
  `idTili` char(18) NOT NULL,
  `idAsiakas` varchar(45) NOT NULL,
  `MainUser` tinyint DEFAULT NULL,
  PRIMARY KEY (`idOikeus`),
  UNIQUE KEY `idOikeus_UNIQUE` (`idOikeus`),
  KEY `Asiakas-Oikeus_idx` (`idAsiakas`),
  KEY `Tili-Oikeus` (`idTili`),
  CONSTRAINT `Asiakas-Oikeus` FOREIGN KEY (`idAsiakas`) REFERENCES `Asiakas` (`idAsiakas`) ON DELETE CASCADE,
  CONSTRAINT `Tili-Oikeus` FOREIGN KEY (`idTili`) REFERENCES `Tili` (`idTili`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Oikeus`
--

LOCK TABLES `Oikeus` WRITE;
/*!40000 ALTER TABLE `Oikeus` DISABLE KEYS */;
/*!40000 ALTER TABLE `Oikeus` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Tili`
--

DROP TABLE IF EXISTS `Tili`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Tili` (
  `idTili` char(18) NOT NULL,
  `Saldo` decimal(15,2) NOT NULL,
  `Luottoraja` decimal(15,2) DEFAULT NULL,
  `NPEuro` decimal(15,2) DEFAULT NULL,
  `NPProsentti` decimal(15,2) DEFAULT NULL,
  `idValuutta` varchar(20) NOT NULL DEFAULT 'Euro',
  `idOikeus` varchar(15) NOT NULL,
  `idKortti` char(16) DEFAULT NULL,
  PRIMARY KEY (`idTili`),
  UNIQUE KEY `idTili_UNIQUE` (`idTili`),
  KEY `idKortti_idx` (`idKortti`),
  KEY `idValuutta_idx` (`idValuutta`),
  CONSTRAINT `Kortti-Tili` FOREIGN KEY (`idKortti`) REFERENCES `Kortti` (`idKortti`),
  CONSTRAINT `Valuutta-Tili` FOREIGN KEY (`idValuutta`) REFERENCES `Valuutta` (`idValuutta`) ON DELETE RESTRICT ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Tili`
--

LOCK TABLES `Tili` WRITE;
/*!40000 ALTER TABLE `Tili` DISABLE KEYS */;
/*!40000 ALTER TABLE `Tili` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Tilitapahtumat`
--

DROP TABLE IF EXISTS `Tilitapahtumat`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Tilitapahtumat` (
  `idTilitapahtumat` int NOT NULL AUTO_INCREMENT,
  `Aikaleima` timestamp NOT NULL,
  `Saldomuutos` decimal(15,2) DEFAULT NULL,
  `Muutoslaji` varchar(15) NOT NULL,
  `idTili` char(18) NOT NULL,
  `Paikkatieto` varchar(15) DEFAULT NULL,
  PRIMARY KEY (`idTilitapahtumat`),
  UNIQUE KEY `idTilitapahtumat_UNIQUE` (`idTilitapahtumat`),
  KEY `idTili_idx` (`idTili`),
  CONSTRAINT `Tili-Tilitapahtumat` FOREIGN KEY (`idTili`) REFERENCES `Tili` (`idTili`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Tilitapahtumat`
--

LOCK TABLES `Tilitapahtumat` WRITE;
/*!40000 ALTER TABLE `Tilitapahtumat` DISABLE KEYS */;
/*!40000 ALTER TABLE `Tilitapahtumat` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Valuutta`
--

DROP TABLE IF EXISTS `Valuutta`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Valuutta` (
  `idValuutta` varchar(20) NOT NULL,
  `Kurssi` float NOT NULL,
  PRIMARY KEY (`idValuutta`),
  UNIQUE KEY `idValuutta_UNIQUE` (`idValuutta`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Valuutta`
--

LOCK TABLES `Valuutta` WRITE;
/*!40000 ALTER TABLE `Valuutta` DISABLE KEYS */;
/*!40000 ALTER TABLE `Valuutta` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2023-11-17  0:04:58
