int main()
{
    string infix;
    string postfix;

    while (getline(cin, infix))
    {
        cout << "  infix: " << infix << endl;
        postfix = convert(infix);
        cout << "postfix: " << postfix << endl;
        int result = evaluate(postfix);
        cout << "  value: " << result << endl << endl;
    }

    return 0;
}
