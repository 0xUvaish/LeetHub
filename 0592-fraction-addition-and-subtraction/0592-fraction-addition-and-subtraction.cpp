class Solution
{
    public:
        string fractionAddition(string s)
        {
            int n = s.size();
            int i = 0;
            int nume = 0;
            int deno = 1;

            while (i < n)
            {
                int currN = 0;
                int currD = 0;
                bool neg = (s[i] == '-');

                if (s[i] == '-' || s[i] == '+') i++;
               	// numerator
                while (i < n && isdigit(s[i]))
                {
                    int val = s[i] - '0';
                    currN = (currN *10) + val;
                    i++;
                }
                i++;

                if (neg)
                {
                    currN *= -1;
                }
               	// denominator
                while (i < n && isdigit(s[i]))
                {
                    int val = s[i] - '0';
                    currD = (currD *10) + val;
                    i++;
                }

                nume = (nume *currD) + (deno *currN);
                deno = deno * currD;

                int GCD = abs(__gcd(nume, deno));
                nume /= GCD;
                deno /= GCD;
            }

            string ans = to_string(nume) + "/" + to_string(deno);
            return ans;
        }
};