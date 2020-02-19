//
//  main.cpp
//  Homework5_Project
//
//  Created by Allen Liu on 11/7/18.
//  Copyright © 2018 Vincent Liu. All rights reserved.
//

#include <iostream>
#include <cassert>
#include <cstring>

using namespace std;

const int MAX_WORD_LENGTH = 20;

int absoluteDiffer(int a, int b){
    if (a>=b)
        return a-b;
    else
        return b-a;
}

int makeProper(char word1[][MAX_WORD_LENGTH+1],
               char word2[][MAX_WORD_LENGTH+1],
               int separation[],
               int nPatterns){

    bool isValid = true;
    if (nPatterns < 0)
        nPatterns = 0;
    int count = nPatterns;
    int j = 0;

    //#1    A word in the pattern contains no characters, or contains a character that is not a letter.
    //exclude pattern contains no characters.
    
    while (j != count)
    {
        if (word1[j][0] == '\0' || word2[j][0] == '\0' || separation[j]<0)
            isValid = false;
        
        for (int i=0; i < MAX_WORD_LENGTH; i++){    //possible problem,
            if((!isalpha(word1[j][i]) && word1[j][i]!='\0') || (!isalpha(word2[j][i])&& word2[j][i]!='\0'))
                isValid = false;
            else{
                word1[j][i] = tolower(word1[j][i]);
                word2[j][i] = tolower(word2[j][i]);}
        }
        
        if (!isValid){
            for(int v=j; v<count-1; v++){
                strcpy(word1[v], word1[v+1]);
                strcpy(word2[v], word2[v+1]);
                separation[v] = separation[v+1];
            }
            count --;
        }
        if(isValid)
            j++;
    
        isValid = true;
    }
    
    
    
    int u = 0;
    while (u != count){
        for(int i=0; i<count; i++){
            if((strcmp(word1[u],word2[i]) == 0 && strcmp(word1[i], word2[u]) == 0) || (strcmp(word1[u],word1[i]) == 0 && strcmp(word2[u], word2[i]) == 0 && u!=i)){
                isValid = false;
                if (separation[u] > separation[i])
                    separation[i] = separation[u];
                for(int v=u; v<count-1; v++){
                    strcpy(word1[v], word1[v+1]);
                    strcpy(word2[v], word2[v+1]);
                    separation[v] = separation[v+1];
                }
                count--;
            }
        }
        if(isValid)
            u++;
        isValid = true;
    }
    
    return count;
}


int rate(const char document[],
         const char word1[][MAX_WORD_LENGTH+1],
         const char word2[][MAX_WORD_LENGTH+1],
         const int separation[],
         int nPatterns)
{
    int score = 0;
    if (nPatterns < 0)
        nPatterns = 0;
    const int MAX_WORD_LENGTH2 = 250;
    char document2[MAX_WORD_LENGTH2]={};
    
    long LENGTH = strlen(document); //61
    int i = 0;  //number of document elements
    int j = 0;  //number of document2 elements
    while(i<LENGTH){
        if (isalpha(document[i]) || (document[i] == ' ' && isalpha(document[i+1]))){
            document2[j] = tolower(document[i]);
            j++;}
        i++;
    }
    if (document2[0] == ' '){
        for(int k=0;k<j;k++)
            document2[k]=document2[k+1];}
    //this part translate document into proper syntax, with only one space seperating each word
    
    char word[200][MAX_WORD_LENGTH] = {};
    int number = 0;
    int k = 0;
    for(int i=0; i<LENGTH;i++){
        if(document2[i] != ' ')
            word[number][i-k] = document2[i];
        if (document2[i] == ' '){
            k = i+1;
            number++;
        }
    }
    //This part translate document2 into an array of words
    //number+1 is the amount of elements in word array.
    
    bool signal = false;
    
    int p=0;
    while(p<nPatterns){

        for(int z=0; z<number+1;z++){
            if (strcmp(word1[p], word[z])==0){
                for(int y=0; y<number+1;y++){
                    if(strcmp(word2[p], word[y])==0 && absoluteDiffer(z, y)-1 <= separation[p]){
                        score++;
                        signal = true;
                        break;
                    }
                }
            }
            if (signal == true){
                signal = false;
                break;}
        }
        p++;
    }
    
    
    return score;
}


int main()
{
//    cerr << "start:"<<endl;
//    const int TEST1_NRULES = 4;
//    char test1w1[TEST1_NRULES][MAX_WORD_LENGTH+1] = {
//        "mad",       "deranged", "nefarious", "have"
//    };
//    char test1w2[TEST1_NRULES][MAX_WORD_LENGTH+1] = {
//        "scientist", "robot",    "plot",      "mad"
//    };
//    int test1dist[TEST1_NRULES] = {
//        1,           3,          0,           12
//    };
//
//    const int TEST2_NRULES = 8;
//    char test2w1[TEST2_NRULES][MAX_WORD_LENGTH+1] = {"mad","deranged","NEFARIOUS","half-witted","robot","plot","have","NeFarious"};
//    char test2w2[TEST2_NRULES][MAX_WORD_LENGTH+1] = {"scientist","robot","PLOT","assistant","deranged","Nefarious","mad","pLoT"};
//    int test2dist[TEST2_NRULES] = {1,3,0,2,1,0,12,0};
//
////    int NewLength1 = makeProper(test1w1, test1w2, test1dist, TEST1_NRULES);
//    int NewLength2 = makeProper(test2w1, test2w2, test2dist, TEST2_NRULES);
//
//    for(int i = 0; i < NewLength2; i++)
//        cerr<<NewLength2<<test2w1[i]<<" "<<test2w2[i]<<" "<<test2dist[i]<<endl;
//
//    int score1 = rate(" The mad have mad UCLA scientist unleashed123 a deranged  robot evil giant @@. nefarious plot",
//                    test2w1, test2w2, test2dist, TEST1_NRULES);
//    cerr<<score1<<endl;
//
//
////    test1
////    The mad UCLA scientist unleashed123 a deranged    evil giant @@ robot.
//
//    assert(rate("The mad UCLA scientist unleashed a deranged evil giant robot.",
//                test1w1, test1w2, test1dist, TEST1_NRULES) == 2);
//    assert(rate("The mad UCLA scientist unleashed    a deranged robot.",
//                test1w1, test1w2, test1dist, TEST1_NRULES) == 2);
//    assert(rate("**** 2018 ****",
//                test1w1, test1w2, test1dist, TEST1_NRULES) == 0);
//    assert(rate("  That plot: NEFARIOUS!",
//                test1w1, test1w2, test1dist, TEST1_NRULES) == 1);
//    assert(rate("deranged deranged robot deranged robot robot",
//                test1w1, test1w2, test1dist, TEST1_NRULES) == 1);
//    assert(rate("That scientist said two mad scientists suffer from deranged-robot fever.",
//                test1w1, test1w2, test1dist, TEST1_NRULES) == 0);
//    cout << "All tests succeeded" << endl;

    //test case
//
//    //1. an already proper collection of patterns with uppercase character in words.
//    const int TEST1_NRULES = 4;
//    char test1w1[TEST1_NRULES][MAX_WORD_LENGTH+1] = {"mad","deranged","NEFARIOUS","have"};
//    char test1w2[TEST1_NRULES][MAX_WORD_LENGTH+1] = {"scientist","robot","PLOT","mad"};
//    int test1dist[TEST1_NRULES] = {1,3,2,1};
//
//    //2. containing a same pattern with exactly same words with same positions.
//    const int TEST2_NRULES = 5;
//    char test2w1[TEST2_NRULES][MAX_WORD_LENGTH+1] = {"mad","deranged","NEFARIOUS","deranged","have"};
//    char test2w2[TEST2_NRULES][MAX_WORD_LENGTH+1] = {"scientist","robot","PLOT","robot","mad"};
//    int test2dist[TEST2_NRULES] = {1,3,0,2,1};
//
//    //3. containing same patterns with exactly same words with exchanged positions in word1 and word2.
//    const int TEST3_NRULES = 6;
//    char test3w1[TEST3_NRULES][MAX_WORD_LENGTH+1] = {"mad","deranged","NEFARIOUS","robot","have", "MAD"};
//    char test3w2[TEST3_NRULES][MAX_WORD_LENGTH+1] = {"scientist","robot","PLOT","deranged","mad", "hAVe"};
//    int test3dist[TEST3_NRULES] = {1,3,0,2,1,2};
//
//    //4. containing word with characters other than alpha
//    const int TEST4_NRULES = 5;
//    char test4w1[TEST4_NRULES][MAX_WORD_LENGTH+1] = {"mad","deranged","NEFARIOUS","half-witted","ROBOT"};
//    char test4w2[TEST4_NRULES][MAX_WORD_LENGTH+1] = {"scientist","robot","PLOT","assistant","deranged"};
//    int test4dist[TEST4_NRULES] = {1,3,0,2,1};
//
//    //5. containing word with same pattern appearing more than twice
//    const int TEST5_NRULES = 7;
//    char test5w1[TEST5_NRULES][MAX_WORD_LENGTH+1] = {"mad","MAD","Scientist","have", "HAVE", "MAd","mad!@#"};
//    char test5w2[TEST5_NRULES][MAX_WORD_LENGTH+1] = {"scientist","ScientIst","maD","mad","Mad","hAve","Have"};
//    int test5dist[TEST5_NRULES] = {1,3,2,1,3,4,3};
//
//    //6. containing many error simultaneously
//    const int TEST6_NRULES = 11;
//    char test6w1[TEST6_NRULES][MAX_WORD_LENGTH+1] = {"ai","bi","ci@@","D","D","D","E","","",""," "};
//    char test6w2[TEST6_NRULES][MAX_WORD_LENGTH+1] = {"AI","BQ","Cassf21423","E","E","D","",""," "};
//    int test6dist[TEST6_NRULES] = {-1,-2,3,4,5,4,3,2,1,-2,0};
//
//    //7 containing testrules equals to zero
//    const int TEST7_NRULES = 0;
//    char test7w1[TEST7_NRULES][MAX_WORD_LENGTH+1] = {};
//    char test7w2[TEST7_NRULES][MAX_WORD_LENGTH+1] = {};
//    int test7dist[TEST7_NRULES] = {};
//
//    //8 containing separations less than zero
//    const int TEST8_NRULES = 5;
//    char test8w1[TEST8_NRULES][MAX_WORD_LENGTH+1] = {"mad","deranged","NEFARIOUS","deranged","have"};
//    char test8w2[TEST8_NRULES][MAX_WORD_LENGTH+1] = {"scientist","robot","PLOT","robot","mad"};
//    int test8dist[TEST8_NRULES] = {1,-3,0,-2,-1};
//
//
//    int score1, score2, score3, score4, score5, score6, score7, score8, score9;
//
//    //1. Normal document with lowercase in key words
//    score1 = rate("The mad UCLA scientist unleashed a deranged evil giant robot.",test1w1, test1w2, test1dist, TEST1_NRULES);
//
//    //2. Normal document with uppercase in key words
//    score2 = rate("The MaD UCLA SCientIST unleashed a dERanged evil giant rOBot.",test1w1, test1w2, test1dist, TEST1_NRULES);
//
//    //3. Document with special characters and numbers
//    score3 = rate("The mad UC#$#&LA scientis123t unleashed @#$% a deran#)$(ged evil giant123 robot.",test1w1, test1w2, test1dist, TEST1_NRULES);
//
//    //4. Document with more than one space separating words
//    score4 = rate("The mad UCLA     scientist unleashed a     deranged   evil giant   robot.",test1w1, test1w2, test1dist, TEST1_NRULES);
//
//    //5. Document with space characters at the beginning
//    score5 = rate("     The mad UCLA     scientist unleashed a     deranged   evil giant   robot.",test1w1, test1w2, test1dist, TEST1_NRULES);
//
//    //6. Document with words satisfying a pattern more than once
//    score6 = rate("The mad scientist mad scientist scientist unleashed a deranged evil robot robot.",test1w1, test1w2, test1dist, TEST1_NRULES);
//
//    //7. key words with special character connecting tham instead of space
//    score7 = rate("The mad-scientist unleashed a-deranged evil giant-robot.",test1w1, test1w2, test1dist, TEST1_NRULES);
//
//    //8. document containing no words matching the patterns
//    score8 = rate("12e32rwaedsf asw321 1323 32asf sfs#@#!#!",test1w1, test1w2, test1dist, TEST1_NRULES);
//
//    cerr<<score1<<" "<<score2<<" "<<score3<<" "<<score4<<" "<<score5<<" "<<score6<<" "<<score7<<" "<<score8;
//
//    char test3wd1[5][21]={"abc", "def", "ABC", "ABC", "abc"};
//        char test3wd2[5][21]={"DEF", "abc", "def", "DEF", "def"};
//        int test3sep[5]={1, 2, 1, 0, 1,};
//        int n=makeProper(test3wd1, test3wd2, test3sep,5);
//        cout <<n;
//

    char test4wd1[5][21]={"abc", "abc", "ABC", "abc", "abc"};
    char test4wd2[5][21]={"abc", "abc", "abc", "abc", "abc"};
    int test4sep[5]={1, 2, 1, 0, 1,};
    int a=makeProper(test4wd1, test4wd2, test4sep,5);
    cout <<a;

}
