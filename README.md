# loan

loan amortization programs


# To install

```sh
make clobber all
sudo make install clobber
```


# Example


## loan

Produce an Amortization Schedule given:

* loan amount (principal)
* loan length (term in years)
* interest rate (percentage)
* starting month (such as: January == 1, .. August ==> 8, .. December == 12)
* write to a file (f) or stdout (s)

```
$ /usr/local/bin/loan
Enter principal amount: 10000
Enter term in years: 3
Enter interest rate in percent: 6
Enter month payments begin (ex: 8 = August): 8
Do you want the report directed to a file or to the screen?
[f = file / s = screen] : s

	 *** Amortization Schedule ***

Principal:  10000.00
Future value:  10951.91
Term of loan in years:  3.00000
Interest Rate:  6.000
Total Interest Charge:  951.91
Payment:  304.22

MONTH	PRINCIPAL	INTEREST	BALANCE
1	 254.22		 50.00		 9745.78
2	 255.49		 48.73		 9490.29
3	 256.77		 47.45		 9233.52
4	 258.05		 46.17		 8975.47
5	 259.34		 44.88		 8716.13
		Interest paid for year 1 is 237.23

6	 260.64		 43.58		 8455.49
7	 261.94		 42.28		 8193.54
8	 263.25		 40.97		 7930.29
9	 264.57		 39.65		 7665.72
10	 265.89		 38.33		 7399.83
11	 267.22		 37.00		 7132.61
12	 268.56		 35.66		 6864.06
13	 269.90		 34.32		 6594.16
14	 271.25		 32.97		 6322.91
15	 272.61		 31.61		 6050.30
16	 273.97		 30.25		 5776.33
17	 275.34		 28.88		 5501.00
		Interest paid for year 2 is 435.51

18	 276.71		 27.50		 5224.28
19	 278.10		 26.12		 4946.18
20	 279.49		 24.73		 4666.69
21	 280.89		 23.33		 4385.81
22	 282.29		 21.93		 4103.52
23	 283.70		 20.52		 3819.82
24	 285.12		 19.10		 3534.70
25	 286.55		 17.67		 3248.15
26	 287.98		 16.24		 2960.17
27	 289.42		 14.80		 2670.75
28	 290.87		 13.35		 2379.89
29	 292.32		 11.90		 2087.57
		Interest paid for year 3 is 237.20

30	 293.78		 10.44		 1793.78
31	 295.25		 8.97		 1498.53
32	 296.73		 7.49		 1201.81
33	 298.21		 6.01		 903.60
34	 299.70		 4.52		 603.89
35	 301.20		 3.02		 302.69
36	 302.71		 1.51		 -0.01
		Interest paid for year 4 is 41.96

		Standard Payment:  304.22
		    Last Payment:  304.21
```


## loanlan

Produce an Amortization Schedule given:

* loan amount (principal)
* standard payment (monthly payment: principal + interest)
* interest rate (percentage)
* starting month (such as: January == 1, .. August ==> 8, .. December == 12)
* write to a file (f) or stdout (s)

### NOTE

If the standard payment is **NOT** the standard amortized payment, then the final month payment may become negative.  In the follow Amortization Schedule, because the "Standard payment" is 300.00 (not 304.22), the loan takes an extra month and the final monthly payment goes negative.

One may simply regard the final month payment is just 166.80 (instead of 300.00), or that the lender will have to refund 133.20 due to the excess of the last payment.

```
$ /usr/local/bin/loanlen
Enter principal amount: 10000
Enter Standard payment: 300
Enter interest rate in percent: 6
Enter month payments begin (ex: 8 = August): 8
Do you want the report directed to a file or to the screen?
[f = file / s = screen] : s

	 *** Amortization Schedule ***

Principal:  10000.00
Future value:  11100.00
Term of loan in years:  3.04628
Interest Rate:  6.000
Total Interest Charge:  1100.00
Payment:  300.00

MONTH	PRINCIPAL	INTEREST	BALANCE
1	 250.00		 50.00		 9750.00
2	 251.25		 48.75		 9498.75
3	 252.51		 47.49		 9246.24
4	 253.77		 46.23		 8992.48
5	 255.04		 44.96		 8737.44
		Interest paid for year 1 is 237.44

6	 256.31		 43.69		 8481.12
7	 257.59		 42.41		 8223.53
8	 258.88		 41.12		 7964.65
9	 260.18		 39.82		 7704.47
10	 261.48		 38.52		 7442.99
11	 262.79		 37.21		 7180.21
12	 264.10		 35.90		 6916.11
13	 265.42		 34.58		 6650.69
14	 266.75		 33.25		 6383.94
15	 268.08		 31.92		 6115.86
16	 269.42		 30.58		 5846.44
17	 270.77		 29.23		 5575.67
		Interest paid for year 2 is 438.24

18	 272.12		 27.88		 5303.55
19	 273.48		 26.52		 5030.07
20	 274.85		 25.15		 4755.22
21	 276.22		 23.78		 4479.00
22	 277.61		 22.39		 4201.39
23	 278.99		 21.01		 3922.40
24	 280.39		 19.61		 3642.01
25	 281.79		 18.21		 3360.22
26	 283.20		 16.80		 3077.02
27	 284.61		 15.39		 2792.41
28	 286.04		 13.96		 2506.37
29	 287.47		 12.53		 2218.90
		Interest paid for year 3 is 243.23

30	 288.91		 11.09		 1930.00
31	 290.35		 9.65		 1639.65
32	 291.80		 8.20		 1347.84
33	 293.26		 6.74		 1054.58
34	 294.73		 5.27		 759.86
35	 296.20		 3.80		 463.65
36	 297.68		 2.32		 165.97
37	 299.17		 0.83		 -133.20
		Interest paid for year 4 is 47.90

		Term of loan in years:  3.04628
		Standard Payment:  300.00
		    Last Payment:  166.80
```


# To use

```
/usr/local/bin/loan

/usr/local/bin/loanlan
```


# DISCLAIMER

These tools attempt to produce a common loan amortization schedule.
The lender you may choose may produce a somewhat different loan schedule
due to things such as:

* differences in rounding
* differences in calculation precision
* periodic loan fees and related loan expenses
* bugs in the lender's loan calculation (this has actually been known to happen!)
* bugs in this code
* etc.

You **MUST** consult with a certified financial planner and/or qualified loan agent
before considering any loan or loan calculation.

The calculations made by these programs are being provided for educational
purposes only. The results are estimates based on information you provide
and may not reflect actual results. The results of the calculations are
not a promise or guarantee of a customer’s eligibility or terms for
a specific product or service.

Landon Curt Noll is not responsible for the content, results, or accuracy
of the information on the calculators.

The calculations are hypothetical examples designed to illustrate the
impact compounding can have. The examples are not representative of
any investment class or specific security. Actual returns and principal
values will vary.


# Reporting Security Issues

To report a security issue, please visit "[Reporting Security Issues](https://github.com/lcn2/loan/security/policy)".
