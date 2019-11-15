int ParseT()
{
    int Tval;
    if (lookahead == num)
    {
        Tval = lexval(lookahead);
        MatchToken(num);
    }
    else
        Error();
    return Tval;
}
int ParseR(int in)
{
    int Rval;
    if (lookahead == '+')
    {
        MacthToken('+');
        int Tval = ParseT();
        int R1in = in + Tval;
        int R1val = ParseR(R1in);
        Rval = R1val;
    }
    else if (lookahead == '-')
    {
        MacthToken('-');
        int Tval = ParseT();
        int R1in = in - Tval;
        int R1val = ParseR(R1in);
        Rval = R1val;
    }
    else if (lookahead == '#')
        Rval = in;
    else
        Error();
    return Rval;
}
int ParseE()
{
    int Eval;
    int Tval = ParseT();
    int Rin = Tval;
    int Rval = ParseR(Rin);
    Eval = Rval;
    return Eval;
}