EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L power:PWR_FLAG #FLG0101
U 1 1 5FC83467
P 7300 4000
F 0 "#FLG0101" H 7300 4075 50  0001 C CNN
F 1 "PWR_FLAG" H 7300 4174 50  0000 C CNN
F 2 "" H 7300 4000 50  0001 C CNN
F 3 "~" H 7300 4000 50  0001 C CNN
	1    7300 4000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0106
U 1 1 5FC83485
P 7300 4000
F 0 "#PWR0106" H 7300 3750 50  0001 C CNN
F 1 "GND" H 7305 3827 50  0000 C CNN
F 2 "" H 7300 4000 50  0001 C CNN
F 3 "" H 7300 4000 50  0001 C CNN
	1    7300 4000
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x03 J1
U 1 1 5FD25C62
P 4200 3800
F 0 "J1" H 4120 3475 50  0000 C CNN
F 1 "IN" H 4120 3566 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 4200 3800 50  0001 C CNN
F 3 "~" H 4200 3800 50  0001 C CNN
F 4 "Male Hader" H 4200 3800 50  0001 C CNN "Device"
F 5 "CONN HEADER VERT 3POS 2.54MM" H 4200 3800 50  0001 C CNN "Description"
F 6 "No" H 4200 3800 50  0001 C CNN "Place"
F 7 "Digikey" H 4200 3800 50  0001 C CNN "Dist"
F 8 "609-3468-ND" H 4200 3800 50  0001 C CNN "DistPartNumber"
F 9 "https://www.digikey.de/product-detail/en/amphenol-icc-fci/68001-102HLF/609-3506-ND/1493701" H 4200 3800 50  0001 C CNN "DistLink"
	1    4200 3800
	-1   0    0    1   
$EndComp
Text GLabel 4400 3900 2    50   Output ~ 0
ING
$Comp
L power:GND #PWR0102
U 1 1 5FD6301D
P 4400 3800
F 0 "#PWR0102" H 4400 3550 50  0001 C CNN
F 1 "GND" V 4400 3600 50  0000 C CNN
F 2 "" H 4400 3800 50  0001 C CNN
F 3 "" H 4400 3800 50  0001 C CNN
	1    4400 3800
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0103
U 1 1 5FD631A0
P 5300 3800
F 0 "#PWR0103" H 5300 3550 50  0001 C CNN
F 1 "GND" V 5300 3600 50  0000 C CNN
F 2 "" H 5300 3800 50  0001 C CNN
F 3 "" H 5300 3800 50  0001 C CNN
	1    5300 3800
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0104
U 1 1 5FD631BB
P 5300 3700
F 0 "#PWR0104" H 5300 3450 50  0001 C CNN
F 1 "GND" V 5300 3500 50  0000 C CNN
F 2 "" H 5300 3700 50  0001 C CNN
F 3 "" H 5300 3700 50  0001 C CNN
	1    5300 3700
	0    1    1    0   
$EndComp
Text GLabel 4400 3700 2    50   Output ~ 0
INR
$Comp
L Connector_Generic:Conn_01x03 J2
U 1 1 5FD63850
P 5500 3800
F 0 "J2" H 5420 3475 50  0000 C CNN
F 1 "GND" H 5420 3566 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 5500 3800 50  0001 C CNN
F 3 "~" H 5500 3800 50  0001 C CNN
F 4 "Male Hader" H 5500 3800 50  0001 C CNN "Device"
F 5 "CONN HEADER VERT 3POS 2.54MM" H 5500 3800 50  0001 C CNN "Description"
F 6 "No" H 5500 3800 50  0001 C CNN "Place"
F 7 "Digikey" H 5500 3800 50  0001 C CNN "Dist"
F 8 "609-3468-ND" H 5500 3800 50  0001 C CNN "DistPartNumber"
F 9 "https://www.digikey.de/product-detail/en/amphenol-icc-fci/68001-102HLF/609-3506-ND/1493701" H 5500 3800 50  0001 C CNN "DistLink"
	1    5500 3800
	1    0    0    1   
$EndComp
$Comp
L power:GND #PWR0101
U 1 1 5FD638FF
P 5300 3900
F 0 "#PWR0101" H 5300 3650 50  0001 C CNN
F 1 "GND" V 5300 3700 50  0000 C CNN
F 2 "" H 5300 3900 50  0001 C CNN
F 3 "" H 5300 3900 50  0001 C CNN
	1    5300 3900
	0    1    1    0   
$EndComp
$Comp
L Device:LED_Dual_ACA D1
U 1 1 5FD639C8
P 5100 4700
F 0 "D1" H 5100 5125 50  0000 C CNN
F 1 "LED_Dual_ACA" H 5100 5034 50  0000 C CNN
F 2 "LED_THT:LED_D3.0mm-3" H 5100 4700 50  0001 C CNN
F 3 "~" H 5100 4700 50  0001 C CNN
F 4 "LED" H 5100 4700 50  0001 C CNN "Device"
F 5 "LED GREEN/RED DIFFUSED T-1 T/H" H 5100 4700 50  0001 C CNN "Description"
F 6 "No" H 5100 4700 50  0001 C CNN "Place"
F 7 "Digikey" H 5100 4700 50  0001 C CNN "Dist"
F 8 "754-1221-ND" H 5100 4700 50  0001 C CNN "DistPartNumber"
F 9 "https://www.digikey.de/product-detail/en/kingbright/WP3VEGW/754-1221-ND/1747620" H 5100 4700 50  0001 C CNN "DistLink"
	1    5100 4700
	-1   0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 5FD63B4A
P 4550 4600
F 0 "R1" V 4343 4600 50  0000 C CNN
F 1 "100" V 4434 4600 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 4480 4600 50  0001 C CNN
F 3 "~" H 4550 4600 50  0001 C CNN
F 4 "Resistor" H 4550 4600 50  0001 C CNN "Device"
F 5 "RES SMD 100 OHM 1% 1/10W 0603" H 4550 4600 50  0001 C CNN "Description"
F 6 "Yes" H 4550 4600 50  0001 C CNN "Place"
F 7 "Digikey" H 4550 4600 50  0001 C CNN "Dist"
F 8 "311-100HRCT-ND" H 4550 4600 50  0001 C CNN "DistPartNumber"
F 9 "https://www.digikey.de/product-detail/en/yageo/RC0603FR-07100RL/311-100HRCT-ND/729835" H 4550 4600 50  0001 C CNN "DistLink"
	1    4550 4600
	0    1    1    0   
$EndComp
$Comp
L Device:R R2
U 1 1 5FD63B7D
P 4550 4800
F 0 "R2" V 4650 4800 50  0000 C CNN
F 1 "100" V 4750 4800 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 4480 4800 50  0001 C CNN
F 3 "~" H 4550 4800 50  0001 C CNN
F 4 "Resistor" H 4550 4800 50  0001 C CNN "Device"
F 5 "RES SMD 100 OHM 1% 1/10W 0603" H 4550 4800 50  0001 C CNN "Description"
F 6 "Yes" H 4550 4800 50  0001 C CNN "Place"
F 7 "Digikey" H 4550 4800 50  0001 C CNN "Dist"
F 8 "311-100HRCT-ND" H 4550 4800 50  0001 C CNN "DistPartNumber"
F 9 "https://www.digikey.de/product-detail/en/yageo/RC0603FR-07100RL/311-100HRCT-ND/729835" H 4550 4800 50  0001 C CNN "DistLink"
	1    4550 4800
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0105
U 1 1 5FD63BA1
P 5500 4700
F 0 "#PWR0105" H 5500 4450 50  0001 C CNN
F 1 "GND" V 5500 4500 50  0000 C CNN
F 2 "" H 5500 4700 50  0001 C CNN
F 3 "" H 5500 4700 50  0001 C CNN
	1    5500 4700
	0    -1   -1   0   
$EndComp
Text GLabel 4300 4600 0    50   Input ~ 0
INR
Text GLabel 4300 4800 0    50   Input ~ 0
ING
Wire Wire Line
	4300 4600 4400 4600
Wire Wire Line
	4300 4800 4400 4800
Wire Wire Line
	4700 4600 4800 4600
Wire Wire Line
	4700 4800 4800 4800
Wire Wire Line
	5400 4700 5500 4700
$EndSCHEMATC