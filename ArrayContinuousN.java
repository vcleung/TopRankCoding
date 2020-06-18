// Java program to find longest subarray with 
// k or less distinct elements. 
import java.util.*;
import java.util.stream.Collectors;



class ArrayContinuousN
{ 

// function to print the longest sub-array 


static void longest2(int a[], int n, int k) 
{ 
	int start = 0, end = k; 
	int maxL = end - start;
	List<Integer> iL = Arrays.stream(a).boxed().collect(Collectors.toList());
	// System.out.println("List Comparison " + iL.equals(iL2));
	for (int i = k; i <= n; i++) 
	{ 
		end = i;
		List<Integer> intL = iL.subList(start, end);
		Set<Integer> setI = new HashSet<>(intL);
		if (setI.size() <= k) 
		{
			if (maxL < (end - start)) maxL = end - start;
			continue;
		}
		else
		{
			while(setI.size() > k)
			{
				start++;
				intL = iL.subList(start, end);
				setI = new HashSet<>(intL);
			}
		}
		
	}										
	System.out.println("MAX " + maxL); 
}

static void shortest(String s) 
{ 
	int start = 0, end;
	int n = s.length();
	
	// Character[] cA = new Character[n];
	// for (int k = 0; k < n; ++k) cA[k] = s.toCharArray()[k];
	// List<Character> l1 = Arrays.asList(cA);
	
	List<Character> l1 = s.chars().mapToObj(i -> (char)i).collect(Collectors.toList());    
	Set<Character> setC = new HashSet<>(l1);
	
// List<Character> ll1 = Arrays.asList(s.toCharArray()).stream().boxed().collect(Collectors.toList());
	
	int sN = setC.size();
	int minL = n;
	
	for (int i = sN; i <= n; i++) 
	{ 
		end = i;
		List<Character> intL = l1.subList(start, end);
		Set<Character> setI = new HashSet<>(intL);
		if (setI.size() < sN) 
		{
			continue;
		}
		else
		{
			
			while(setI.size() >= sN )
			{
				if (minL > (end - start)) minL = end - start;
				start++;
				intL = l1.subList(start, end);				
				setI = new HashSet<>(intL);				
			}
		}
		
	}										
	System.out.println("MIN " + minL); 
}


// using System;
// using System.Collections.Generic;
static int substringcalculator()
{

String s = "kincenvizh";
Set<String> setS = new HashSet<String>();

	for(int i = 0; i < s.length(); i++)
	{
		String sub = s.substring(i);
		int subLen = sub.length();
		for(int j = 0; j < subLen; j++)
		{
		String subS = sub.substring(0, subLen - j);
		setS.add(subS);
		}
	}
System.out.println(setS.size());
return setS.size();
}
// Driver code 
public static void main(String args[]) 
{ 
	// int a[] = { 6, 5, 1, 2, 3, 2, 2, 2, 3, 1, 4, 5 }; 
	int a[] = {6, 5, 1, 2, 3, 2, 1, 4, 5};
    
	int n = a.length; 
	int k = 3; 
	longest2(a, n, k);
	shortest("aabbccd");
	substringcalculator();
} 
} 

// This code is contributed by 
// Surendra_Gangwar 
