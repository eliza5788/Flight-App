#include <iostream>
#include <fstream>
#include <string>
#include<string.h>
#include<cstring>

using namespace std;

class Zboruri{
public:
    char plecare[50];
    char sosire[50];
    char data[9];
    int nrlocuri;
    void setplecare(char s[50])
    {
        strcpy(plecare,s);
    }
    void setsosire(char s[50])
    {
        strcpy(sosire,s);
    }
    void setdata(char s[9])
    {
        strcpy(data,s);
    }
    void setnrlocuri(int x)
    {
        nrlocuri = x;
    }
};

class Utilizator{
public:
    char username[50];
    char parola[50];
    char parolacriptata[100];
    char email[50];
    int statut; // acest atribut va fi 1 daca utilizatorul este operator, si 0 daca este un om obisnuit
    void setusername(char s[50])
    {
        strcpy(username,s);
    }
    void setparola(char s[50])
    {
        strcpy(parola,s);
    }
    void setparolacriptata(char s[100])
    {
        strcpy(parolacriptata,s);
    }
    void setemail(char s[50])
    {
        strcpy(email,s);
    }
    void setstatut(int x)
    {
        statut = x;
    }
};

class Rezervare : public Utilizator{
public:
    char rezervareplecare[50];
    char rezervaresosire[50];
    char rezervaredata[50];
    char nume[50];
    char prenume[50];
    int varsta;
    char sex[2];
    char CNP[13];
    char datanasterii[13];
    void setrezervareplecare(char s[50])
    {
        strcpy(rezervareplecare,s);
    }
    void setrezervaresosire(char s[50])
    {
        strcpy(rezervaresosire,s);
    }
    void setrezervaredata(char s[50])
    {
        strcpy(rezervaredata,s);
    }
    void setnume(char s[50])
    {
        strcpy(nume,s);
    }
    void setprenume(char s[50])
    {
        strcpy(prenume,s);
    }
    void setvarsta(int p)
    {
        varsta = p;
    }
    void setsex(char e[2])
    {
        strcpy(sex,e);
    }
    void setCNP(char b[13])
    {
        strcpy(CNP,b);
    }
    void setdatanasterii(char b[13])
    {
        strcpy(datanasterii,b);
    }

};

int main()
{
    Zboruri zbor[150];
    Utilizator users[150];
    fstream newfile;
    char k, e[2], rasp1, rasp2, rasp3, rasp4, str[50], em[50], pass[50], user[50], conf[50], anstr[10], zistr[10], lunastr[10], b[13], encryptedpass[100];
    char *cuv;
    int i, verif=0, n, ok, nrzboruri=0, nrutilizatori=0, x, an, luna, zi, nr, j, h, a, d, verif1=0, verif2=0, verif3=0, c, nroptiuni=0, q, opt, index[150], v, w, p;
    newfile.open("listazboruri.txt",ios::in);
   if (newfile.is_open())
   {
       string strrand;
       while(getline(newfile, strrand))
       {
        n = strrand.length();
        char rand[n + 1];
        strcpy(rand, strrand.c_str());
        cuv=strtok(rand," ");
        zbor[nrzboruri].setplecare(cuv);
        cuv=strtok(NULL," ");
        zbor[nrzboruri].setsosire(cuv);
        cuv=strtok(NULL," ");
        zbor[nrzboruri].setdata(cuv);
        cuv=strtok(NULL," ");
        x=atoi(cuv);
        zbor[nrzboruri].setnrlocuri(x);
        nrzboruri++;
       }
       newfile.close();
   }
   strcpy(cuv,"");
   newfile.open("listautilizatori.txt",ios::in);
   if (newfile.is_open())
   {
       string strrand;
       while(getline(newfile, strrand))
       {
        n = strrand.length();
        char rand[n + 1];
        strcpy(rand, strrand.c_str());
        cuv=strtok(rand," ");
        users[nrutilizatori].setusername(cuv);
        cuv=strtok(NULL," ");
        users[nrutilizatori].setparola(cuv);
        cuv=strtok(NULL," ");
        for(int w=0;w<strlen(users[nrutilizatori].parola);w++)
        {
        encryptedpass[w]=users[nrutilizatori].parola[w]+12;
        }
        users[nrutilizatori].setparolacriptata(encryptedpass);
        //cout<<users[nrutilizatori].parolacriptata<<endl;
        users[nrutilizatori].setemail(cuv);
        cuv=strtok(NULL," ");
        x=atoi(cuv);
        users[nrutilizatori].setstatut(x);
        nrutilizatori++;
       }
        newfile.close();
   }
   cout<<"Cauti zboruri catre orice destinatie? \nEsti in locul potrivit!\nDoar inca un pas ramas pana cand poti rezerva biletele... \nAi deja cont? Daca da, tasteaza L pentru 'login'. Daca nu, tasteaza S pentru 'sign up'."<<endl;
   try
   {
       cin>>k;
       if (k=='L' || k=='l' || k=='S' || k=='s')
       {
           if (k=='L' || k=='l')
           {
               cout<<"Ai deja cont pe platforma noastra? Introdu usernameul, si mai apoi parola:"<<endl;
               cout<<"USERNAME: ";
               try
               {
                cin>>user;
                for (i=0; i<nrutilizatori && verif==0; i++)
                    if (strcmp(user,users[i].username)==0)
                            verif=1;
                i--;
                if (verif==1)
                {
                   cout<<"PAROLA: ";
                   try
                   {
                       cin>>pass;
                       if (strcmp(pass,users[i].parola)==NULL)
                       {
                           cout<<"Login efectuat cu succes!"<<endl;
                           if (users[i].statut ==1)
                           {
                               cout<<"Utilizator privilegiat. Doriti sa faceti modificari la lista de zboruri? D/N"<<endl;
                               try
                               {
                                cin>>rasp1;
                                if (rasp1=='N' || rasp1=='n')
                                   {
                                    throw(9);
                                    }
                                else
                                {
                                    if (rasp1=='D' || rasp1=='d')
                                    {
                                        cout<<"Doriti sa stergeti zboruri sau sa adaugati zboruri? \nStergere - s/S\nAdaugare - A/a\n"<<endl;
                                        cin>>rasp2;
                                        if (rasp2=='A' || rasp2=='a')
                                        {
                                            cout<<"Ati selectat optiunea de adaugare in lista de zboruri a unor noi zboruri. Cate zboruri noi doriti sa adaugati?\n"<<endl;
                                            cin>>nr;
                                            for (d=0; d<nr; d++)
                                            {
                                                cout<<endl<<"Introduceti orasul de plecare al zborului "<<d+1<<": ";
                                                try
                                                {
                                                    cin>>str;
                                                    h=0;
                                                    for (j=0;j<strlen(str)&& h==0; j++)
                                                        if (strchr(".,;?!@$%^&-+=",str[j])!=NULL)
                                                            h=1;
                                                    if (h==0)
                                                    {
                                                        zbor[nrzboruri].setplecare(str);
                                                        cout<<endl<<"Introduceti orasul de sosire al zborului: "<<d+1<<": ";
                                                        try
                                                        {
                                                            cin>>str;
                                                            a=0;
                                                            for (j=0;j<strlen(str)&& a==0; j++)
                                                                if (strchr(".,;?!@$%^&-+=",str[j])!=NULL)
                                                                        a=1;
                                                            if (a==0)
                                                            {
                                                                zbor[nrzboruri].setsosire(str);
                                                                cout<<endl<<"Introduceti data zborului  "<<d+1<<" (format zi.luna.an ex: 07.01.2022): ";
                                                                try
                                                                {
                                                                    cin>>str;
                                                                    strcpy(zistr,str);
                                                                    zistr[2]='\0';
                                                                    zi=atoi(zistr);
                                                                    strcpy(lunastr,str+3);
                                                                    lunastr[2]='\0';
                                                                    luna=atoi(lunastr);
                                                                    strcpy(anstr,str+6);
                                                                    an=atoi(anstr);
                                                                    if (an<2021 || luna>12 || zi>31)
                                                                    {
                                                                        throw(6);
                                                                    }
                                                                    if (an==2021)
                                                                    {
                                                                        if (luna<12 || (luna==12 && zi<13))
                                                                        {
                                                                            throw(6);
                                                                        }
                                                                        else
                                                                        {
                                                                            zbor[nrzboruri].setdata(str);
                                                                            cout<<endl<<"Introduceti nr. de locuri al zborului "<<d+1<<" :"<<endl;
                                                                            cin>>x;
                                                                            zbor[nrzboruri].setnrlocuri(x);
                                                                            nrzboruri++;
                                                                        }
                                                                    }
                                                                    if (an>2021)
                                                                    {
                                                                       if (luna==12 && zi<13)
                                                                       {
                                                                           throw(6);
                                                                       }
                                                                       else
                                                                       {
                                                                        zbor[nrzboruri].setdata(str);
                                                                        cout<<endl<<"Introduceti nr. de locuri al zborului "<<d+1<<" :"<<endl;
                                                                        cin>>x;
                                                                        zbor[nrzboruri].setnrlocuri(x);
                                                                        nrzboruri++;
                                                                       }
                                                                    }

                                                                }
                                                                catch (int ok)
                                                                {
                                                                    d--;
                                                                    cout<<"Formatul de data introdusa este incorect. Reincercati."<<endl;
                                                                }
                                                            }
                                                            else
                                                            {
                                                                throw(7);
                                                            }
                                                        }
                                                        catch(int ok)
                                                        {
                                                            d--;
                                                            cout<<"Orasul de sosire nu este valid."<<endl;
                                                        }
                                                    }
                                                    else
                                                    {
                                                        throw(8);
                                                    }

                                                }
                                                catch(int ok)
                                                {
                                                    d--;
                                                    cout<<"Orasul de plecare nu este valid."<<endl;
                                                }
                                            }
                                          cout<<"Zborurile au fost adaugate cu succes!"<<endl;
                                        }
                                        else
                                        {
                                            if (rasp2=='S' || rasp2=='s')
                                            {
                                                cout<<"Ati selectat optiunea de stergere din lista de zboruri a unor zboruri. Cate zboruri doriti sa stergeti?\n"<<endl;
                                                cin>>nr;
                                                Zboruri z;
                                                for (d=0; d<nr; d++)
                                                {
                                                    cout<<endl<<"Introduceti orasul de plecare al zborului "<<d+1<<" pe care doriti sa il stergeti: ";
                                                    cin>>str;
                                                    z.setplecare(str);
                                                    cout<<endl<<"Introduceti orasul de sosire al zborului "<<d+1<<" pe care doriti sa il stergeti: ";
                                                    cin>>str;
                                                    z.setsosire(str);
                                                    cout<<endl<<"Introduceti data zborului "<<d+1<<" pe care doriti sa il stergeti: ";
                                                    cin>>str;
                                                    z.setdata(str);
                                                    z.setnrlocuri(0);
                                                    try
                                                    {
                                                        verif1=0;
                                                        for (j=0; j<nrzboruri && verif1==0; j++)
                                                            if (strcmp(zbor[j].plecare,z.plecare)==NULL && strcmp(zbor[j].sosire,z.sosire)==NULL && strcmp(zbor[j].data,z.data)==NULL)
                                                        {
                                                                verif1=1;
                                                        }
                                                        if (verif1==1)
                                                        {
                                                            j--;
                                                            cout<<"Zborul a fost identificat. Se sterge..."<<endl;
                                                            for (q=j; q<nrzboruri-1; q++)
                                                            {
                                                                strcpy(zbor[q].plecare,zbor[q+1].plecare);
                                                                strcpy(zbor[q].sosire,zbor[q+1].sosire);
                                                                strcpy(zbor[q].data,zbor[q+1].data);
                                                                zbor[q].nrlocuri=zbor[q+1].nrlocuri;
                                                            }
                                                            nrzboruri--;
                                                            cout<<"Zborul a fost sters cu succes."<<endl;
                                                        }
                                                        else
                                                        {
                                                            throw(10);
                                                        }
                                                    }
                                                    catch (int ok)
                                                    {
                                                        d--;
                                                        cout<<"Zborul cautat de sters nu a fost gasit. Reincercati."<<endl;
                                                    }
                                                }
                                            }
                                            else
                                            {
                                                cout<<"Litera pe care ati introdus-0 nu este valida."<<endl;
                                            }
                                        }
                                    }
                                    else
                                    {
                                        cout<<"Litera pe care ati introdus-o nu este valida. Reincercati."<<endl;
                                    }
                                }
                               }
                               catch (int ok)
                               {
                                   cout<<"Nu se doreste modificarea zborurilor."<<endl;
                               }
                           }
                           else
                           {
                               cout<<"Doriti sa cautati un zbor pentru a efectua o rezervare? D/N"<<endl;
                               try
                               {
                                   cin>>rasp3;
                                   if (rasp3=='D' || rasp3=='d')
                                   {
                                       Zboruri t;
                                       cout<<endl<<"Introduceti orasul de plecare al zborului pe care doriti sa il cautati: ";
                                       cin>>str;
                                       t.setplecare(str);
                                       cout<<endl<<"Introduceti orasul de sosire al zborului pe care doriti sa il cautati: ";
                                       cin>>str;
                                       t.setsosire(str);
                                       t.setdata("15.12.2021");
                                       verif3=0;
                                       for (j=0; j<nrzboruri; j++)
                                            if (strcmp(zbor[j].plecare,t.plecare)==NULL && strcmp(zbor[j].sosire,t.sosire)==NULL)
                                       {
                                           nroptiuni++;
                                           index[nroptiuni]=j;
                                           cout<<zbor[j].plecare<<" "<<zbor[j].sosire<<" "<<zbor[j].data<<" Optiunea "<<nroptiuni<<endl;
                                           verif3=1;
                                       }
                                       if (verif3==0)
                                       {
                                           cout<<"Nu exista zboruri corespunzatoare cerintelor dvs."<<endl;
                                       }
                                       else
                                       {
                                           cout<<endl;
                                           cout<<"Doriti sa rezervati unul dintre aceste zboruri? D/N"<<endl;
                                           try
                                           {
                                              cin>>rasp4;
                                              if (rasp4=='D' || rasp4=='d')
                                              {
                                                  Rezervare r;
                                                  cout<<"Introduceti numarul corespunzator optiunii pe care doriti sa o rezervati: ";
                                                  cin>>opt;
                                                  r.setusername(users[i].username);
                                                  r.setparola(users[i].parola);
                                                  r.setemail(users[i].email);
                                                  r.setstatut(0);
                                                  x=index[opt];
                                                  r.setrezervareplecare(zbor[x].plecare);
                                                  r.setrezervaresosire(zbor[x].sosire);
                                                  r.setrezervaredata(zbor[x].data);
                                                  cout<<endl<<"Introduceti numele dvs. de familie: ";
                                                  cin>>str;
                                                  r.setnume(str);
                                                  cin.ignore();
                                                  cout<<endl<<"Introduceti prenumele dvs. complet: ";
                                                  cin.getline(str, 50);
                                                  r.setprenume(str);
                                                  cout<<endl<<"Introduceti varsta dvs.: ";
                                                  cin>>p;
                                                  r.setvarsta(p);
                                                  cout<<endl<<"Introduceti sexul dvs. (M/F/O): ";
                                                  cin>>e;
                                                  r.setsex(e);
                                                  cout<<endl<<"Introduceti CNP-ul dvs.: ";
                                                  cin>>b;
                                                  r.setCNP(b);
                                                  cout<<endl<<"Introduceti data nasterii: ";
                                                  cin>>b;
                                                  r.setdatanasterii(b);
                                                  cout<<"Tocmai ati rezervat zborul "<<r.rezervareplecare<<" "<<r.rezervaresosire<<" "<<r.rezervaredata<<endl;

                                              }
                                              else
                                              {
                                                  if (rasp4=='N' || rasp4=='n')
                                                  {
                                                      cout<<"Nu ati dorit rezervarea niciunui zbor."<<endl;
                                                  }
                                                  else
                                                  {
                                                      throw(14);
                                                  }
                                              }

                                           }
                                           catch (int ok)
                                           {
                                               cout<<"Litera pe care ati introdus-o nu corespunde variantelor de raspuns. Reincercati."<<endl;
                                           }
                                       }
                                   }
                                   else
                                   {
                                       if (rasp3=='N' || rasp3=='n')
                                            cout<<"Nu s-a dorit cautarea/rezervarea niciunui zbor."<<endl;
                                       else
                                       {
                                           throw(11);
                                       }
                                   }

                               }
                               catch (int ok)
                               {
                                   cout<<"Litera introdusa nu corespunde niciunui raspuns. Reincercati."<<endl;
                               }

                           }
                       }
                       else
                       {
                           throw(5);
                       }

                   }
                   catch (int ok)
                   {
                       cout<<"Parola incorecta. Reincercati."<<endl;
                   }

                }
                else
                {
                    throw(4);
                }
               }
               catch(int ok)
               {
                   cout<<"Utilizatorul nu a fost gasit in baza de date. Reincercati."<<endl;
               }

           }
           else
           {
               cout<<"Utilizator nou? Introduceti adresa dvs de email, alegeti un username, si mai apoi o parola:"<<endl;
               cout<<"EMAIL: ";
               try
               {
                  cin>>em;
                  if (strstr(em,".com")!=NULL || strstr(em,".ro")!=NULL)
                  {
                      if (strchr(em,'@')!=NULL)
                      {
                          cout<<endl;
                          cout<<"USERNAME: ";
                          cin>>user;
                          cout<<endl;
                          try
                          {
                              cout<<"Parola trebuie sa contina minim 8 caractere, si maxim 20 de caractere."<<endl<<"PAROLA: ";
                              cin>>pass;
                              if (strlen(pass)>=7 && strlen(pass)<21)
                              {
                                  cout<<"Reconfirmati parola aleasa."<<endl<<"CONFIRMARE PAROLA: ";
                                  cin>>conf;
                                  try
                                  {
                                      if (strcmp(pass,conf)==NULL)
                                      {
                                          cout<<"Parola confirmata cu succes. Contul dvs. a fost creat!"<<endl;
                                          users[nrutilizatori].setusername(user);
                                          users[nrutilizatori].setparola(pass);
                                          users[nrutilizatori].setemail(em);
                                          users[nrutilizatori].setstatut(0);
                                          for(int w=0;w<strlen(users[nrutilizatori].parola);w++)
                                            {
                                        encryptedpass[w]=users[nrutilizatori].parola[w]+12;

                                            }
                                            users[nrutilizatori].setparolacriptata(encryptedpass);
                                          nrutilizatori++;
                                      }
                                      else
                                      {
                                          throw(3);
                                      }
                                  }
                                  catch (int ok)
                                  {
                                      cout<<"Confirmarea parolei nu coincide cu parola aleasa. Reincercati."<<endl;
                                  }
                              }
                              else
                              {
                                  throw(2);
                              }

                          }
                          catch (int ok)
                          {
                              cout<<"Parola introdusa nu corespunde criteriilor. Reincercati."<<endl;
                          }
                      }
                      else
                      {
                          throw(1);
                      }
                  }
                  else
                  {
                      throw(1);
                  }

               }
               catch (int ok)
               {
                   cout<<"Emailul introdus nu este valid. Reincercati."<<endl;
               }
           }
       }
       else
       {
           throw(k);
       }

   }
   catch (char k)
   {
       cout<<endl<<"Litera introdusa nu este nici S/s, nici L/l. Reincercati."<<endl;
   }


}
