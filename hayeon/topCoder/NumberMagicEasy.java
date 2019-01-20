package topcoder;

import java.util.Scanner;

public class NumberMagicEasy {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		
		Scanner scan = new Scanner(System.in);
		String answer=scan.next();
		
		System.out.println(theNumber(answer));
		
	}
	public static int theNumber(String answer) {
		
		String[] c= {
			"YYYY",
			"YYYN",
			"YYNY",
			"YYNN",
			"YNYY",
			"YNYN",
			"YNNY",
			"YNNN",
			"NYYY",
			"NYYN",
			"NYNY",
			"NYNN",
			"NNYY",
			"NNYN",
			"NNNY",
			"NNNN"
		};
		
		for(int i=0;i<=15;i++) {
			if(answer.equals(c[i]))
				return i+1;
			
		}
		return 0;
		
		
		
	}

}
