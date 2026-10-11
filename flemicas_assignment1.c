#include <stdio.h>
#include <math.h>

// CS 374 Assignment 1
// Programmer: Cassandra Fleming (flemicas@oregonstate.edu)
// Description: This assignment uses user input values to calculate the total surface area and volume of a user determined number of spherical segments
//              After it finishes calculations for individual segments, it will then caclulate the average total surface area and volume


int main(void) {
    //declare variables
    const float PI = 3.14159265359;
    
    int n;                          // number of spherical segments

    //loop variables
    float R;                        // radius
    float ha;                       // height a
    float hb;                       // height b
    float h;                        // height a-b
    float a;                        // radius of top segment a
    float b;                        // radius of bottom segment b
    float top_surface_area;
    float bottom_surface_area;
    float lateral_surface_area;
    float loop_total_surface_area;             
    float loop_volume;
    
    //validation variables
    int valid_n = 0;
    int valid_R = 0;
    int valid_ha = 0;
    int valid_hb = 0;
    
    //final averages
    float total_surface_area;
    float total_volume;
         
    //get the number of spherical segments
    while (valid_n == 0){
        // this section does not want "invalid input", just cycle till completed
        printf("How many spherical segments you want to evaluate [2-10]? ");
        scanf("%d", &n);
        if (n >= 2 && n <= 10){
            valid_n = 1;
        }
    }
    
    //obtain the data for each spherical segment
    for (int i = 1; i <= n; i++){       

        //get and validate user input for R, ha, hb
        while(valid_R == 0 || valid_ha == 0 || valid_hb == 0){
            printf("Obtaining data for spherical segment number %d\n",i);

            //get user inputs
            printf("What is the radius of the sphere (R)? ");
            scanf("%f", &R);
            printf("What is the height of the top area of the spherical segment (ha)? ");
            scanf("%f", &ha);
            printf("What is the height of the bottom area of the spherical segment (hb)? ");
            scanf("%f", &hb);

            //print to console what the user entered
            printf("Entered data: R = %.2f, ha = %.2f, hb = %.2f.\n", R, ha, hb);

            // validation:
            // R, ha, hb must all be positive real values - aka all must be numbers greater than 0
            // ha and hb must never be bigger than R
            // ha must always be >= hb
            if(R > 0 && ha > 0 && hb > 0){   
                valid_R = 1;
                if (ha < R && hb < R){
                    valid_hb = 1;
                    if (ha >= hb){
                        valid_ha = 1;
                    }
                }
            }

            if(valid_R == 0 || valid_ha == 0 || valid_hb == 0){
                printf("Invalid Input.\n");
            }
        }

        // do calculations
        a = sqrt((R*R)-(ha*ha));
        b = sqrt((R*R)-(hb*hb));
        h = ha - hb;
        top_surface_area = PI*(a*a);
        bottom_surface_area = PI*(b*b);
        lateral_surface_area = 2*PI*R*h;
        loop_total_surface_area = top_surface_area + bottom_surface_area + lateral_surface_area;
        loop_volume = (1.0/6)*PI*h*((3*(a*a))+(3*(b*b))+(h*h));

        //print loop results        
        printf("Total Surface Area = %.2f Volume = %.2f.\n", loop_total_surface_area, loop_volume);

        //update global totals
        total_surface_area += loop_total_surface_area;
        total_volume += loop_volume;

        //reset validation
        valid_R = 0;
        valid_ha = 0;
        valid_hb = 0;
        
    }

    //print averages
    printf("Total average results:\n");
    printf("Average Surface Area = %.2f Average Volume = %.2f.\n", (total_surface_area/n), (total_volume/n));

    return 0;
}


