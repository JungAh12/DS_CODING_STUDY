package ch06;

import java.util.HashMap;
import java.util.Scanner;

public class interstingParty {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner sc = new Scanner(System.in);
		
		String[] first = new String[50];
		String[] second = new String[50];
		
		int i=0;
		String temp=null;
		
		while(true) { // first 배열 입력받기
			
		temp=sc.next();
		
		if(temp == null)
			break;
		
		first[i] =temp;
		i++;
		}

		i=0;
		
		while(true) { // second 배열 입력받기
			
			temp=sc.next();
			
			if(temp == null)
				break;
			
			second[i] =temp;
			i++;
			}
		
		System.out.println(match(first, second));
		
		
		}
	
	public static int match(String[] first, String[] second) {
		
		HashMap<String, Integer> dic = new HashMap<String,Integer>();
		
		for( int i=0;i<first.length; i++) {
			dic.put(first[i], 0);
			dic.put(second[i], 0);
		}
		
		for( int i=0; i<first.length; i++) {
			dic.put(first[i], dic.get(first[i]));
			dic.put(second[i], dic.get(second[i]));
			
		}
		
		int ans =0;
		for(String key: dic.keySet()) {
			ans = Math.max(ans, dic.get(key));
		}
			return ans;
	}

}
