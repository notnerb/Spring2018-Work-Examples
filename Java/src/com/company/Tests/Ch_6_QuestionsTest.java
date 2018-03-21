package com.company.Tests;

import com.company.Ch_6_Questions;

import static org.junit.jupiter.api.Assertions.*;

class Ch_6_QuestionsTest {
    @org.junit.jupiter.api.Test
    void intToString() {
        int testInt = 16;
        assertEquals("16", Ch_6_Questions.intToString(testInt), "16 must be converted to Type String");
    }

    @org.junit.jupiter.api.Test
    void stringToInt() {
        String test = "-2018";
        Integer i = -2018;
        assertEquals(i, Ch_6_Questions.stringToInt(test), "-2018 must be converted to type Int");
    }

    @org.junit.jupiter.api.Test
    void replaceARemove() {
        char [] test = {'a','c','d','b','b','c','a'};
        char [] output = {'d','d','c','d','c','d','d'};
        assertArrayEquals(output, Ch_6_Questions.replaceARemove(7, test), "a's should be replaced with w d's and b's should be removed");

    }

    @org.junit.jupiter.api.Test
    void reverseWords() {
        char []  test = {'M','a','r','y',' ','a','n','d',' ','B','o','b'};
        char [] output = {'B','o','b',' ','a','n','d',' ','M','a','r','y'};

        assertArrayEquals(output, Ch_6_Questions.reverseWords(test), "output char array should contain words of input in reverse order");
    }


}