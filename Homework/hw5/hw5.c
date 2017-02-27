/* Prob 3.63 */
long switch_prob(long x, long n) 
{
  long result = x;
  switch(n) {
  case 60:
    //result *= 8;
    //    break;
    //  case 1: 
    //    result += 75;
    //break;
  case 62:
    result *= 8;
    break;
  case 63:
    result = result / 8;
    break;
  case 64:
    result *= 16;
    result -= x;
  case 65:
    result *= result;
  default:
    result += 75;
  }
  return result;
}

int main () {
  switch_prob(2, 63);
}
