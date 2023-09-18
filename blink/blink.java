// Welcome to USACO Silver 1


/* blink

http://www.usaco.org/index.php?page=viewproblem2&cpid=279

*/

import java.util.*;
import java.io.*;

public class blink {
    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(new File("blink.in"));
        int n = in.nextInt();
        long b = in.nextLong();
        
        int[] bulbs = new int[n];
        for (int i = 0; i < n; i++) bulbs[i] = in.nextInt();
        in.close();
    
        long t = 0;
        Map<String,Long> prevStates = new HashMap<>();
        // key: String representing a previous state
        // value: time that state previously occurred
        
        while (t < b) {
            String state = Arrays.toString(bulbs);
            
            if (prevStates.containsKey(state)) {
                long prevT = prevStates.get(state);
                
                long cycleLen = t - prevT;
                long remaining = b - t;
                long cycles = remaining / cycleLen;
                
                t += cycles * cycleLen;
                
                // {1,1,0,0,0}    prevT=1      <-- map 
                
                // bulbs = 1,1,0,0,0
                
                // t = 15 trill 16
                // b = 15 trill 21
                
                // PREVENT THE IF STATEMENT FROM TRIGGERING AGAIN
                prevStates.clear();
            }
            else {
                prevStates.put(state, t);
                
                step(bulbs);
                t++;
            }
        }
    
    
    
        PrintWriter out = new PrintWriter(new File("blink.out"));
        for (int i = 0; i < n; i++) {
            int result = bulbs[i];
            System.out.println(result);
            out.println(result);
        }
        out.close();
    }
    
    
    static void step(int[] bulbs) {
        int lastBulb = bulbs[bulbs.length-1];
        
        
        for (int i = bulbs.length-1; i > 0; i--) {
            if (bulbs[i-1] == 1) bulbs[i] = 1-bulbs[i];
        }
        
        if (lastBulb == 1) bulbs[0] = (bulbs[0] + 1) % 2;
        
        // other toggling tricks
        //    bulb = Math.abs(bulb-1);
        //    bulb = bulb ^ 1;           // bitwise xor = exclusive or
        
        //    bulb = bulb == 1 ?    0   :    1    ;
        //           condition   iftrue  iffalse
        //     ternary operator (3-part operation)
        
        
        
        //   (a,b) -> a.value - b.value
    }
    
    
}




/* ANALYSIS

Time T=0: 1 0 0 0 0
Time T=1: 1 1 0 0 0
Time T=2: 1 0 1 0 0
Time T=3: 1 1 1 1 0
Time T=4: 1 0 0 0 1
Time T=5: 0 1 0 0 1
Time T=6: 1 1 1 0 1

...

Time T=16: 1 1 0 0 0        same as T=1, cycle length = 15

...


Time T=15 trillion 16: 1 1 0 0 0
                     : 1 0 1 0 0
     T=15 trillion 18: 1 1 1 1 0


    HashSet would let you see "this element/previous state has occurred before"
        (without any additional information)
        
        "{1,0,1,0,0}"
        "{1,0,0,0,0}"
        "{1,1,0,0,0}"
        
        
    HashMap could link a previous bulb state to the previous time
    
        ...
        "{1,0,1,0,0}" => 2
        "{1,0,0,0,0}" => 0
        "{1,1,0,0,0}" => 1
        ...


N <= 16

2^16 = 65,536





int => 32 bit => 2^(32-1)-1 max ~= 2^31 ~= 2 billion max

long => 64 bit => 2^(64-1)-1 max ~= 9 quintillion ~= 9x10^18


*/

