package com.mycompany.phonenumbertowordsfinder;

import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author Kashif Beckford
 */
public class PhoneNumberToWordsFinder {
    int noofChar;
    List<String> words;
    
    public List<String> findWords(String phoneNumber) {
        System.out.println("I will find the words, I promise " + phoneNumber);
        noofChar = phoneNumber.length();
        words = new ArrayList<>();
        permutate("", phoneNumber);
        
        return words;
    }
    
    public String findPhoneNumber(String phoneWord) {
        String[] letters = phoneWord.split("");
        String phoneNumber = "";
        for (String letter: letters) {
            if ("ABC".contains(letter)) phoneNumber += "2";
            else if ("DEF".contains(letter)) phoneNumber += "3";
            else if ("GHI".contains(letter)) phoneNumber += "4";
            else if ("JKL".contains(letter)) phoneNumber += "5";
            else if ("MNO".contains(letter)) phoneNumber += "6";
            else if ("PQRS".contains(letter)) phoneNumber += "7";
            else if ("TUV".contains(letter)) phoneNumber += "8";
            else if ("WXYZ".contains(letter)) phoneNumber += "9";
            else phoneNumber += letter;
        }
        
        return phoneNumber;
    }
    
    private void permutate(String prefix, String numStr) {
        if (prefix.length() == noofChar) {
            words.add(prefix);
        }
        if (numStr.equals("")) return;
        
        int n = Character.getNumericValue(numStr.charAt(0));
        String[] letters = getLettersFromNumber(n);
        numStr = numStr.substring(1);
        for (String letter: letters) {
            permutate(prefix + letter, numStr);
        }
    }
    
    private String[] getLettersFromNumber(int n) {
        String[] num2strMap = {
            "000",  // 0
            "111",  // 1
            "ABC",  // 2
            "DEF",  // 3
            "GHI",  // 4
            "JKL",  // 5
            "MNO",  // 6
            "PQRS", // 7
            "TUV",  // 8
            "WXYZ", // 9
        }; 
        String[] letters = num2strMap[n].split("");
        return letters;
    }
}
