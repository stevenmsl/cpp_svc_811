#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <algorithm>
#include <iterator>
#include <unordered_map>
#include <stack>
#include <string>
using namespace sol811;
using namespace std;

/*takeaways
  - use a map to record the count for each subdomain
*/
vector<string> Solution::getcpsubdomains(vector<string> &cpdomains)
{
  /* record the count for each subdomain */
  auto cpsubs = unordered_map<string, int>();

  for (auto cp : cpdomains)
  {
    /* retrieve the count */
    int spaceIdx = cp.find(' ');
    auto count = stoi(cp.substr(0, spaceIdx));
    auto domain = cp.substr(spaceIdx + 1);
    cpsubs[domain] += count;
    auto dotIdx = -1;

    while (true)
    {
      dotIdx = domain.find('.');
      if (dotIdx == -1)
        break;
      domain = domain.substr(dotIdx + 1);
      cpsubs[domain] += count;
    }
  }

  auto result = vector<string>();
  for (auto &[domain, count] : cpsubs)
    result.push_back(to_string(count) + ' ' + domain);

  return result;
}