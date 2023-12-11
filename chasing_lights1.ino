const int nleds=6;
const int wait=30;
int lp[]={2,3,4,5,6,7};

void setup()
{
  for(int l=0;l<nleds;l++)
  {
    pinMode(lp[l],OUTPUT);
  }
}
void loop()
{
  for(int l=0;l<nleds;l++)
  {
    digitalWrite(lp[l],HIGH);
    delay(wait);
    digitalWrite(lp[l+1],HIGH);
    delay(wait);
    digitalWrite(lp[l],LOW);
    delay(2*wait);
  }
  for(int l=nleds;l>0;l--)
  {
    digitalWrite(lp[l],HIGH);
    delay(wait);
    digitalWrite(lp[l+1],HIGH);
    delay(wait);
    digitalWrite(lp[l],LOW);
    delay(2*wait);
  }
  
  
}