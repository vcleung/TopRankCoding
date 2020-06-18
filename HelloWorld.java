import java.util.Scanner;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;
import java.util.function.Function;
import java.util.stream.*;
import java.util.stream.Collectors;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;




public class HelloWorld {
	static boolean isPrime(int n, int i)
	{
		if (n > 2)
		{
			if (n % i == 0) return false;
			if ( i * i > n) return true;
			return isPrime(n, i+1);
		}
		else
		{
			return (n == 2);
		}
	};
	
	public static int fib(int n)
	{
		return (n < 2 ? n : fib(n - 1) + fib(n - 2));
	}

	private static int reverse(int number){
        int reverse = 0;
      
        while(number != 0){
          reverse = reverse*10 + number%10; 
          number = number/10;
        }
              
        return reverse;
    }

//Read more: https://javarevisited.blogspot.com/2012/12/how-to-check-if-number-is-palindrome-or-not-example.html#ixzz6J8B98wyv
	// Read more: https://www.java67.com/2019/03/nth-fibonacci-number-in-java-coding.html#ixzz6J89EB3Qy

	public static Boolean isPalin(String original)
	{
		String reverse = new StringBuilder(original).reverse().toString();		
		return original.equals(reverse);
	}
	
	public static Boolean isAnagram(String ss, String mss)
	{
		char cA1[] = ss.toCharArray();
		char cA2[] = mss.toCharArray();
		Arrays.sort(cA1);
		Arrays.sort(cA2);
		return (Arrays.equals(cA1, cA2));
		
	}
	
	public static Boolean isAnagram2(String ss, String mss)
	{
		String ssSorted = Stream.of(ss.split("")).sorted().collect(Collectors.joining());
		String mssSorted = Stream.of(mss.split("")).sorted().collect(Collectors.joining());
		return ssSorted.equals(mssSorted);		
	}
	
	
    public static void main(String[] args){
        int i = 010;
        int j = 07;
        System.out.println(i);
        System.out.println(j);
        
        String str = "automation 123";
        StringBuilder strB = new StringBuilder();
        strB.append(str);
        strB = strB.reverse();
        System.out.println(strB);
        int length = str.length();
        char cA[] = str.toCharArray();
        String token[] = str.split("");
        String words[] = str.split(" ");

        Stream <String> streamOfWords = Arrays.stream(words);

        streamOfWords.forEach(w -> {

            System.out.println("Original word: " + w);

            Function <String,String> reverse = s -> new StringBuilder(s).reverse().toString();

            String reversedWord = reverse.apply(w);

            System.out.println("Reversed word: " + reversedWord + "\n");
        });
        
        String words2[] = str.split(" ");
        
        StringBuilder sb2 = new StringBuilder();
 
        Stream <String> stream = Arrays.stream(words2);
 
        stream.forEach(w -> {
 
            Function <String,String> reverse = s -> new StringBuilder(s).reverse().toString();
 
            String reversedWord = reverse.apply(w);
 
            sb2.append(reversedWord + " ");
        });
        System.out.println(sb2.toString());

       // for (int k = length -1; k >= 0; --k)
       // 	System.out.print(token[k]); // str.charAt(k));
        
        int x, y, temp;
       /* System.out.println("Enter x N y");
        Scanner in = new Scanner(System.in);
        x = in.nextInt();
        y = in.nextInt();
        temp = x;
        x = y;
        y = temp;
        
        x = x + y;
        y = x - y;
        x = x - y;
        System.out.println("" + x + " " + y); */
        
        String str2 = "This this is is done by Saket Saket";
		String[] split = str2.split(" ");
		HashMap<String,Integer> map = new HashMap<String,Integer>();
		for (int k=0; k<split.length; k++) {
			if (map.containsKey(split[k])) {
				int count = map.get(split[k]);
				map.put(split[k], count+1);
			}
			else {
				map.put(split[k], 1);
			}
		}
		System.out.println(map);
		
		Iterator itr = map.entrySet().iterator();
		while(itr.hasNext()) {
			Map.Entry me = (Map.Entry) itr.next();
			System.out.println("Key is " + me.getKey() + " Value is " + me.getValue());
		}
		System.out.println("For Loop:");
		for(Map.Entry me2: map.entrySet()) {
			System.out.println("Key is: " + me2.getKey() + " Value is: " + me2.getValue());
		}

		
		/* boolean isPrime = true; 
		Scanner in3 = new Scanner(System.in);
		int num2 = in3.nextInt();
		in3.close();
		/* for (int m = 2; m<= num/2; m++) {
			temp = num%m;
			if (temp == 0) {
				isPrime = false;
				break;
			}
		} 
		if(isPrime(num2, 2)) 
			System.out.println(num2 + "number is prime");
			else 
				System.out.println(num2 + "number is not a prime");
    	
    String original, reverse = "";
    
    System.out.println("Test pallen ");
    Scanner in2 = new Scanner(System.in);
    original = in2.nextLine();
	length = original.length();
	in2.close();
	
	for (int n =length -1; n>=0; n--) {
		reverse = reverse + original.charAt(n);
	} 
	StringBuffer sb0 = new StringBuffer();
	sb0.append(original);
	reverse = sb0.reverse().toString();
	System.out.println("reverse is:" +reverse);
	
	if(original.equals(reverse)) 
		System.out.println("The number is palindrome");
	else
		System.out.println("The number is not a palindrome");
	*/
	int num, a = 0,b=0, c =1;
	Scanner in = new Scanner(System.in);
	System.out.println("Enter the number of times");
	num = in.nextInt();
	System.out.println("Fibonacci Series of the number is:");
	for (int p=0; p<=num; p++) {
		a = b;
		b = c;
		c = a+b;
		System.out.println(a + "");    //if you want to print on the same line, use print()
	}
	
	ArrayList list = new ArrayList();
	list.add("20");
	list.add("30");
	list.add("40");
	System.out.println("List size " + list.size());
	System.out.println("While Loop:");
	Iterator itr2 = list.iterator();
	while(itr2.hasNext()) {
		System.out.println(itr2.next());
	}
	System.out.println("Advanced For Loop:");
	for(Object obj : list) {
		System.out.println(obj);
}
	System.out.println("For Loop:");
	for(int q=0; q<list.size(); q++) {
		System.out.println(list.get(q));
	}
	System.out.println("STREAM printing list");
	list.stream().forEach(obj->{System.out.println(obj);});
	
	String str3 = new String("Sakkett");
    int count = 0;
    char[] chars = str3.toCharArray();
    ArrayList<Character> cList = new ArrayList<Character>();
    for(char cc : chars) cList.add(cc);
    Set<Character> cSet = new HashSet<>();
    Set<Character> dSet = new HashSet<>();
    dSet = cList.stream().filter(obj->!cSet.add(obj)).collect(Collectors.toSet());
    System.out.println(dSet);
    System.out.println("Duplicate characters are:");
    for (int s=0; s<str3.length();s++) {
                for(int t=s+1; t<str3.length();t++) {
                           if (chars[s] == chars[t]) {
                                      System.out.println(chars[t]);
                                      count++;
                                      break;
                            }
                 }
     }
    // checking size using lambda
    List<Integer> listWithDuplicates = Arrays.asList(1, 2, 3);
    int siz1 = listWithDuplicates.size();
    int siz2 =  listWithDuplicates.stream().distinct().collect(Collectors.toList()).size();
    System.out.println("Arrays with no duplicates: " + (siz1 == siz2));

    // number of substrings that are palindrome
    String s1 = "cababd";
    int countS = 0;
    
  //  Set<String> setS = new HashSet<String>();

    	for(int i1 = 0; i1 < s1.length(); i1++)
    	{
    		String sub = s1.substring(i1);
    		int subLen = sub.length();
    		for(int j1 = 0; j1 < subLen; j1++)
    		{
    		String subS = sub.substring(0, subLen - j1);
    		if (isPalin(subS))
    			{
    			System.out.println("PALIN " + subS);
    			++countS;
    			}
    		}
    	}
    	System.out.println("# of palin substrings " + countS);
    
    	String sList[] = {"am", "ma", "spy", "pys", "ysp"};
    	String sentence = "I am a spy";
    	ArrayList<String> sList5 = new ArrayList<String>();
    	for (String s : sList)
    	{
    		String sSorted = Arrays.stream(s.split("")).sorted().collect(Collectors.joining());
    		sList5.add(sSorted);
    	}
    	Map<String, Long> anagramMap5 = 
    			sList5.stream().collect(Collectors.groupingBy(Function.identity(), Collectors.counting()));
    	HashMap<String, Integer> anagramMap = new  HashMap<String, Integer>();
    	for (String ss : sList)
    	{
    		Boolean isnew = true;
    		for (String mss : anagramMap.keySet())
    		{
    			if (isAnagram2(ss, mss))
    			{
    				anagramMap.put(mss, anagramMap.get(mss) + 1);
    				isnew = false;
    				break;
    			}
    		}
    		if (isnew) anagramMap.put(ss, 1);
    	}
    	String sList2[] = new String[sList.length];
    	int ij = 0;
    	for (String s2 : sList)    		
    	{
    		char cA3[] = s2.toCharArray();
    		Arrays.sort(cA3);
    		sList2[ij++] = new String(cA3);
    	}
    	ArrayList<String> sList3 = new ArrayList<String>();
    	
    	for (String s2 : sList)
    	{
    		char cA3[] = s2.toCharArray();
    		Arrays.sort(cA3);
    		sList3.add(new String(cA3));
    	}
    	ArrayList<String> sList4 = new ArrayList<String>();
    	for (String s2 : sList)
    	{
    		String s2sorted = Stream.of(s2.split("")).sorted().collect(Collectors.joining());
    		sList4.add(s2sorted);
    	}
    	Map<String, Long> anagramMap2 =
    			Stream.of(sList2).collect(Collectors.groupingBy(Function.identity(), Collectors.counting()));
    	Map<String, Long> anagramMap3 =
    			sList3.stream().collect(Collectors.groupingBy(Function.identity(), Collectors.counting()));
    	Map<String, Long> anagramMap4 =
    			sList4.stream().collect(Collectors.groupingBy(Function.identity(), Collectors.counting()));

    	String sentenceA[] = sentence.split(" ");
    	long totalCounts = 1;
    	for (String senS : sentenceA)
    	{
    		String senSorted = Arrays.stream(senS.split("")).sorted().collect(Collectors.joining());
    		Long multiplier = anagramMap4.get(senSorted);
    		totalCounts *= (multiplier == null) ? 1L : multiplier;
    	}
    	System.out.println("Total number of anagram sentences " + totalCounts);
    	
    	
    	
    
    int arr[] = { 100,14, 46, 47, 94, 94, 52, 86, 36, 94, 89 };
    int largest = 0;
    int secondLargest = 0;
    System.out.println("The given array is:");
    for (int u = 0; u < arr.length; u++)
    {
        System.out.print(arr[u] + "\t");
    }
    for (int v = 0; v < arr.length; v++)
    {
        if (arr[v] > largest)
        {
            secondLargest = largest;
            largest = arr[v];
        }
        else if (arr[v] > secondLargest)
        {
            secondLargest = arr[v];
        }
    }
    System.out.println("\nSecond largest number is:" + secondLargest);
    System.out.println("Largest Number is: "  +largest);
    ArrayList<Integer> iList2 = new ArrayList<Integer>();
    
    for (int ii : arr) iList2.add(ii);
    iList2.stream().sorted(Comparator.reverseOrder()).limit(2).forEach(obj->{System.out.println(obj + "");});
    Arrays.stream(arr).boxed().sorted(Comparator.reverseOrder()).limit(2).forEach(obj->{System.out.println(obj+ "");;});
    List<Integer> iList3 = 
    		Arrays.stream(arr).boxed().sorted(Comparator.reverseOrder()).limit(2).collect(Collectors.toList());
    System.out.println("List 3 " + iList3);
    ArrayList<Integer> aList3 = 
    		Arrays.stream(arr).boxed().sorted(Comparator.reverseOrder()).limit(2).collect(Collectors.toCollection(ArrayList::new));

    int cc=0,aa,temp2;  
    int n=153;//It is the number to check Armstrong  
    temp2=n;  
    while(n>0)  
    {  
    aa=n%10;  
    n=n/10;  
     cc=cc+(aa*aa*aa);  
     }  
     if(temp2==cc)  
     System.out.println("armstrong number");   
     else  
         System.out.println("Not armstrong number"); 
     
     String str1 = "Saket Saurav        is a QualityAna    list";
     
     //1. Using replaceAll() Method

     String str4 = str1.replaceAll("\\s", "");

     System.out.println(str4);
     
     char[] chars2 = str1.toCharArray();
     
     StringBuffer sb = new StringBuffer();

     for (int w = 0; w < chars2.length; w++)
     {
         if( (chars2[w] != ' ') && (chars2[w] != '\t') )
         {
             sb.append(chars2[w]);
         }
     } 
     System.out.println(sb);           //Output : CoreJavajspservletsjdbcstrutshibernatespring
     // ArrayList<Character> cA2 = new ArrayList<Character>();
     
     // for (char c3 : chars2) cA2.add(c3);
     List<Character> cA2 = str1.chars().mapToObj(ii -> (char)(ii)).collect(Collectors.toList());
     cA2.stream().filter(xx-> xx != ' ').forEach(System.out::print);
     
     // # of sockets
     int socksN = 4;
     int socksA[] = {1, 2, 3, 4, 1, 2, 3, 4, 1, 1};
     HashMap<Integer, Integer> sMap = new HashMap<Integer, Integer>();
     for (int s : socksA)
     {
    	 if (sMap.get(s) == null) sMap.put(s ,1);
    	 else sMap.put(s, sMap.get(s) + 1);
     }
     int pairs = 0;
     for (int ns : sMap.values())
    	 pairs += ns / 2;
    
     System.out.println("Number of pairs " + pairs);
     
     List<Integer> OddNumbers = Arrays.asList(1, 3, 5); 
     
     // Creating a list of Even Numbers 
     List<Integer> EvenNumbers = Arrays.asList(2, 4, 6, 8); 

     List<List<Integer>> listOfListofInts = 
             Arrays.asList(OddNumbers, EvenNumbers); 

     System.out.println("The Structure before " + listOfListofInts);
       
     // Using flatMap for transformating and flattening. 
     List<Integer> listofInts  = listOfListofInts.stream() 
                                 .flatMap(alist -> alist.stream()) 
                                 .collect(Collectors.toList()); 

     System.out.println("The Structure after flattening is : " + 
                                                      listofInts); 
     
     IntStream.range(1, 10).reduce((xx, yy) -> xx + yy).ifPresent(s -> System.out.println(s));
     IntStream.range(1, 10).reduce(Integer::max).ifPresent(s -> System.out.println(s));
     
     String[] charS = { "A", "B", "C", "A", "C", "A" };

     		Map<String, Long> freq = 
     					Stream.of(charS)
     					.collect(Collectors.groupingBy(Function.identity(), 
     											Collectors.counting()));
     		Map<String, Long> freqMap = 
     		        Arrays.asList(charS).stream().collect(Collectors.groupingBy(Function.identity(), Collectors.counting()));
     		System.out.println(freq);
     		
     		String input = "Hello";
     		String result = Stream.of(input.split(""))
     		                       .sorted((s3, s2) -> -1)
     		                       .collect(Collectors.joining());
     		System.out.println("Reverse " + result);
     		System.out.print("Hello,\nworld!");
     		System.out.println(10 + 20 + "Javatpoint");   
            System.out.println("Javatpoint" + 10 + 20);
            
            
     		
    }
    
    // Creating a list of Odd Numbers 
    
}
    

