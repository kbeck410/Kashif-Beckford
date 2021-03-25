package com.mycompany.phonenumbertowordsfinder;

import java.util.List;

/**
 *
 * @author Kashif Beckford
 */
public class SolutionWithRecursion {
    public static void main(String[] args) {
        System.out.println("--- Our Solution with Recursion ---");
        
        PhoneNumberToWordsFinder finder = new PhoneNumberToWordsFinder();
        String phoneNumber = "7382273";
        List<String> words = finder.findWords(phoneNumber);
        
        for (String word: words) {
            System.out.println("Word I found: " + word);
        }
        
        System.out.println("Let's find out the phone numbers now");
        String word = "1-800-PETCARE";
        phoneNumber = finder.findPhoneNumber(word);
        System.out.println(String.format("%s phone number is %s", word, 
                phoneNumber));
    }
}
