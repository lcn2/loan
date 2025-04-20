/*
 * loanlen - determine the length of a loan given a payment
 *
 * This is free and unencumbered software released into the public domain.
 *
 * Anyone is free to copy, modify, publish, use, compile, sell, or
 * distribute this software, either in source code form or as a compiled
 * binary, for any purpose, commercial or non-commercial, and by any
 * means.
 *
 * In jurisdictions that recognize copyright laws, the author or authors
 * of this software dedicate any and all copyright interest in the
 * software to the public domain. We make this dedication for the benefit
 * of the public at large and to the detriment of our heirs and
 * successors. We intend this dedication to be an overt act of
 * relinquishment in perpetuity of all present and future rights to this
 * software under copyright law.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * These tools attempt to produce a common loan amortization schedule.
 * The lender you may choose may produce a somewhat different loan schedule
 * due to things such as:
 *
 * * differences in rounding
 * * differences in calculation precision
 * * periodic loan fees and related loan expenses
 * * bugs in the lender's loan calculation (this has actually been known to happen!)
 * * bugs in this code
 * * etc.
 *
 * You **MUST** consult with a certified financial planner and/or qualified loan agent
 * before considering any loan or loan calculation.
 *
 * The calculations made by these programs are being provided for educational
 * purposes only. The results are estimates based on information you provide
 * and may not reflect actual results. The results of the calculations are
 * not a promise or guarantee of a customer’s eligibility or terms for
 * a specific product or service.
 *
 * Landon Curt Noll is not responsible for the content, results, or accuracy
 * of the information on the calculators.
 *
 * The calculations are hypothetical examples designed to illustrate the
 * impact compounding can have. The examples are not representative of
 * any investment class or specific security. Actual returns and principal
 * values will vary.
 *
 * Based on loan.c  (6 Jul 1994)
 *
 * chongo (Landon Curt Noll) /\oo/\
 *
 * http://www.isthe.com/chongo/index.html
 * https://github.com/lcn2
 *
 * Share and enjoy!  :-)
 */

#include <stdio.h>
#include <math.h>

/*
 * official version
 */
#define VERSION "1.5.1 2025-03-28"          /* format: major.minor YYYY-MM-DD */

int
main(void)		/* loan program */
{
	float amt, term, rate, ic;
	float r, pmt, fv;
	float exp, prin, mbeg, mnbr, yrint = 0;
	int month, i, k, a = 0, yr=1;
	char d, filename[9], c;
	FILE *fp;
	/*  prompt for input from terminal  */

	printf("Enter principal amount: ");
	scanf("%f", &amt);

	printf("Enter Standard payment: ");
	scanf("%f", &pmt);

	printf("Enter interest rate in percent: ");
	scanf("%f", &rate);

	printf("Enter month payments begin (ex: 8 = August): ");
	scanf("%f", &mbeg);

	/*  compute payment and future value  */

	r = rate/100.0;
	term = log(1 - ((amt*r)/(12.0*pmt))) / (-12.0 * log(1 + r/12.0));
	k = ceil(term*12.0);
	fv = pmt*k;
	ic = fv - amt;

	printf("Do you want the report directed to a file or to the screen?");
	printf("\n[f = file / s = screen] : ");
	d = getchar();      /* This is only here to eat up the '\n' left over
			       from the last scanf. */
	d = getchar();
	switch(d) {
	     case 'f':
	     d = getchar();
	     printf("\nEnter a filename: ");
	     scanf("%s", filename);
	     while((c = getchar()) != '\n') {
	     filename[a] = c; a++; }
	     fp = fopen(filename, "w");
	     break;
	     default:
	     fp = stdout;
	     break;
	     }

	     /*  print header  */

	   fprintf(fp,"\n\t *** Amortization Schedule ***\n\n");
	   fprintf(fp,"Principal:  %.2f\n", amt);
	   fprintf(fp,"Future value:  %.2f\n", fv);
	   fprintf(fp,"Term of loan in years:  %.5f\n", term);
	   fprintf(fp,"Interest Rate:  %3.3f\n", rate);
	   fprintf(fp,"Total Interest Charge:  %.2f\n", ic);
	   fprintf(fp,"Payment:  %.2f\n", pmt);
	   fprintf(fp,"\nMONTH\tPRINCIPAL\tINTEREST\tBALANCE\n");

	   /* start of loop to print amortization schedule */

	   mnbr=mbeg;
	   for (i=1; i<=k; i++) {
	      month = i;
	      exp = amt*(r/12.0);
	      yrint=yrint+exp;
	      prin = pmt-exp;
	      amt = amt-prin;
	      mnbr++;
	      fprintf(fp,"%d\t %.2f\t\t %.2f\t\t %.2f\n", month, prin, exp, amt);
	      if (mnbr > 12 ) {
	      fprintf(fp,"\t\tInterest paid for year %d is %.2f\n\n",yr,yrint);
	      yr++;
	      yrint=0;
	      mnbr=1;
              }
}
	     fprintf(fp,"\t\tInterest paid for year %d is %.2f\n\n",yr,yrint);
	     fprintf(fp,"\t\tTerm of loan in years:  %.5f\n", term);
	     fprintf(fp,"\t\tStandard Payment:  %.2f\n", pmt);
	     fprintf(fp,"\t\t    Last Payment:  %.2f\n", pmt+amt);
	     fclose(fp);
}
