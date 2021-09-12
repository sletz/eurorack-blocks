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
L pspice:VSOURCE V1
U 1 1 5FF747BD
P 3400 3700
F 0 "V1" H 3628 3746 50  0000 L CNN
F 1 "VSOURCE" H 3628 3655 50  0000 L CNN
F 2 "" H 3400 3700 50  0001 C CNN
F 3 "" H 3400 3700 50  0001 C CNN
F 4 "V" H 3400 3700 50  0001 C CNN "Spice_Primitive"
F 5 "dc 1" H 3850 3550 50  0000 C CNN "Spice_Model"
F 6 "Y" H 3400 3700 50  0001 C CNN "Spice_Netlist_Enabled"
	1    3400 3700
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5FF74822
P 3400 4000
F 0 "#PWR?" H 3400 3750 50  0001 C CNN
F 1 "GND" H 3405 3827 50  0000 C CNN
F 2 "" H 3400 4000 50  0001 C CNN
F 3 "" H 3400 4000 50  0001 C CNN
	1    3400 4000
	1    0    0    -1  
$EndComp
Wire Wire Line
	3400 3400 3900 3400
Text Notes 3200 2950 0    50   ~ 0
.dc V1 -12 12 .5
$Comp
L Diode:1N4148 D1
U 1 1 613BAEEA
P 4500 3550
F 0 "D1" V 4454 3630 50  0000 L CNN
F 1 "1N4148" V 4545 3630 50  0000 L CNN
F 2 "Diode_THT:D_DO-35_SOD27_P7.62mm_Horizontal" H 4500 3375 50  0001 C CNN
F 3 "https://assets.nexperia.com/documents/data-sheet/1N4148_1N4448.pdf" H 4500 3550 50  0001 C CNN
F 4 "D" H 4500 3550 50  0001 C CNN "Spice_Primitive"
F 5 "1N4148" H 4500 3550 50  0001 C CNN "Spice_Model"
F 6 "Y" H 4500 3550 50  0001 C CNN "Spice_Netlist_Enabled"
F 7 "2 1" H 4500 3550 50  0001 C CNN "Spice_Node_Sequence"
	1    4500 3550
	0    1    1    0   
$EndComp
Wire Wire Line
	4200 3400 4500 3400
Connection ~ 4500 3400
$Comp
L power:GND #PWR?
U 1 1 5FF7469C
P 4500 3700
F 0 "#PWR?" H 4500 3450 50  0001 C CNN
F 1 "GND" V 4500 3500 50  0000 C CNN
F 2 "" H 4500 3700 50  0001 C CNN
F 3 "" H 4500 3700 50  0001 C CNN
	1    4500 3700
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 5FF74120
P 4050 3400
F 0 "R1" V 3843 3400 50  0000 C CNN
F 1 "100k" V 3934 3400 50  0000 C CNN
F 2 "" V 3980 3400 50  0001 C CNN
F 3 "~" H 4050 3400 50  0001 C CNN
	1    4050 3400
	0    1    1    0   
$EndComp
Text Notes 5500 3350 0    50   ~ 0
PROBE
Wire Wire Line
	4500 3400 5750 3400
$Comp
L Diode:1N4148 D2
U 1 1 613B7063
P 4500 3250
F 0 "D2" V 4454 3330 50  0000 L CNN
F 1 "1N4148" V 4545 3330 50  0000 L CNN
F 2 "Diode_THT:D_DO-35_SOD27_P7.62mm_Horizontal" H 4500 3075 50  0001 C CNN
F 3 "https://assets.nexperia.com/documents/data-sheet/1N4148_1N4448.pdf" H 4500 3250 50  0001 C CNN
F 4 "D" H 4500 3250 50  0001 C CNN "Spice_Primitive"
F 5 "1N4148" H 4500 3250 50  0001 C CNN "Spice_Model"
F 6 "Y" H 4500 3250 50  0001 C CNN "Spice_Netlist_Enabled"
F 7 "2 1" H 4500 3250 50  0001 C CNN "Spice_Node_Sequence"
	1    4500 3250
	0    1    1    0   
$EndComp
$Comp
L pspice:VSOURCE V2
U 1 1 613B7193
P 5000 2650
F 0 "V2" H 5228 2696 50  0000 L CNN
F 1 "VSOURCE" H 5228 2605 50  0000 L CNN
F 2 "" H 5000 2650 50  0001 C CNN
F 3 "" H 5000 2650 50  0001 C CNN
F 4 "V" H 5000 2650 50  0001 C CNN "Spice_Primitive"
F 5 "3.3" H 5450 2500 50  0000 C CNN "Spice_Model"
F 6 "Y" H 5000 2650 50  0001 C CNN "Spice_Netlist_Enabled"
	1    5000 2650
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 613B86D5
P 5000 2950
F 0 "#PWR?" H 5000 2700 50  0001 C CNN
F 1 "GND" H 5005 2777 50  0000 C CNN
F 2 "" H 5000 2950 50  0001 C CNN
F 3 "" H 5000 2950 50  0001 C CNN
	1    5000 2950
	1    0    0    -1  
$EndComp
Wire Wire Line
	5000 2350 4500 2350
Wire Wire Line
	4500 2350 4500 3100
$EndSCHEMATC
