import java.util.HashMap;
public class InterestingParty {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		
		String[] first= {"fishing", "gardening", "swimming", "fishing"};
		String[] second= {"hunting", "fishing", "fishing", "biting"};
		
		int result = bestInvitation(first, second);
		
		System.out.println(result);
		
	}

	public static int bestInvitation(String[] first, String[] second) {
		String[] tmp= new String[first.length+second.length];
		System.arraycopy(first, 0, tmp, 0, first.length);
		System.arraycopy(second, 0, tmp, first.length, second.length);
		int result=0;
		
		
		
		HashMap<String, Integer>tp = new HashMap<String, Integer>();
		
		for(String t: tmp) {
			if(!tp.containsKey(t))
				tp.put(t, 1);
			else
				tp.put(t,tp.get(t)+1);
		}
		
		for(String t: tp.keySet()) {
			if(tp.get(t)>result)
				result=tp.get(t);
		}
		
		return result;
	}
	
}
