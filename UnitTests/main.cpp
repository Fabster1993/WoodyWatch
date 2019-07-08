#include "UnitTests/testwatchdial.h"
#include "UnitTests/testws2811interface.h"


int main(int argc, char** argv)
{
   quint16 status = 0;
   {
      TestWatchDial testclass;
      status |= QTest::qExec(&testclass, argc, argv);
   }
   {
      TestWs2811Interface testclass;
      status |= QTest::qExec(&testclass, argc, argv);
   }
   return status;
}
