struct node
{
    int val, len;
};
int ParseB()
{
    int Bval;
    if (lookahead == '0')
    {
        MatchToken('0');
        Bval = 0;
    }
    else if (lookahead == '1')
    {
        MatchToken('1');
        Bval = 1;
    }
    else
        Error();
    return Bval;
}
node ParseR(int in)
{
    node R;
    if (lookahead == '0' || lookahead == '1')
    {
        int Bval = ParseB();
        int R1in = 2 * in + Bval;
        node R1 = ParseR(R1in);
        R = {R1.val, R1.len + 1};
    }
    else if (lookahead == '#')
    {
        R = {in, 0};
    }
    else
        Error();
    return R;
}
node ParseS()
{
    node S;
    int Bval = ParseB();
    int Rin = Bval;
    node R = ParseR(Rin);
    S = {R.val, R.len + 1};
    return S;
}
float ParseN()
{
    float Nval;
    node S1 = ParseS();
    MatchToken('.');
    node S2 = ParseS();
    Nval = S1.val + 2 ^ (-S2.len) * S2.val;
    return Nval;
}