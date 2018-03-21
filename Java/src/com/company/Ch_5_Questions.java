package com.company;

import java.util.*;

public class Ch_5_Questions {

    public static void main(String[] args) {
        // write your code here
       // Scanner in = new Scanner(System.in);

        //int n = in.nextInt();
        //test gen primes
        System.out.print( genPrimes(15));
       List<Integer> A = Arrays.asList(1,2);
       //testmultiply int
        List<Integer> B = Arrays.asList(-1,2);
        System.out.print(multiplyIntegers(A,B ));
        //test permuteArray
        List<Integer> Perm = Arrays.asList(3,2,1,0);
        List<Integer> Arr = Arrays.asList(1,2,3,4);
        permuteArray(Perm, Arr);
        System.out.print(Arr);
    }
    //5.9
    public static List<Integer> genPrimes(int n){
        //list of primes for result
        List<Integer> primes =  new ArrayList<>();
        //Initilize list of Booleans to represent prime numbers
        List<Boolean> isPrime =  new ArrayList<>(Collections.nCopies(n+1, true));

        //remove 1 and 2 from the list.
        isPrime.set(0, false);
        isPrime.set(1, false);

        for ( int i = 2; i <= n; ++i){
            //add prime number to primes
            if (isPrime.get(i)){
                primes.add(i);
                //sieve out all future multiples of that prime number
                for (int p = i; p <= n ; p += i){
                    isPrime.set(p, false);
                }
            }

        }


        return primes;
    }

    //5.3 Multiply 2 arbitrary precision integers.
    //funky functions used: collections.nCopies, Arraylist.subList
    public static List<Integer> multiplyIntegers(List<Integer> A, List<Integer> B){
        List<Integer> result =  new ArrayList<>(Collections.nCopies(A.size() + B.size(), 0));


       //compute the signage, where the first integer determines signage for the entire number.
       int sign = A.get(0) < 0 ^ B.get(0) < 0 ? -1 : 1;
        A.set(0, Math.abs(A.get(0)));
        B.set(0, Math.abs(B.get(0)));
       //Multiply every integer in the first array by every integer in the second, adding each sub-result
        //Increase the magnitude of values by ten as we move left.
        for(int i = A.size()-1; i >= 0 ; --i ){
            for(int j = B.size()-1; j>=0 ; --j){
                //
                result.set(i+j+1, result.get(i+j+1)+A.get(i)*B.get(j) );
                result.set(i+j, result.get(i+j) + result.get(i+j+1)/10);
                result.set(i+j+1, result.get(i+j+1)%10);
            }
        }
        //remove leading zeros.
        int numZeros = 0;
        while( numZeros < result.size() && result.get(numZeros) == 0){
            numZeros++;
        }
       result = result.subList(numZeros, result.size());
        //add signage
        result.set(0, result.get(0)*sign);
        return result;
    }
    //5.10 Permute an Array
    //funky functions: Collections.swap
    public static void permuteArray(List<Integer> perm, List<Integer>  arr){
        for(int i = 0; i < perm.size();++i){
            int next = i;
            while(perm.get(next)>0){
                int temp = perm.get(next);
                //perform swap on array
                Collections.swap(arr, i, perm.get(next));
                //previous entry is now in arr[i]
                perm.set(next, perm.get(next) - perm.size());
                next =  temp;
            }
        }

    }

    public static void swapPractice(int a, int b){

        
    }

}

