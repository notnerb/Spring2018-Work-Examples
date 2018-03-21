package com.company;
import java.io.Console;
import java.util.Scanner;

import static com.company.Ch_5_Questions.*;

public class Ch_6_Questions {

    public static void main(String []args){
        System.out.print("Please Enter your Integer for interconversion log flume");
        Scanner scanner = new Scanner(System.in);


        String str = scanner.nextLine();

        Integer A = Integer.parseInt(str);
        System.out.print(intToString(A) + "\n");
        System.out.print(stringToInt(str));
        System.out.print(intToString(A) + "\n");
        char [] charA = {'a','c','d','b','b','c','a'};
        charA = replaceARemove(7,charA);
        System.out.print(charA.toString() + "\n");
        System.out.print(charA);
        System.out.print("\n");
        char [] sent = {'M','a','r','y',' ','a','n','d',' ','B','o','b'};
        System.out.print(sent);
        System.out.print("\n");
       sent =  reverseWords(sent);
        System.out.print(sent);
        System.out.print("\n");
    }
    //6.1: Math.abs, StringBuilder.append; .reverse; .toString
    public static String intToString(Integer A){

        boolean isNeg = false;
        if(A < 0){
            isNeg = true;
        }

        StringBuilder result =  new StringBuilder();
        Integer lsd;

        while(A != 0){
            lsd = A%10;
            result.append((char)('0' + Math.abs(lsd)));
            A /= 10;
        }
        if(isNeg){
            result.append('-');
        }

        result.reverse();
        return result.toString();

    }

    public static Integer stringToInt(String A){
        //Start at A[0] or A[1] depending on if the String represents a negative Integer.
        int result = 0;
        for(int i =  A.charAt(0) == '-' ? 1:0; i < A.length(); ++i){
            //A final int is:
            final int digit = ( A.charAt(i) - '0');

            result = result*10 + digit;
        }
        return result*(A.charAt(0)== '-'? -1:1);

    }
    //6.4 offset indexes
    public static char[] replaceARemove(int size, char[] A){
        int writer = 0;
        int countA = 0;
        //remove B's first.
        for(int i = 0; i< size; ++i){
            if(A[i] != 'b'){
                A[writer++] = A[i];
            }
            if(A[i] == 'a'){
                countA++;
            }
        }
        //the new write head should be position at writer + countA
        int revWriter = writer + countA - 1;
        int finalsize = revWriter + 1;
        for(writer -= 1; writer >= 0; --writer){
            if(A[writer] == 'a'){
                A[revWriter--] = 'd';
                A[revWriter--] = 'd';
            }
            else{
                A[revWriter--] = A[writer];
            }
        }
        return A;
    }

    public static char[] reverseWords(char[] w){
        //start and end points for individual words.
        int wStart = 0;
        int wEnd = 0;
        int size = w.length - 1;
        //first reverse w.
        reverse(w, 0, size);
        //System.out.print(w);
        System.out.print("\n");
        //then reverse each word as delineated by whitespace.
        while(wStart < size){
            //bring wStart up to wEnd and past the white space, to the next word
            while(wStart < wEnd || wStart < size && w[wStart] == ' '){
                wStart++;
            }
            while (wEnd < wStart || wEnd <= size && w[wEnd] != ' ') {
                wEnd++;
            }
            reverse(w, wStart,wEnd - 1 );
        }
        return w;

    }
    //simple reverse method.
    public static void reverse(char[] g, int start, int end){
        while(start <= end){
            char tmp = g[start];
            g[start] = g[end];
            g[end] = tmp;
            start++;
            end--;
        }

    }


}

