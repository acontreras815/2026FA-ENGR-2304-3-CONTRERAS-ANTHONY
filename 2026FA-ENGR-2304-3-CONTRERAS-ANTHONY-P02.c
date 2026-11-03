// 2026FA-ENGR-2304-3-CONTRERAS-ANTHONY-P02


#include <stdio.h>

int main()
{
	
	int menuChoice;
	int running = 1;
	
	while(running == 1)
	{
	
    printf("Number Conversion Program\n");
    printf("1. Decimal / Binary Conversion\n");
    printf("2. Hexadecimal / Binary Conversion\n");
	printf("3. Exit\n");
    printf("Enter your choice: ");

    scanf("%d", &menuChoice);	
	
	if (menuChoice == 1)
	{
	
		int choice;
	
		printf("1. Decimal to Binary\n");
		printf("2. Binary to Decimal\n");
		printf("Enter your choice: ");
		
		scanf("%d", &choice);
	
	
	
		if (choice == 1)
		{
		    int number;
		    int binary[8] = {0};
		    int i = 7;
			
			printf("Enter a number: ");
			scanf("%d", &number);
			
			if (number < -127 || number > 127)
			{
				printf("Number must be between -127 and 127.");
				
			}
			else
				{
				
					if (number < 0)
					{
						binary[0] = 1;
						number = -number;	
					}
				
				    while (number > 0)
				    {
				        binary[i] = number % 2;
				        number = number / 2;
				        i = i - 1;
				    }
					
					printf("Binary: ");
				
				    for (i = 0; i < 8; i++)
				    {
				        printf("%d", binary[i]);
			    }
				printf("\n");
			}
			}
			else if (choice == 2)
			{
				char binaryInput[9];
				int decimal;
		
		    	printf("Enter an 8-bit binary number: ");
		    	scanf("%8s", binaryInput);
			
			decimal = ((binaryInput[1] - '0') * 64) +
					  ((binaryInput[2] - '0') * 32) +
					  ((binaryInput[3] - '0') * 16) +
					  ((binaryInput[4] - '0') * 8) +
					  ((binaryInput[5] - '0') * 4) +
			          ((binaryInput[6] - '0') * 2) +
					  ((binaryInput[7] - '0') * 1);
			
				if (binaryInput[0] == '1')
				{
				    decimal = -decimal;
				}
				
				printf("Decimal: %d\n", decimal);
					
					
					
			}
			else
			{
				
				printf("Invalid choice. \n");
			}
		}
	else if (menuChoice == 2)
	{
		  char input[66];
		
		    printf("Enter a binary or hexadecimal number: ");
		    scanf("%65s", input);
		
		
		    if (input[0] == '0' && input[1] == 'x')
		    {
		        int i = 2;
		
		        printf("Binary: ");
			
				
		
		        while (input[i] != '\0')
		        {
					if (input[i] == '.')
					{
					    printf(".");
					}
					else if (input[i] == '0')
					{
					    printf("0000");
					}
					else if (input[i] == '1')
					{
					    printf("0001");
					}
		            else if (input[i] == '2')
		            {
		                printf("0010");
		            }
		            else if (input[i] == '3')
		            {
		                printf("0011");
		            }
		            else if (input[i] == '4')
		            {
		                printf("0100");
		            }
		            else if (input[i] == '5')
		            {
		                printf("0101");
		            }
		            else if (input[i] == '6')
		            {
		                printf("0110");
		            }
		            else if (input[i] == '7')
		            {
		                printf("0111");
		            }
		            else if (input[i] == '8')
		            {
		                printf("1000");
		            }
		            else if (input[i] == '9')
		            {
		                printf("1001");
		            }
		            else if (input[i] == 'A' || input[i] == 'a')
		            {
		                printf("1010");
		            }
		            else if (input[i] == 'B' || input[i] == 'b')
		            {
		                printf("1011");
		            }
		            else if (input[i] == 'C' || input[i] == 'c')
		            {
		                printf("1100");
		            }
		            else if (input[i] == 'D' || input[i] == 'd')
		            {
		                printf("1101");
		            }
		            else if (input[i] == 'E' || input[i] == 'e')
		            {
		                printf("1110");
		            }
		            else if (input[i] == 'F' || input[i] == 'f')
		            {
                printf("1111");
            }

            i = i + 1;
        }

		        printf("\n");
		    }
		
		
		    else
		    {
		        char left[33] = {0};
		        char right[33] = {0};
		
		        char hexLeft[9] = {0};
		
		        int leftLength = 0;
		        int rightLength = 0;
		
		        int i = 0;
		        int pointFound = 0;
		
		        int binaryIndex;
		        int hexIndex = 7;
		
		        int value;
		        int rightIndex;
		
		
		
		        while (input[i] != '\0')
		        {
		            if (input[i] == '.')
		            {
		                pointFound = 1;
		            }
		            else if (pointFound == 0)
		            {
		                left[leftLength] = input[i];
		                leftLength = leftLength + 1;
		            }
		            else
		            {
		                right[rightLength] = input[i];
		                rightLength = rightLength + 1;
		            }
		
		            i = i + 1;
		        }
		
		
		        binaryIndex = leftLength - 1;
		
		        while (binaryIndex >= 0)
		        {
		            value = 0;
		
		            if (binaryIndex >= 0)
		            {
		                value = value + ((left[binaryIndex] - '0') * 1);
		                binaryIndex = binaryIndex - 1;
		            }
		
		            if (binaryIndex >= 0)
		            {
		                value = value + ((left[binaryIndex] - '0') * 2);
		                binaryIndex = binaryIndex - 1;
		            }
		
		            if (binaryIndex >= 0)
		            {
		                value = value + ((left[binaryIndex] - '0') * 4);
		                binaryIndex = binaryIndex - 1;
		            }
		
		            if (binaryIndex >= 0)
		            {
		                value = value + ((left[binaryIndex] - '0') * 8);
		                binaryIndex = binaryIndex - 1;
		            }
		
		
		            if (value < 10)
		            {
		                hexLeft[hexIndex] = value + '0';
		            }
		            else if (value == 10)
		            {
		                hexLeft[hexIndex] = 'A';
		            }
		            else if (value == 11)
		            {
		                hexLeft[hexIndex] = 'B';
		            }
		            else if (value == 12)
		            {
		                hexLeft[hexIndex] = 'C';
		            }
		            else if (value == 13)
		            {
		                hexLeft[hexIndex] = 'D';
		            }
		            else if (value == 14)
		            {
		                hexLeft[hexIndex] = 'E';
		            }
		            else if (value == 15)
		            {
		                hexLeft[hexIndex] = 'F';
		            }
		
		            hexIndex = hexIndex - 1;
		        }
		
		
		        printf("Hex: 0x");
		
		
		
		        for (i = hexIndex + 1; i < 8; i++)
		        {
		            printf("%c", hexLeft[i]);
		        }
		
		
		        if (rightLength > 0)
		        {
		            printf(".");
		
		            rightIndex = 0;
		
		            while (rightIndex < rightLength)
		            {
		                value = 0;
		
		                if (rightIndex < rightLength)
		                {
		                    value = value + ((right[rightIndex] - '0') * 8);
		                    rightIndex = rightIndex + 1;
		                }
		
		                if (rightIndex < rightLength)
		                {
		                    value = value + ((right[rightIndex] - '0') * 4);
		                    rightIndex = rightIndex + 1;
		                }
		
		                if (rightIndex < rightLength)
		                {
		                    value = value + ((right[rightIndex] - '0') * 2);
		                    rightIndex = rightIndex + 1;
		                }
		
		                if (rightIndex < rightLength)
		                {
		                    value = value + ((right[rightIndex] - '0') * 1);
		                    rightIndex = rightIndex + 1;
		                }
		
		
		                if (value < 10)
		                {
		                    printf("%d", value);
		                }
		                else if (value == 10)
		                {
		                    printf("A");
		                }
		                else if (value == 11)
		                {
		                    printf("B");
		                }
		                else if (value == 12)
		                {
		                    printf("C");
		                }
		                else if (value == 13)
		                {
		                    printf("D");
		                }
		                else if (value == 14)
		                {
		                    printf("E");
                }
                else if (value == 15)
                {
                    printf("F");
                }
            }
        }

        printf("\n");
	    }
			
		}
		else if (menuChoice == 3)
		{
			running = 0;
			printf("Exiting program.\n");
		}
		else{
			printf("Invalid choice.\n");
		}
	}
	
    return 0;
}