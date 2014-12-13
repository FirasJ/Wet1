/*
 * stress_tests.cpp
 *
 *  Created on: Nov 29, 2014
 *      Author: Denis
 */


#include "iDroid.h"
#include "mtmtest.h"

// STRESS_TEST1 checks DS's Strength at maintaining large amounts of data.
bool STRESS_TEST1();

// STRESS_TEST2 checks correctness of DS in removal of applications.
bool STRESS_TEST2();

// STRESS_TEST3 checks "increase downloads" , "upgrade version"
bool STRESS_TEST3();

//STRESS_TEST4 checks "update downloads" and "get all applications by downloads"
bool STRESS_TEST4();

// random generated operations.
bool STRESS_TEST5();

bool STRESS_TEST1() {
	iDroid DS;

	ASSERT_TRUE( SUCCESS == DS.AddVersion(1) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(2) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(3) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(4) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(5) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(6) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(7) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(8) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(9) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(10) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(11) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(12) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(13) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(14) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(15) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(16) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(17) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(18) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(19) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(20) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(21) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(22) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(23) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(24) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(25) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(26) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(27) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(28) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(29) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(30) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(31) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(32) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(33) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(34) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(35) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(36) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(37) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(38) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(39) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(40) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(41) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(42) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(43) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(44) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(45) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(46) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(47) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(48) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(49) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(50) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(51) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(52) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(53) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(54) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(55) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(56) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(57) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(58) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(59) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(60) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(61) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(62) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(63) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(64) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(65) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(66) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(67) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(68) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(69) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(70) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(71) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(72) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(73) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(74) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(75) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(76) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(77) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(78) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(79) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(80) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(81) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(82) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(83) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(84) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(85) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(86) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(87) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(88) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(89) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(90) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(91) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(92) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(93) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(94) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(95) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(96) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(97) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(98) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(99) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(100) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(101) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(102) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(103) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(104) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(105) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(106) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(107) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(108) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(109) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(110) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(111) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(112) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(113) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(114) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(115) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(116) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(117) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(118) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(119) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(120) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(121) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(122) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(123) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(124) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(125) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(126) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(127) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(128) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(129) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(130) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(131) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(132) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(133) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(134) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(135) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(136) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(137) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(138) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(139) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(140) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(141) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(142) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(143) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(144) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(145) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(146) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(147) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(148) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(149) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(150) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(151) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(152) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(153) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(154) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(155) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(156) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(157) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(158) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(159) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(160) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(161) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(162) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(163) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(164) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(165) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(166) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(167) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(168) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(169) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(170) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(171) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(172) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(173) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(174) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(175) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(176) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(177) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(178) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(179) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(180) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(181) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(182) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(183) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(184) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(185) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(186) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(187) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(188) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(189) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(190) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(191) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(192) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(193) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(194) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(195) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(196) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(197) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(198) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(199) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(200) );

	ASSERT_TRUE( SUCCESS == DS.AddApplication(1,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(2,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(3,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(4,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(5,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(6,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(7,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(8,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(9,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(10,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(11,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(12,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(13,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(14,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(15,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(16,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(17,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(18,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(19,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(20,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(21,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(22,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(23,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(24,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(25,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(26,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(27,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(28,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(29,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(30,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(31,1,1) );
	ASSERT_TRUE( FAILURE == DS.AddApplication(31,2,1) );
	ASSERT_TRUE( FAILURE == DS.AddApplication(31,3,1) );
	ASSERT_TRUE( FAILURE == DS.AddApplication(31,4,1) );
	ASSERT_TRUE( FAILURE == DS.AddApplication(31,5,1) );
	ASSERT_TRUE( FAILURE == DS.AddApplication(31,6,1) );
	ASSERT_TRUE( FAILURE == DS.AddApplication(31,7,1) );
	ASSERT_TRUE( FAILURE == DS.AddApplication(31,8,1) );
	ASSERT_TRUE( FAILURE == DS.AddApplication(31,9,1) );
	ASSERT_TRUE( FAILURE == DS.AddApplication(31,10,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(32,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(33,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(34,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(35,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(36,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(37,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(38,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(39,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(40,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(41,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(42,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(43,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(44,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(45,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(46,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(47,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(48,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(49,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(50,1,2) ); //top application for version 1.
	ASSERT_TRUE( SUCCESS == DS.AddApplication(51,2,2) ); //top application for version 2.
	ASSERT_TRUE( SUCCESS == DS.AddApplication(52,2,2) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(53,2,2) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(54,2,2) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(55,2,2) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(56,2,2) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(57,2,2) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(58,2,2) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(59,2,2) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(60,2,2) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(61,3,10) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(62,3,10) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(63,3,10) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(64,3,10) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(65,3,10) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(66,3,10) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(67,3,10) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(68,3,10) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(69,3,10) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(70,3,10) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(71,3,10) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(72,3,10) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(73,3,10) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(74,3,10) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(75,3,10) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(76,3,10) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(77,3,10) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(78,3,10) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(79,3,10) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(80,3,10) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(81,3,1000) ); //top application for version 3.
	ASSERT_TRUE( SUCCESS == DS.AddApplication(82,3,1000) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(83,3,1000) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(84,3,1000) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(85,3,1000) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(86,3,1000) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(87,3,1000) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(88,3,1000) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(89,3,1000) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(90,3,1000) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(91,4,2) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(92,4,2) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(93,4,2) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(94,4,2) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(95,4,2) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(96,4,2) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(97,4,2) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(98,4,2) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(99,4,2) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(100,4,20) ); //best application for version 4.

	// checking application being added correctly.
	int app = 0;
	ASSERT_TRUE( SUCCESS == DS.GetTopApp(1,&app) );
	ASSERT_TRUE( 50 == app );
	ASSERT_TRUE( SUCCESS == DS.GetTopApp(2,&app) );
	ASSERT_TRUE( 51 == app );
	ASSERT_TRUE( SUCCESS == DS.GetTopApp(3,&app) );
	ASSERT_TRUE( 81 == app );
	ASSERT_TRUE( SUCCESS == DS.GetTopApp(4,&app) );
	ASSERT_TRUE( 100 == app );
	ASSERT_TRUE( SUCCESS == DS.GetTopApp(-1,&app) );
	ASSERT_TRUE( 81 == app );

	// adds new applications.
	ASSERT_TRUE( SUCCESS == DS.AddApplication(101,10,5) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(102,10,6) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(103,10,7) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(104,10,8) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(105,10,9) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(106,10,10) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(107,10,11) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(108,10,12) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(109,10,13) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(110,10,14) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(111,10,15) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(112,10,16) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(113,10,17) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(114,10,18) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(115,10,19) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(116,10,20) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(117,10,21) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(118,10,22) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(119,10,23) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(120,10,24) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(121,10,25) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(122,10,26) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(123,10,27) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(124,10,28) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(125,10,29) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(126,10,30) ); //top application for version 10.
	ASSERT_TRUE( SUCCESS == DS.AddApplication(127,100,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(128,100,199) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(129,100,991) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(130,100,999) ); //top application for version 100.

	// checking application being added correctly.
	ASSERT_TRUE( SUCCESS == DS.GetTopApp(1,&app) );
	ASSERT_TRUE( 50 == app );
	ASSERT_TRUE( SUCCESS == DS.GetTopApp(2,&app) );
	ASSERT_TRUE( 51 == app );
	ASSERT_TRUE( SUCCESS == DS.GetTopApp(3,&app) );
	ASSERT_TRUE( 81 == app );
	ASSERT_TRUE( SUCCESS == DS.GetTopApp(4,&app) );
	ASSERT_TRUE( 100 == app );
	ASSERT_TRUE( SUCCESS == DS.GetTopApp(10,&app) );
	ASSERT_TRUE( 126 == app );
	ASSERT_TRUE( SUCCESS == DS.GetTopApp(100,&app) );
	ASSERT_TRUE( 130 == app );
	ASSERT_TRUE( SUCCESS == DS.GetTopApp(-1,&app) );
	ASSERT_TRUE( 81 == app );

	return true;
}

bool STRESS_TEST2() {
	iDroid DS;

	ASSERT_TRUE( SUCCESS == DS.AddVersion(1) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(2) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(3) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(4) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(5) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(6) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(7) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(8) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(9) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(10) );

	ASSERT_TRUE( SUCCESS == DS.AddApplication(1,1,1) ); //top application for version 1.
	ASSERT_TRUE( SUCCESS == DS.AddApplication(2,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(3,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(4,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(5,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(6,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(7,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(8,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(9,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(10,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(11,2,2) ); //top application for version 2.
	ASSERT_TRUE( SUCCESS == DS.AddApplication(12,2,2) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(13,2,2) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(14,2,2) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(15,2,2) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(16,2,2) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(17,2,2) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(18,2,2) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(19,2,2) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(20,2,2) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(21,3,2) ); //top application for version 3.
	ASSERT_TRUE( SUCCESS == DS.AddApplication(22,3,2) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(23,3,2) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(24,3,2) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(25,3,2) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(26,3,2) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(27,3,2) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(28,3,2) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(29,3,2) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(30,3,2) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(31,8,8) ); //top application for version 8.
	ASSERT_TRUE( SUCCESS == DS.AddApplication(32,8,8) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(33,9,9) ); //top application for version 9.
	ASSERT_TRUE( SUCCESS == DS.AddApplication(34,9,9) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(35,10,10) ); //top application for version 10.
	ASSERT_TRUE( SUCCESS == DS.AddApplication(36,10,10) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(37,10,10) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(38,7,7) ); //top application for version 7.
	ASSERT_TRUE( SUCCESS == DS.AddApplication(39,7,7) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(40,7,7) );

	// checking application being added correctly.
	int app = 0;
	ASSERT_TRUE( SUCCESS == DS.GetTopApp(1,&app) );
	ASSERT_TRUE( 1 == app );
	ASSERT_TRUE( SUCCESS == DS.GetTopApp(2,&app) );
	ASSERT_TRUE( 11 == app );
	ASSERT_TRUE( SUCCESS == DS.GetTopApp(3,&app) );
	ASSERT_TRUE( 21 == app );
	ASSERT_TRUE( SUCCESS == DS.GetTopApp(7,&app) );
	ASSERT_TRUE( 38 == app );
	ASSERT_TRUE( SUCCESS == DS.GetTopApp(8,&app) );
	ASSERT_TRUE( 31 == app );
	ASSERT_TRUE( SUCCESS == DS.GetTopApp(9,&app) );
	ASSERT_TRUE( 33 == app );
	ASSERT_TRUE( SUCCESS == DS.GetTopApp(10,&app) );
	ASSERT_TRUE( 35 == app );

	ASSERT_TRUE( SUCCESS == DS.GetTopApp(-1,&app) );
	ASSERT_TRUE( 35 == app );

	// should only successfully remove applications in range 1-40.
	ASSERT_TRUE( SUCCESS == DS.RemoveApplication(10) );
	ASSERT_TRUE( FAILURE == DS.RemoveApplication(101) );
	ASSERT_TRUE( FAILURE == DS.RemoveApplication(101) );
	ASSERT_TRUE( FAILURE == DS.RemoveApplication(99) );
	ASSERT_TRUE( FAILURE == DS.RemoveApplication(43) );
	ASSERT_TRUE( FAILURE == DS.RemoveApplication(56) );
	ASSERT_TRUE( SUCCESS == DS.RemoveApplication(12) );
	ASSERT_TRUE( FAILURE == DS.RemoveApplication(67) );
	ASSERT_TRUE( FAILURE == DS.RemoveApplication(999) );
	ASSERT_TRUE( FAILURE == DS.RemoveApplication(100) );
	ASSERT_TRUE( SUCCESS == DS.RemoveApplication(2) );
	ASSERT_TRUE( SUCCESS == DS.RemoveApplication(3) );
	ASSERT_TRUE( SUCCESS == DS.RemoveApplication(14) );
	ASSERT_TRUE( SUCCESS == DS.RemoveApplication(22) );
	ASSERT_TRUE( FAILURE == DS.RemoveApplication(55) );
	ASSERT_TRUE( SUCCESS == DS.RemoveApplication(27) );
	ASSERT_TRUE( SUCCESS == DS.RemoveApplication(31) );
	ASSERT_TRUE( SUCCESS == DS.RemoveApplication(1) );
	ASSERT_TRUE( FAILURE == DS.RemoveApplication(1) );
	ASSERT_TRUE( SUCCESS == DS.RemoveApplication(6) );
	ASSERT_TRUE( FAILURE == DS.RemoveApplication(90) );
	ASSERT_TRUE( FAILURE == DS.RemoveApplication(34424) );
	ASSERT_TRUE( FAILURE == DS.RemoveApplication(700) );
	ASSERT_TRUE( SUCCESS == DS.RemoveApplication(8) );
	ASSERT_TRUE( SUCCESS == DS.RemoveApplication(9) );
	ASSERT_TRUE( FAILURE == DS.RemoveApplication(10) );
	ASSERT_TRUE( SUCCESS == DS.RemoveApplication(40) );
	ASSERT_TRUE( SUCCESS == DS.RemoveApplication(30) );

	// checking new top application in each version.
	ASSERT_TRUE( SUCCESS == DS.GetTopApp(1,&app) );
	ASSERT_TRUE( 4 == app );
	ASSERT_TRUE( SUCCESS == DS.GetTopApp(2,&app) );
	ASSERT_TRUE( 11 == app );
	ASSERT_TRUE( SUCCESS == DS.GetTopApp(3,&app) );
	ASSERT_TRUE( 21 == app );
	ASSERT_TRUE( SUCCESS == DS.GetTopApp(7,&app) );
	ASSERT_TRUE( 38 == app );
	ASSERT_TRUE( SUCCESS == DS.GetTopApp(8,&app) );
	ASSERT_TRUE( 32 == app );
	ASSERT_TRUE( SUCCESS == DS.GetTopApp(9,&app) );
	ASSERT_TRUE( 33 == app );
	ASSERT_TRUE( SUCCESS == DS.GetTopApp(10,&app) );
	ASSERT_TRUE( 35 == app );

	// top application in DS.
	ASSERT_TRUE( SUCCESS == DS.GetTopApp(-1,&app) );
	ASSERT_TRUE( 35 == app );

	ASSERT_TRUE( SUCCESS == DS.RemoveApplication(4) );
	ASSERT_TRUE( SUCCESS == DS.RemoveApplication(11) );
	ASSERT_TRUE( SUCCESS == DS.RemoveApplication(21) );
	ASSERT_TRUE( SUCCESS == DS.RemoveApplication(38) );
	ASSERT_TRUE( SUCCESS == DS.RemoveApplication(32) );
	ASSERT_TRUE( SUCCESS == DS.RemoveApplication(33) );
	ASSERT_TRUE( SUCCESS == DS.RemoveApplication(35) );

	// checking new top application in each version.
	ASSERT_TRUE( SUCCESS == DS.GetTopApp(1,&app) );
	ASSERT_TRUE( 5 == app );
	ASSERT_TRUE( SUCCESS == DS.GetTopApp(2,&app) );
	ASSERT_TRUE( 13 == app );
	ASSERT_TRUE( SUCCESS == DS.GetTopApp(3,&app) );
	ASSERT_TRUE( 23 == app );
	ASSERT_TRUE( SUCCESS == DS.GetTopApp(7,&app) );
	ASSERT_TRUE( 39 == app );
	ASSERT_TRUE( SUCCESS == DS.GetTopApp(8,&app) );
	ASSERT_TRUE( -1 == app );
	ASSERT_TRUE( SUCCESS == DS.GetTopApp(9,&app) );
	ASSERT_TRUE( 34 == app );
	ASSERT_TRUE( SUCCESS == DS.GetTopApp(10,&app) );
	ASSERT_TRUE( 36 == app );

	// top application in DS.
	ASSERT_TRUE( SUCCESS == DS.GetTopApp(-1,&app) );
	ASSERT_TRUE( 36 == app );

	return true;
}

bool STRESS_TEST3() {
	iDroid DS;

	ASSERT_TRUE( SUCCESS == DS.AddVersion(1) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(2) );

	ASSERT_TRUE( SUCCESS == DS.AddApplication(1,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(2,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(3,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(4,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(5,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(6,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(7,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(8,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(9,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(10,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(11,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(12,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(13,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(14,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(15,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(16,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(17,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(18,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(19,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(20,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(21,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(22,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(23,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(24,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(25,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(26,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(27,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(28,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(29,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(30,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(31,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(32,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(33,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(34,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(35,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(36,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(37,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(38,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(39,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(40,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(41,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(42,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(43,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(44,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(45,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(46,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(47,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(48,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(49,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(50,1,1) );

	int app = 0;
	ASSERT_TRUE( SUCCESS == DS.GetTopApp(1,&app) );
	ASSERT_TRUE( 1 == app );
	ASSERT_TRUE( SUCCESS == DS.GetTopApp(2,&app) );
	ASSERT_TRUE( -1 == app );

	// at the end of upgrade applications 1-32 are in version 2,the others still in version 1.
	ASSERT_TRUE( SUCCESS == DS.UpgradeApplication(1));
	ASSERT_TRUE( SUCCESS == DS.UpgradeApplication(2));
	ASSERT_TRUE( SUCCESS == DS.UpgradeApplication(3));
	ASSERT_TRUE( SUCCESS == DS.UpgradeApplication(4));
	ASSERT_TRUE( SUCCESS == DS.UpgradeApplication(5));
	ASSERT_TRUE( SUCCESS == DS.UpgradeApplication(6));
	ASSERT_TRUE( SUCCESS == DS.UpgradeApplication(7));
	ASSERT_TRUE( SUCCESS == DS.UpgradeApplication(8));
	ASSERT_TRUE( SUCCESS == DS.UpgradeApplication(9));
	ASSERT_TRUE( SUCCESS == DS.UpgradeApplication(10));
	ASSERT_TRUE( SUCCESS == DS.UpgradeApplication(11));
	ASSERT_TRUE( SUCCESS == DS.UpgradeApplication(12));
	ASSERT_TRUE( SUCCESS == DS.UpgradeApplication(13));
	ASSERT_TRUE( SUCCESS == DS.UpgradeApplication(14));
	ASSERT_TRUE( SUCCESS == DS.UpgradeApplication(15));
	ASSERT_TRUE( SUCCESS == DS.UpgradeApplication(16));
	ASSERT_TRUE( SUCCESS == DS.UpgradeApplication(17));
	ASSERT_TRUE( SUCCESS == DS.UpgradeApplication(18));
	ASSERT_TRUE( SUCCESS == DS.UpgradeApplication(19));
	ASSERT_TRUE( SUCCESS == DS.UpgradeApplication(20));
	ASSERT_TRUE( SUCCESS == DS.UpgradeApplication(21));
	ASSERT_TRUE( SUCCESS == DS.UpgradeApplication(22));
	ASSERT_TRUE( SUCCESS == DS.UpgradeApplication(23));
	ASSERT_TRUE( SUCCESS == DS.UpgradeApplication(24));
	ASSERT_TRUE( SUCCESS == DS.UpgradeApplication(25));
	ASSERT_TRUE( SUCCESS == DS.UpgradeApplication(26));
	ASSERT_TRUE( SUCCESS == DS.UpgradeApplication(27));
	ASSERT_TRUE( SUCCESS == DS.UpgradeApplication(28));
	ASSERT_TRUE( SUCCESS == DS.UpgradeApplication(29));
	ASSERT_TRUE( SUCCESS == DS.UpgradeApplication(30));
	ASSERT_TRUE( SUCCESS == DS.UpgradeApplication(31));
	ASSERT_TRUE( SUCCESS == DS.UpgradeApplication(32));

	ASSERT_TRUE( SUCCESS == DS.GetTopApp(1,&app) );
	ASSERT_TRUE( 33 == app );
	ASSERT_TRUE( SUCCESS == DS.GetTopApp(2,&app) );
	ASSERT_TRUE( 1 == app );

	// checking that "IncreaseDownloads" isn't doing troubles.
	for( int i = 1 ; i <= 50 ; i++) {
		for( int j = 1 ; j <=3 ; j++)
		ASSERT_TRUE( SUCCESS == DS.IncreaseDownloads(i,j) );
	}

	ASSERT_TRUE( SUCCESS == DS.GetTopApp(1,&app) );
	ASSERT_TRUE( 33 == app );
	ASSERT_TRUE( SUCCESS == DS.GetTopApp(2,&app) );
	ASSERT_TRUE( 1 == app );

	return true;
}

bool STRESS_TEST4() {
	iDroid DS;

	ASSERT_TRUE( SUCCESS == DS.AddVersion(1) );

	ASSERT_TRUE( SUCCESS == DS.AddApplication(1,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(2,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(3,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(4,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(5,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(6,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(7,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(8,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(9,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(10,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(11,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(12,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(13,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(14,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(15,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(16,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(17,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(18,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(19,1,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(20,1,1) );

	int numOfApps;
	int* apps;

	ASSERT_NO_THROW(DS.GetAllAppsByDownloads(1,&apps,&numOfApps));
	ASSERT_TRUE( 20 == numOfApps );

	ASSERT_TRUE( 1 == apps[0] );
	ASSERT_TRUE( 2 == apps[1] );
	ASSERT_TRUE( 3 == apps[2] );
	ASSERT_TRUE( 4 == apps[3] );
	ASSERT_TRUE( 5 == apps[4] );
	ASSERT_TRUE( 6 == apps[5] );
	ASSERT_TRUE( 7 == apps[6] );
	ASSERT_TRUE( 8 == apps[7] );
	ASSERT_TRUE( 9 == apps[8] );
	ASSERT_TRUE( 10 == apps[9] );
	ASSERT_TRUE( 11 == apps[10] );
	ASSERT_TRUE( 12 == apps[11] );
	ASSERT_TRUE( 13 == apps[12] );
	ASSERT_TRUE( 14 == apps[13] );
	ASSERT_TRUE( 15 == apps[14] );
	ASSERT_TRUE( 16 == apps[15] );
	ASSERT_TRUE( 17 == apps[16] );
	ASSERT_TRUE( 18 == apps[17] );
	ASSERT_TRUE( 19 == apps[18] );
	ASSERT_TRUE( 20 == apps[19] );

	free(apps);

	ASSERT_NO_THROW(DS.UpdateDownloads(2,2));

	ASSERT_NO_THROW(DS.GetAllAppsByDownloads(-1,&apps,&numOfApps));
	ASSERT_TRUE( 20 == numOfApps );

	ASSERT_TRUE( 2 == apps[0] );
	ASSERT_TRUE( 4 == apps[1] );
	ASSERT_TRUE( 6 == apps[2] );
	ASSERT_TRUE( 8 == apps[3] );
	ASSERT_TRUE( 10 == apps[4] );
	ASSERT_TRUE( 12 == apps[5] );
	ASSERT_TRUE( 14 == apps[6] );
	ASSERT_TRUE( 16 == apps[7] );
	ASSERT_TRUE( 18 == apps[8] );
	ASSERT_TRUE( 20 == apps[9] );
	ASSERT_TRUE( 1 == apps[10] );
	ASSERT_TRUE( 3 == apps[11] );
	ASSERT_TRUE( 5 == apps[12] );
	ASSERT_TRUE( 7 == apps[13] );
	ASSERT_TRUE( 9 == apps[14] );
	ASSERT_TRUE( 11 == apps[15] );
	ASSERT_TRUE( 13 == apps[16] );
	ASSERT_TRUE( 15 == apps[17] );
	ASSERT_TRUE( 17 == apps[18] );
	ASSERT_TRUE( 19 == apps[19] );

	free(apps);

	ASSERT_NO_THROW(DS.UpdateDownloads(5,2));

	ASSERT_NO_THROW(DS.GetAllAppsByDownloads(-1,&apps,&numOfApps));

	ASSERT_TRUE( 10 == apps[0] );
	ASSERT_TRUE( 20 == apps[1] );
	ASSERT_TRUE( 2 == apps[2] );
	ASSERT_TRUE( 4 == apps[3] );
	ASSERT_TRUE( 5 == apps[4] );
	ASSERT_TRUE( 6 == apps[5] );
	ASSERT_TRUE( 8 == apps[6] );
	ASSERT_TRUE( 12 == apps[7] );
	ASSERT_TRUE( 14 == apps[8] );
	ASSERT_TRUE( 15 == apps[9] );
	ASSERT_TRUE( 16 == apps[10] );
	ASSERT_TRUE( 18 == apps[11] );
	ASSERT_TRUE( 1 == apps[12] );
	ASSERT_TRUE( 3 == apps[13] );
	ASSERT_TRUE( 7 == apps[14] );
	ASSERT_TRUE( 9 == apps[15] );
	ASSERT_TRUE( 11 == apps[16] );
	ASSERT_TRUE( 13 == apps[17] );
	ASSERT_TRUE( 17 == apps[18] );
	ASSERT_TRUE( 19 == apps[19] );

	free(apps);

	ASSERT_NO_THROW(DS.UpdateDownloads(1,50));

	ASSERT_NO_THROW(DS.GetAllAppsByDownloads(-1,&apps,&numOfApps));

	ASSERT_TRUE( 10 == apps[0] );
	ASSERT_TRUE( 20 == apps[1] );
	ASSERT_TRUE( 2 == apps[2] );
	ASSERT_TRUE( 4 == apps[3] );
	ASSERT_TRUE( 5 == apps[4] );
	ASSERT_TRUE( 6 == apps[5] );
	ASSERT_TRUE( 8 == apps[6] );
	ASSERT_TRUE( 12 == apps[7] );
	ASSERT_TRUE( 14 == apps[8] );
	ASSERT_TRUE( 15 == apps[9] );
	ASSERT_TRUE( 16 == apps[10] );
	ASSERT_TRUE( 18 == apps[11] );
	ASSERT_TRUE( 1 == apps[12] );
	ASSERT_TRUE( 3 == apps[13] );
	ASSERT_TRUE( 7 == apps[14] );
	ASSERT_TRUE( 9 == apps[15] );
	ASSERT_TRUE( 11 == apps[16] );
	ASSERT_TRUE( 13 == apps[17] );
	ASSERT_TRUE( 17 == apps[18] );
	ASSERT_TRUE( 19 == apps[19] );

	free(apps);

	ASSERT_NO_THROW(DS.UpdateDownloads(31,2));

	ASSERT_NO_THROW(DS.GetAllAppsByDownloads(-1,&apps,&numOfApps));

	ASSERT_TRUE( 10 == apps[0] );
	ASSERT_TRUE( 20 == apps[1] );
	ASSERT_TRUE( 2 == apps[2] );
	ASSERT_TRUE( 4 == apps[3] );
	ASSERT_TRUE( 5 == apps[4] );
	ASSERT_TRUE( 6 == apps[5] );
	ASSERT_TRUE( 8 == apps[6] );
	ASSERT_TRUE( 12 == apps[7] );
	ASSERT_TRUE( 14 == apps[8] );
	ASSERT_TRUE( 15 == apps[9] );
	ASSERT_TRUE( 16 == apps[10] );
	ASSERT_TRUE( 18 == apps[11] );
	ASSERT_TRUE( 1 == apps[12] );
	ASSERT_TRUE( 3 == apps[13] );
	ASSERT_TRUE( 7 == apps[14] );
	ASSERT_TRUE( 9 == apps[15] );
	ASSERT_TRUE( 11 == apps[16] );
	ASSERT_TRUE( 13 == apps[17] );
	ASSERT_TRUE( 17 == apps[18] );
	ASSERT_TRUE( 19 == apps[19] );

	free(apps);

	for( int i = 1 ; i <= 20 ; i++ )
		ASSERT_TRUE( SUCCESS == DS.RemoveApplication(i) );

	ASSERT_TRUE( SUCCESS == DS.AddVersion(2) );

	for( int i = 1 ; i <= 10 ; i++ )
		ASSERT_TRUE( SUCCESS == DS.AddApplication(i,1,1) );

	for( int i = 11 ; i <= 20 ; i++ )
		ASSERT_TRUE( SUCCESS == DS.AddApplication(i,2,2) );

	ASSERT_NO_THROW(DS.GetAllAppsByDownloads(1,&apps,&numOfApps));
	ASSERT_TRUE( 10 == numOfApps );

	ASSERT_TRUE( 1 == apps[0] );
	ASSERT_TRUE( 2 == apps[1] );
	ASSERT_TRUE( 3 == apps[2] );
	ASSERT_TRUE( 4 == apps[3] );
	ASSERT_TRUE( 5 == apps[4] );
	ASSERT_TRUE( 6 == apps[5] );
	ASSERT_TRUE( 7 == apps[6] );
	ASSERT_TRUE( 8 == apps[7] );
	ASSERT_TRUE( 9 == apps[8] );
	ASSERT_TRUE( 10 == apps[9] );

	free(apps);

	ASSERT_NO_THROW(DS.GetAllAppsByDownloads(2,&apps,&numOfApps));
	ASSERT_TRUE( 10 == numOfApps );

	ASSERT_TRUE( 11 == apps[0] );
	ASSERT_TRUE( 12 == apps[1] );
	ASSERT_TRUE( 13 == apps[2] );
	ASSERT_TRUE( 14 == apps[3] );
	ASSERT_TRUE( 15 == apps[4] );
	ASSERT_TRUE( 16 == apps[5] );
	ASSERT_TRUE( 17 == apps[6] );
	ASSERT_TRUE( 18 == apps[7] );
	ASSERT_TRUE( 19 == apps[8] );
	ASSERT_TRUE( 20 == apps[9] );

	free(apps);

	ASSERT_NO_THROW(DS.GetAllAppsByDownloads(-1,&apps,&numOfApps));
	ASSERT_TRUE( 20 == numOfApps );

	ASSERT_TRUE( 11 == apps[0] );
	ASSERT_TRUE( 12 == apps[1] );
	ASSERT_TRUE( 13 == apps[2] );
	ASSERT_TRUE( 14 == apps[3] );
	ASSERT_TRUE( 15 == apps[4] );
	ASSERT_TRUE( 16 == apps[5] );
	ASSERT_TRUE( 17 == apps[6] );
	ASSERT_TRUE( 18 == apps[7] );
	ASSERT_TRUE( 19 == apps[8] );
	ASSERT_TRUE( 20 == apps[9] );
	ASSERT_TRUE( 1 == apps[10] );
	ASSERT_TRUE( 2 == apps[11] );
	ASSERT_TRUE( 3 == apps[12] );
	ASSERT_TRUE( 4 == apps[13] );
	ASSERT_TRUE( 5 == apps[14] );
	ASSERT_TRUE( 6 == apps[15] );
	ASSERT_TRUE( 7 == apps[16] );
	ASSERT_TRUE( 8 == apps[17] );
	ASSERT_TRUE( 9 == apps[18] );
	ASSERT_TRUE( 10 == apps[19] );

	free(apps);

	ASSERT_NO_THROW(DS.UpdateDownloads(2,2));

	ASSERT_NO_THROW(DS.GetAllAppsByDownloads(-1,&apps,&numOfApps));
	ASSERT_TRUE( 20 == numOfApps );

	ASSERT_TRUE( 12 == apps[0] );
	ASSERT_TRUE( 14 == apps[1] );
	ASSERT_TRUE( 16 == apps[2] );
	ASSERT_TRUE( 18 == apps[3] );
	ASSERT_TRUE( 20 == apps[4] );
	ASSERT_TRUE( 2 == apps[5] );
	ASSERT_TRUE( 4 == apps[6] );
	ASSERT_TRUE( 6 == apps[7] );
	ASSERT_TRUE( 8 == apps[8] );
	ASSERT_TRUE( 10 == apps[9] );
	ASSERT_TRUE( 11 == apps[10] );
	ASSERT_TRUE( 13 == apps[11] );
	ASSERT_TRUE( 15 == apps[12] );
	ASSERT_TRUE( 17 == apps[13] );
	ASSERT_TRUE( 19 == apps[14] );
	ASSERT_TRUE( 1 == apps[15] );
	ASSERT_TRUE( 3 == apps[16] );
	ASSERT_TRUE( 5 == apps[17] );
	ASSERT_TRUE( 7 == apps[18] );
	ASSERT_TRUE( 9 == apps[19] );


	free(apps);

	ASSERT_NO_THROW(DS.GetAllAppsByDownloads(1,&apps,&numOfApps));
	ASSERT_TRUE( 10 == numOfApps );

	ASSERT_TRUE( 2 == apps[0] );
	ASSERT_TRUE( 4 == apps[1] );
	ASSERT_TRUE( 6 == apps[2] );
	ASSERT_TRUE( 8 == apps[3] );
	ASSERT_TRUE( 10 == apps[4] );
	ASSERT_TRUE( 1 == apps[5] );
	ASSERT_TRUE( 3 == apps[6] );
	ASSERT_TRUE( 5 == apps[7] );
	ASSERT_TRUE( 7 == apps[8] );
	ASSERT_TRUE( 9 == apps[9] );

	free(apps);

	ASSERT_NO_THROW(DS.GetAllAppsByDownloads(2,&apps,&numOfApps));
	ASSERT_TRUE( 10 == numOfApps );

	ASSERT_TRUE( 12 == apps[0] );
	ASSERT_TRUE( 14 == apps[1] );
	ASSERT_TRUE( 16 == apps[2] );
	ASSERT_TRUE( 18 == apps[3] );
	ASSERT_TRUE( 20 == apps[4] );
	ASSERT_TRUE( 11 == apps[5] );
	ASSERT_TRUE( 13 == apps[6] );
	ASSERT_TRUE( 15 == apps[7] );
	ASSERT_TRUE( 17 == apps[8] );
	ASSERT_TRUE( 19 == apps[9] );

	free(apps);

	return true;
}

bool STRESS_TEST5() {
	iDroid DS;

	ASSERT_TRUE( SUCCESS == DS.AddVersion(6) );
	ASSERT_TRUE( FAILURE == DS.AddApplication(1,1,1) );
	ASSERT_TRUE( FAILURE == DS.UpgradeApplication(21));
	ASSERT_TRUE( FAILURE == DS.RemoveApplication(11) );
	ASSERT_TRUE( FAILURE == DS.AddApplication(1,5,1) );
	ASSERT_TRUE( FAILURE == DS.AddApplication(1,7,1) );
	ASSERT_TRUE( SUCCESS == DS.AddApplication(1,6,1) );
	ASSERT_TRUE( FAILURE == DS.UpgradeApplication(34));
	ASSERT_TRUE( FAILURE == DS.UpgradeApplication(16));
	ASSERT_TRUE( FAILURE == DS.UpgradeApplication(6));
	ASSERT_TRUE( FAILURE == DS.AddVersion(2) );
	ASSERT_TRUE( FAILURE == DS.RemoveApplication(300) );
	ASSERT_TRUE( FAILURE == DS.AddVersion(3) );
	ASSERT_TRUE( SUCCESS == DS.AddVersion(7) );
	ASSERT_TRUE( FAILURE == DS.UpgradeApplication(19));
	ASSERT_TRUE( FAILURE == DS.UpgradeApplication(3));
	ASSERT_TRUE( SUCCESS == DS.UpgradeApplication(1));

	// we have version 7 containing application 1,and version 6 with no application.
	int numOfApps;
	int* apps;
	int app;

	ASSERT_NO_THROW(DS.GetAllAppsByDownloads(6,&apps,&numOfApps));
	ASSERT_TRUE( 0 == numOfApps );
	free(apps);

	ASSERT_TRUE( SUCCESS == DS.AddApplication(6,6,2) );
	ASSERT_TRUE( FAILURE == DS.AddApplication(6,6,1) );
	ASSERT_TRUE( FAILURE == DS.AddApplication(6,7,2) );

	ASSERT_TRUE( SUCCESS == DS.GetTopApp(6,&app) );
	ASSERT_TRUE( 6 == app);
	ASSERT_TRUE( SUCCESS == DS.GetTopApp(7,&app) );
	ASSERT_TRUE( 1 == app);
	ASSERT_TRUE( SUCCESS == DS.GetTopApp(-1,&app) );
	ASSERT_TRUE( 6 == app);

	ASSERT_TRUE( FAILURE == DS.AddVersion(7) );

	ASSERT_NO_THROW(DS.GetAllAppsByDownloads(-5,&apps,&numOfApps));
	ASSERT_TRUE( 2 == numOfApps );
	ASSERT_TRUE( 6 == apps[0] );
	ASSERT_TRUE( 1 == apps[1] );

	free(apps);

	// case version doesn't exist.
	ASSERT_TRUE( FAILURE == DS.GetAllAppsByDownloads(3,&apps,&numOfApps) );

	ASSERT_TRUE( SUCCESS == DS.RemoveApplication(6) );

	ASSERT_NO_THROW(DS.GetAllAppsByDownloads(-234,&apps,&numOfApps));
	ASSERT_TRUE( 1 == numOfApps );
	ASSERT_TRUE( 1 == apps[0] );


	free(apps);

	ASSERT_TRUE( SUCCESS == DS.AddVersion(24) );
	// in case the version has no applications.
	ASSERT_TRUE( SUCCESS == DS.GetAllAppsByDownloads(24,&apps,&numOfApps) );
	ASSERT_TRUE( 0 == numOfApps );
	ASSERT_TRUE( NULL == apps );


	ASSERT_TRUE( SUCCESS == DS.AddApplication(24,24,1) );

	ASSERT_NO_THROW(DS.GetAllAppsByDownloads(24,&apps,&numOfApps));
	ASSERT_TRUE( 1 == numOfApps );
	ASSERT_TRUE( 24 == apps[0] );

	free(apps);

	ASSERT_TRUE( SUCCESS == DS.GetTopApp(-1,&app) );
	ASSERT_TRUE( 1 == app);

	ASSERT_TRUE( SUCCESS == DS.UpgradeApplication(1));

	ASSERT_NO_THROW(DS.GetAllAppsByDownloads(24,&apps,&numOfApps));
	ASSERT_TRUE( 2 == numOfApps );
	ASSERT_TRUE( 1 == apps[0] );
	ASSERT_TRUE( 24 == apps[1] );

	free(apps);

	ASSERT_NO_THROW(DS.UpdateDownloads(24,24));

	ASSERT_NO_THROW(DS.GetAllAppsByDownloads(24,&apps,&numOfApps));
	ASSERT_TRUE( 2 == numOfApps );
	ASSERT_TRUE( 24 == apps[0] );
	ASSERT_TRUE( 1 == apps[1] );

	free(apps);

	return true;
}

int main() {
	RUN_TEST(STRESS_TEST1);
	RUN_TEST(STRESS_TEST2);
	RUN_TEST(STRESS_TEST3);
	RUN_TEST(STRESS_TEST4);
	RUN_TEST(STRESS_TEST5);
	return 0;
}
