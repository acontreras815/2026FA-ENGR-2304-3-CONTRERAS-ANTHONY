#include <stdio.h>

int main()
{
    int choice;

    printf("Algebraic Equation Solver\n");
    printf("1. Solve Two Equations\n");
    printf("2. Solve Three Equations Using Cramer's Rule\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        double a1, b1, c1;
        double a2, b2, c2;
        double determinant;
        double x, y;

        printf("\nEquation format: ax + by = c\n");

        printf("\nEnter a, b, and c for equation 1: ");
        scanf("%lf %lf %lf", &a1, &b1, &c1);

        printf("Enter a, b, and c for equation 2: ");
        scanf("%lf %lf %lf", &a2, &b2, &c2);

        determinant = (a1 * b2) - (a2 * b1);

        if (determinant == 0)
        {
            printf("\nThere is no unique solution.\n");
        }
        else
        {
            x = ((c1 * b2) - (c2 * b1)) / determinant;
            y = ((a1 * c2) - (a2 * c1)) / determinant;

            printf("\nx = %.2lf\n", x);
            printf("y = %.2lf\n", y);
        }
    }

    else if (choice == 2)
    {
        double a1, b1, c1, d1;
        double a2, b2, c2, d2;
        double a3, b3, c3, d3;

        double D, Dx, Dy, Dz;
        double x, y, z;

        printf("\nEquation format: ax + by + cz = d\n");

        printf("\nEnter a, b, c, and d for equation 1: ");
        scanf("%lf %lf %lf %lf", &a1, &b1, &c1, &d1);

        printf("Enter a, b, c, and d for equation 2: ");
        scanf("%lf %lf %lf %lf", &a2, &b2, &c2, &d2);

        printf("Enter a, b, c, and d for equation 3: ");
        scanf("%lf %lf %lf %lf", &a3, &b3, &c3, &d3);

        /* Main determinant using cofactor expansion */
        D = a1 * ((b2 * c3) - (c2 * b3))
          - b1 * ((a2 * c3) - (c2 * a3))
          + c1 * ((a2 * b3) - (b2 * a3));

        /* Determinant for x */
        Dx = d1 * ((b2 * c3) - (c2 * b3))
           - b1 * ((d2 * c3) - (c2 * d3))
           + c1 * ((d2 * b3) - (b2 * d3));

        /* Determinant for y */
        Dy = a1 * ((d2 * c3) - (c2 * d3))
           - d1 * ((a2 * c3) - (c2 * a3))
           + c1 * ((a2 * d3) - (d2 * a3));

        /* Determinant for z */
        Dz = a1 * ((b2 * d3) - (d2 * b3))
           - b1 * ((a2 * d3) - (d2 * a3))
           + d1 * ((a2 * b3) - (b2 * a3));

        if (D == 0)
        {
            printf("\nThere is no unique solution.\n");
        }
        else
        {
            x = Dx / D;
            y = Dy / D;
            z = Dz / D;

			printf("\nD  = %.2f\n", D);
			printf("Dx = %.2f\n", Dx);
			printf("Dy = %.2f\n", Dy);
			printf("Dz = %.2f\n", Dz);

			printf("\nx = %.2f\n", x);
			printf("y = %.2f\n", y);
			printf("z = %.2f\n", z);
        }
    }

    else
    {
        printf("\nInvalid choice.\n");
    }

    return 0;
}