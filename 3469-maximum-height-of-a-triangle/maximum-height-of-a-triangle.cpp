class Solution {
public:
    int maxHeightOfTriangle(int red, int blue)
{
  int h = 0;
  int r = red;
  int b = blue;
  int redVal = 1;
  int i = 1;
  int j = 2;
  while (true)
  {
    if (redVal)
    {
      if (red >= i)
        red = red - i;
      else
      {
        break;
      }
      i += 2;
      redVal ^= 1;
      h++;
    }
    else
    {
      if (blue >= j)
      {
        blue = blue - j;
      }
      else
      {
        break;
      }
      j += 2;
      h++;
      redVal ^= 1;
    }
  }
  int h1 = h;
  h = 0;
  i = 1;
  j = 2;
  int blueVal = 1;
  red = r;
  blue = b;
  while (true)
  {
    if (blueVal)
    {
      if (blue >= i)
        blue = blue - i;
      else
      {
        break;
      }
      i += 2;
      blueVal ^= 1;
      h++;
    }
    else
    {
      if (red >= j)
      {
        red = red - j;
        
      }
      else
      {
        break;
      }
      j += 2;
      h++;
      blueVal^=1;
    
    }
  }
  cout << red << " " << blue << endl;

  cout << h1 << " " << h << endl;
  return max(h1, h);
}
    
};