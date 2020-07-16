//---------------------------------------------------------------------------
#include <stdio.h>
#include <conio.h>
//---------------------------------------------------------------------------
class Queue
   {
   protected:
   int Array[100];
   int Count;
   double Avg;
   public:
   Queue(void) {Count = Avg = 0;}
   int Add(int Element);
   };
//---------------------------------------------------------------------------
int Queue::Add(int Element)
   {
   if(Count >= 100) return 0;
   Array[Count] = Element;
   Count++;
   for(int i = Avg = 0 ; i < Count ; i++) Avg += Array[i];
   Avg /= Count;
   return 1;
   }
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
class Ciclic : public Queue
   {
   int CurrentElement;
   public:
   Ciclic(void) : Queue() {CurrentElement = 0;}
   int Get(void);
   double GetAvg(void) {return Avg;}
   Ciclic &operator=(Queue &cl);
   };
//---------------------------------------------------------------------------
int Ciclic::Get(void)
   {
   int Temp;
   Temp = Array[CurrentElement];
   CurrentElement++;
   if(CurrentElement >= Count) CurrentElement = 0;
   return Temp;
   }
//---------------------------------------------------------------------------
Ciclic &Ciclic::operator=(Queue &cl)
   {
   Count = cl.Count;
   Avg = cl.Avg;
   CurrentElement = 0;
   for(int i = 0 ; i < Count ; i++) Array[i] = cl.Array[i];
   return *this;
   }
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void main()
   {
   int i, Element;
   double Average;
   Queue Q;
   Ciclic C;

   for(i = 0 ; i < 7 ; i++)
      {
      printf("Element = "); scanf("%d", &Element);
      C.Add(Element);
      }

   Q = C;

   for(i = 0 ; i < 10 ; i++)
      {
      Element = C.Get();
      printf("\nElement = %d\n", Element);
      }

   printf("\nAverage = %lf\n", C.GetAvg());
   getch();
   }
//---------------------------------------------------------------------------
