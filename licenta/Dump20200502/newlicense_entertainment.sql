-- MySQL dump 10.13  Distrib 8.0.13, for Win64 (x86_64)
--
-- Host: localhost    Database: newlicense
-- ------------------------------------------------------
-- Server version	8.0.13

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
 SET NAMES utf8 ;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `entertainment`
--

DROP TABLE IF EXISTS `entertainment`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `entertainment` (
  `id` bigint(20) NOT NULL,
  `name` varchar(1000) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `entertainment`
--

LOCK TABLES `entertainment` WRITE;
/*!40000 ALTER TABLE `entertainment` DISABLE KEYS */;
INSERT INTO `entertainment` VALUES (1,'https://scontent.fsbz3-1.fna.fbcdn.net/v/t1.0-9/94380048_1856865851110877_8117487639684186112_o.jpg?_nc_cat=111&_nc_sid=8bfeb9&_nc_ohc=uwh3hi8MbG8AX8pCNK7&_nc_ht=scontent.fsbz3-1.fna&oh=78f0f23fc655f8bff2401aa57de34917&oe=5EC8208F'),(2,'https://scontent.fsbz3-1.fna.fbcdn.net/v/t1.0-9/93482181_1849927441804718_7051365753387220992_o.jpg?_nc_cat=108&_nc_sid=8bfeb9&_nc_ohc=TMf6xT7BP8EAX9z7ycn&_nc_ht=scontent.fsbz3-1.fna&oh=3b696dd8b1166d2fc3c1fa848015b7bc&oe=5ECBC343'),(3,'https://scontent.fsbz3-1.fna.fbcdn.net/v/t1.0-9/93936776_1852520238212105_2326767626023337984_o.jpg?_nc_cat=103&_nc_sid=8bfeb9&_nc_ohc=oT2imexMQdsAX9yIYV0&_nc_ht=scontent.fsbz3-1.fna&oh=a8254bac619fe141b23ef0d6d3483d82&oe=5ECADBA6'),(4,'https://scontent.fsbz3-1.fna.fbcdn.net/v/t1.0-9/93901613_1846373808826748_1183943933126770688_o.jpg?_nc_cat=105&_nc_sid=8bfeb9&_nc_ohc=dhDxJHAD2esAX8Lqcjp&_nc_ht=scontent.fsbz3-1.fna&oh=73904e9c5b26059ba4783816ec5f74c6&oe=5ECBB5D0'),(5,'https://scontent.fsbz3-1.fna.fbcdn.net/v/t1.0-9/92760072_1843863265744469_2397696202008166400_o.jpg?_nc_cat=108&_nc_sid=8bfeb9&_nc_ohc=6b1B0jbcv3YAX8_GmDR&_nc_ht=scontent.fsbz3-1.fna&oh=a5aef52e6bd4f4da7233cd02af1de5fc&oe=5EC92E0F'),(6,'https://scontent.fsbz3-1.fna.fbcdn.net/v/t1.0-9/92571910_1841857825945013_4022068522870898688_n.jpg?_nc_cat=102&_nc_sid=8bfeb9&_nc_ohc=iU68JIRY_GQAX_oMEgg&_nc_ht=scontent.fsbz3-1.fna&oh=ea4800c57c05ee5dc51841f698b8f2e4&oe=5EC994DB'),(7,'https://scontent.fsbz3-1.fna.fbcdn.net/v/t1.0-9/92510261_1839910882806374_272172799102025728_o.jpg?_nc_cat=108&_nc_sid=8bfeb9&_nc_ohc=X721M5Y58a8AX_SlZx3&_nc_ht=scontent.fsbz3-1.fna&oh=5a09c4167b41c98515c5193decea0d78&oe=5EC909B1'),(8,'https://scontent.fsbz3-1.fna.fbcdn.net/v/t1.0-9/91820180_1839122552885207_2012586168410963968_o.jpg?_nc_cat=100&_nc_sid=8bfeb9&_nc_ohc=ezMKQIbgpDwAX_mDTbJ&_nc_ht=scontent.fsbz3-1.fna&oh=11af1ff2e48dad166aec18d9bb2e3a0f&oe=5ECACBF1'),(9,'https://scontent.fsbz3-1.fna.fbcdn.net/v/t1.0-9/92328995_1835746093222853_8141261529208061952_o.jpg?_nc_cat=108&_nc_sid=8bfeb9&_nc_ohc=pkdrKRhwPv4AX-V3VHF&_nc_ht=scontent.fsbz3-1.fna&oh=af44b0b399e7bd85f806ef2d4b7ae5eb&oe=5ECA5D03'),(10,'https://scontent.fsbz3-1.fna.fbcdn.net/v/t1.0-9/91473012_1833532713444191_6908076882659377152_o.jpg?_nc_cat=109&_nc_sid=8bfeb9&_nc_ohc=zjCK6-atwpcAX8WJH1V&_nc_ht=scontent.fsbz3-1.fna&oh=17f1499565a155ea8fba9c0999c65da3&oe=5EC98E25'),(11,'https://scontent.fsbz3-1.fna.fbcdn.net/v/t1.0-9/90680603_1827720644025398_7702778783132024832_n.jpg?_nc_cat=111&_nc_sid=8bfeb9&_nc_ohc=A1n2Kpt2NmYAX87XfuB&_nc_ht=scontent.fsbz3-1.fna&oh=ce30b00028436aa34b94e0d966cddf9e&oe=5EC9E144'),(12,'https://scontent.fsbz3-1.fna.fbcdn.net/v/t1.0-9/90949991_1828879593909503_7668012388670504960_n.jpg?_nc_cat=102&_nc_sid=8bfeb9&_nc_ohc=BDFg6dvUvpQAX8BLZa1&_nc_ht=scontent.fsbz3-1.fna&oh=9e427d7e7813a0de61b2b2140b861b5e&oe=5ECAF88D'),(13,'https://scontent.fsbz3-1.fna.fbcdn.net/v/t1.0-9/90790677_1824617954335667_8416553251956064256_o.jpg?_nc_cat=102&_nc_sid=8bfeb9&_nc_ohc=b7gQW9lua4IAX_2M5hW&_nc_ht=scontent.fsbz3-1.fna&oh=535e52d509cbc0a9d66e7c29e614ff13&oe=5EC8F6E2'),(14,'https://scontent.fsbz3-1.fna.fbcdn.net/v/t1.0-9/89808026_1817883158342480_4284350269988274176_o.jpg?_nc_cat=105&_nc_sid=8bfeb9&_nc_ohc=VHp8jdNppcUAX9JMGtC&_nc_ht=scontent.fsbz3-1.fna&oh=b6b01f018f72061c157077c4e5e87e0c&oe=5ECB9826');
/*!40000 ALTER TABLE `entertainment` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2020-05-02 17:37:43
