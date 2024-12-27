/* Write a function that takes an array of words and smashes them together into a sentence and returns the sentence. 
You can ignore any need to sanitize words or add punctuation, but you should add spaces between each word. 
Be careful, there shouldn't be a space at the beginning or the end of the sentence!
words = ['hello', 'world', 'this', 'is', 'great']
smash(words) returns "hello world this is great"

Source: Codewars
*/

#include <vector>
#include <string>
using namespace std;

string smash(const vector<string>& words)
{
  string ans = "";
  for(int i = 0; i<words.size();i++){
    if(ans == ""){
      ans = ans + words[i];
    }else {ans = ans + " " + words[i];}
  }
   return ans;
}
