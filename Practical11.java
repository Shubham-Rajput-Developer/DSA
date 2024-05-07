/*
Assume we have two input and two output tapes to perform the sorting. 
The internal Memory can hold and sort m records at a time.
Write a program in java for external sorting. 
Find out time complexity
*/
import java.io.*;
import java.util.Collections;
import java.util.ArrayList;

public class Practical11
{
	public static void main(String args[])
	{
		String inputFile = "number.txt";
		String outputFile = "sorted_Number.txt";
		
		ArrayList<Integer> numbers = readNumberFromFile(inputFile);
		
		if(numbers != null)
		{
			Collections.sort(numbers);
			if(writeNumberToFile(outputFile,numbers))
			{
				System.out.println("Sorted numbers written to "+outputFile);
			}
			else
			{
				System.out.println("Failed to write sorted numbers to file.");
			}
		}
		else
		{
			System.out.println("Failed to read number form file.");
		}
	}
	
	private static ArrayList<Integer> readNumberFromFile(String FileName)
	{
		ArrayList<Integer> numbers = new ArrayList<>();
		try(BufferedReader br = new BufferedReader(new FileReader(FileName)))
		{
			String line;
			while((line = br.readLine()) != null)
			{
				try{
					int number = Integer.parseInt(line);
					numbers.add(number);
				}
				catch(NumberFormatException e)
				{
					System.out.println("Invalid number found : "+line);
				}
			}
		}
		catch(IOException e)
		{
			System.out.println("Error Message : "+e.getMessage());
			return null;
		}
		return numbers;
	}
	
	private static boolean writeNumberToFile(String FileName,ArrayList<Integer> numbers)
	{
		try(BufferedWriter bw = new BufferedWriter(new FileWriter(FileName))){
				for(int number : numbers)
				{
					bw.write(Integer.toString(number));
					bw.newLine();
				}
		}
		catch(IOException e)
		{
			System.out.println("Error writing to file : "+e.getMessage());
			return false;
		}
		return true;
	}
}