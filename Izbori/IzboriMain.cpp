//---------------------------------------------------------------------------
struct ProtocolRow
   {
   int Number;
   char Name[10];
   int Votes;
   };
//---------------------------------------------------------------------------
class Protocol
   {
   char RegionName[50];
   int SectionNumber;
   char PersonName[30];
   ProtocolRow Table[24];
   int TotalVotes;
   public:
   Protocol(void);
   void SetVota(char *Part, int VotaCount);
   friend int FindPollingPlace(Protocol *ProrotocolsArray, int Count);
   Protocol operator+(Prptpcol &p);
   };
//---------------------------------------------------------------------------
Protocol::Protocol(void)
   {
   RegionName[0] = 0;
   SectionNumber = 0;
   PersonName[0] = 0;
   TotalVotes = 0;
   }
//---------------------------------------------------------------------------
void Protocol::SetVota(char *Part, int VotaCount)
   {
   for(int i = 0 ; i < 24 ; i++) if(!strcmp(Table[i].Name, Part)) Table[i].Votes = VotaCount;
   }
//---------------------------------------------------------------------------
int FindPollingPlace(Protocol *ProrotocolsArray, int Count)
   {
   int i, Max, MaxNumber;
   Max = ProrotocolsArray[0].TotalVotes;
   MaxNumber = ProrotocolsArray[0].SectionNumber;
   for(i = 1 ; i < Count ; i++)
      {
      if(ProrotocolsArray[i].TotalVotes > Max)
         {
         Max = ProrotocolsArray[i].TotalVotes;
         MaxNumber = ProrotocolsArray[i].SectionNumber;
         }
      }
   return MaxNumber;
   }
//---------------------------------------------------------------------------
Protocol Protocol::operator+(Protocol &p)
   {
   Protocol Temp;

   for(int i = 0 ; i < 24 ; i++) Temp.Table[i].Votes = Table[i].Votes + p.Table[i].Votes;
   Temp.TotalVotes = TotaVotes + p.TotaVotes;

   return Temp;
   }
//---------------------------------------------------------------------------
void main(void)
   {
   int SecNum;

   Protocol Protocols[200];
   SecNum = FindPollingPlace(Prorotocols, 200);
   printf("Nomerat na sekcijata s nai-mnogo podadeni glasove e: %d", SecNum);
   }
//---------------------------------------------------------------------------
