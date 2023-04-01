//
//  C3_Erosion.cpp
//  FIOI_C3_Ta_Erosion
//
//  Created by William Koskas de Diego on 02/03/2023.
//

#include <iostream>
using namespace std;

void Erosion(int ligne, int colonne, char **Image)
{
  char **Copie= new char*[ligne];
  for (int i=0; i<ligne; i++)
    Copie[i]= new char[colonne];
  int delta[4][2]={{0,1}, {1,0}, {0, -1}, {-1, 0}};
  for (int i=0; i<ligne; i++)
    for (int j=0; j<colonne; j++)
    {
      if (i==0 || j==0 || i==ligne-1 || j==colonne-1)
        Copie[i][j]='.';
      else
      {
        if (Image[i][j]=='#')
        {
          bool bord = false;
          for (int k=0; k<4; k++)
            if (Image[i+delta[k][0]][j+delta[k][1]]=='.')
            {
              Copie[i][j]='.';
              bord = true;
              break;
            }
          if (!bord)
            Copie[i][j]='#';
        }
      }
    }
  for (int i=0; i<ligne; i++)
    for (int j=0; j<colonne; j++)
      Image[i][j]=Copie[i][j];
  for (int i=0;i<ligne; i++)
    delete[] Copie[i];
  delete[] Copie;
}

int main()
{
  int n;
  cin >> n;
  int ligne, colonne;
  cin >> ligne >> colonne;
  char **Image = new char*[ligne];
  for (int i=0; i<ligne; i++)
    Image[i] = new char[colonne];
  for (int i=0; i<ligne; i++)
    for (int j=0; j<colonne; j++)
      cin >> Image[i][j];
  for (int i=0; i<n; i++)
    Erosion (ligne, colonne, Image);
  for (int i=0; i<ligne; i++)
  {
    for (int j=0; j<colonne; j++)
      cout << Image[i][j];
    cout << endl;
  }
  for (int i=0; i<ligne; i++)
    delete[] Image[i];
  delete[] Image;
  return 0;
}
