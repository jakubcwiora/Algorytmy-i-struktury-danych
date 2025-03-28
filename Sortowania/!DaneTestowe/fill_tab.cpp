#include <fstream>

int main()
{
  std::ofstream deb("dbg20.txt");
  for(int i = 0; i < 20; i++)
  {
    deb<<rand()%100<<'\n';
  }
  std::ofstream sto("dbg100.txt");
  for(int i = 0; i < 100; i++)
  {
    sto<<rand()%100<<'\n';
  }

  std::ofstream tys("dbg1000.txt");
  for(int i = 0; i < 1000; i++)
  {
    tys<<rand()%100<<'\n';
  }

  std::ofstream stotys("dbg100000.txt");
  for(int i = 0; i < 100000; i++)
  {
    stotys<<rand()%100<<'\n';
  }

  return 0;
}
