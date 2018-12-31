package topcoder;

public class InterestingDigits {
	
	public static void b(int c) {
		c=c-1;
		for(int i=2;i<=c;i++) {
		
      if((c%i)==0) {
				System.out.print(i+" ");
		  }
		
    }	
    
    
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		int case1 = 10;
		b(case1);
	}
}
