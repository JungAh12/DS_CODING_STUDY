import java.util.Scanner;

public class Q2869 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner sc= new Scanner(System.in);
		int A=sc.nextInt();
		int B=sc.nextInt();
		int V=sc.nextInt();
		
		int now=0;
		int result=1;
		
		while(true) {
			now+=A;
			if(now>=V) break;
			now=now-B;
			result++;
		}
    
		System.out.print(result);
		
	}

}
