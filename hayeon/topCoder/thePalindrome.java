package topcoder;

public class Cryptography {

	
	public static int b(String c) {
		
		String[] c1=c.split("");
		int center=c1.length/2;
		for(int i=center+1;i<c1.length;i++) {
			
			if(c1[i].equals(c1[center-(i-center)]) ) {
			}
			else {
				center=center+1;
				i=center;
			}
      
		}
		return center*2+1;
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		
		String case1 = "abab";
		
		System.out.println(b(case1));

	}

}
