#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol811;

/*
Example 1:
Input:
["9001 discuss.leetcode.com"]
Output:
["9001 discuss.leetcode.com", "9001 leetcode.com", "9001 com"]
Explanation:
We only have one website domain: "discuss.leetcode.com".
As discussed above, the subdomain "leetcode.com" and
"com" will also be visited. So they will all be visited 9001 times.
*/

tuple<vector<string>, vector<string>>
testFixture1()
{
  auto input = vector<string>{"9001 discuss.leetcode.com"};
  auto output = vector<string>{"9001 discuss.leetcode.com", "9001 leetcode.com", "9001 com"};
  return make_tuple(input, output);
}

/*
Example 2:
Input:
["900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"]
Output:
["901 mail.com","50 yahoo.com","900 google.mail.com","5 wiki.org","5 org","1 intel.mail.com","951 com"]
Explanation:
We will visit "google.mail.com" 900 times, "yahoo.com" 50 times, "intel.mail.com" once and
"wiki.org" 5 times. For the subdomains, we will visit "mail.com" 900 + 1 = 901 times, "com"
900 + 50 + 1 = 951 times, and "org" 5 times.
*/

tuple<vector<string>, vector<string>>
testFixture2()
{
  auto input = vector<string>{"900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"};
  auto output = vector<string>{"901 mail.com", "50 yahoo.com", "900 google.mail.com",
                               "5 wiki.org", "5 org", "1 intel.mail.com", "951 com"};
  return make_tuple(input, output);
}

void test1()
{
  auto f = testFixture1();
  cout << "Expect to see " << Util::toString(get<1>(f)) << endl;
  Solution sol;
  cout << Util::toString(sol.getcpsubdomains(get<0>(f))) << endl;
}

void test2()
{
  auto f = testFixture2();
  cout << "Expect to see " << Util::toString(get<1>(f)) << endl;
  Solution sol;
  cout << Util::toString(sol.getcpsubdomains(get<0>(f))) << endl;
}

main()
{
  test1();
  test2();
  return 0;
}