package topcoder;

public class Cryptography {

	
	public static int b(int[] nums) {
	
		int res=0;
		int tmp=1;
		for(int i=0;i<nums.length;i++) {
			
			nums[i]=nums[i]+1;
			tmp=1;
			for(int j=0;j<nums.length;j++) {
				tmp=tmp*nums[j];
				
			}
			
			res=Math.max(tmp, res);
			
			nums[i]=nums[i]-1;
		}
		return res;
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		
		int[] aa= {1,2,3};
	
		System.out.print(b(aa));
		

	}

}
