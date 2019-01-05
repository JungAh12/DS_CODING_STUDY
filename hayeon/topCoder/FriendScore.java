package topcoder;

public class FriendScore {
	
	public static int highestScore(String[] friends) {
		
		int result=0;
		for(int i=0;i<friends.length;i++) {
			int cnt=0;
			for(int j=0;j<friends.length;j++) {
				
				if(i==j)
					continue;
				if(friends[i].charAt(j)=='Y') {
					cnt++;
				}
				else {
					for(int t=0;t<friends.length;t++) {
						if(friends[j].charAt(t)=='Y'&&friends[t].charAt(i)=='Y') {
							cnt++;
							break;
						}
					}
				}
				
			}
			result=Math.max(result, cnt);
		}
		
		
		
		return result;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub


		String[] friends={"NYNNN",
				"YNYNN",
				"NYNYN",
				"NNYNY",
				"NNNYN"};
		
		System.out.print(highestScore(friends));
		
		
		
	}

}
