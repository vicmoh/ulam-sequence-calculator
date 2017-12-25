//Name: Vicky Mohammad
//Student ID: 0895381
//Program finds the sequence of the n-th of the ulam term number
//plases note that i save all sequence value to the memory hence
//it might take a while when finding a high value index

//import libraries i might need
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <math.h>

int main(int argc, char ** argv){
    //declare variables that i may need
    int term = 3;
    int sum = 0;
    int currentIndex = 3;
    int index = 3;
    int numOfSum = 0;
    int x, y;
    int* indexValue = malloc(sizeof(int)*10);

    //assigned 4 of the ulam number to start on the index
    //you only need 2 at the start but i just thought it would be easier to debug
    indexValue[0] = 0;//this 0 will be unused to make counting easier for me to code 
    //which will perfectly represent an index
    indexValue[1] = 1;
    indexValue[2] = 2;
    indexValue[3] = 3;
    indexValue[4] = 4;

    //ask the user for the index
    printf("\nEnter the index of the Ulam:\n");
    scanf("%d",&index); 
    
    //keep looping to the next index until it meets the index of the ulam search
    while(currentIndex <= index){

        //loop to find how many sum are there
        for(x=0; x <= currentIndex; x++){
            //i get the first num of from the first loop and
            //then get the second number with the second loop
            //note that i use "0+x+1" to prevent and duplication of the sum of ulam number
            for(y=0+x+1; y <= currentIndex; y++){
                //basically, i check if the sum is equal to the term 
                sum = indexValue[x] + indexValue[y];
                if(sum == term){
                    //and then count how many sum is equal to the term through the loop
                    numOfSum++;
                }//end if
            }//end for loop
        }//end for loop
        
        //if there is only one sum, put it as a term of that index
        //because ulam number only have one sum out of the equation
        if(numOfSum == 1){
            //when there is only one sum out of the sequence
            //it means it is an ulam number, so i set it as the index of that position
            //and then add more memory so that i can store more sequences
            currentIndex++;
            indexValue[currentIndex] = term;
            indexValue = realloc(indexValue, sizeof(int)* 11 + term);
        }//end if
        //i already found an ulam number so i set numOfSum = 0
        //so i can scount how many sum for the next term of ulam number
        numOfSum = 0;
        term++;
        
    }//end while

    //print the term of the index and exit the program
    printf("The Ulam at index you entered is %d\n\n", indexValue[index]);
    return 0;
}//end main