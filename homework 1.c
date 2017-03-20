/*************************************************************
* Below program prints rectangles with specified width, height
* and thickness, whenever possible. If it is not, it simply
* prints the full rectangle.
*************************************************************/
#include <stdio.h>

int rectangle();//prototype
//main function

int main(){
    int c;
    rectangle();
    printf ("Do you want to continue? 1 for Yes, 0 for No.\n");
    scanf("%d",&c);
    while (c != 0)
    {
        switch (c)
        {
            case 1:
                main();
                break;

            case '\n':
            case '\t':
            case ' ' :
                break;
            default:
                break;
        }
        break;
    }

    return 0;

}//end main

int rectangle()
{
    int height,width,thickness,hCounter,wCounter;
    printf ("Welcome here. Please enter the height of the rectangle.\n");
    scanf("%d",&height);
    printf ("Now type the width of the rectangle.\n");
    scanf("%d",&width);
    printf ("Now type the thickness of the rectangle.\n");
    scanf("%d",&thickness);

    if( height <= 0 || width <=0) /*Whether height either width higher than zero */
    {
        printf("Height and width must be higher than zero\n");//If they are not, program will be terminated.
        return(-1);
    } //end if
    else
    {


            if ((float)width/thickness>2 && (float)height/thickness>2) /*Actually that is not descent to use floats in conditional statements. However;
			If I apply this conditions with integers, it would be really long and hard to read code. */
            {
                for (hCounter=0;hCounter < height;hCounter++)
                {
                    for (wCounter=0;wCounter < width;wCounter++)
                    {
                        if (hCounter < thickness  || hCounter >= height-thickness)
                            printf("*");
                        else
                        {
                            if (wCounter < thickness || wCounter >= width-thickness)
                                printf ("*");
                            else
                            {
                                printf (" ");
                            }//end of 3rd else
                        }//end of 2nd else


                    }//end of 2nd for
                    printf("\n");
                }//end of 1st for
            }//end of 2nd if
            else if ((float)width/thickness <= 2 && (float)height/thickness <= 2)
            {
                printf("It is not possible to draw your rectangle with the specified thickness. The rectangle without the thickness option is drawn below:\n");
                for (hCounter=0;hCounter < height;hCounter++)
                {
                    for (wCounter=0;wCounter < width;wCounter++)
                    {
                        printf("*");

                    }//end for
                    printf("\n");
                }//end for
            }//end else if
            else if ((float)width/thickness >2 || (float)height/thickness >2)
            {
                for (hCounter=0;hCounter < height;hCounter++)
                {
                    for (wCounter=0;wCounter < width;wCounter++)
                    {
                        if (hCounter < thickness  || hCounter >= height-thickness)
                            printf("*");
                        else
                        {
                            if (wCounter < thickness-1 || wCounter >= width-thickness+1)
                                printf ("*");
                            else
                            {
                                printf (" ");
                            }//end of 3rd else
                        }//end of 2nd else
                    }//end of 2nd for
                    printf("\n");
                }//end for
            }//end else if


    }//end first else
}
