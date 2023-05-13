#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int answer[4]; // 컴퓨터에서 생성된 답을 저장할 배열
    int guess[4]; // 플레이어가 예측하는 답을 저장할 배열
    int attempts = 0; // 플레이어의 시도 횟수

    
    srand(time(NULL)); 
    for (int i = 0; i < 4; i++)
    {
        answer[i] = rand() % 10; // 0-9 사이의 난수 생성
    }

    
    printf("Welcome to Number Baseball!\n");
    printf("Guess the 4-digit number generated by the computer.\n");
    printf("You have 15 attempts.\n");

    while (attempts < 15)
    {
        printf("Enter your guess (4 digits): ");
        scanf_s("%1d%1d%1d%1d", &guess[0], &guess[1], &guess[2], &guess[3]); 

        // guess와 answer 비교

        int strikes = 0;
        int balls = 0;

        for (int i = 0; i < 4; i++)
        {
            if (guess[i] == answer[i])
            {
                strikes++;
            }
            else
            {
                for (int j = 0; j < 4; j++)
                {
                    if (guess[i] == answer[j])
                    {
                        balls++;
                        break; // 동일한 숫자를 여러 번 세는 것을 방지
                    }
                }
            }
        }

        
        printf("%d strike(s), %d ball(s)\n", strikes, balls);

        
        if (strikes == 4)
        {
            printf("Congratulations, you Win!\n");
            return 0;
        }

        attempts++;
    }

    
    printf("Sorry, you lose.\n");
    printf("The answer was: %d%d%d%d\n", answer[0], answer[1], answer[2], answer[3]);

    return 0;
}