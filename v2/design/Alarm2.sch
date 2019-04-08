EESchema Schematic File Version 4
LIBS:Alarm2-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Alarm Clock"
Date "2019-01-12"
Rev "1"
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Device:Buzzer BZ1
U 1 1 5C3A1434
P 5100 5700
F 0 "BZ1" H 5253 5729 50  0000 L CNN
F 1 "Buzzer" H 5253 5638 50  0000 L CNN
F 2 "Buzzer_Beeper:Buzzer_12x9.5RM7.6" V 5075 5800 50  0001 C CNN
F 3 "~" V 5075 5800 50  0001 C CNN
	1    5100 5700
	-1   0    0    -1  
$EndComp
$Comp
L MCU_Microchip_ATmega:ATmega328P-PU U1
U 1 1 5C3A15F2
P 4300 3750
F 0 "U1" H 4300 3850 50  0000 R CNN
F 1 "ATmega328P-PU" H 4550 3750 50  0000 R CNN
F 2 "Package_DIP:DIP-28_W7.62mm" H 4300 3750 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/ATmega328_P%20AVR%20MCU%20with%20picoPower%20Technology%20Data%20Sheet%2040001984A.pdf" H 4300 3750 50  0001 C CNN
	1    4300 3750
	1    0    0    -1  
$EndComp
$Comp
L Timer_RTC:DS1307+ U2
U 1 1 5C3A1758
P 6550 3500
F 0 "U2" H 7091 3546 50  0001 L CNN
F 1 "DS1307+" H 7091 3455 50  0001 L CNN
F 2 "Package_DIP:DIP-8_W7.62mm" H 6550 3000 50  0001 C CNN
F 3 "https://datasheets.maximintegrated.com/en/ds/DS1307.pdf" H 6550 3300 50  0001 C CNN
	1    6550 3500
	1    0    0    1   
$EndComp
$Comp
L Switch:SW_Push SW1
U 1 1 5C3A4E60
P 5900 4350
F 0 "SW1" H 5900 4635 50  0000 C CNN
F 1 "SW_Push" H 5900 4550 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Horizontal" H 5900 4550 50  0001 C CNN
F 3 "" H 5900 4550 50  0001 C CNN
	1    5900 4350
	1    0    0    -1  
$EndComp
$Comp
L Device:R_US R1
U 1 1 5C3A54FA
P 6300 4500
F 0 "R1" V 6095 4500 50  0000 C CNN
F 1 "10K" V 6186 4500 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 6340 4490 50  0001 C CNN
F 3 "~" H 6300 4500 50  0001 C CNN
	1    6300 4500
	0    1    1    0   
$EndComp
$Comp
L Switch:SW_Push SW2
U 1 1 5C3A88CD
P 5900 4900
F 0 "SW2" H 5900 5185 50  0000 C CNN
F 1 "SW_Push" H 5900 5100 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Horizontal" H 5900 5100 50  0001 C CNN
F 3 "" H 5900 5100 50  0001 C CNN
	1    5900 4900
	1    0    0    -1  
$EndComp
$Comp
L Device:R_US R2
U 1 1 5C3A88DA
P 6300 5000
F 0 "R2" V 6095 5000 50  0000 C CNN
F 1 "10k" V 6186 5000 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 6340 4990 50  0001 C CNN
F 3 "~" H 6300 5000 50  0001 C CNN
	1    6300 5000
	0    1    1    0   
$EndComp
$Comp
L Switch:SW_Push SW3
U 1 1 5C3A8EAA
P 5900 5400
F 0 "SW3" H 5900 5685 50  0000 C CNN
F 1 "SW_Push" H 5900 5600 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Horizontal" H 5900 5600 50  0001 C CNN
F 3 "" H 5900 5600 50  0001 C CNN
	1    5900 5400
	1    0    0    -1  
$EndComp
$Comp
L Device:R_US R3
U 1 1 5C3A8EB6
P 6300 5500
F 0 "R3" V 6095 5500 50  0000 C CNN
F 1 "10K" V 6186 5500 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 6340 5490 50  0001 C CNN
F 3 "~" H 6300 5500 50  0001 C CNN
	1    6300 5500
	0    1    1    0   
$EndComp
$Comp
L Switch:SW_Push SW4
U 1 1 5C3A8EC4
P 5900 5900
F 0 "SW4" H 5900 6185 50  0000 C CNN
F 1 "SW_Push" H 5900 6100 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Horizontal" H 5900 6100 50  0001 C CNN
F 3 "" H 5900 6100 50  0001 C CNN
	1    5900 5900
	1    0    0    -1  
$EndComp
$Comp
L Device:R_US R4
U 1 1 5C3A8ED0
P 6300 6000
F 0 "R4" V 6095 6000 50  0000 C CNN
F 1 "10K" V 6186 6000 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 6340 5990 50  0001 C CNN
F 3 "~" H 6300 6000 50  0001 C CNN
	1    6300 6000
	0    1    1    0   
$EndComp
Wire Wire Line
	5700 4350 5700 4500
Wire Wire Line
	5700 4500 6150 4500
Wire Wire Line
	5700 4900 5700 5000
Wire Wire Line
	5700 5000 6150 5000
Wire Wire Line
	6450 4500 6450 5000
Connection ~ 6450 5000
Wire Wire Line
	5700 5900 5700 6000
Wire Wire Line
	5700 6000 6150 6000
Wire Wire Line
	6100 4900 6100 4350
Connection ~ 6100 4900
Wire Wire Line
	4900 4250 5600 4250
Wire Wire Line
	5600 4250 5600 4350
Wire Wire Line
	5600 4350 5700 4350
Connection ~ 5700 4350
Wire Wire Line
	4900 4350 5500 4350
Wire Wire Line
	5500 4350 5500 4900
Wire Wire Line
	5500 4900 5700 4900
Connection ~ 5700 4900
Wire Wire Line
	4900 4450 5400 4450
Wire Wire Line
	5400 4450 5400 5400
Wire Wire Line
	5400 5400 5700 5400
Wire Wire Line
	4900 4550 5300 4550
Wire Wire Line
	5300 4550 5300 5900
Wire Wire Line
	5300 5900 5700 5900
Connection ~ 5700 5900
Wire Wire Line
	6100 4350 6100 4250
Connection ~ 6100 4350
Connection ~ 6450 4500
Wire Wire Line
	5700 5400 5700 5500
Wire Wire Line
	5700 5500 6150 5500
Connection ~ 5700 5400
Wire Wire Line
	6100 4900 6100 5400
Wire Wire Line
	6450 5000 6450 5500
Wire Wire Line
	6450 6000 6450 5500
Connection ~ 6450 5500
Wire Wire Line
	6100 5900 6100 5400
Connection ~ 6100 5400
Wire Wire Line
	4900 4650 5200 4650
Wire Wire Line
	5200 4650 5200 5600
$Comp
L Device:Crystal Y1
U 1 1 5C3C8BCA
P 5850 3350
F 0 "Y1" V 5850 3350 50  0000 C CNN
F 1 "32.768Khz" V 6050 3350 50  0000 C CNN
F 2 "Crystal:Crystal_AT310_D3.0mm_L10.0mm_Horizontal" H 5850 3350 50  0001 C CNN
F 3 "~" H 5850 3350 50  0001 C CNN
	1    5850 3350
	0    1    -1   0   
$EndComp
$Comp
L Device:Battery_Cell BT1
U 1 1 5C3CF090
P 7200 3450
F 0 "BT1" H 7318 3546 50  0000 L CNN
F 1 "Battery_Cell" H 7318 3455 50  0000 L CNN
F 2 "Battery:BatteryHolder_Keystone_3001_1x12mm" V 7200 3510 50  0001 C CNN
F 3 "~" V 7200 3510 50  0001 C CNN
	1    7200 3450
	1    0    0    1   
$EndComp
Wire Wire Line
	7200 3900 7200 3650
Wire Wire Line
	7200 3350 7200 3100
Wire Wire Line
	7200 3100 6550 3100
$Comp
L Nokia:Nokia-5110 D1
U 1 1 5C3D6524
P 6150 3150
F 0 "D1" H 6300 2100 50  0000 C CNN
F 1 "Nokia-5110" H 6300 2200 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x08_P2.54mm_Vertical" H 6200 3150 50  0001 C CNN
F 3 "" H 6200 3150 50  0001 C CNN
	1    6150 3150
	1    0    0    1   
$EndComp
Wire Wire Line
	4900 2550 6050 2550
Wire Wire Line
	4900 2650 6050 2650
Wire Wire Line
	4900 2750 6050 2750
Wire Wire Line
	4900 2850 5600 2850
Wire Wire Line
	4900 2950 5700 2950
Wire Wire Line
	4900 3050 5500 3050
Wire Wire Line
	6100 4250 6450 4250
Wire Wire Line
	6450 4250 6450 4350
Wire Wire Line
	6550 3900 7200 3900
Wire Wire Line
	5850 3200 6050 3200
Wire Wire Line
	6050 3200 6050 3300
Wire Wire Line
	5850 3500 6050 3500
Wire Wire Line
	6050 3500 6050 3400
Wire Wire Line
	4950 2450 6050 2450
Wire Wire Line
	6050 2350 5100 2350
Wire Wire Line
	4300 1950 4300 2250
Wire Wire Line
	5100 2350 5100 1950
Connection ~ 5100 1950
Wire Wire Line
	5100 1950 4300 1950
Wire Wire Line
	7950 4350 7950 1950
Wire Wire Line
	6450 4350 7950 4350
Wire Wire Line
	6450 4500 6850 4500
Wire Wire Line
	5200 6100 6850 6100
Wire Wire Line
	6850 6100 6850 4500
Wire Wire Line
	5200 5800 5200 6100
Connection ~ 6850 4500
Wire Wire Line
	6850 4500 8050 4500
Wire Wire Line
	4300 6100 5200 6100
Wire Wire Line
	4300 5250 4300 6100
Connection ~ 5200 6100
$Comp
L Connector:AVR-ISP-6 J2
U 1 1 5C3BE46D
P 5500 1400
F 0 "J2" V 5083 1450 50  0000 C CNN
F 1 "AVR-ISP-6" V 5174 1450 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x03_P2.54mm_Vertical" V 5250 1450 50  0001 C CNN
F 3 " ~" H 4225 850 50  0001 C CNN
	1    5500 1400
	0    1    1    0   
$EndComp
Wire Wire Line
	6000 1300 6000 1950
Connection ~ 6000 1950
Wire Wire Line
	6000 1950 5100 1950
Wire Wire Line
	5700 1800 5700 2950
Connection ~ 5700 2950
Wire Wire Line
	5700 2950 6050 2950
Wire Wire Line
	5600 1800 5600 2850
Connection ~ 5600 2850
Wire Wire Line
	5600 2850 6050 2850
Wire Wire Line
	5500 1800 5500 3050
Connection ~ 5500 3050
Wire Wire Line
	5500 3050 6050 3050
Wire Wire Line
	5400 1800 5400 4050
Wire Wire Line
	5400 4050 4900 4050
Wire Wire Line
	4950 1300 5100 1300
Wire Wire Line
	4950 900  4950 1300
Connection ~ 4950 1300
Wire Wire Line
	4950 1300 4950 2450
Wire Wire Line
	4950 900  6350 900 
$Comp
L Device:R_US R5
U 1 1 5C3DB18D
P 5500 3750
F 0 "R5" H 5500 3450 50  0000 C CNN
F 1 "2.2K" H 5500 3550 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 5540 3740 50  0001 C CNN
F 3 "~" H 5500 3750 50  0001 C CNN
	1    5500 3750
	-1   0    0    1   
$EndComp
$Comp
L Device:R_US R6
U 1 1 5C3DB39E
P 5650 3850
F 0 "R6" H 5650 3550 50  0000 C CNN
F 1 "2.2K" H 5650 3650 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 5690 3840 50  0001 C CNN
F 3 "~" H 5650 3850 50  0001 C CNN
	1    5650 3850
	-1   0    0    1   
$EndComp
Wire Wire Line
	6050 3600 5500 3600
Wire Wire Line
	5000 3600 5000 3850
Wire Wire Line
	5000 3850 4900 3850
Wire Wire Line
	4900 3950 5100 3950
Wire Wire Line
	5100 3950 5100 3700
Wire Wire Line
	5100 3700 5650 3700
Connection ~ 5500 3600
Wire Wire Line
	5500 3600 5000 3600
Connection ~ 5650 3700
Wire Wire Line
	5650 3700 6050 3700
Wire Wire Line
	5500 3900 5500 4000
Wire Wire Line
	5500 4000 5650 4000
Wire Wire Line
	5650 4000 6450 4000
Wire Wire Line
	6450 3900 6450 4000
Connection ~ 5650 4000
Wire Wire Line
	6450 4000 6450 4250
Connection ~ 6450 4000
Connection ~ 6450 4250
Wire Wire Line
	7200 3100 8050 3100
Connection ~ 7200 3100
Wire Wire Line
	8050 3100 8050 4500
$Comp
L 10118193-0001LF:10118193-0001LF J1
U 1 1 5C48473D
P 6900 1100
F 0 "J1" V 6840 672 50  0000 R CNN
F 1 "10118193-0001LF" V 6749 672 50  0000 R CNN
F 2 "FCI_10118193-0001LF" H 6900 1100 50  0001 L BNN
F 3 "Conn Micro USB Type B RCP 5 POS 0.65mm Solder RA SMD 5 Terminal 1 Port T/R" H 6900 1100 50  0001 L BNN
F 4 "Amphenol ICC" H 6900 1100 50  0001 L BNN "Field4"
F 5 "https://www.digikey.com/product-detail/en/amphenol-icc-fci/10118193-0001LF/609-4616-1-ND/2785380?utm_source=snapeda&utm_medium=aggregator&utm_campaign=symbol" H 6900 1100 50  0001 L BNN "Field5"
F 6 "10118193-0001LF" H 6900 1100 50  0001 L BNN "Field6"
F 7 "None" H 6900 1100 50  0001 L BNN "Field7"
F 8 "609-4616-1-ND" H 6900 1100 50  0001 L BNN "Field8"
	1    6900 1100
	0    -1   -1   0   
$EndComp
Wire Wire Line
	6000 1950 6600 1950
Connection ~ 6600 1950
Wire Wire Line
	6600 1950 7950 1950
Wire Wire Line
	6600 1500 6600 1650
Wire Wire Line
	6350 900  6350 1800
Wire Wire Line
	8050 1800 8050 3100
Connection ~ 8050 3100
Wire Wire Line
	7000 1500 7000 1650
Connection ~ 7000 1800
Wire Wire Line
	7000 1800 8050 1800
$Comp
L Device:C C1
U 1 1 5C4A78CE
P 6800 1650
F 0 "C1" V 6800 1950 50  0000 C CNN
F 1 "1uF" V 6800 1350 50  0000 C CNN
F 2 "Capacitor_THT:C_Disc_D5.0mm_W2.5mm_P5.00mm" H 6838 1500 50  0001 C CNN
F 3 "~" H 6800 1650 50  0001 C CNN
	1    6800 1650
	0    -1   -1   0   
$EndComp
Wire Wire Line
	6600 1650 6650 1650
Connection ~ 6600 1650
Wire Wire Line
	6600 1650 6600 1950
Wire Wire Line
	6950 1650 7000 1650
Connection ~ 7000 1650
Wire Wire Line
	7000 1650 7000 1800
Wire Wire Line
	6350 1800 7000 1800
$EndSCHEMATC
