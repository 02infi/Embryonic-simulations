#include <GL/glut.h>
#include <math.h>
#include <cmath>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <ctime>


using namespace std;
void Setinitialnuclei(void) ;
void Timer (int value);
int refreshmillis = 30;
ofstream myfile ;
int g;


void InitGL(void)
{
    glClearColor(0,0,0,1);
}



int main(int argc, char** argv)
{ 
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(500,50);
    glutInitWindowSize(1000,800);
    glutCreateWindow("pro");
    glutDisplayFunc(Setinitialnuclei);
    glutTimerFunc(30,Timer,0);
    glutMainLoop();
    return 0; 
}

void Setinitialnuclei (void)
{   int v = 0;
    int abc = 0;
    float color = 0;
    int z = 0;
    float adre = 0.3;
    float tot_time = 97 ;
    int j = 0 ;
    float pos_y1 ,pos_y2 ;
    float pos_x1 ,pos_x2 ;
    float tot_step = 0.25;
    int Tot_No_Nuclei[10000];
    Tot_No_Nuclei[0] = {100};
    int Tot_No_Nuclei_1[10000];
    Tot_No_Nuclei_1[0] = {100};
    int Tot_No_Nuclei_2[10000] ;
    Tot_No_Nuclei_2[0] = {100};
    int No_of_DiffeCells1 = 0;
    int No_of_DiffeCells2 = 0;
    double **nuclei = new double*[100000];
    for (int ja = 0 ; ja <= 100000;ja++)
   { nuclei[ja] = new double[5] ;
}
                                                                    
  //  memset(nuclei, 1, sizeof(nuclei[0][0]) * 1000* 5);
    float size_cell = 1 ;
    int divisons = 0;
    float trans ;
    float cell_cycle[97] = {50.0000,50.0000,50.0000,50.0000,50.0000,50.0000,36.2486,26.5332,22.4759,19.6578,17.6252,16.1062,14.9542,14.0638,13.3803,12.8038,12.3900,12.0441,11.7859,11.5543,11.3994,11.2688,11.1705,11.1094,11.0731,11.1279,11.2799,11.4901,11.7785,12.1242,12.5409,13.0147,13.5550,14.1691,14.8626,15.6363,16.5157,17.4181,18.3572,19.3371,20.3152,21.3693,22.4236,23.5478,24.6948,25.8836,27.1765,28.4821,29.8625,31.0687,31.9687,32.6184,32.8337,32.7632,32.3151,31.5788,30.5702,29.3899,28.1092,26.7131,25.3939,24.2854,23.3844,22.6733,22.1111,21.6755,21.3511,21.1238,20.9887,20.9470,20.9632,21.0557,21.2202,21.4236,21.7220,22.0514,22.4438,22.8824,23.3590,23.8731,24.4472,25.0735,25.6937,26.4119,27.1377,27.9629,28.8172,29.7259,30.7580,31.8704,33.1358,34.5348,36.1771,38.1498,40.6664,43.8148,43.6664};
    float pp_nn[] = {1.0000,1.0000,1.0000,1.0000,1.0000,1.0000,1.0000,1.0000,1.0000,1.0000,1.0000,1.0000,1.0000,1.0000,1.0000,1.0000,1.0000,1.0000,0.9974,0.9775,0.9580,0.9391,0.9207,0.9028,0.8859,0.8709,0.8575,0.8455,0.8342,0.8238,0.8134,0.8034,0.7934,0.7832,0.7726,0.7617,0.7491,0.7329,0.7115,0.6850,0.6538,0.6164,0.5743,0.5259,0.4722,0.4129,0.3468,0.2760,0.2015,0.1342,0.0790,0.0353,0.0049,-0.0137,-0.0190,-0.0132,0.0038,0.0318,0.0674,0.1124,0.1617,0.2088,0.2524,0.2924,0.3307,0.3663,0.4008,0.4332,0.4646,0.4955,0.5253,0.5541,0.5823,0.6041,0.6190,0.6272,0.6286,0.6235,0.6112,0.5930,0.5679,0.5369,0.4992,0.4555,0.4057,0.3495,0.2877,0.2201,0.1460,0.0668,-0.0184,-0.1091,-0.2051,-0.3069,-0.4148,-0.5266,-0.5266};

   /* float time_vector [389];
    for (int n = 0; n <= 388 ; n++)
    {
        time_vector[n] = n*(tot_step);
    }*/
    int **type_of_nuclei = new int*[1000000];
    for (int ja = 0 ; ja <= 1000000; ja++){
     type_of_nuclei[ja] = new int[2];     
}


  int **phase_nuclei = new int*[1000000];
    for (int ja = 0 ; ja <= 1000000; ja++){
     phase_nuclei[ja] = new int[2];     
}

    for (int m = 0 ; m < 2 ; m++){
    for(int n = 0 ; n < 1000000 ; n++)
      {
        type_of_nuclei[n][m] = rand()%2;
        phase_nuclei[n][m] = round((rand()%2) - 0.5 ) ;
    }
    }
    float gap = -0.95;
    float dis = (Tot_No_Nuclei[0] * 0.025) - 0.95 ;
    float leap = (Tot_No_Nuclei[0] * 0.025) - 0.95 ;
    for (int n = 0; n < Tot_No_Nuclei[0]; n++)
    {
        nuclei[n][0] = -0.70+ (0.60) * (((double) rand() / (RAND_MAX)) * ((double) rand() / (RAND_MAX)))  ;
        nuclei[n][1] = gap;
        nuclei[n][2] = 0.10 + (0.25) * (((double) rand() / (RAND_MAX)) + ((double) rand() / (RAND_MAX))) ;
        nuclei[n][3] = gap;
        gap = gap + 0.025;

    }

   for (int m = 0 ; m < 2 ; m++){
    for(int n = 0 ; n < Tot_No_Nuclei[0] ; n++)
      {
        type_of_nuclei[n][m] = 0;

    }
    }

    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_COLOR);
    glLoadIdentity();
    float theta = 2 * 3.14 /20;
    float c = cosf(theta);//precalculate the sine and cosine
    float s = sinf(theta);
    float t;

    float x = 0.01;//we start at angle = 0
    float y = 0;


 for (int n = 0; n < Tot_No_Nuclei[0]; n++)
 {

   glBegin(GL_LINES);
   glColor3f(type_of_nuclei[n][0],1-type_of_nuclei[n][0],0);                                               // code to represent the graphical properties of the line
   glVertex2f(-0.70,nuclei[n][1]) /* x1 and y1 */;
   glVertex2f(-0.10,nuclei[n][1]);/* x2 and y2 */
   glEnd();

     glBegin(GL_TRIANGLE_FAN);
    for(int ii = 0; ii < 20; ii++)                                    // code to represent the graphical properties of the the cell
    {
        glColor3f(type_of_nuclei[n][0],1-type_of_nuclei[n][0],0);
        glVertex2f(x + nuclei[n][0], y + nuclei[n][1]);
        t = x;
        x = c * x - s * y;
        y = s * t + c * y;
    }
    glEnd();

   glBegin(GL_LINES);
   glColor3f(type_of_nuclei[n][0],1-type_of_nuclei[n][0],0);          // code to represent the graphical properties of the line
   glVertex2f(0.10,nuclei[n][3]) /* x1 and y1 */;
   glVertex2f(0.70,nuclei[n][3]);/* x2 and y2 */
   glEnd();


 glBegin(GL_TRIANGLE_FAN);
 for(int ii = 0; ii < 20; ii++)                                    // code to represent the graphical properties of the the cell
    {
        glColor3f(type_of_nuclei[n][0],1-type_of_nuclei[n][0],0);
        glVertex2f(x + nuclei[n][2], y + nuclei[n][3]);
        t = x;
        x = c * x - s * y;
        y = s * t + c * y;
    }

    glEnd();
 }
 glutSwapBuffers();
  j = 0;
    ofstream myfile ;
    myfile.open ("data.txt");


  for (int time = 0;  time < (tot_time/tot_step) ; time++)

    {
        for (int n = 0; n < Tot_No_Nuclei_1[time]; n++)

        {


            if (nuclei[n][0] < -0.70)
            {
                if(type_of_nuclei[n][0] == 1 )
                {

                    type_of_nuclei[n][0] = -1;
                    phase_nuclei[n][0] = 0;
                    nuclei[n][0] = nuclei[n][0] - x * 0.00001;
                    x = x + 1 ;
                    pos_x1 = nuclei[n][1] ;
                    z++;


                    No_of_DiffeCells1++ ;
                }

                else if (type_of_nuclei[n][0] != -1)
                {
                    phase_nuclei[n][0] = - phase_nuclei[n][0];
                    nuclei[n][0] = -0.70;

                 }
            }

            else if (nuclei[n][0] > -0.10)
    {

              divisons = divisons + 1 ;
              phase_nuclei[n][0] = 1;

             phase_nuclei[Tot_No_Nuclei_1[time]][0]= 1;
              int x  = round(tot_step + (time * tot_step));
              float numer = - pp_nn[x] ;
              float denom1 = ((double) rand()/ (RAND_MAX));
              float denom2 = ((double) rand()/ (RAND_MAX));
              type_of_nuclei[Tot_No_Nuclei_1[time]][0] = round((numer/2)+ denom1);
              cout << time << "\t"<<  type_of_nuclei[Tot_No_Nuclei_1[time]][0] << endl ;
              type_of_nuclei[n][0] = round((numer/2) + denom2);
              if(z != 0)
                {
                nuclei[Tot_No_Nuclei_1[time]][1] = pos_x1;
                z = 0;
                }
               else
              {
                    nuclei[Tot_No_Nuclei_1[time]][1] = dis  + (0.025 * abc);
                     abc++;
              }

              nuclei[n][0] = -0.10 ;
              nuclei[Tot_No_Nuclei_1[time]][0] = -0.10 ;
                Tot_No_Nuclei_1[time] = Tot_No_Nuclei_1[time] + 1;

    }

            else {

                v = round((tot_step+(time * tot_step)));
                int I = cell_cycle[v];
                float velocity = (adre* (1/lgamma(I))) * phase_nuclei[n][0];
                nuclei[n][0] = nuclei[n][0] - velocity;
                Tot_No_Nuclei_1[time+1] = Tot_No_Nuclei_1[time];


            }


       }
     for (int n = 0 ; n < Tot_No_Nuclei_2[time]; n++)
      {



      if (nuclei[n][2] > 0.50)
            {
                if(type_of_nuclei[n][1] == 1 )
                {
                    type_of_nuclei[n][1] = -1;
                    phase_nuclei[n][1] = 0;
                    nuclei[n][2] = nuclei[n][2] + x * 0.00001;
                    x = x + 1 ;
                    pos_y1  =  nuclei[n][3] ;
                    No_of_DiffeCells2++ ;
                    z++;
                    color = 1 ;
                }

                else if (type_of_nuclei[n][1] != -1)
                {
                    phase_nuclei[n][1] = - phase_nuclei[n][1];
                    nuclei[n][2] = 0.50 ;

                 }
            }


            else if (nuclei[n][2] < 0.10)
          {

              divisons = divisons + 1 ;
              phase_nuclei[n][1] = 1;

              phase_nuclei[Tot_No_Nuclei_2[time]][1]= 1;
              int x  = round(tot_step + (time * tot_step));
              float numer = -pp_nn[x] ;
              float denom1 = ((double) rand()/ (RAND_MAX));
              float denom2 = ((double) rand()/ (RAND_MAX));
              type_of_nuclei[Tot_No_Nuclei_2[time]][1] = round((numer/2)+ denom1);
              type_of_nuclei[n][1] = round((numer/2) + denom2);

              if(z!= 0)
                {
                nuclei[Tot_No_Nuclei_2[time]][3] = pos_y1;
                z = 0;
                }
              else
               {
                    float pos_y = leap + (0.025 * j);
                    nuclei[Tot_No_Nuclei_2[time]][3] = pos_y;
                    j++;
               }
               Tot_No_Nuclei_2[time] = Tot_No_Nuclei_2[time] + 1;
              nuclei[n][2] = 0.10 ;
              nuclei[Tot_No_Nuclei_2[time]][2] = 0.10;


}

         else {

               if (phase_nuclei[n][1] == 1)
                { float velocity = 0.005;
                nuclei[n][2] = nuclei[n][2] + velocity;
                Tot_No_Nuclei_2[time+1] = Tot_No_Nuclei_2[time];
                 }
               else{
                g = round((tot_step+(time * tot_step)));
                int I = cell_cycle[g];
                float velocity = (adre* (1/lgamma(I))) * phase_nuclei[n][1];
                nuclei[n][2] = nuclei[n][2] - 0.01;
                Tot_No_Nuclei_2[time+1] = Tot_No_Nuclei_2[time];
}

            }

      //  cout << type_of_nuclei[n][1] << endl ;
        }


    //   cout << time << "\t" << Tot_No_Nuclei_1[time] << "\t" << No_of_DiffeCells1 << "\t"<<Tot_No_Nuclei_2[time] << "\t" << No_of_DiffeCells2 << "\t" << g << "\t" << v <<  endl ;
       myfile << time << "\t" << Tot_No_Nuclei_1[time] << "\t" << No_of_DiffeCells1 << "\t"<<Tot_No_Nuclei_2[time] << "\t" << No_of_DiffeCells2 << "\t" << g << "\t" << v <<  endl ;

    



    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    float theta = 2 * 3.14 /20;
    float c = cosf(theta);//precalculate the sine and cosine
    float s = sinf(theta);
    float t;

    float x = 0.01;//we start at angle = 0
    float y = 0;

        for (int n = 0; n < Tot_No_Nuclei_1[time]; n++)
 {


    glBegin(GL_LINES);
    glColor3f(type_of_nuclei[n][0],1 - type_of_nuclei[n][0],1 - abs(phase_nuclei[n][0]));
    glVertex2f(-0.70,nuclei[n][1]) ;
    glVertex2f(-0.10,nuclei[n][1]);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
     glColor3f(type_of_nuclei[n][0],1 - type_of_nuclei[n][0],1 - abs(phase_nuclei[n][0]));
    for(int ii = 0; ii < 20; ii++)                                    // code to represent the graphical properties of the the cell
    {
        glVertex2f(x + nuclei[n][0], y + nuclei[n][1]);
        t = x;
        x = c * x - s * y;
        y = s * t + c * y;

    }
    glEnd();

}

for (int n = 0; n < Tot_No_Nuclei_2[time]; n++)
        {

    glBegin(GL_LINES);
    glColor3f(type_of_nuclei[n][1],1 - type_of_nuclei[n][1],1 - abs(phase_nuclei[n][1]));
    glVertex2f(0.10,nuclei[n][3]) ;
    glVertex2f(0.50,nuclei[n][3]);
    glEnd();





     glBegin(GL_TRIANGLE_FAN);
     glColor3f(type_of_nuclei[n][1],1 - type_of_nuclei[n][1],1 - abs(phase_nuclei[n][1]));
    for(int ii = 0; ii < 20; ii++)                                    // code to represent the graphical properties of the the cell
    {
        glVertex2f(x + nuclei[n][2], y + nuclei[n][3]);
        t = x;
        x = c * x - s * y;
        y = s * t + c * y;
    }

     glEnd();


        }

        glutSwapBuffers();

    }



for (int ja = 0 ; ja <=1000000 ; ja++){
delete [] type_of_nuclei[ja] ;
}
delete [] type_of_nuclei; 
for (int ja = 0 ; ja <=1000000 ; ja++){
delete [] phase_nuclei[ja] ;
}
delete [] phase_nuclei ;

for(int i = 0; i < 1000000; ++i) {
    delete [] nuclei[i];
}
delete [] nuclei;
myfile.close();
std::cout << "Press enter to continue ...";
    std::cin.get();



}





void Timer (int value)
{
    glutPostRedisplay();
    glutTimerFunc(refreshmillis,Timer,0);
}
